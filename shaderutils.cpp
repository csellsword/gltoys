#include <cstdio>
#include <glew.h>
#include <string>

void LoadShader( const std::string& path, GLenum type )
{
  char line[256];
  std::string shaderSrc;
  FILE* src = fopen( path.c_str(), "r" );
  while( feof( src ) != 0 )
  {
    fgets( line, 256, src );
    shaderSrc.append( line );
  }

  GLuint shaderObj = glCreateShader( type );
  const char* cstr = shaderSrc.c_str();
  glShaderSource( shaderObj, 1, &cstr, NULL );
  glCompileShader( shaderObj );

  // logging
  glGetShaderiv( shaderObj, GL_COMPILE_STATUS, &result );
  glGetShaderiv( shaderObj, GL_INFO_LOG_LENGTH, &infologlength );
  if( infologlength > 0 )
  {
    // print some shit, defered to later
  }

  // linking
  GLuint program = glCreateProgram();
  glAttachShader( program, shaderObj );
  glLinkProgram( program ); // this should probably be a separate function

  // log the linking
  glGetProgramiv( program, GL_LINK_STATUS, &result );
  glGetProgramiv( program, GL_INFO_LOG_LENGTH, &infologlength );
  if( infologlength > 0 )
  {
    // print some shit
  }

  glDeleteShader( shaderObj ); // certainly don't need the obj anymore

  return program; // need to actually return the shader
}
