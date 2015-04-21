/*  Created on: Feb 27, 2015
 *      Author: T.Delame (tdelame@gmail.com)
 */
# include <shaderprogram.h>
# include <stdexcept>
# include <fstream>
# include <sstream>
# include <stdlib.h>

///FIXME: not robust at all! But it should work fine in our case (@tdelame)
static std::string get_extension( const std::string& filename )
{
  std::string::size_type pos = filename.find_last_of( "." );
  if( pos == std::string::npos )
    return "";
  return filename.substr( pos );
}

static GLuint compile_shader ( std::string shader_name, GLuint type )
{
  // open the shader file
  std::ifstream shader_file ( shader_name.c_str() );
  if ( !shader_file.is_open() )
    {
      throw std::runtime_error( "[error] cannot open shader file " + shader_name );
    }

  // create a new shader object
  GLuint shader = glCreateShader ( type );
  if ( !shader )
    {
      throw std::runtime_error( "[error] error when creating shader [" + shader_name + "]" );
    }

  // load the shader source in one string
  std::stringstream shader_data;
  shader_data << shader_file.rdbuf();
  shader_file.close(); // no more needed, so close it now
  const std::string shader_string = shader_data.str();

  // set the source of the shader (as one big cstring)
  const char*  strShaderVar = shader_string.c_str();
  GLint iShaderLen = shader_string.size();
  glShaderSource ( shader, 1,(const GLchar**) &strShaderVar, (GLint*)&iShaderLen );

  // compile the shader
  glCompileShader ( shader );
  GLint result;
  glGetShaderiv( shader, GL_COMPILE_STATUS, &result );
  if( GL_FALSE == result )
    {
      std::cerr<< "[error] shader [" << shader_name << "] compilation failed!" << std::endl;
      GLint logLen;
      GLCHECK(glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &logLen ));
      if( logLen > 0 )
        {
          char*  log = (char* )malloc(logLen);
          GLsizei written;
          glGetShaderInfoLog( shader, logLen, &written, log);
          std::cerr<<"[error] shader log:\n" << log << std::endl;
          free(log);
        }
      GLCHECK(glDeleteShader( shader ));
      throw std::runtime_error( "[error] canno compile shader [" + shader_name + "]" );
    }
  return shader;
}

ShaderProgram::~ShaderProgram()
{
  if( glIsShader( id ) )
    {
      GLCHECK( glDeleteProgram( id ) );
    }
}

ShaderProgram::ShaderProgram() :
  id( 0 )
{}

void
ShaderProgram::load(
  const std::string& vertexShaderSourceFile,
  const std::string& fragmentShaderSourceFile )
{
  GLCHECK(bool already_loaded = glIsShader( id ));
  if( already_loaded )
    {
      GLCHECK( glDeleteProgram( id ) );
    }
  GLCHECK( id = glCreateProgram());
  if( get_extension( vertexShaderSourceFile ) != ".vert" )
    throw std::runtime_error( "[error] vertex shader source file does not have .vert extension" );
  if( get_extension( fragmentShaderSourceFile ) != ".frag" )
    throw std::runtime_error( "[error] fragment shader source file does not have .frag extension" );

  GLuint vertex_shader = compile_shader( vertexShaderSourceFile, GL_VERTEX_SHADER );
  GLuint fragment_shader = compile_shader( fragmentShaderSourceFile, GL_FRAGMENT_SHADER );
  GLCHECK( glAttachShader( id, vertex_shader ) );
  GLCHECK( glAttachShader( id, fragment_shader ) );
  GLCHECK( glDeleteShader( fragment_shader ) );
  GLCHECK( glDeleteShader( vertex_shader ) );

  GLCHECK( glLinkProgram( id ) );
  GLint status;
  glGetProgramiv( id, GL_LINK_STATUS, &status );
  if( GL_FALSE == status )
    {
      std::cerr<<"[error] failed to link shader program " << id << "!"<<std::endl;
      GLint logLen;
      glGetProgramiv( id, GL_INFO_LOG_LENGTH, &logLen);
      if( logLen > 0 )
        {
          char * log = (char *)malloc(logLen);
          GLsizei written;
          glGetProgramInfoLog(id, logLen, &written, log);
          std::cerr<<"[error] program log:\n" << log << std::endl;
          free(log);
        }
      throw std::runtime_error( "[error] cannot link shader program " + id );
    }
}
