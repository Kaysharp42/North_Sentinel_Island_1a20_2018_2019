#define MAX_SPEED 10
typedef struct perssonage
{
SDL_Surface *personnage;
SDL_Rect rect;
SDL_Rect rects[26];
int frame;
float xvelocity,yvelocity;
}perssonage;

void initialiser_perssonage (perssonage *p)
{
p->personnage=IMG_Load("detective.png");
p->frame=0;
p->rect.x=0;
p->rect.h = 144;
p->rect.w = 72;
p->rect.y=350;
p->xvelocity=1;
p->yvelocity=1;
}

void afficher_perssonage (perssonage *p,SDL_Surface *screen)
{
	SDL_BlitSurface(p->personnage,&p->rects[p->frame],screen,&p->rect);
}
void mouvementright (perssonage *p)
{
if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=MAX_SPEED;
if (p->rect.x<350)
p->rect.x+=p->xvelocity;
}

void mouvementleft (perssonage *p)
{
if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=MAX_SPEED;
if (p->rect.x>150)
p->rect.x-=p->xvelocity;
}
void detectCollision(perssonage *p,ennemi *e){
if (p->rect.x + p->rect.y < e->rect.x) || (p->rect.x > e->rect.x + e->rect.w)
|| (p->rect.y + p->rect.h< e->rect.y) || (p->rect.y> e->rect.y + e->rect.h )
Collision = 0 //Pas de collision
else
Collision = 1 //Collision detectée
}
