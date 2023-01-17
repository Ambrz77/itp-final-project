//============================================================================
// Name        : BirdKiller.cpp
// Author      : SBU ITP TAs Group
// Version     : 1.0
// Copyright   : Free 
// Description : A sample game using C/C++ and SDL graphical library
//============================================================================

#include <iostream>
#include "hash.h"
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL2_rotozoom.h>
using namespace std;

int screen_height = 640;
int screen_width = 400;
void ClearScreen();
void LoadImages();
void DoPhysics();
/**************** Global Variable Defintion *****************/
//	Main surface
SDL_Surface* screen;
SDL_Surface* back_ground;
SDL_Surface* nose ,*lik;
SDL_Surface* rotated;
int main() 
{


	/***************** Loading Section **********************/
	InitEngine(screen,"Doodle",screen_width,screen_height);
	LoadImages();
	/**************** Initializing Section *****************/
	int cx = screen_width /2;
	int cy = screen_height /2 ; 
	while(!ExitRequested)
	{
		Update();
		SDL_BlitSurface(back_ground,screen,0,0);
		float rad = atan2(cx -Mouse.x , cy -Mouse.y);
		float deg = 180 * rad / M_PI;
		rotated = rotozoomSurface(nose,deg,1,1);
		SDL_BlitSurface(lik,screen,cx-(lik->w)/2,cy-(lik->h)/2-10);
		SDL_BlitSurface(rotated,screen,cx-(rotated->w)/2,cy-(rotated->h)/2);
		SDL_UpdateScreen();
		SDL_Delay(30);
	}
	return 0;
}
void LoadImages()
{
	back_ground = ImgLoader("assets/images/bck_M.png",0,0,255);
	nose= ImgLoader("assets/images/liknjuska_X.png",255,255,255); 
	lik =ImgLoader("assets/images/likpucaodskok_X.png",255,255,255);
}
