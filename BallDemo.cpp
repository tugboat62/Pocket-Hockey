# include "iGraphics.h"
#include <ctime>
#include <math.h>
#include <cstdlib>
#define PI 3.1416

double ground_x=300, ground_y=300;
double goal_post1_x=500, goal_post1_y=300 , goal_post2_x=500, goal_post2_y=1175;
double ball_x=550,ball_y=750;
double player1_x=550,player1_y=525,player2_x=550,player2_y=975;
int back_index = 0;
int dx,dy;
int gameover1=0, gameover2=0;
int collision1, collision2;
int collision,crowd;
double inc1;
double inc2;
double d1, d2;

double angle=0;
//double l_x=x+15*cos(PI*angle),l_y=x+15*sin(PI*angle);

void iDraw()
{
    //place your drawing codes here

    iClear();
    if(back_index == 0)
    {
        iShowBMP(0,0,"pic\\game_background.bmp");
        iSetColor(255,0,0);
        iText(500,600,"PRESS P TO PLAY!",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,0,255);
        iText(498,600,"PRESS P TO PLAY!",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(back_index == 1)
    {
        iSetColor(253, 214, 166);
        iFilledRectangle(ground_x, ground_y, 500, 900);
        iSetColor(255, 0 , 0);
        iFilledRectangle(goal_post1_x, goal_post1_y, 100, 25);
        iFilledRectangle(goal_post2_x, goal_post2_y, 100, 25);
        iSetColor(255, 255, 0);
        iSetColor(0, 0, 255);
        iCircle(550, 750, 100, 1000);
        iRectangle(ground_x+100, ground_y+700, 300, 200);
        iRectangle(ground_x+100, ground_y, 300, 200);
        iLine(300, 750, 800, 750);
        iFilledCircle(player1_x, player1_y, 30);
        iSetColor(255,0,0);
        iText(player1_x,player1_y,"1");

        iSetColor(0, 0, 255);
        iFilledCircle(player2_x, player2_y, 30);
          iSetColor(255,0,0);
        iText(player2_x,player2_y,"2");

        iSetColor(0, 0, 0);
        iFilledCircle(ball_x, ball_y, 15);
        iSetColor(255,255,255);
        iFilledRectangle(900,600,200,50);
        iSetColor(0,0,0);
        iText(930,610,"EXIT GAME",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,255,255);
        iFilledRectangle(900,655,200,50);
        iSetColor(0,0,0);
        iText(920,665,"RESUME GAME",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,255,255);
        iFilledRectangle(900,710,200,50);
        iSetColor(0,0,0);
        iText(930,720,"PAUSE GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(gameover1 == 1){
        iSetColor(253, 214, 166);
        iFilledRectangle(ground_x, ground_y, 500, 900);
        iSetColor(255, 0 , 0);
        iFilledRectangle(goal_post1_x, goal_post1_y, 100, 25);
        iFilledRectangle(goal_post2_x, goal_post2_y, 100, 25);
        iSetColor(0, 0, 255);
        iCircle(550, 750, 100, 1000);
        iRectangle(ground_x+100, ground_y+700, 300, 200);
        iRectangle(ground_x+100, ground_y, 300, 200);
        iLine(300, 750, 800, 750);
        iSetColor(0, 0, 255);
        iFilledCircle(player1_x, player1_y, 30);
         iSetColor(255,0,0);
        iText(player1_x,player1_y,"1");

        iSetColor(0, 0, 255);
        iFilledCircle(player2_x, player2_y, 30);
         iSetColor(255,0,0);
        iText(player2_x,player2_y,"2");

        iSetColor(0, 0, 0);
        iFilledCircle(ball_x, ball_y, 15);
        iSetColor(255,0,0);
        iText(320,600,"    PRESS P TO PLAY AGAIN",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(320,900,"    GAME OVER!!  PLAYER2 WINS",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,0,255);
        iText(318,900,"    GAME OVER!!  PLAYER2 WINS",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(318,600,"    PRESS P TO PLAY AGAIN",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iFilledRectangle(900,600,200,50);
        iSetColor(0,0,0);
        iText(930,610,"EXIT GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(gameover2 == 1){
        iSetColor(253, 214, 166);
        iFilledRectangle(ground_x, ground_y, 500, 900);
        iSetColor(255, 0 , 0);
        iFilledRectangle(goal_post1_x, goal_post1_y, 100, 25);
        iFilledRectangle(goal_post2_x, goal_post2_y, 100, 25);
        iSetColor(0, 0, 255);
        iCircle(550, 750, 100, 1000);
        iRectangle(ground_x+100, ground_y+700, 300, 200);
        iRectangle(ground_x+100, ground_y, 300, 200);
        iLine(300, 750, 800, 750);
        iSetColor(0, 0, 255);
        iFilledCircle(player1_x, player1_y, 30);
         iSetColor(255,0,0);
        iText(player1_x,player1_y,"1");

        iSetColor(0, 0, 255);
        iFilledCircle(player2_x, player2_y, 30);
          iSetColor(255,0,0);
        iText(player2_x,player2_y,"2");

        iSetColor(0, 0, 0);
        iFilledCircle(ball_x, ball_y, 15);
        iSetColor(255,0,0);
        iText(320,600,"    PRESS P TO PLAY AGAIN",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(320,900,"    GAME OVER!!  PLAYER1 WINS",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,0,255);
        iText(318,600,"    PRESS P TO PLAY AGAIN",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(318,900,"    GAME OVER!!  PLAYER1 WINS",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iFilledRectangle(900,600,200,50);
        iSetColor(0,0,0);
        iText(930,610,"EXIT GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    }
}

void iKeyboard(unsigned char key)
{
    if(key == 'p')
    {
        if(back_index == 2){
            back_index--;
            iResumeTimer(0);
        }
        else back_index=+1;
        crowd = 0;
    }
    if(player2_y-15-10 >= ground_y+450 && sqrt((player2_x - ball_x)*(player2_x - ball_x)+(player2_y-10-ball_y)*(player2_y-10-ball_y)) >= 45)
        if(key == 's')
        {
            player2_y -= 10;
        }
    if(player2_y+15+10 <= ground_y+900 && sqrt((player2_x - ball_x)*(player2_x - ball_x)+(player2_y+10-ball_y)*(player2_y+10-ball_y)) >= 45)
        if(key == 'w')
        {
            player2_y += 10;
        }
    if(player2_x+15+10 <= ground_x+500 && sqrt((player2_x+10 - ball_x)*(player2_x+10 - ball_x)+(player2_y-ball_y)*(player2_y-ball_y)) >= 45)
        if(key == 'd')
        {
            player2_x += 10;
        }
    if(player2_x-15-10 >= ground_x && sqrt((player2_x-10 - ball_x)*(player2_x-10 - ball_x)+(player2_y-ball_y)*(player2_y-ball_y)) >= 45)
        if(key == 'a')
        {
            player2_x -= 10;
        }

    //place your codes for other keys here
}
void iMouseMove(int mx, int my){

    //place your codes here
}

void iMouse(int button, int state, int mx, int my)
{

        //place your codes here
        if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        {
            if(mx>=900&&mx<=1100){
            if(my>=770&&my<=810)
            {
                exit(0);
            }
            else if(my>810&&my<=850)
            {
                iResumeTimer(0);
            }
            else if(my>850&&my<=890)
            {
                iPauseTimer(0);
            }
        }
        }
}



/*
    function iSpecialKeyboard() is called whenver user hits special keys like-
    function keys, home, end, pg up, pg down, arraows etc. you have to use
    appropriate constants to detect them. A list is:
    GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
    GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
    GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
    GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(player1_x+15+10 <= ground_x+500 && sqrt((player1_x+10 - ball_x)*(player1_x+10 - ball_x)+(player1_y-ball_y)*(player1_y-ball_y)) >= 45)
    if(key==GLUT_KEY_RIGHT)
    {
        player1_x += 10;
    }
    if(player1_x-15-10 >= ground_x && sqrt((player1_x-10 - ball_x)*(player1_x-10 - ball_x)+(player1_y-ball_y)*(player1_y-ball_y)) >= 45)
    if(key==GLUT_KEY_LEFT)
    {
        player1_x -= 10;
    }
    if(player1_y+15+10 <= ground_y+450 && sqrt((player1_x - ball_x)*(player1_x - ball_x)+(player1_y+10-ball_y)*(player1_y+10-ball_y)) >= 45)
    if(key==GLUT_KEY_UP)
    {
        player1_y += 10;
    }
    if(player1_y-15-10 >= ground_y && sqrt((player1_x - ball_x)*(player1_x - ball_x)+(player1_y-10-ball_y)*(player1_y-10-ball_y)) >= 45)
    if(key==GLUT_KEY_DOWN)
    {
        player1_y -= 10;
    }
    //place your codes for other keys here
}

void change(){
    ball_x += dx*cos(PI*(angle));
    ball_y += dy*sin(PI*angle);
    inc1 = atan((player1_y-ball_y)/(player1_x-ball_x));
    inc2 = atan((player2_y-ball_y)/(player2_x-ball_x));

    if(ball_x > ground_x+500-15 || ball_x < ground_x+15)
    {
        dx = -1*dx;
    }
    if(ball_x > ground_x+500-14)
    {
        ball_x = ground_x+500-15;
    }
    if(ball_x < ground_x+14)
    {
        ball_x = ground_x+15;
    }
    if(ball_y > ground_y+900-15 || ball_y < ground_y+15)
    {
        dy = -1*dy;
    }
    if(ball_y > ground_y+900-14 )
    {
        ball_y = ground_y+900-15;
    }
    if(ball_y < ground_y+14)
    {
        ball_y = ground_y+15;
    }
    if(abs(sqrt((player1_x-ball_x)*(player1_x-ball_x)+(player1_y-ball_y)*(player1_y-ball_y))) > 45 ) collision1 = 0;
    if(abs(sqrt((player1_x-ball_x)*(player1_x-ball_x)+(player1_y-ball_y)*(player1_y-ball_y))) <= 45 ){
        if(collision1 == 1) collision1 = collision1*(-1);
        else if(collision1 == 0) collision1 = 1;
    }
    if(collision1 == 1)
    {
        d1 = sqrt((ball_x-player1_x)*(ball_x-player1_x)+(ball_y-player1_y)*(ball_y-player1_y));
        angle = angle + 1;
        PlaySound("collision.wav",NULL,SND_ASYNC);
        if(dx < 0 && dy < 0) {if(ball_y >= player1_y+d1*sin(PI/2)){dy*=-1;angle = angle+2*sqrt(atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;}
                            else {dx*=-1;angle = angle-2*sqrt(atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;}
                            }
        else if(dx < 0 && ball_y==player1_y) {dx = dx * -1;}
        else if(dy < 0 && ball_x==player1_x) {dy = dy * -1;}
        else if(dx > 0 && dy > 0) {if(ball_y >= player1_y-d1*sin(PI/2)){dx*=-1;angle = angle-2*sqrt(atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;}
                            else {dy*=-1;angle = angle+2*sqrt(atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;}
                            }
        else if(dx > 0 && ball_y==player1_y) {dx = dx * -1;}
        else if(dy > 0 && ball_x==player1_x) {dy = dy * -1;}
        else if(dx > 0 && dy < 0) {if(ball_y >= player1_y+d1*sin(PI/2)){dy*=-1;angle = angle-2*sqrt(atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;}
                            else {dx*=-1;angle = angle+2*sqrt(atan((tan(angle)+(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;}
                            }
        else if(dx < 0 && dy > 0) {if(ball_y >= player1_y-d1*sin(PI/2)){dx*=-1;angle = angle+2*sqrt(atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;}
                            else {dy*=-1;angle = angle-2*sqrt(atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;}
                            }

        //inc1 = inc1 + PI;
        //if(angle >= 3/2 && angle < 2){
            /*if(ball_y < player1_y)*///if(inc1/PI > angle) angle = angle+2*sqrt(atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;
            /*else if(ball_y >= player1_y)*///else angle = angle-2*sqrt(atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*atan((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;
        /*}
        if(angle >= 0 && angle <= 1/2){
            if(ball_x <= player1_x) angle = angle-1-2*sqrt(tanh((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*tanh((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;
            else if(ball_x > player1_x) angle = angle-1+2*sqrt(tanh((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*tanh((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;
        }
        if(angle > 1/2 && angle <= 1){
            if(ball_y >= player1_y) angle = angle-1+2*sqrt(tanh((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*tanh((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;
            else if(ball_y < player1_y) angle = angle-1-2*sqrt(tanh((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*tanh((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;
        }
        if(angle > 1 && angle < 3/2){
            if(ball_x >= player1_x) angle = angle-1-2*sqrt(tanh((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*tanh((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;
            else if(ball_x < player1_x) angle = angle-1+2*sqrt(tanh((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x)))*tanh((tan(angle)-(player1_y-ball_y)/(player1_x-ball_x))/(1+tan(angle)*(player1_y-ball_y)/(player1_x-ball_x))))/PI;
        }*/
    }
    if(abs(sqrt((player2_x-ball_x)*(player2_x-ball_x)+(player2_y-ball_y)*(player2_y-ball_y))) > 50 ) collision2 = 0;
    if(abs(sqrt((player2_x-ball_x)*(player2_x-ball_x)+(player2_y-ball_y)*(player2_y-ball_y))) <= 50 ){
        if(collision2 == 1) collision2 = collision2*(-1);
        else if(collision2 == 0) collision2 = 1;
    }
    if(collision2 == 1)
    {
        d2=sqrt((ball_x-player2_x)*(ball_x-player2_x)+(ball_y-player2_y)*(ball_y-player2_y));
        angle = angle + 1;
        PlaySound("collision.wav",NULL,SND_ASYNC);
        if(dx < 0 && dy < 0) {if(ball_y >= player2_y+d2*sin(PI/2)) {dy*=-1;angle = angle+2*sqrt(atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;}
                                else {dx*=-1;angle = angle-2*sqrt(atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;}
                                }
        else if(dx < 0 &&  ball_y==player2_y) {dx = dx * -1;}
        else if(dy < 0 && ball_x==player2_x) {dy = dy * -1;}
        else if(dx > 0 && dy > 0) {if(ball_y >= player2_y-d2*sin(PI/2)) {dx*=-1;angle = angle-2*sqrt(atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;}
                                else {dy*=-1;angle = angle+2*sqrt(atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;}
                                }
        else if(dx > 0 && ball_y==player2_y) {dx = dx * -1;}
        else if(dy > 0 && ball_x==player2_x) {dy = dy * -1;}
        else if(dx > 0 && dy < 0) {if(ball_y >= player2_y+d2*sin(PI/2)){dy*=-1; angle = angle-2*sqrt(atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;}
                                else {dx*=-1;angle = angle+2*sqrt(atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;}
                                }
        else if(dx < 0 && dy > 0) {if(ball_y >= player2_y-d2*sin(PI/2)) {dx*=-1;angle = angle+2*sqrt(atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;}
                                else {dy*=-1;angle = angle-2*sqrt(atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;}
                                }

        //inc2 = inc2 + PI;
        //if(angle >= 3/2 && angle < 2){
            /*if(ball_y < player2_y)*///if(inc2/PI > angle) angle = angle+2*sqrt(atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;
            /*else if(ball_y >= player2_y)*///else angle = angle-2*sqrt(atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*atan((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;
        /*}
        if(angle >= 0 && angle <= 1/2){
            if(ball_x <= player2_x) angle = angle-1-2*sqrt(tanh((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*tanh((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;
            else if(ball_x > player2_x) angle = angle-1+2*sqrt(tanh((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*tanh((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;
        }
        if(angle > 1/2 && angle <= 1){
            if(ball_y >= player2_y) angle = angle-1+2*sqrt(tanh((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*tanh((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;
            else if(ball_y < player2_y) angle = angle-1-2*sqrt(tanh((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*tanh((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;
        }
        if(angle > 1 && angle < 3/2){
            if(ball_x >= player2_x) angle = angle-1-2*sqrt(tanh((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*tanh((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;
            else if(ball_x < player2_x) angle = angle-1+2*sqrt(tanh((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x)))*tanh((tan(angle)-(player2_y-ball_y)/(player2_x-ball_x))/(1+tan(angle)*(player2_y-ball_y)/(player2_x-ball_x))))/PI;
        }*/
    }
    if(ball_x >= goal_post1_x-15 && ball_x-15 <= goal_post1_x+100 && ball_y <= 340 && dy < 0){
        PlaySound("cheers.wav",NULL,SND_ASYNC);
        iPauseTimer(0);
        if(gameover1 == 1) gameover1--;
        gameover1++;
        if(gameover2 == 1) gameover2--;
        back_index++;
        ground_x=300, ground_y=300;
        goal_post1_x=500, goal_post1_y=300 , goal_post2_x=500, goal_post2_y=1175;
        ball_x=550,ball_y=750;
        player1_x=550,player1_y=525,player2_x=550,player2_y=975;
        angle=1.6;
        crowd = 1;
    }
    if(ball_x >= goal_post2_x-15 && ball_x-15 <= goal_post2_x+100 && ball_y>= 1160 && dy > 0){
        PlaySound("cheers.wav",NULL,SND_ASYNC);
        iPauseTimer(0);
        if(gameover2 == 1) gameover2--;
        gameover2++;
        if(gameover1 == 1) gameover1--;
        back_index++;
        ground_x=300, ground_y=300;
        goal_post1_x=500, goal_post1_y=300 , goal_post2_x=500, goal_post2_y=1175;
        ball_x=550,ball_y=750;
        player1_x=550,player1_y=525,player2_x=550,player2_y=975;
        angle=1.6;
        crowd = 1;
    }

}

int main()
{
//    PlaySound((LPCSTR) "C:\\Users\\Public\\Music\\Sample Music\\Sleep Away.mp3", NULL, SND_FILENAME | SND_ASYNC);
//    DWORD dwError = GetLastError();

    //place your own initialization codes here.

    iSetTimer(5, change);
    dx = 7;
    dy = 9;
    /*if(collision == 1)
    PlaySound("collision.wav",NULL,SND_ASYNC);*/
   /* if(crowd == 1) PlaySound("crowd.wav",NULL,SND_LOOP | SND_ASYNC);
    else if(crowd == 0) PlaySound(0, 0, 0);*/
    iInitialize(1100, 1200, "Pocket Hockey!!");

    return 0;
}
