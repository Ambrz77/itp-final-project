#include <iostream>
#include "hash.h"
#include <time.h>
#include <stdio.h>
#include <deque>
#include <SDL2/SDL.h>
#include <vector>
using namespace std;
SDL_Surface* screen;
SDL_Surface* back_ground;
int a=0;
int y=500;
int v=-10;
int w=100;
int M=1;
int e = 500;
void ClearScreen()
{
    SDL_FillRect(screen,NULL,BLUE);
}
// enum GameScreen
// {
// 	MainMenu;
// 	Playing;
// 	YouWin;
// 	GameOver;
// };
// enum ObjectMouseStatus
// {
// 	Nothing;
// 	OnIt;
// 	Clicked;
// };
struct Position{
	int x;
	int y;
}p;
deque<Position> platform;
int generate()
{
    int maxY = platform.size() == 0? 800: platform[platform.size()-1].y;
    p.x = rand() % 900;
    p.y = maxY - rand() % 100;
    platform.push_back(p);
}
void show(){
    SDL_Surface* n_platform = ImgLoader("images/normal platform.png", 255, 255, 255);
    for (int i=0; i< platform.size(); i++){
        SDL_BlitSurface(n_platform, screen, platform[i].x, platform[i].y);
        cout<<platform[i].x<<endl;
    }
}
void jump()
{
    // int vy=0;
    // int y=0;
    // SDL_Surface* doodler = ImgLoader("images/likright_X.png", 255, 255, 255);
    // SDL_BlitSurface(doodler, screen, Mouse.x, y);
    for (size_t i =0; i <platform.size(); i++){
        SDL_Rect r1 ={platform[i].x,platform[i].y, 110,30};
        SDL_Rect r2= {Mouse.x, y, 60, 90};
        y +=v;
        a -=v;
        if(a>=100)
            v=-v;
        if(SDL_HasIntersection(&r1, &r2) == SDL_TRUE && v>0){
            v=-v;
            a=0;
            cout << i << endl;
        }
    }
}
void kb(){
    if(event.key.keysym.sym == SDLK_LEFT)
    w-=10;
    if (event.key.keysym.sym == SDLK_RIGHT)
    w+=10;
}
bool GP =true;
int main()
{
    srand(time(0));
    int menu =1;
    int choice;
    int v= -15;

    //  struct player{
    //      int Px;
    //      int Py;
    //      int Vx=20;
    //      int Vy;
    //  }p;
    // p.Px=100;
    // p.Py=100;
    int screen_height = 700;
    int screen_width = 600;
    InitEngine(screen,"Doodle",screen_width,screen_height);
    SDL_Surface* back_ground=ImgLoader("images/bck_X.png", 0, 0, 255);
    SDL_Surface* doodler = ImgLoader("images/likright_X.png", 0, 0, 255);
    SDL_Surface* n_platform = ImgLoader("images/normal platform.png", 0, 0, 255);
    SDL_Surface* play = ImgLoader("images/play_X.png", 0, 0, 255);
    SDL_Surface* play_again = ImgLoader("images/playagain_X.png", 0, 0, 255);
    SDL_Surface* cafineh = ImgLoader("images/ufo f1.png", 0, 0, 255);
    SDL_Surface* menu_2 = ImgLoader("images/menu_X.png", 0, 0, 255);
    SDL_Surface* ON_G = ImgLoader("images/on_g.png", 0, 0, 255);
    SDL_Surface* OFF_G = ImgLoader("images/off_g.png", 0, 0, 255);
    SDL_Surface* ON_R = ImgLoader("images/on_r.png", 0, 0, 255);
    SDL_Surface* OFF_R = ImgLoader("images/off_r.png", 0, 0, 255);
    SDL_Surface* Exit = ImgLoader("images/Exit.png", 0, 0 ,255);
    SDL_Surface* Music_V = ImgLoader("images/Music.png", 0, 0 ,255);
    SDL_Surface* doodle_scren = ImgLoader("images/likright_X.png", 0, 0 ,255);
    SDL_Surface* setting = ImgLoader("images/options_X.png", 0, 0 ,255);
    Sound* bgMusic = LoadSound("sounds/bgmusic.ogg");
    // Music* bgMusic = LoadSound("sounds/bgmusic.ogg");
    PlaySound(bgMusic, 3);
    while(!ExitRequested){
        Update();
        ClearScreen();
        SDL_BlitSurface(back_ground, screen, 0 ,0);

       switch (menu){
            case 1:
            SDL_BlitSurface(back_ground, screen, 0 ,0);
            SDL_BlitSurface(n_platform, screen, 100 ,600);
            SDL_BlitSurface(play, screen, 300, 400);
            SDL_BlitSurface(doodler, screen, 100,60);
            SDL_BlitSurface(setting, screen, 300, 500);
            SDL_BlitSurface(cafineh, screen, 450, 100);
            // SDL_BlitSurface(doodle_scren, screen, 10, 60);
            SDL_BlitSurface(Exit, screen, 600,600 );
            // e+=v;
            // if(e==440)
            // v= -v;
            // if(w>=100 && w<=324 && e>=600 && e<=630)
            // v=-v;
            if (MouseX>= 300 && MouseX<=480 && MouseY >=700 &&MouseY<=800 && MouseLB!=0)
            atexit(SDL_Quit);
            if (MouseX>= 300 && MouseX<=524 && MouseY >=400 &&MouseY<=488 && MouseLB!=0)
            menu =2;
            if (MouseX>= 500 && MouseX<=614 && MouseY >=700 &&MouseY<=788 && MouseLB!=0)
            menu =3;
            break;
            case 2: SDL_BlitSurface(back_ground , screen, 0, 0);
            kb();
            SDL_BlitSurface(doodler, screen, w, y);
            if (GP)
            {
                for (size_t i=0 ; i<10 ; i++){
                    generate();
                }
                GP=false;
            }
           show();
           jump();
           if (y>=990)
           menu=4;
           if (w>=600)
           w=-50;
           break;
           case 3: SDL_BlitSurface(back_ground, screen, 0, 0);
           SDL_BlitSurface(menu_2, screen, 200, 550);
           SDL_BlitSurface(Music_V, screen, 170, 300);
           SDL_BlitSurface(ON_G, screen, 270, 300);
           SDL_BlitSurface(OFF_G, screen, 380, 300);
            if (MouseX>= 200 && MouseX<=424 && MouseY >=550 &&MouseY<=630 && MouseLB!=0)
            menu =1;
            if (MouseX>= 270 && MouseX<=380 && MouseY >=300 &&MouseY<=400 && MouseLB!=0)
            SDL_BlitSurface(ON_R, screen, 270, 300);
            if (MouseX>= 500 && MouseX<=614 && MouseY >=700 &&MouseY<=788 && MouseLB!=0)
            SDL_BlitSurface(OFF_R, screen, 380, 300);
            if (MouseX>= 380 && MouseX<=490 && MouseY >=300 &&MouseY<=400)
            SDL_BlitSurface(OFF_R, screen, 380, 300);
            if (MouseX>= 380 && MouseX<=490 && MouseY >=300 &&MouseY<=400 && MouseLB!=0)
            M=1;
            if (MouseX>= 270 && MouseX<=380 && MouseY >=300 &&MouseY<=400 && MouseLB!=0)
            M=0;
            break;
            case 4: SDL_BlitSurface(back_ground, screen, 0, 0);
            SDL_BlitSurface(play_again, screen, 200, 300);
            if (MouseX>= 200 && MouseX<=424 && MouseY >=300 &&MouseY<=388 && MouseLB!=0)
            menu = 2;
            SDL_BlitSurface(menu_2, screen, 200, 500);
            if (MouseX>= 200 && MouseX<=424 && MouseY >=500 &&MouseY<=588 && MouseLB!=0)
            menu =1;
            y= 500;
            w=200;
            break;
        // case GameScreen.MainMenu:
        // case GameScreen.Playing:
        // case GameScreen.YouWin:
        // case GameScreen.GameOver:
        // p.Py+=p.Vy+6;
        // if (p.Py==200)
        // p.Vy = -p.Vy; 
        //}
       }
        SDL_UpdateScreen();
        SDL_Delay(10);
    
    }
return 0;
}