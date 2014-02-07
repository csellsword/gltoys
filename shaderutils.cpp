#include <cstdio>
#include <glew.h>
#include <string>
#include <fstream>

// Compiles a shader from source file at path
GLuint CompileShaderObject( const std::string& path, GLenum type )
{
  std::string shaderSrc;

  std::ifstream src( path.c_str(), std::ios::in );
  if( src.is_open() )
  {
    std::string line = "";
    while( getline( src, line ) )
    {
      shaderSrc += "\n" + line;
    }
    src.close();
  }

  GLuint shaderObj = glCreateShader( type );
  const char* cstr = shaderSrc.c_str();
  glShaderSource( shaderObj, 1, &cstr, NULL );
  glCompileShader( shaderObj );

  // logging
  unsigned int bufsize = 256;
  GLsizei length;
  char *log = new char[bufsize];
  glGetShaderInfoLog( shaderObj, bufsize, &length, log );
  if( length > 0 )
  {
    // print some shit, defered to later
    fprintf( stderr, "%s\n", log );
  }
  delete [] log;

  return shaderObj;
}

GLuint LinkShaderProgram( const GLuint* names, unsigned int size )
{
  // linking
  GLuint program = glCreateProgram();

  for( unsigned int i = 0; i < size; i++ )
  {
    glAttachShader( program, names[i] );
    glLinkProgram( program ); // this should probably be a separate function
  }

  // log the linking
  unsigned int bufsize = 256;
  GLsizei length;
  char *log = new char[bufsize];
  glGetProgramInfoLog( program, bufsize, &length, log );
  if( length > 0 )
  {
    // print some shit, defered to later
    fprintf( stderr, "%s\n", log );
  }
  delete [] log;

  //glDeleteShader( shaderObj ); //delete on your own time
  
  return program; // need to actually return the shader
}
