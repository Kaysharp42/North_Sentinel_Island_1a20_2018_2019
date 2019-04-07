#include "background.h"

void initialisation_background (background *b  )
{
//b->pos.x=0;
//b->pos.y=0;
b->camera.x=0;
b->camera.y=0;
b->camera.w=800;
b->camera.h=400;
b->background=IMG_Load("background.jpg");

}



void afficher_background (SDL_Surface *screen , background *b)
{
SDL_BlitSurface(b->background,&b->camera,screen,NULL);
}

void scrolling_right (background *b , SDL_Surface *screen )
{
if (b->camera.x<1600-b->camera.w)
b->camera.x+=20;
}

void scrolling_left (background *b , SDL_Surface *screen )
{
  if (b->camera.x>0)
b->camera.x-=20;
}

