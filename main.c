#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define LARGEUR 1300
#define HAUTEUR 705

SDL_Surface* screen=NULL;
SDL_Rect screenrect={0,0,0,0};
SDL_Surface* backg=NULL;
SDL_Rect backgrect={0,0,0,0};
SDL_Surface* play=NULL;
SDL_Rect playrect={74,400,230,58};
SDL_Surface* setting=NULL;
SDL_Rect settingrect={74,480,230,58};
SDL_Surface* leave=NULL;
SDL_Rect leaverect={74,560,230,58};
SDL_Surface* Hplay=NULL;
SDL_Surface* Hset=NULL;
SDL_Surface* Hleave=NULL;
SDL_Surface* tmp=NULL;
SDL_Event event={0};
int main()
{
int run=0;
int menu=1;
int now=0;
int ex=0;
int pfps=5;
int dt=0;
int etat=4;
int settingg;
float pfpss=0;
SDL_Init(SDL_INIT_VIDEO);
const SDL_VideoInfo *pinfo=SDL_GetVideoInfo();
int bpp=pinfo->vfmt->BitsPerPixel;
//images
backg=IMG_Load("ress/def.bmp");
SDL_GetClipRect(backg,&backgrect);
play=IMG_Load("ress/aa.png");
setting=IMG_Load("ress/set.png");
leave=IMG_Load("ress/leave.png");
Hplay=IMG_Load("ress/aasel.png");
SDL_SetColorKey( Hplay , SDL_SRCCOLORKEY, SDL_MapRGB( Hplay->format, 0, 0, 0) );

Hset=IMG_Load("ress/setsel.png");
Hleave=IMG_Load("ress/leavesel.png");
screen=SDL_SetVideoMode(LARGEUR,HAUTEUR,bpp,SDL_HWSURFACE);
SDL_WM_SetCaption("Menu",NULL);
while(menu)
{


now=SDL_GetTicks();
dt=now-ex;
if(dt>=pfps)
{
//update
SDL_BlitSurface(backg,NULL,screen,&backgrect);
SDL_BlitSurface(play,NULL,screen,&playrect);
SDL_BlitSurface(setting,NULL,screen,&settingrect);
SDL_BlitSurface(leave,NULL,screen,&leaverect);
if(etat==3)
SDL_BlitSurface(Hplay,NULL,screen,&playrect);
if(etat==2)
SDL_BlitSurface(Hset,NULL,screen,&settingrect);
if(etat==1)
SDL_BlitSurface(Hleave,NULL,screen,&leaverect);
if(etat==0)
etat=4;
if(etat==5)
etat=1;
SDL_PollEvent(&event);
switch(event.type)
{case SDL_QUIT:
{
    menu=0;
  }
break;
case SDL_KEYDOWN:
 if(event.key.keysym.sym==SDLK_DOWN)

  {
etat--;
SDL_Delay(100);
  }
 if(event.key.keysym.sym==SDLK_UP)

  {
etat++;
SDL_Delay(100);
  }

 if(event.key.keysym.sym==SDLK_RETURN)

  {	if(etat==1){menu=0;}
if(etat==2){settingg=1;menu=0;}
if(etat==3){run=1,menu=0;}


}
break;
case SDL_MOUSEMOTION:
if(94<event.motion.x&&event.motion.x<284)
{if(448<event.motion.y&&event.motion.y<506)
{
//update
SDL_BlitSurface(Hplay,NULL,screen,&playrect);
etat=3;
}
else if(518<event.motion.y&&event.motion.y<574)
{
//update
SDL_BlitSurface(Hset,NULL,screen,&settingrect);
etat=2;
}
else if(596<event.motion.y&&event.motion.y<652)
{
//update
SDL_BlitSurface(Hleave,NULL,screen,&leaverect);
etat=1;
}


}

break;
case SDL_MOUSEBUTTONDOWN:
if( event.button.button == SDL_BUTTON_LEFT )
		{if(94<event.button.x&&event.button.x<284)
{if(596<event.button.y&&event.button.y<652)
{
menu=0;
}else if(448<event.button.y&&event.button.y<506)
{
menu=0;
run=1;}else if(518<event.button.y&&event.button.y<574)
{
menu=0;
settingg=1;}
}
}
break;
}




SDL_Flip(screen);
ex=now;
}else
 SDL_Delay(pfps-dt);
}
SDL_FreeSurface(play);
SDL_FreeSurface(setting);
SDL_FreeSurface(leave);
SDL_FreeSurface(Hplay);
SDL_FreeSurface(Hset);
SDL_FreeSurface(Hleave);
SDL_Quit();
return 0;
}

