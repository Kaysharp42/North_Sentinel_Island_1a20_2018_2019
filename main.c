#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>
#define True 1;
#define False 0;
struct options
{
int r;
int s;
};
typedef struct options options;
options optionsmenu(SDL_Surface* screen, SDL_Surface* t1[], SDL_Surface* t[], SDL_Rect imagebg , TTF_Font* font,options op)
{
  Uint32 time;
int x,y,c=0;
SDL_FreeSurface(t[x]);
SDL_BlitSurface(t[y],NULL,screen,&imagebg);
SDL_Flip(screen);
SDL_Event event;

  while(1)
  {
      while (SDL_PollEvent(&event))

      {
          if (event.type == SDL_QUIT)
          {
          return op;
          }
          if(event.type == SDL_MOUSEMOTION)
          {
                  if((event.motion.x>78)&&(event.motion.x<156)&&(event.motion.y>296)&&(event.motion.y<375))
                  {
                  y=1;
                  }
                  if((event.motion.x>254)&&(event.motion.x<327)&&(event.motion.y>296)&&(event.motion.y<375))
                  {
                  y=2;
                  }
                  if((event.motion.x>418)&&(event.motion.x<490)&&(event.motion.y>296)&&(event.motion.y<375))
                  {
                  y=3;
                  }
                  if((event.motion.x>566)&&(event.motion.x<638)&&(event.motion.y>296)&&(event.motion.y<375))
                  {
                  y=4;
                  }
                  if((event.motion.x>734)&&(event.motion.x<806)&&(event.motion.y>296)&&(event.motion.y<375))
                  {
                  y=5;
                  }


          }
          if(event.type == SDL_MOUSEBUTTONDOWN)
          {
              if (event.button.button == SDL_BUTTON_LEFT)
              {
                  switch (y)
                  {
                  case 1:
                    //
                      break;
                  case 2:
///
                     break;
                  case 3:
//
                      break;
                      case 4:
                      //
                      break;
                  case 5:
//
                      break;

                  }
              }
          }
          if (event.type == SDL_KEYDOWN)
          {
              if(event.key.keysym.sym == SDLK_RIGHT)
              {
                  if(x<5)
                      y=y+1;
              }
              if(event.key.keysym.sym == SDLK_LEFT)
              {
                  if(x>1)
                      y=y-1;
              }
              else if (((event.key.keysym.sym == SDLK_KP_ENTER)||(event.key.keysym.sym == SDLK_RETURN)))
              {
                  switch (y)
                  {
                  case 1:
                    //
                      break;
                  case 2:
                    //
                      break;
                  case 3:
                //
                      break;
                      case 4:
              //

                      break;
                  case 5:
            return op;
                      break;
                  }
              }
          }
      }
  }
}
int showmenu(SDL_Surface* screen, SDL_Surface* t[], SDL_Rect imagebg , TTF_Font* font, SDL_Surface* t1[])
{
  options op;
        Uint32 time;
        int i=0,x=0,y,c=0,tmp=0;
  //      SDL_BlitSurface( t[x] ,NULL, screen, &imagebg );
        SDL_Flip(screen);
        SDL_Event event;
        printf("sssss1s\n" );
        while(1)
            {
/*            if (i>16)  i =0;
              SDL_BlitSurface(t[i],NULL,screen,&imagebg);
              SDL_FreeSurface(t[i-1]);
              i++;*/
                while (SDL_PollEvent(&event))

                {
                  SDL_WaitEvent(&event);

                    if (event.type == SDL_QUIT)
                    {
                      return 0;
                    }
                    if(event.type == SDL_MOUSEMOTION)
                    {
                            if((event.motion.x>78)&&(event.motion.x<156)&&(event.motion.y>296)&&(event.motion.y<375))
                            {
                              tmp=x;
                            x=1;
                            }
                            if((event.motion.x>254)&&(event.motion.x<327)&&(event.motion.y>296)&&(event.motion.y<375))
                            {
                              tmp=x;
                            x=2;
                            }
                            if((event.motion.x>418)&&(event.motion.x<490)&&(event.motion.y>296)&&(event.motion.y<375))
                            {
                              tmp=x;
                            x=3;
                            }
                            if((event.motion.x>566)&&(event.motion.x<638)&&(event.motion.y>296)&&(event.motion.y<375))
                            {
                              tmp=x;
                            x=4;
                            }
                    }
                    if(event.type == SDL_MOUSEBUTTONDOWN)
                    {
                        if (event.button.button == SDL_BUTTON_LEFT)
                        {
                            switch (x)
                            {
                            case 1:
                                //
                                break;
                            case 2:
                                //
                                break;
                            case 3:
                            op=optionsmenu(screen, t1,t, imagebg ,font, op);
                    //        SDL_FreeSurface(t[y]);

                                break;
                                case 4:
                            return 0;
                                break;

                            }
                        }
                    }
                    if (event.type == SDL_KEYDOWN)
                    {
                        if(event.key.keysym.sym == SDLK_RIGHT)
                        {
                            if(x<4)
                            tmp=x;
                                x=x+1;
                        }
                        if(event.key.keysym.sym == SDLK_LEFT)
                        {
                            if(x>1)
                            tmp=x;
                                x=x-1;
                        }
                        else if (((event.key.keysym.sym == SDLK_KP_ENTER)||(event.key.keysym.sym == SDLK_RETURN)))
                        {
                            switch (x)
                            {
                            case 1:
                                //
                                break;
                            case 2:
                              //
                                break;
                            case 3:
                                op=optionsmenu(screen,t1,t, imagebg ,font, op);
                                break;
                                case 4:
                                return 0;
                                break;
                            }
                        }
                    }
                }
                SDL_FreeSurface(t[tmp]);
                SDL_Flip(screen);

            }
}
int  main() {
  char pause;
  int l=0,i=0;
   SDL_Init(SDL_INIT_VIDEO);
   TTF_Init();

   TTF_Font *font = NULL;
   font =TTF_OpenFont("arial_narrow_7.ttf", 36);



   if (SDL_Init(SDL_INIT_VIDEO)!=0)
   {printf("unable to initialize SDL : %s\n",SDL_GetError());
   return 1;
   }
   SDL_Surface *screen, *image, *WinImg;
  screen = SDL_SetVideoMode(800, 600, 32,SDL_DOUBLEBUF |SDL_SWSURFACE);

  if(!screen)
  {
    printf("Unable to set 60*400 video : %s\n",SDL_GetError() );
    return (-1);
    }
        SDL_WM_SetCaption("test1", NULL);
        SDL_Rect positionecran ,posdetec,frame,positionwin;  // rect to describe the source desr region of our blit
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
        {
          printf("music error%s\n",Mix_GetError() );

        }
      Mix_Music *music;
        music = Mix_LoadMUS("Menu/intro.wav");
      //  Mix_VolumeChunk(music, MIX_MAX_VOLUME/4);

       Mix_PlayMusic(music,-1);
    // load the bit map into image surface & check
  image = SDL_LoadBMP("background.bmp");// or IMG_Load
  WinImg = IMG_Load("win.png");// or IMG_Load
printf("sss\n");
  SDL_Surface* t[15];
  t[0]=IMG_Load("Menu/options/1.png");
  t[1]=IMG_Load("Menu/options/2.png");
  t[2]=IMG_Load("Menu/options/3.png");
  t[3]=IMG_Load("Menu/options/4.png");
  t[4]=IMG_Load("Menu/options/5.png");
  t[5]=IMG_Load("Menu/options/6.png");
  t[6]=IMG_Load("Menu/options/7.png");
  t[7]=IMG_Load("Menu/options/8.png");
  t[8]=IMG_Load("Menu/options/9.png");
  t[9]=IMG_Load("Menu/options/10.png");
  t[10]=IMG_Load("Menu/options/11.png");
  t[11]=IMG_Load("Menu/options/12.png");
  t[12]=IMG_Load("Menu/options/13.png");
  t[13]=IMG_Load("Menu/options/14.png");
  t[14]=IMG_Load("Menu/options/15.png");
  t[15]=IMG_Load("Menu/options/16.png");
  SDL_Surface* t1[15];
  t1[0]=IMG_Load("Menu/options/1.png");
  t1[1]=IMG_Load("Menu/options/2.png");
  t1[2]=IMG_Load("Menu/options/3.png");
  t1[3]=IMG_Load("Menu/options/4.png");
  t1[4]=IMG_Load("Menu/options/5.png");
  t1[5]=IMG_Load("Menu/options/6.png");
  t1[6]=IMG_Load("Menu/options/7.png");
  t1[7]=IMG_Load("Menu/options/8.png");
  t1[8]=IMG_Load("Menu/options/9.png");
  t1[9]=IMG_Load("Menu/options/10.png");
  t1[10]=IMG_Load("Menu/options/11.png");
  t1[11]=IMG_Load("Menu/options/12.png");
  t1[12]=IMG_Load("Menu/options/13.png");
  t1[13]=IMG_Load("Menu/options/14.png");
  t1[14]=IMG_Load("Menu/options/15.png");
  t1[15]=IMG_Load("Menu/options/16.png");
  printf("sss\n");

  SDL_Rect imagebg;
  imagebg.x = 0;
  imagebg.y = 0;
  if (image == NULL) {
    printf( " ERROR %s\n",SDL_GetError());
    return 1;
  }
  if (i>16)  i =0;
    SDL_BlitSurface(t[i],NULL,screen,&positionecran);
    i++;
  positionecran.x = 0;
  positionecran.y = 0;
  positionecran.w = 800;
  positionecran.h =image->h;
  positionwin.x = 0;
  positionwin.y = 0;
  positionwin.w = WinImg->w;
  positionwin.h =WinImg->h;
//    SDL_BlitSurface(image, NULL, screen, &positionecran);
    SDL_Flip(screen);
     int CurFrame =0, MaxFrame = 8;
    SDL_Surface *caractere;
    caractere= IMG_Load("movements.png");
    if (caractere == NULL) {
      printf( " ERROR  caractere %s\n",SDL_GetError());
      return 1;
    }
        posdetec.x=0;
    posdetec.y=350;
    posdetec.h =32;
    posdetec.w =32;
    frame.x=0;
    frame.y=0;
    frame.w=32;
    frame.h=32;
    printf("sss\n");

   int r =showmenu(screen, t ,imagebg,font,t1);
   printf("sss\n");
    SDL_Event event;
    while(r==1)
    {
      SDL_BlitSurface(caractere,&frame,screen,&posdetec);
      SDL_Flip(screen);
      while(SDL_PollEvent(&event))
       {

SDL_WaitEvent(&event);
switch (event.type) {
  case SDL_QUIT  : r=0 ; break;
  case SDL_KEYDOWN :
  if (event.key.keysym.sym == SDLK_ESCAPE)
  {
    r=0;
    break;
  }
  if (event.key.keysym.sym == SDLK_RIGHT)
  {
    posdetec.x += 80;
    CurFrame ++ ;
    if (CurFrame > MaxFrame) {
      CurFrame =0;
    }
    frame.x=CurFrame * frame.w;

  }
  if (event.key.keysym.sym == SDLK_LEFT)
  {
    posdetec.x -= 80;

  }
  if (event.key.keysym.sym == SDLK_UP)
  {
    posdetec.y -= 80;

  }
  if (event.key.keysym.sym == SDLK_DOWN)
  {
    posdetec.y += 80;

  }
break;
}
if (posdetec.x > 800) {
  posdetec.x = 0;
  positionecran.x=positionecran.w;
}

SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));

SDL_BlitSurface(caractere,&frame,screen,&posdetec);
SDL_BlitSurface(image, &positionecran, screen, NULL);
SDL_Flip(screen);




}

    }
    SDL_FreeSurface(t[r]);

    SDL_FreeSurface(caractere);

    SDL_FreeSurface(image);

    //Mix_FreeMusic(music);
        TTF_Quit();
                SDL_Quit();
  return 0;
}
