#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"


typedef struct background 
{
SDL_Surface *background;
SDL_Rect camera;
}background;

void initialisation_background (background *b  );
void afficher_background (SDL_Surface *screen , background *b);
void scrolling_right (background *b , SDL_Surface *screen );
void scrolling_left (background *b , SDL_Surface *screen );

