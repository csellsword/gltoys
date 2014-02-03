#include <SDL.h>
#include <glew.h> // Replaces OpenGL headers, links with -lGLEW

const GLfloat triangle[][3] = {  { 0.0, 1.0, 0.0 },
                                 { 0.0, 0.0, 0.0 },
                                 { 1.0, 0.0, 0.0 } };

int main( int argc, char** argv )
{
  // Functions that can fail return 0 if successful
  if( SDL_Init( SDL_INIT_VIDEO ) != 0 )
  {
    fprintf( stderr, "SDL_Init failed: %s\n", SDL_GetError() );
    return -1;
  }
  
  SDL_Window* window = SDL_CreateWindow( "Bouncing Balls",
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         800,
                                         600,
                                         SDL_WINDOW_OPENGL );
  if( window == NULL )
  {
    fprintf( stderr, "SDL_CreateWindow failed: %s\n", SDL_GetError() );
    return -1;
  }

  SDL_GLContext glcontext = SDL_GL_CreateContext( window );
  if( glcontext == NULL )
  {
    fprintf( stderr, "SDL_GL_CreateContext failed: %s\n", SDL_GetError() );
    return -1;
  }
 
  glewInit();
  
  const GLubyte* pVersion = glGetString( GL_VERSION );
  fprintf( stdout, "%s\n", pVersion );

  GLuint VAO;
  glGenVertexArrays( 1, &VAO );
  glBindVertexArray( VAO );

  GLuint Buffers;
  glGenBuffers( 1, &Buffers );
  glBindBuffer( GL_ARRAY_BUFFER, Buffers );

  glBufferData( GL_ARRAY_BUFFER, sizeof( triangle ), &triangle, GL_STATIC_DRAW );

  // There is no "LoadShader" function provided by the API
  // One must compose shaders in a manner similiar to VAO's
  // and other ogl objects

  glClearColor( 84.0/255.0 , 84.0/255.0 , 84.0/255.0, 1.0 );
  glClear( GL_COLOR_BUFFER_BIT );

  SDL_GL_SwapWindow( window );

  int quit = 0;
  while( quit == 0 )
  {
    SDL_Event event;
    while( SDL_PollEvent( &event ) )
    {
      switch( event.type )
      {
        case SDL_KEYDOWN:
          if( event.key.keysym.sym  == SDLK_ESCAPE ) quit = 1;
      }
          
    }
  }
  SDL_DestroyWindow( window );
  SDL_Quit();
  return 0;
}
