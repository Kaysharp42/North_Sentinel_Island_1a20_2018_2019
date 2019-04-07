#include "personnage.h"


void annimation_right (personnage *p)
{
p->stable=0;
if (p->frame <= 0 || p-> frame >= 12)
 p->frame=0;
p->frame++;
if (p->frame>=nbr_fr)
p->frame=0;
}



void annimation_left (personnage *p)
{
p->stable=1;
if (p->frame <= 11 || p-> frame >= 24)
 p->frame=12;
p->frame++;
if (p->frame>=2*nbr_fr)
p->frame=13;
}
