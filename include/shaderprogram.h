#pragma once

# include <glcheck.h>
# include <string>

/**
 * A shader program is a binary that will be executed on the graphic card to
 * replace operations of the fixed pipeline. It is composed of two shading
 * stages:
 * - vertex shading (basically processing vertices sent to the graphic card)
 * - fragment shading (processing fragments of primitives after tessellation)
 * Each of these stage is described by a shader, i.e. a sub-program.
 */
class ShaderProgram {
public:
  /* The default construction return a null shader program (it does nothing)*/
  ShaderProgram();
  /* The program is deleted from the graphic card memory */
  ~ShaderProgram();

  /* Load a program on the graphic card whose stage are described by the
   * file given as arguments. If this was already on the graphic card, the
   * previous program is deleted before loading the new one. */
  void load(
    const std::string& vertexShaderSourceFile,
    const std::string& fragmentShaderSourceFile );

  /* Automatic conversion operator to use an instance of ShaderProgram as a
   * GLint representing the name of the shader program on the graphic card.
   * Thus something like this could be used:
   * glUseProgram( *this ); */
  inline
  operator GLint() const
  {
    return id;
  }
private:
  /* A shader program represents a binary on the graphic card memory. To avoid
   * the difficulty of managing a memory pointed to by more than one object,
   * we simply forbid (for now) any transmission of internal data from one
   * instance to another. */
  ShaderProgram( const ShaderProgram& other );
  ShaderProgram&
  operator=( const ShaderProgram& other );
  GLint id;
};

