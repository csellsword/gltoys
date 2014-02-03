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
  glShaderSource( shaderObj, 1, shaderSrc.c_str(), NULL );
  glCompileShader( shaderObj );

