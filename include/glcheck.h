#pragma once

#include <iostream>
#include <glew.h>

# define GLCHECK( call )                     \
  call;                                      \
  check_gl_error( #call, __FILE__, __LINE__ );

inline void check_gl_error( const char* call, const char* file, const int line )
{
  unsigned int gle = glGetError();
  if( gle != GL_NO_ERROR )
  {
    std::cerr<<"[error][GL] GL Error discovered when calling " << call << " at " << file << "(l " << line << "): ";
    switch (gle)
    {
      case GL_INVALID_ENUM:
        std::cerr << "Invalid enum.\n";
        break;
      case GL_INVALID_VALUE:
        std::cerr << "Invalid value.\n";
        break;
      case GL_INVALID_OPERATION:
        std::cerr <<"Invalid Operation.\n";
        break;
      case GL_STACK_OVERFLOW:
        std::cerr << "Stack overflow.\n";
        break;
      case GL_STACK_UNDERFLOW:
        std::cerr << "Stack underflow.\n";
        break;
      case GL_OUT_OF_MEMORY:
        std::cerr << "Out of memory.\n";
        break;
    }
    return;
  }
}

