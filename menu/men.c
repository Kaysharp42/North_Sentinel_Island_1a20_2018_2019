#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
struct options
{
int r;
int s;
};
typedef struct options options;
options settings (SDL_Surface *ecran, SDL_Surface *Menu_anime[],SDL_Rect posstart ,SDL_Rect posbackground,options op )
{
  Uint32 time;
int x,y,i,c=0;
  SDL_Surface *t[8],*bg;
  t[0]=IMG_Load("o1.png");
  t[1]=IMG_Load("o2.png");
  t[2]=IMG_Load("o3.png");
  t[3]=IMG_Load("o4.png");
  t[4]=IMG_Load("o5.png");
  t[5]=IMG_Load("o6.png");
  t[6]=IMG_Load("o7.png");
  t[7]=IMG_Load("o8.png");
  bg=IMG_Load("1.png");
  SDL_Rect pos ;
  pos.x=0;
  pos.y=0;
      SDL_Event event;
      SDL_BlitSurface( bg,NULL, ecran, &posbackground );

      if (op.r == 0 &&  op.s==0){SDL_BlitSurface( t[1],NULL, ecran, &pos );}
      if (op.r == 1 &&  op.s==0){SDL_BlitSurface( t[0] ,NULL, ecran, &pos );}
      if (op.r == 0 &&  op.s==1){SDL_BlitSurface( t[4] ,NULL, ecran, &pos );}
      if (op.r == 1 &&  op.s==1){SDL_BlitSurface( t[7] ,NULL, ecran, &pos );}
      SDL_Flip(ecran);

while (1){

        time = SDL_GetTicks();
  while(SDL_PollEvent(&event))
  {
    SDL_WaitEvent(&event);
    switch(event.type)
            {
                      case SDL_QUIT:
      return op;
                              break;
              case SDL_MOUSEMOTION:
                    x = event.motion.x;
                      y = event.motion.y;
                      if (op.r==0 && op.s==0)
                            {
                              if(x>=441 && x<590 && y>=227 && y<=260)
                              {
                                SDL_BlitSurface( t[2] ,NULL, ecran, &pos );
                                  break;
                              }
                            }
                            if (op.r==0 && op.s==1)
                                 {
                                   if(x>=441 && x<590 && y>=227 && y<=260)
                                   {
                                     SDL_BlitSurface( t[5] ,NULL, ecran, &pos );
                                       break;
                                   }
                                 }
                             if (op.r==1 && op.s==0)
                                 {
                                   if(x>=441 && x<590 && y>=227 && y<=260)
                                   {
                                     SDL_BlitSurface( t[3] ,NULL, ecran, &pos );
                                       break;
                                   }
                                 }
                                  if (op.r == 1 && op.s == 1){
                                    if(x>=441 && x<590 && y>=227 && y<=260)
                                    {
                                      SDL_BlitSurface( t[7] ,NULL, ecran, &pos );
                                        break;
                                    }

                                       }

                              break;
                              case SDL_MOUSEBUTTONDOWN:
                                        x = event.button.x;
                                      y = event.button.y;
                                      if (event.button.button == SDL_BUTTON_LEFT) {
                              if(x>=441 && x<=462 && y>=227 && y<=261)
                             {
                                if (op.r ==1 ) { op.r=0;
                                  break;
                              }
                              if(x>=567 && x<=590 && y>=227 && y<=260)
                              {
                                if (op.r ==0 ) { op.r=1;}
                                  break;
                              }
                              if(x>=440 && x<=462 && y>=435 && y<=381)
                              {
                                if (op.s ==1 ) { op.s=0;}
                                  break;
                              }
                              if(x>=567 && x<=590 && y>=347 && y<=380)
                              {
                                if (op.s ==0 ) { op.s=1;}
                                  break;
                              }
                              }
                              if(x>=316 && x<=480 && y>=400 && y<=451)
                              {
                              return op;
                                break;
                              }
                              break;

  }
            }

}
}
for (int i=0; i<8 ;i++){SDL_FreeSurface(t[i]);}
SDL_FreeSurface(bg);
SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,39,138,226));

}
int main( int argc, char *argv[] )
 {
  options op;
  op.r=0;
  op.s=1;
SDL_Surface *ecran=NULL, *background=NULL  , *start=NULL, *setings=NULL, *exit=NULL ;
SDL_Surface *starto=NULL, *setingso=NULL, *exito=NULL , *Menu_anime[266],*loadgameo=NULL;
SDL_Rect posbackground , posstart  , posexit ;
 SDL_Event event;
Mix_Music *musique;
Mix_Chunk *ding;


int curseur=1,continuer=1,m=0,i,fix=0;
     char menu[40];
start = IMG_Load("menu.png");

posbackground.x=0;
posbackground.y=0;
posstart.x=400;
posstart.y=300;
posexit.x=300;
posexit.y=300;

SDL_Init( SDL_INIT_VIDEO );
ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE );
     SDL_WM_SetCaption("Time Machine", NULL);

     SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,39,138,226));

 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
     {
    	printf("%s", Mix_GetError());
     }

     musique = Mix_LoadMUS("music.mp3");
 for (i=0; i<=16; i++)
     {
     	sprintf(menu,"%d.png",i);
        Menu_anime[i]=IMG_Load(menu);
        SDL_BlitSurface(Menu_anime[i],NULL,ecran,&posbackground);
        SDL_Flip(ecran);
        SDL_Delay(20);
     }

start= IMG_Load("start.png");
setings= IMG_Load("setings.png");
exit = IMG_Load ("exit.png" ) ;
SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,39,138,226));

 for (i=0; i<=16; i++)
    {
        sprintf(menu,"%d.png",i);
        Menu_anime[i]=IMG_Load(menu);

    }
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,39,138,226));

    while (continuer!=0)
    {
      if(op.s==1){Mix_PlayMusic(musique, -1);}
	if (curseur>3)
		curseur=1;
	if (curseur<1)
		curseur=3;
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,39,138,226));

	if (i>16) i=1;
	sprintf(menu,"%d.png",i);
    SDL_BlitSurface(Menu_anime[i],NULL,ecran,&posbackground);
    SDL_Delay(100);
    i++;
    SDL_BlitSurface(start,NULL,ecran,&posstart);
while (SDL_PollEvent(&event))
	{
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYUP:
                fix=0;
			break;
case SDL_KEYDOWN:
				if(!fix)
				{
             switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
			curseur--;
                    break;
                    case SDLK_DOWN:
			curseur++;
                    break;
		    case SDLK_KP_ENTER:
			if (curseur==4)
			{
			continuer = 0;
			}
                    break;
			fix=1;
			}
                }
            break;
case SDL_MOUSEMOTION:
            	if ((event.motion.x>290 )&&(event.motion.x<310)&&(event.motion.y>300)&&(event.motion.y<360))
            	{
            		curseur=1;
starto= IMG_Load("playon.png");
            	}
            	if ((event.motion.x>250)&&(event.motion.x<475)&&(event.motion.y>380)&&(event.motion.y<420))
            	{
            		curseur=2;
                loadgameo=IMG_Load ("loadgameon.png" ) ;

            	}
            	if ((event.motion.x>250)&&(event.motion.x<475)&&(event.motion.y>460)&&(event.motion.y<500))
            	{
            		curseur=3;
                setingso= IMG_Load("optionson.png");
            	}
            	if ((event.motion.x>250)&&(event.motion.x<475)&&(event.motion.y>540)&&(event.motion.y<590))
            	{
            		curseur=4;
                exito = IMG_Load ("quiton.png" ) ;

            	}
        }
	}
if (curseur==1)
	{
    	        SDL_BlitSurface(starto, NULL, ecran, &posstart);
	}
if (curseur==2)
	{
		SDL_BlitSurface(loadgameo, NULL, ecran, &posstart);
    }
if (curseur==3)
	{
		SDL_BlitSurface(setingso, NULL, ecran, &posstart);
	}
if (curseur==4)
	{
		SDL_BlitSurface(exito, NULL, ecran, &posstart);
	}
  if(event.type == SDL_MOUSEBUTTONDOWN)
                    {
                      switch (curseur) {
                        case 1:
                        return 1 ;
                        break;
                        case 2 :
                        return 2 ;
                        case 3 :
                        SDL_FreeSurface(Menu_anime[i]);
                        SDL_FreeSurface(exito);
                        SDL_FreeSurface(setingso);
                        SDL_FreeSurface(loadgameo);
                        SDL_FreeSurface(starto);

                       op=settings(ecran,Menu_anime,posstart,posbackground, op);
                      break;
                      case 4 :
                    //   n=quit()
                       break;
                      }
                    }

SDL_Flip(ecran);
    }
    Mix_FreeMusic(musique);
    Mix_FreeChunk(ding);
    Mix_CloseAudio();
    SDL_FreeSurface(background);
    SDL_Quit();

    return EXIT_SUCCESS;
}
