#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "background.h"




 
int main ()
{
SDL_Surface *screen;
screen=SDL_SetVideoMode(800,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
background b;
initialisation_background (&b  );
int done=1;
SDL_Event event;
    while(done)
    {
      
      if (SDL_PollEvent(&event))
       {


switch (event.type) {
  case SDL_QUIT  : done=0 ; break;
case SDL_KEYDOWN :
  if (event.key.keysym.sym == SDLK_RIGHT){
 
    scrolling_right (& b , screen );


}
 else if (event.key.keysym.sym == SDLK_LEFT){
    
   scrolling_left (& b , screen );

  }
  
break;

}
}
afficher_background (screen ,& b);
SDL_Flip(screen);
}

return 0;
}
