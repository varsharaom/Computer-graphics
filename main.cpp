
#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

#include<time.h>
int windoswitch=0,no_of_windows=0,arr=0,ao=0,mov1;
int down=1,u=0,i;
int in,ih,openb,lp1,icc1,hand,ch1,fch1;//icecream
int h1,l1,fh1,fl1,mov;
void *font2=GLUT_BITMAP_9_BY_15;
void *font3=GLUT_BITMAP_HELVETICA_18;
void *font1=GLUT_BITMAP_TIMES_ROMAN_24;
int l,h,fl,fh,j;//used in disp customer bag
int dlayf=0;
int mov_hand=0;//
int fm=1;//for movements in bagman
int drink=0;
void mouse(int btn,int state,int x,int y);
void mouse_screen2(int btn,int state,int x,int y);
void mouse_screen3(int btn,int state,int x,int y);
void mouse4(int btn,int state,int x,int y);
int fill=0;//to fill the glass
void delay(unsigned int mseconds)//function for delay
{
    clock_t goal = mseconds + clock();
    while (goal > clock());

}


void  drawCircle1(int a1,int a2,int x1,int y1,int r1,int r2)
{float a;
    glBegin(GL_POLYGON);
    for( a=a1;a<=a2;a=a+1)
{
float angle_radians=a*(22/7)/(float)180;
float x=x1+r1*(float)cos(angle_radians);
float y=y1+r2*(float)sin(angle_radians);
        glVertex2f(x,y);
}
glEnd();
}
void disp11(int x, int y, char *string,int a)
{
  int len, i;
  glRasterPos2f(x, y);
  len=(int)strlen(string);
  switch(a)
{
    case 1:for (i=0;i<len;i++)
      glutBitmapCharacter(font1 , string[i]);
      break;
      case 2:for (i=0;i<len;i++)
      glutBitmapCharacter(font2 , string[i]);
      break;
      case 3:for (i=0;i<len;i++)
      glutBitmapCharacter(font3 , string[i]);
      break;
   }
}
void four_vertex(int x1,int y1,int x2,int y2 ,int x3,int y3,int x4,int y4 )
{
    glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
glEnd();

}
void three_vertex(int x1,int y1,int x2,int y2,int x3,int y3)
{
    glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glEnd();
}
void six_vertex(int x1,int y1,int x2,int y2 ,int x3,int y3,int x4,int
y4,int x5,int y5,int x6,int y6 )
{
    glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
        glVertex2f(x5,y5);
    glVertex2f(x6,y6);

glEnd();

}
void two_vertex(int x1,int y1,int x2,int y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();

}
void handle(int x1, int y1,int x2,int y2,int x3 ,int y3)
{
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
    glBegin(GL_LINES);
     glVertex2f(x3,y3);
    glVertex2f(x2,y2);
    glEnd();
}
void drawborder(int x1,int y1,int x2,int y2,int x3 ,int y3,int x4,int y4)
{
   glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
    glBegin(GL_LINES);
     glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
    glBegin(GL_LINES);
     glVertex2f(x4,y4);
    glVertex2f(x1,y1);
    glEnd();
}
void drawTree(int x,int y)
{
 glColor3f(0.0,0.8,0.0);
           glBegin(GL_POLYGON);
          glVertex2i(x+5,y+25);
          glVertex2i(x+8,y+10);

glVertex2i(x+2,y+10);
                    glEnd();
                    four_vertex(x,y,x+10,y,x+7,y+10,x+3,y+10);
}
void icecreammanhand(int k,int l)
{
     glColor3f(0.0,0.4,0.6);

    //six_vertex(105,115,104,106,108,98,108,104,106,106,108,115);//left hand
    //left hand
    //four_vertex(105,115,108,115,107,106,104,106);
    four_vertex(105+k,115+l,108+k,115+l,105+k,105+l,101+k,105+l);//left hand top part
    four_vertex(101+k,105+l,105+k,105+l,103+k,98+l,99+k,98+l);//left hand bottom part
    //four_vertex(98,105,102,105,103,99,100,99);
    //four_vertex(104,106,107,106,110-i,96,108-i,96);
    //right hand
    four_vertex(116+k,115+l,119+k,115+l,120+k,106+l,117+k,106+l);
    four_vertex(117+k,106+l,120+k,106+l,116+k,96+l,114+k,96+l);
}
 void drawcustomerice(int i,int j)
{

if(l==0)
fl=0;
if(h==0)
fh=0;
if(h<10&&fh==0)
 {glColor3f(0.0,0.0,0.0);
    four_vertex(10+i+h,30,17+i+h,30,14+i+h,35,11+i+h,35);//left shoe
    four_vertex(21+i-h,34,24+i-h,34,27+i-h,29,20+i-h,29);//right shoe
    glColor3f(0.0,0.0,0.2);
    four_vertex(11+i+h,35,14+i+h,35,19+i,72,13+i,72);//left leg
    glColor3f(0.0,0.0,0.4);
    four_vertex(14+i,72,22+i,72,24+i-h,34,21+i-h,34);//right leg
    if(fm==1)
    h++;
 }
 if(h==10)
 fh=1;
 if(fh==1)
 {glColor3f(0.0,0.0,0.0);
    four_vertex(10+i+h,30,17+i+h,30,14+i+h,35,11+i+h,35);//left shoe
    four_vertex(21+i-h,34,24+i-h,34,27+i-h,29,20+i-h,29);//right shoe
    glColor3f(0.0,0.0,0.2);
    four_vertex(11+i+h,35,14+i+h,35,19+i,72,13+i,72);//left leg
    glColor3f(0.0,0.0,0.4);
    four_vertex(14+i,72,22+i,72,24+i-h,34,21+i-h,34);//right leg
    if(fm==1)
    h--;
 }
    if(l<15&&fl==0)
    {glColor3f(1.0,0.4,0.0);
            four_vertex(20+i,96,21+i,86,24+i-l,78,27+i-l,78);//right hAND-hand at back side
    glColor3f(1.0,0.8,0.6);
    six_vertex(24+i-l,78,27+i-l,78,27+i-l,77,26+i-l,75,25+i-l,75,24+i-l,77);//right -bak side palm

    }
        if(fl==1)
    {glColor3f(1.0,0.4,0.0);
            four_vertex(20+i,96,21+i,86,24+i-l+j/2,78+j,27+i-l+j/2,78+j);//right hAND-hand at back side
    glColor3f(1.0,0.8,0.6);
    six_vertex(24+i-l,78,27+i-l,78+j,27+i-l,77+j,26+i-l,75,25+i-l,75,24+i-l,77);//right -bak side palm

    }

        glColor3f(1.0,0.6,0.2);

    four_vertex(12+i,72,23+i,72,20+i,96,14+i,96);//body
    glColor3f(1.0,0.8,0.6);
    drawCircle1(0,360,17+i,107,4,9);//face
    //four_vertex(17,96,19,96,19,99,17,99);//neck
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    handle(15+i,109,16+i,110,18+i,109);//left eye brow
    handle(19+i,110,20+i,111,21+i,111);//right eye brow
    handle(19+i,108,20+i,106,19+i,105);//nose
    handle(14+i,108,14+i,106,15+i,106);
    three_vertex(20+i,103,19+i,101,17+i,102);//mouth
    glLineWidth(4.0);
    two_vertex(17+i,107,17+i,108);//left eye
    two_vertex(20+i,109,20+i,108);//right eye
    //two_vertex(20,114,12,114);//hair
    drawCircle1(0,180,18+i,113,3,5);//hair
    drawCircle1(0,185,16+i,113,3,5);//hair
    three_vertex(12+i,114,17+i,114,13+i,107);//hair
    six_vertex(14+i,96,20+i,96,19+i,98,19+i,99,16+i,99,16+i,98);//neck+upper body
    if(l<15&&fl==0&&j==0&&hand==0)
    {    glColor3f(1.0,0.4,0.0);

        four_vertex(14+i,96,16+i,90,12+i+l,77,9+i+l,77);//left hand

    glColor3f(1.0,0.8,0.6);
     six_vertex(9+i+l,77,12+i+l,77,12+i+l,76,11+i+l,74,10+i+l,74,9+i+l,76);//left palm
     if(fm==1)
     l++;
    }
    if(l==15)
    fl=1;
    printf("%d",l);
    if(fl==1&&j==0&&hand==0)
    {
         glColor3f(1.0,0.4,0.0);

        four_vertex(14+i,96,16+i,90,12+i+l-j,77,9+i+l-j,77);//left hand

    glColor3f(1.0,0.8,0.6);
     six_vertex(9+i+l-j,77,12+i+l-j,77,12+i+l-j,76,11+i+l-j,74,10+i+l-j,74,9+i+l-j,76);//left palm
     if(fm==1)
     l--;

    }
    //to make hand go up
if(j>0&&j<20&&mov_hand==0&&hand==0)
{
            glColor3f(1.0,0.4,0.0);

        four_vertex(14+i,96,16+i,90,12+i+l+j*0.8,77+j,9+i+l+j*0.8,77+j);//left hand

    glColor3f(1.0,0.8,0.6);
     six_vertex(9+i+l+j*0.8,77+j,12+i+l+j*0.8,77+j,12+i+l+j*0.8,76+j,11+i+l+j*0.8,74+j,10+i+l+j*0.8,74+j,9+i+l+j*0.8,76+j);//left palm

}
//to make hand movements
if(j>20&&mov_hand==0&&hand==0)
{
      glColor3f(1.0,0.4,0.0);

        four_vertex(14+i,96,16+i,90,12+i+l+0.8*20,77+j,9+i+l+0.8*20,77+j);//left hand

    glColor3f(1.0,0.8,0.6);
     six_vertex(9+i+l+0.8*20,77+j,12+i+l+0.8*20,77+j,12+i+l+0.8*20,76+j,11+i+l+0.8*20,74+j,10+i+l+0.8*20,74+j,9+i+l+0.8*20,76+j);//left palm}
}
if(mov_hand==1)
{
glColor3f(1.0,0.4,0.0);

        four_vertex(14+i,96,16+i,90,12+i+l+0.8*12-2*j,77+12,9+i+l+0.8*12-2*j,77+12);//left hand

    glColor3f(1.0,0.8,0.6);
     six_vertex(9+i+l+0.8*12-2*j,77+12,12+i+l+0.8*12-2*j,77+12,12+i+l+0.8*12-2*j,76+12,11+i+l+0.8*12-2*j,74+12,10+i+l+0.8*12-2*j,74+12,9+i+l+0.8*12-2*j,76+12);//left palm

}
}

void drawmanice(int i,int j)
{
    glColor3f(1.0,1.0,0.8);
    four_vertex(107+i,120+j,117+i,120+j,117+i,133+j,107+i,133+j);//face
   // glColor3f(1.0,1.0,0.8);
   //glColor3f(1.0,0.0,1.0);

    three_vertex(107+i,120+j,117+i,120+j,112+i,116+j);//chin
    four_vertex(111+i,120+j,113+i,120+j,113+i,115+j,111+i,115+j);//neck

    glColor3f(0.0,0.0,0.0);
    four_vertex(107+i,133+j,112+i,133+j,111+i,130+j,106+i,130+j);//left side hair
    four_vertex(112+i,133+j,117+i,133+j,118+i,130+j,113+i,130+j);//right side hair
     glLineWidth(2.0);
     handle(107+i,120+j,107+i,133+j,117+i,133+j);//to draw border for face
     handle(117+i,133+j,117+i,120+j,113+i,117+j);//border
     handle(107+i,120+j,111+i,117+j,111+i,115+j);//border
     two_vertex(113+i,117+j,113+i,115+j);//neck border right

    two_vertex(109+i,127+j,112+i,126+j);//left eye brow
    two_vertex(113+i,126+j,116+i,127+j);//right eye brow
  glLineWidth(4.0);
     two_vertex(111+i,124+j,111+i,123+j);//left eye
     two_vertex(114+i,124+j,114+i,123+j);//right eye

     four_vertex(111+i,120+j,114+i,120+j,113+i,118+j,112+i,118+j);//mouth
     //four_vertex(111,121,114,121,114,120,111,120);

    glColor3f(0.0,0.0,0.4);
    four_vertex(105+i,115+j,119+i,115+j,119+i,92+j,105+i,92+j);//shirt
    glColor3f(0.0,0.0,0.0);

    four_vertex(105+i,92+j,104+i,60+j,110+i,60+j,113+i,92+j);//left leg
    four_vertex(119+i,92+j,120+i,60+j,114+i,60+j,111+i,92+j);//right leg
    glColor3f(1.0,1.0,1.0);
     two_vertex(112+i,109+j,112+i,108+j);//buttons
     two_vertex(112+i,112+j,112+i,111+j);//upper button
     glColor3f(1.0,0.0,0.0);
     three_vertex(111+i,115+j,109+i,115+j,112+i,113+j);//left collar
     three_vertex(113+i,115+j,115+i,115+j,112+i,113+j);//right collar
glColor3f(1.0,1.0,0.6);
four_vertex(104+i,60+j,110+i,60+j,106+i,55+j,101+i,55+j);//left chappal
three_vertex(101+i,55+j,106+i,55+j,102+i,52+j);

//right chappal
four_vertex(114+i,60+j,120+i,60+j,123+i,55+j,118+i,55+j);
three_vertex(118+i,55+j,123+i,55+j,122+i,52+j);
glColor3f(0.2,0.0,0.8);
glLineWidth(3.0);
handle(103+i,58+j,104+i,55+j,108+i,58+j);//left chappal bar
handle(116+i,58+j,121+i,55+j,121+i,58+j);//right chappal bar
glColor3f(0.0,0.0,0.0);
glLineWidth(1.0);
handle(114+i,60+j,118+i,55+j,122+i,52+j);//border for right chappal
handle(120+i,60+j,123+i,55+j,122+i,52+j);
//border for left chappal
handle(104+i,60+j,101+i,55+j,102+i,52+j);
handle(110+i,60+j,106+i,55+j,102+i,52+j);
/*glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);*/

   //four_vertex(108,98,108,104,111,103,111,99);//left palm
    //four_vertex(116,98,116,104,113,103,113,99);//right palm
//glFlush();
//icecreammanhand(40,40);
}

void icecreambox()
{
    glColor3f(1.0,1.0,0.8);
    four_vertex(125,130,125,102,152,102,152,130);//front side of box
    four_vertex(152,130,152,102,158,102,158,138);//side of box
    //four_vertex(131,138,158,138,152,130,125,130);

    glLineWidth(1.0);
    glColor3f(0.0,0.0,0.0);
    two_vertex(125,102,125,130);//left line
    handle(125,130,152,130,152,102);//ulta L
    handle(152,130,158,138,158,102);//side
    //handle(125,130,131,138,158,138);//top part
    handle(125,128,152,128,158,136);

}

void icecreamdoor()
{
    glColor3f(1.0,1.0,0.8);
    four_vertex(131,138,158,138,152,130,125,130);
    handle(125,130,131,138,158,138);//top part


}
void drawmenu()
{
    glColor3f(1.0, 0.8, 0.2);
    four_vertex(195,45,235,45,239,90,199,90);//front
    glColor3f(0.0, 0.0, 0.0);
    three_vertex(239,90,235,45,242,60);//back side  triangle

    glLineWidth(2.0);
    glColor3f(1.0, 0.2, 0.0);
    drawborder(195,45,235,45,239,90,199,90);//border for the front part
    drawborder(197,47,233,47,237,88,201,88);//inner border
    disp11(213,80,"MENU",3);
    disp11(200,70,"CHOCOBAR - Rs.10/-",3);
    disp11(200,60,"CORNETTO - Rs.25/-",3);
    disp11(200,50,"CANDY       - Rs.10/-",3);


}
void manreplica()
{
    drawmanice(40,40);
	glColor3f(0.8,0.8,0.8);//to mask the man's legs
	glRecti(97,100,163,102);
	glColor3f(1.0,1.0,0.6);
	glRecti(97,85,163,100);
	glLineWidth(2.0);
	glColor3f(0.0,0.0,0.0);
	two_vertex(97,102,163,102);
	two_vertex(97,100,163,100);
}
void screen_icecream()
{

    glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
   //     glPushMatrix();
	//gluOrtho2D(0,250,0,250);*/
	//glColor3f(0.8,0.8,1.0);//road
	glColor3f(0.752941,0.752941, 0.752941);
	four_vertex(0,0,0,35,250,35,250,0);
glColor3f(0.4,0.2,0.0);//ground
four_vertex(0,35,0,100,250,100,250,35);
glColor3f(1.0,1.0,0.6);
//front tyre part
glRecti(30,55,90,120);
//door part
four_vertex(30,120,90,120,90,190,50,190);
glColor3f(0.2,0.0,0.4);
glRecti(30,55,90,68);//design
drawCircle1(0,180,50,58,14,20);

glColor3f(1.0,1.0,0.6);
//middle
glRecti(90,55,180,190);
glColor3f(0.2,0.0,0.4);//design
glRecti(90,55,180,68);
//last
/*glColor3f(1.0,1.0,0.6);
four_vertex(170,55,220,70,220,210,170,190);
*/
//outline
glColor3f(0.0,0.0,0.0);
glLineWidth(1.5);
two_vertex(30,55,90,55);
two_vertex(90,55,180,55);

//top front
glColor3f(1.0,0.0,0.0);
four_vertex(50,190,90,190,90,210,55,200);
glRecti(90,190,180,210);//middle
//four_vertex(170,190,220,210,220,230,170,210);
glColor3f(0.8,0.8,0.8);//glass
glRecti(55,130,85,170);
four_vertex(55,130,40,130,40,138,55,170);
glRecti(95,100,165,180);
glColor3f(0.8, 0.4, 0.2);//inside window
glRecti(97,102,163,178);
glColor3f(0.0,0.0,0.0);
drawborder(95,100,95,180,165,180,165,100);
drawborder(97,102,97,178,163,178,163,102);
glLineWidth(2.5);
two_vertex(55,130,40,130);//outline
two_vertex(40,130,40,138);
two_vertex(40,138,55,170);
two_vertex(55,170,85,170);
two_vertex(85,170,85,130);
two_vertex(85,130,55,130);


/*glColor3f(0.2,0.0,0.4);//headlights
four_vertex(170,55,185,60,185,85,170,82);
four_vertex(205,90,220,97,220,70,205,65);
glColor3f(1.0,0.0,0.0);
four_vertex(172,67,182,68,182,75,172,74);
four_vertex(207,74,217,76,217,82,207,80);*/
glColor3f(0.0,0.0,0.0);//front tyre
drawCircle1(0,360,50,55,12,18);

glColor3f(0.8,0.8,0.8);
drawCircle1(0,360,50,55,7,12);
glColor3f(0.2,0.0,0.4);//design 2nd tyre
drawCircle1(0,180,150,55,14,25);
glColor3f(0.0,0.0,0.0);//2nd tyre
drawCircle1(0,360,150,55,12,18);
glColor3f(0.8,0.8,0.8);
drawCircle1(0,360,150,55,7,12);
glColor3f(0.0,0.0,0.0);
/*two_vertex(170,55,220,70);//outine
two_vertex(220,70,220,230);
two_vertex(220,230,170,210);*/
two_vertex(180,210,90,210);
two_vertex(90,210,55,200);
two_vertex(55,200,50,190);
two_vertex(50,190,30,120);
two_vertex(30,120,30,55);
two_vertex(180,210,180,190);
two_vertex(180,190,180,55);
/*glColor3f(1.0,1.0,0.0);//number plate
four_vertex(188,70,202,72,202,78,188,76);*/
	//glFlush();
	/*drawmanice(40,40);
	glColor3f(0.8,0.8,0.8);//to mask the man's legs
	glRecti(97,100,163,102);
	glColor3f(1.0,1.0,0.6);
	glRecti(97,85,163,100);
	glLineWidth(2.0);
	glColor3f(0.0,0.0,0.0);
	two_vertex(97,102,163,102);
	two_vertex(97,100,163,100);*/
	drawmenu();
glColor3f(0.8,0.8,0.8);
    glRecti(10,210,30,225);
    glLineWidth(1.5);
    glColor3f(0.0,0.0,0.0);
    two_vertex(10,210,30,210);
    two_vertex(30,210,30,225);
    two_vertex(30,225,10,225);
    two_vertex(10,225,10,210);
    disp11(15,217,"BACK",1);
}
void lastpart(int lp)
{
     glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
screen_icecream();
manreplica();
//drawcustomerice(140,0);
 glColor3f(0.0,0.4,0.6);
four_vertex(105+40,115+40,108+40,115+40,105+40,105+40,101+40,105+40);//left hand top part
    four_vertex(101+40,105+40,105+40,105+40,103+40,98+40,99+40,98+40);//left hand bottom part
//icecreammanhand(40,40);
icecreambox();
//icecreamdoor();
icecreamdoor();
drawcustomerice(125,0);
glColor3f(0.0,0.4,0.6);
/*four_vertex(156,155,159,155,160,146,157,116);
four_vertex(157,116,160,146,156-w,136,154-w,136);*/
four_vertex(116+40,115+40,119+40,115+40,120+40,106+40,117+40,106+40);//top part of ryt hand
 four_vertex(117+40,106+40,120+40,106+40,116+40-2,96+40-3-8,114+40-3,96+40-3-8);//bottom part of ryt hand aftr going inside the box

//glLineWidth(4.0);




glColor3f(1.0,1.0,0.8);
    four_vertex(131-12,138+12,158-12,138+12,152,130,125,130);//door
glColor3f(0.0,0.0,0.0);
    handle(125,130,131-12,138+12,158-12,138+12);
    glLineWidth(1.0);
    two_vertex(125,130,152,130);//border
    two_vertex(152,130,158-12,138+12);
     glColor3f(1.0,0.4,0.0);
          four_vertex(14+125,96,16+125,90,12+125+9+8-lp,77+20,9+125+9+8-lp,77+20);//left hand

    glColor3f(1.0,0.8,0.6);
   six_vertex(9+125+9+8-lp,77+20,12+125+9+8-lp,77+20,12+125+9+8-lp,76+20,11+125+9+8-lp,74+20,10+125+9+8-lp,74+20,9+125+9+8-lp,76+20);//left pal
   glColor3f(0.0,1.0,0.0);
four_vertex(149+3-lp,131+3-8-30,150+3-lp,132+3-8-30,150+3-lp,134+3-8-30,149+3-lp,134+3-8-30);//icecream stick
glColor3f(1.0,0.0,0.0);
four_vertex(148+3-lp,134+3-8-30,151+3-lp,134+3-8-30,151+3-lp,139+3-8-30,148+3-lp,139+3-8-30);//icecream upper part
if(lp1<8)
glutTimerFunc(200,lastpart,lp1++);
glFlush();
}
void customer_hand(int ch)
{hand=1;
  glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
screen_icecream();
manreplica();
//drawcustomerice(140,0);
 glColor3f(0.0,0.4,0.6);
four_vertex(105+40,115+40,108+40,115+40,105+40,105+40,101+40,105+40);//left hand top part
    four_vertex(101+40,105+40,105+40,105+40,103+40,98+40,99+40,98+40);//left hand bottom part
//icecreammanhand(40,40);
icecreambox();
//icecreamdoor();
icecreamdoor();
drawcustomerice(125,0);
glColor3f(0.0,0.4,0.6);
/*four_vertex(156,155,159,155,160,146,157,116);
four_vertex(157,116,160,146,156-w,136,154-w,136);*/
four_vertex(116+40,115+40,119+40,115+40,120+40,106+40,117+40,106+40);//top part of ryt hand
 four_vertex(117+40,106+40,120+40,106+40,116+40-2,96+40-3-8,114+40-3,96+40-3-8);//bottom part of ryt hand aftr going inside the box

//glLineWidth(4.0);




glColor3f(1.0,1.0,0.8);
    four_vertex(131-12,138+12,158-12,138+12,152,130,125,130);//door
glColor3f(0.0,0.0,0.0);
    handle(125,130,131-12,138+12,158-12,138+12);
    glLineWidth(1.0);
    two_vertex(125,130,152,130);//border
    two_vertex(152,130,158-12,138+12);
    if(ch1<25&&fch1==0)
   {
glColor3f(0.0,1.0,0.0);
four_vertex(149+3,131+3-8,150+3,132+3-8,150+3,134+3-8,149+3,134+3-8);//icecream stick
glColor3f(1.0,0.0,0.0);
four_vertex(148+3,134+3-8,151+3,134+3-8,151+3,139+3-8,148+3,139+3-8);//icecream upper part
glColor3f(1.0,0.4,0.0);
        four_vertex(14+125,96,16+125,90,12+125+9+ch1/3,77+ch1,9+125+9+ch1/3,77+ch1);//left hand

    glColor3f(1.0,0.8,0.6);
     six_vertex(9+125+9+ch1/3,77+ch1,12+125+9+ch1/3,77+ch1,12+125+9+ch1/3,76+ch1,11+125+9+ch1/3,74+ch1,10+125+9+ch1/3,74+ch1,9+125+9+ch1/3,76+ch1);//left palm
    } if(ch1>25&&ch1<50&&fch1==0)
     {   glColor3f(0.0,1.0,0.0);
four_vertex(149+3,131+3-8,150+3,132+3-8,150+3,134+3-8,149+3,134+3-8);//icecream stick
glColor3f(1.0,0.0,0.0);
four_vertex(148+3,134+3-8,151+3,134+3-8,151+3,139+3-8,148+3,139+3-8);//icecream upper part
         glColor3f(1.0,0.4,0.0);
four_vertex(14+125,96,16+125,90,12+125+9+8,77+ch1,9+125+9+8,77+ch1);//left hand

    glColor3f(1.0,0.8,0.6);
     six_vertex(9+125+9+8,77+ch1,12+125+9+8,77+ch1,12+125+9+8,76+ch1,11+125+9+8,74+ch1,10+125+9+8,74+ch1,9+125+9+8,76+ch1);//left pal
     }
     //get hand and icecream down
     if(ch1==50)
     fch1=ch1;
if(ch1>=50)
 {    glColor3f(1.0,0.4,0.0);


          four_vertex(14+125,96,16+125,90,12+125+9+8,77+fch1,9+125+9+8,77+fch1);//left hand

    glColor3f(1.0,0.8,0.6);
   six_vertex(9+125+9+8,77+fch1,12+125+9+8,77+fch1,12+125+9+8,76+fch1,11+125+9+8,74+fch1,10+125+9+8,74+fch1,9+125+9+8,76+fch1);//left pal
   glColor3f(0.0,1.0,0.0);
four_vertex(149+3,131+3-8+(fch1-50),150+3,132+3-8+(fch1-50),150+3,134+3-8+(fch1-50),149+3,134+3-8+(fch1-50));//icecream stick
glColor3f(1.0,0.0,0.0);
four_vertex(148+3,134+3-8+(fch1-50),151+3,134+3-8+(fch1-50),151+3,139+3-8+(fch1-50),148+3,139+3-8+(fch1-50));//icecream upper part

   fch1--;  }
if(ch1<80)
glutTimerFunc(300,customer_hand,ch1++);
if(ch1==80)
lastpart(0);

glFlush();

}
void icecream_to_customer(int icc)
{
  glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
screen_icecream();
manreplica();
//drawcustomerice(140,0);
 glColor3f(0.0,0.4,0.6);
four_vertex(105+40,115+40,108+40,115+40,105+40,105+40,101+40,105+40);//left hand top part
    four_vertex(101+40,105+40,105+40,105+40,103+40,98+40,99+40,98+40);//left hand bottom part
//icecreammanhand(40,40);
icecreambox();
//icecreamdoor();
icecreamdoor();
drawcustomerice(125,0);
glColor3f(0.0,0.4,0.6);
/*four_vertex(156,155,159,155,160,146,157,116);
four_vertex(157,116,160,146,156-w,136,154-w,136);*/
four_vertex(116+40,115+40,119+40,115+40,120+40,106+40,117+40,106+40);//top part of ryt hand
 four_vertex(117+40,106+40,120+40,106+40,116+40-2,96+40-3-icc,114+40-3,96+40-3-icc);//bottom part of ryt hand aftr going inside the box

//glLineWidth(4.0);

glColor3f(0.0,1.0,0.0);
four_vertex(149+3,131+3-icc,150+3,132+3-icc,150+3,134+3-icc,149+3,134+3-icc);//icecream stick
glColor3f(1.0,0.0,0.0);
four_vertex(148+3,134+3-icc,151+3,134+3-icc,151+3,139+3-icc,148+3,139+3-icc);//icecream upper part



glColor3f(1.0,1.0,0.8);
    four_vertex(131-12,138+12,158-12,138+12,152,130,125,130);//door
glColor3f(0.0,0.0,0.0);
    handle(125,130,131-12,138+12,158-12,138+12);
    glLineWidth(1.0);
    two_vertex(125,130,152,130);//border
    two_vertex(152,130,158-12,138+12);
if(icc1<8)
glutTimerFunc(1200,icecream_to_customer,icc1++);
if(icc1==8)
{
    customer_hand(0);
}

glFlush();
}
void handwithicecream(int hwi)
{
  glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
screen_icecream();
manreplica();
//drawcustomerice(140,0);
 glColor3f(0.0,0.4,0.6);
four_vertex(105+40,115+40,108+40,115+40,105+40,105+40,101+40,105+40);//left hand top part
    four_vertex(101+40,105+40,105+40,105+40,103+40,98+40,99+40,98+40);//left hand bottom part
//icecreammanhand(40,40);
icecreambox();
//icecreamdoor();
icecreamdoor();
drawcustomerice(125,0);
glColor3f(0.0,0.4,0.6);
/*four_vertex(156,155,159,155,160,146,157,116);
four_vertex(157,116,160,146,156-w,136,154-w,136);*/
four_vertex(116+40,115+40,119+40,115+40,120+40,106+40,117+40,106+40);//top part of ryt hand
    four_vertex(117+40,106+40,120+40,106+40,116+40-5+hwi,96+40-5+hwi,114+40-5+hwi,96+40-5+hwi);//bottom part of ryt hand aftr going inside the box

//glLineWidth(4.0);

glColor3f(0.0,1.0,0.0);
four_vertex(149+hwi,131+hwi,150+hwi,132+hwi,150+hwi,134+hwi,149+hwi,134+hwi);//icecream stick
glColor3f(1.0,0.0,0.0);
four_vertex(148+hwi,134+hwi,151+hwi,134+hwi,151+hwi,139+hwi,148+hwi,139+hwi);//icecream upper part



glColor3f(1.0,1.0,0.8);
    four_vertex(131-12,138+12,158-12,138+12,152,130,125,130);//door
glColor3f(0.0,0.0,0.0);
    handle(125,130,131-12,138+12,158-12,138+12);
    glLineWidth(1.0);
    two_vertex(125,130,152,130);//border
    two_vertex(152,130,158-12,138+12);


if(ih<3)
glutTimerFunc(200,handwithicecream,ih++);
else
if(ih==3)
icecream_to_customer(0);
glFlush();


}




void manhandinbox(int w)
{
  glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
screen_icecream();
manreplica();
 glColor3f(0.0,0.4,0.6);
four_vertex(105+40,115+40,108+40,115+40,105+40,105+40,101+40,105+40);//left hand top part
    four_vertex(101+40,105+40,105+40,105+40,103+40,98+40,99+40,98+40);//left hand bottom part
//icecreammanhand(40,40);
icecreambox();
//icecreamdoor();
icecreamdoor();
drawcustomerice(125,0);
glColor3f(0.0,0.4,0.6);
/*four_vertex(156,155,159,155,160,146,157,116);
four_vertex(157,116,160,146,156-w,136,154-w,136);*/
four_vertex(116+40,115+40,119+40,115+40,120+40,106+40,117+40,106+40);
    four_vertex(117+40,106+40,120+40,106+40,116+40-w,96+40-w,114+40-w,96+40-w);
glColor3f(1.0,1.0,0.8);
    four_vertex(131-12,138+12,158-12,138+12,152,130,125,130);//door
glColor3f(0.0,0.0,0.0);
    handle(125,130,131-12,138+12,158-12,138+12);
    glLineWidth(1.0);
    two_vertex(125,130,152,130);//border
    two_vertex(152,130,158-12,138+12);
    glColor3f(0.0,0.0,0.0);

//glColor3f

if(in<6)
glutTimerFunc(200,manhandinbox,in++);

if(in==6)
{
handwithicecream(0);
}
glFlush();


}
void boxopen(int i)
 {
     glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
screen_icecream();
 //drawmanice(40,40);

 manreplica();
 icecreammanhand(40,40);
    icecreambox();

    icecreamdoor();
    drawcustomerice(125,0);
 glColor3f(1.0,1.0,0.8);
    four_vertex(131-i,138+i,158-i,138+i,152,130,125,130);
    glColor3f(0.0,0.0,0.0);
    handle(125,130,131-i,138+i,158-i,138+i);
    glLineWidth(1.0);
    two_vertex(125,130,152,130);//border
    two_vertex(152,130,158-i,138+i);


    if(openb<13)
	glutTimerFunc(100,boxopen,openb++);

if(openb==13)
{
manhandinbox(0);
}
 glFlush();
 }
void disp_icecream()
{
    for(i=0;i<125;i++)
    {screen_icecream();
	manreplica();
	icecreambox();
	 icecreamdoor();
	drawcustomerice(i,0);
	icecreammanhand(40,40);
	delay(50900);
	glFlush();}
	icecreammanhand(40,40);
    icecreambox();
    icecreamdoor();
    fm=0;
    boxopen(0);
}

void drawbottle(int a,float b,float c,float d)
{
    glColor3f(b,c,d);
     six_vertex(195+a,89,199+a,89,199+a,105,198+a,107,196+a,107,195+a,105);
   // four_vertex(195+a,105,199+a,105,199+a,111,195+a,111);
glRecti(196+a,107,198+a,111);
     glColor3f(0.0,0.0,0.0);
     glLineWidth(1.0);
     two_vertex(195+a,105,195+a,89);//left straight line
     two_vertex(195+a,89,199+a,89);//base line
     two_vertex(199+a,89,199+a,105);//right straight line
     two_vertex(195+a,105,196+a,107);//left slant line
     two_vertex(199+a,105,198+a,107);//right slnt line
     handle(196+a,107,196+a,111,198+a,111);//left side bottle cap
     two_vertex(198+a,107,198+a,111);//bottle top
    // glFlush();
}
void drawglass(int g)
{
    glLineWidth(1.0);
    glColor3f(0.0,0.0,0.0);
    drawborder(94+g,89,98+g,89,98+g,102,94+g,102);//glass
        glColor3f(0.8,0.8,1.0);
    four_vertex(94+g,89,98+g,89,98+g,102,94+g,102);//glass
}
void drawmachine(int i)
{

    glColor3f(0.8,0.8,0.8);
    four_vertex(89+i,89,89+i,130,78+i,130,78+i,89);//front
    glColor3f( 0.658824, 0.658824, 0.658824);
    four_vertex(100+i,93,100+i,135,89+i,130,89+i,89);//side
    four_vertex(78+i,130,89+i,130,100+i,135,89+i,135);//top

    glLineWidth(1.0);


    glColor3f(0.0,0.0,0.0);
    drawborder(100+i,93,100+i,135,89+i,130,89+i,89);//tap side square
    //two_vertex(100,);
    drawborder(89+i,89,89+i,130,78+i,130,78+i,89);//front side
    drawborder(78+i,130,89+i,130,100+i,135,89+i,135);//top side

      //  drawborder(94+i,89,98+i,89,98+i,98,94+i,98);//glass
       // glColor3f(0.8,0.8,1.0);
//    four_vertex(94+i,89,98+i,89,98+i,98,94+i,98);//glass
        glLineWidth(4.0);
        glColor3f(0.0,0.0,0.0);
    two_vertex(93+i,114,97+i,116);//tap
    two_vertex(95+i,115,95+i,111);//tap
}


void bagshopdraw()//
{
//glColor3f(0.8,0.8,1.0);//road
glColor3f(0.752941,0.752941, 0.752941);
four_vertex(0,0,0,35,250,35,250,0);
glColor3f(0.2,0.2,0.4);//left wall
//four_vertex(0,35,30,110,30,210,0,240);
glBegin(GL_POLYGON);
glVertex2f(30,110);
glVertex2f(30,210);
glColor3f(0.2,0.2,0.6);
glVertex2f(0,240);
glVertex2f(0,35);
glEnd();

glColor3f(0.2,0.2,0.4);//right wall
//four_vertex(250,35,220,110,220,210,250,240);
glBegin(GL_POLYGON);
glVertex2f(220,110);
glVertex2f(220,210);
glColor3f(0.2,0.2,0.6);
glVertex2f(250,240);
glVertex2f(250,35);
glEnd();

glColor3f(0.2,0.2,0.4);//roof
//four_vertex(30,210,220,210,250,240,0,240);
glBegin(GL_POLYGON);
glVertex2f(30,210);
glVertex2f(220,210);
glColor3f(0.2,0.2,0.6);
glVertex2f(250,240);
glVertex2f(0,240);
glEnd();
glColor3f(0.6, 0.6, 0.4);//base
four_vertex(0,35,30,110,220,110,250,35);
glColor3f(0.0,0.0,0.0);
glLineWidth(1.0);
handle(0,240,30,210,220,210);
handle(0,240,250,240,220,210);
four_vertex(0,32,4,32,4,249,0,249);//stick left
four_vertex(250,32,246,32,246,249,250,249);//stick right
four_vertex(30,109,32,109,32,211,30,211);//stick left back
  four_vertex(220,109,218,109,218,211,220,211);//stick right back




four_vertex(60,190,190,190,190,230,60,230);//board

glLineWidth(4.0);
two_vertex(70,230,65,240);//hanging the board
two_vertex(180,230,185,240);
glColor3f(1.0,0.0,0.0);
//disp11(105,210,"FANCY BAG SHOP",3);
//disp11(105,210,"FANCY BAG SHOP",1);
drawborder(65,195,185,195,185,225,65,225);//inner border
drawborder(60,190,190,190,190,230,60,230);//outer border
}
void shelfdraw()
{
  glColor3f(0.0,0.0,0.0);
  four_vertex(58,95,61,95,61,183,58,183);//shelf left stick
  four_vertex(189,95,192,95,192,183,189,183);//shelf right stick
  four_vertex(65,100,67,100,67,178,65,178);//shelf left back stick
  four_vertex(185,100,183,100,183,178,185,178);//shelf right back stick
  glColor3f(1.0,0.0,0.0);
  four_vertex(65,170,185,170,191,162,59,162);//1st row
  four_vertex(65,147,185,147,191,140,59,140);//2nd row
  four_vertex(65,124,185,124,191,117,59,117);//3rd row


}
void bagtobuy(int i)
{
//3rd row 1st bag
glColor3f(0.2,0.8,1.0);
four_vertex(72,119-i,84,119-i,83,130-i,73,130-i);
glColor3f(0.2,0.6,1.0);
three_vertex(84,119-i,85,121-i,83,130-i);
glLineWidth(6.0);
handle(73,130-i,78,139-i,83,130-i);
}
void drawbags()
{
    glColor3f(0.4,0.0,0.2);
    four_vertex(71,164,83,164,82,175,73,175);//first bag 1st row
    glColor3f(0.2,0.0,0.2);
    three_vertex(83,164,82,175,84,167);//side of bag
    three_vertex(77,169,73,175,82,175);//cover of bAG
    glColor3f(0.0,0.0,0.0);
    glLineWidth(1.0);//border for 1st bag
    two_vertex(73,175,77,169);
    two_vertex(82,175,77,169);


    drawborder(73,175,71,164,83,164,82,175);

   two_vertex(84,167,83,164);
    two_vertex(82,175,84,167);

    glLineWidth(6.0);//handle
    two_vertex(78,186,73,175);
    two_vertex(78,186,82,175);

    glColor3f(0.2,0.0,0.6);
    four_vertex(90,164,105,164,103,178,92,178);//2nd bag

    glColor3f(0.0,1.0,0.6);

    glLineWidth(3.0);
    two_vertex(92,178,105,164);//line on bag
    two_vertex(103,178,90,164);


    glColor3f(0.2,0.0,1.0);

    glLineWidth(6.0);//handle
    two_vertex(92,178,98,185);
    two_vertex(98,185,103,178);
 glColor3f(0.0,0.0,0.0);

    glLineWidth(2.0);
    two_vertex(92,178,90,164);//borders
    two_vertex(103,178,105,164);
    two_vertex(92,178,103,178);
    two_vertex(105,164,90,164);
    three_vertex(103,178,105,164,106,168);//side


    //third bag
    glColor3f(1.0,0.8,0.0);
    four_vertex(115,164,127,164,127,181,115,181);
    glColor3f(1.0,0.6,0.0);
    three_vertex(127,164,127,181,128,169);
    four_vertex(115,181,120,175,122,175,127,181);
    glLineWidth(6.0);
    handle(119,181,121,188,123,181);//to draw handle
    glColor3f(0.0,0.0,0.0);
    glLineWidth(1.0);
    drawborder(115,181,115,164,127,164,127,181);//border
    drawborder(115,181,120,175,122,175,127,181);
    handle(127,181,128,169,127,164);//to draw side's border

    //4th bag 1st row
    glColor3f(0.6,0.0,0.0);
    four_vertex(138,164,150,164,148,176,140,176);
    glLineWidth(4.0);
    glColor3f(0.8,0.0,0.0);
    handle(140,176,144,180,148,176);
    glColor3f(1.0,0.8,0.0);
    three_vertex(140,176,144,170,138,164);
    three_vertex(148,176,144,170,150,164);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawborder(140,176,138,164,150,164,148,176);
    //5th bag 1st row
    glColor3f(1.0,0.4,0.8);
    four_vertex(164,164,180,164,180,183,164,183);
    glColor3f(1.0,0.2,0.6);
    three_vertex(164,164,164,183,162,168);
    glLineWidth(6.0);
    handle(168,183,172,189,176,183);
    four_vertex(168,168,168,179,176,179,176,168);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(1.0);
    drawborder(164,164,180,164,180,183,164,183);
    handle(164,164,162,168,164,183);

    //2nd row 1st bag
    glColor3f(0.2,1.0,1.0);
    four_vertex(68,142,83,142,82,155,69,155);
    glColor3f(1.0,0.2,0.6);
    glLineWidth(4.0);
    handle(69,155,75,161,82,155);//handle
    two_vertex(68,145,83,145);
    two_vertex(69,150,82,150);
    glColor3f(0.4,0.8,0.8);
    three_vertex(83,142,84,144,82,155);//side
    glColor3f(0.0,0.0,0.0);
    glLineWidth(1.0);
    drawborder(68,142,83,142,82,155,69,155);
    handle(83,142,84,144,82,155);//border


//2nd row 2nd bag
glColor3f(0.6,0.2,0.8);
glBegin(GL_POLYGON);
glVertex2f(94,156);
glVertex2f(110,156);
glColor3f(1.0,0.4,0.6);

glVertex2f(110,142);
glVertex2f(94,142);
glEnd();
glLineWidth(6.0);
handle(94,156,102,160,110,156);
glLineWidth(1.0);
glColor3f(0.0,0.0,0.0);
drawborder(94,156,110,156,110,142,94,142);


//2nd row 3rd bag
glColor3f(0.2,0.0,0.4);
four_vertex(120,142,132,142,131,155,121,155);
glLineWidth(6.0);
glColor3f(0.4,0.0,0.4);
handle(122,155,126,160,130,155);
glColor3f(0.8,0.0,0.0);
glLineWidth(2.0);
two_vertex(121,155,132,142);
two_vertex(131,155,120,142);
three_vertex(131,155,132,142,133,144);

//2nd row 4th bag
glColor3f(0.0,0.6,0.2);
four_vertex(142,142,154,142,153,154,143,154 );
glColor3f(0.0,0.4,0.0);
glLineWidth(3.0);
handle(143,154,148,148,153,154);//to draw inner cover
three_vertex(154,142,153,154,155,144);//side
glLineWidth(6.0);
handle(145,154,148,161,151,154);

//2nd row 5th bag
glColor3f(0.8,0.2,0.0);
four_vertex(164,142,178,142,178,155,164,155);
glColor3f(0.8,0.4,0.2);
three_vertex(178,142,179,144,178,155);//side
three_vertex(164,155,178,155,171,150);//inner cover
handle(164,155,171,160,178,155);//actual handle
glColor3f(0.0,0.0,0.0);
glLineWidth(1.0);
drawborder(164,142,178,142,178,155,164,155);
handle(164,155,171,150,178,155);//border for inner cover
handle(178,142,179,144,178,155);//border for side




//3rd row 2nd bag

glColor3f(0.2,0.2,0.4);
four_vertex(94,119,106,119,106,132,94,132);
glColor3f(0.2,0.2,0.6);
three_vertex(106,119,107,121,106,132);//side
three_vertex(94,132,106,132,100,125);//handle
handle(94,132,100,138,106,132);
glColor3f(0.0,0.0,0.0);
glLineWidth(1.0);
drawborder(94,119,106,119,106,132,94,132);
handle(106,119,107,121,106,132);//for border
handle(94,132,100,125,106,132);//for border


//for 3rd row 3rd bag
glColor3f(0.6,0.8,0.0);
glBegin(GL_POLYGON);
glVertex2f(116,119);
glVertex2f(128,119);
glColor3f(0.8,0.2,0.6);
glVertex2f(128,133);
glVertex2f(116,133);
glEnd();

glLineWidth(6.0);
handle(116,133,122,138,128,133);//handle
three_vertex(128,119,128,133,129,121);
glLineWidth(1.0);
glColor3f(0.0,0.0,0.0);
drawborder(116,119,128,119,128,133,116,133);
handle(128,133,129,121,128,119);

//3rd row 4th bag

glColor3f(0.2,0.2,1.0);
four_vertex(140,119,152,119,151,134,141,134);
glColor3f(0.2,0.8,1.0);
three_vertex(152,119,151,134,153,121);
glLineWidth(6.0);
handle(144,134,146,138,147,134);//actual border
three_vertex(141,134,146,125,151,134);
glColor3f(0.0,0.0,0.0);
glLineWidth(1.0);
drawborder(140,119,152,119,151,134,141,134);
handle(152,119,153,121,151,134);//borders
handle(141,134,146,125,151,134);
//3rd row 5th bag

glColor3f(0.0,0.6,0.4);
four_vertex(162,119,174,119,174,133,162,133);
glColor3f(0.0,0.6,0.0);
three_vertex(174,119,175,121,174,133);
three_vertex(174,133,168,125,162,133);
glLineWidth(6.0);
handle(162,133,168,138,174,133);

glColor3f(0.0,0.0,0.0);
glLineWidth(1.0);
drawborder(162,119,174,119,174,133,162,133);
handle(174,119,175,121,174,133);
handle(174,133,168,125,162,133);
}
void drawman(int i,int j,int k)
{
    glColor3f(1.0,1.0,0.8);

four_vertex(107+j/4-i,120+j/2,117+j/4-i,120+j/2,117+j/4-i,133+j/2,107+j/4-i,133+j/2);//face
   // glColor3f(1.0,1.0,0.8);
   //glColor3f(1.0,0.0,1.0);


three_vertex(107+j/4-i,120+j/2,117+j/4-i,120+j/2,112+j/4-i,116+j/2);//chin

four_vertex(111+j/2-i,120+j/4,113+j/2-i,120+j/4,113+j/2-i,115+j/4,111+j/2-i,115+j/4);//neck

    glColor3f(0.0,0.0,0.0);

four_vertex(107+j/4-i,133+j/2,112+j/4-i,133+j/2,111+j/4-i,130+j/2,106+j/4-i,130+j/2);//left
//side hair

four_vertex(112+j/4-i,133+j/2,117+j/4-i,133+j/2,118+j/4-i,130+j/2,113+j/4-i,130+j/2);//right
//side hair
     glLineWidth(2.0);
     handle(107+j/4-i,120+j/2,107+j/4-i,133+j/2,117+j/4-i,133+j/2);//to
//draw border for face
     handle(117+j/4-i,133+j/2,117+j/4-i,120+j/2,113+j/4-i,117+j/2);//border
     handle(107+j/4-i,120+j/2,111+j/4-i,117+j/2,111+j/4-i,115+j/2);//border
     two_vertex(113+j/4-i,117+j/2,113+j/4-i,115+j/2);//neck border right

    two_vertex(109+j/4-i,127+j/2,112+j/4-i,126+j/2);//left eye brow
    two_vertex(113+j/4-i,126+j/2,116+j/4-i,127+j/2);//right eye brow
  glLineWidth(4.0);
     two_vertex(111+j/4-i,124+j/2,111+j/4-i,123+j/2);//left eye
     two_vertex(114+j/4-i,124+j/2,114+j/4-i,123+j/2);//right eye


 four_vertex(111+j/4-i,120+j/2,114+j/4-i,120+j/2,113+j/4-i,118+j/2,112+j/4-i,118+j/2);//mouth
     //four_vertex(111,121,114,121,114,120,111,120);

    glColor3f(0.0,0.0,0.4);
    four_vertex(105+j/6-i,115+j,119-i,115,119-i,92,105+j/6-i,92+j);//shirt
    glColor3f(0.0,0.0,0.0);


four_vertex(105+j/6-i,92+j,104+j/6-i,60+j,110+j/6-i,60+j,113+j/6-i,92+j/1.5);//left
//leg

four_vertex(119-i,92,120-j/6-i,60+j,114-j/6-i,60+j,111+j/6-i,92+j/1.5);//right
//leg
    glColor3f(1.0,1.0,1.0);
     two_vertex(112-i,109,112-i,108);//buttons
     two_vertex(112-i,112,112-i,111);//upper button
     glColor3f(1.0,0.0,0.0);
     three_vertex(111-i,115+j/2,109-i,115+j/2,112-i,113+j/2);//left collar
     three_vertex(113-i,115+j/2,115-i,115+j/2,112-i,113+j/2);//right collar
glColor3f(1.0,1.0,0.6);
four_vertex(104+j/6-i,60+j,110+j/6-i,60+j,106+j/6-i,55+j,101+j/6-i,55+j);//left
//chappal
three_vertex(101+j/6-i,55+j,106+j/6-i,55+j,102+j/6-i,52+j);

//right chappal
four_vertex(114-i,60+j,120-i,60+j,123-j-i,55+j,118-j-i,55+j);
three_vertex(118-j-i,55+j,123-j-i,55+j,122-j-i,52+j);
glColor3f(0.2,0.0,0.8);
glLineWidth(3.0);
handle(103+j/6-i,58+j,104+j/6-i,55+j,108-j/6-i,58+j);//left chappal bar
handle(116-j/2-i,58+j,121-j-i,55+j,121-j/2-i,58+j);//right chappal bar
glColor3f(0.0,0.0,0.0);
glLineWidth(1.0);
handle(114-i,60+j,118-j-i,55+j,122-j-i,52+j);//border for right chappal
handle(120-i,60+j,123-j-i,55+j,122-j-i,52+j);
//border for left chappal
handle(104+j/6-i,60+j,101+j/6-i,55+j,102+j/6-i,52+j);
handle(110+j/6-i,60+j,106+j/6-i,55+j,102+j/6-i,52+j);
/*glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);*/
glColor3f(0.0,0.4,0.6);
four_vertex(105-i+j/4,115+j,105-i+j/4,105+j,102-i,98+j+k,102-i,106+k+j);

//six_vertex(105-i,115+j,104-i,106+j,108-i,98+j,110-i,98+j,106-i,106+j,105-i,115+j);
    six_vertex(119-i,115,120-i,106,116-i,98,116-i,104,118-i,106,116-i,115);
    //four_vertex(119,115,120,106,116,98,116,104);//right hand
    //glColor3f(1.0,1.0,1.0);
   // four_vertex(108,98,108,104,111,103,111,99);//left palm
    //four_vertex(116,98,116,104,113,103,113,99);//right palm

}
void drawtable()
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//left leg front
    glVertex2f(28,85);
    glVertex2f(28,38);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(30,38);
    glVertex2f(30,85);
    glEnd();
    glColor3f(0.0,0.0,0.0);//right leg front
    glBegin(GL_POLYGON);//
    glVertex2f(222,85);
    glVertex2f(222,38);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(220,38);
    glVertex2f(220,85);
    glEnd();
     glColor3f(0.0,0.0,0.0);//table front strip
    glBegin(GL_POLYGON);//
    glVertex2f(26,85);
    glVertex2f(224,85);

    glColor3f(1.0,1.0,1.0);
    glVertex2f(224,87);
    glVertex2f(26,87);
    glEnd();
    //table top
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(26,87);
    glVertex2f(224,87);

    glColor3f(1.0,1.0,1.0);
    glVertex2f(214,94);
    glVertex2f(36,94);
    glEnd();
    //table back right leg
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(214,85);
    glVertex2f(214,45);

    glColor3f(1.0,1.0,1.0);
    glVertex2f(216,45);
    glVertex2f(216,85);
    glEnd();
    //table left back leg
     glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(36,85);
    glVertex2f(36,45);

    glColor3f(1.0,1.0,1.0);
    glVertex2f(38,45);
    glVertex2f(38,85);
    glEnd();
}
void disp()//for the bag shop
{
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
 bagshopdraw();
    shelfdraw();
    drawbags();
    glColor3f(1.0,0.0,0.0);
    disp11(105,210,"FANCY BAG SHOP",1);
    //drawman();

    glColor3f(0.8,0.8,0.8);
    glRecti(10,210,30,225);
    glLineWidth(1.5);
    glColor3f(0.0,0.0,0.0);
    two_vertex(10,210,30,210);
    two_vertex(30,210,30,225);
    two_vertex(30,225,10,225);
    two_vertex(10,225,10,210);
    disp11(15,217,"BACK",1);

}
void wordpop(int i,int j)
{
    glColor3f(1.0,1.0,0.0);
drawCircle1(0,360,69+i,105+j,8,8);
drawCircle1(0,360,77+i,113+j,8,8);
drawCircle1(0,360,85+i,105+j,8,8);
drawCircle1(0,360,80+i,100+j,8,10);
drawCircle1(0,360,75+i,100+j,8,10);
}
void drawcustomer(int i,int j)
{

if(l==0)
fl=0;
if(h==0)
fh=0;
if(h<10&&fh==0)
 {glColor3f(0.0,0.0,0.0);
    four_vertex(10+i+h,30,17+i+h,30,14+i+h,35,11+i+h,35);//left shoe
    four_vertex(21+i-h,34,24+i-h,34,27+i-h,29,20+i-h,29);//right shoe
    glColor3f(0.0,0.0,0.2);
    four_vertex(11+i+h,35,14+i+h,35,19+i,72,13+i,72);//left leg
    glColor3f(0.0,0.0,0.4);
    four_vertex(14+i,72,22+i,72,24+i-h,34,21+i-h,34);//right leg
    if(fm==1)
    h++;
 }
 if(h==10)
 fh=1;
 if(fh==1)
 {glColor3f(0.0,0.0,0.0);
    four_vertex(10+i+h,30,17+i+h,30,14+i+h,35,11+i+h,35);//left shoe
    four_vertex(21+i-h,34,24+i-h,34,27+i-h,29,20+i-h,29);//right shoe
    glColor3f(0.0,0.0,0.2);
    four_vertex(11+i+h,35,14+i+h,35,19+i,72,13+i,72);//left leg
    glColor3f(0.0,0.0,0.4);
    four_vertex(14+i,72,22+i,72,24+i-h,34,21+i-h,34);//right leg
    if(fm==1)
    h--;
 }
    if(l<15&&fl==0)
    {glColor3f(1.0,0.4,0.0);
            four_vertex(20+i,96,21+i,86,24+i-l,78,27+i-l,78);//right
//hAND-hand at back side
    glColor3f(1.0,0.8,0.6);

six_vertex(24+i-l,78,27+i-l,78,27+i-l,77,26+i-l,75,25+i-l,75,24+i-l,77);//right
//-bak side palm

    }
        if(fl==1)
    {glColor3f(1.0,0.4,0.0);

four_vertex(20+i,96,21+i,86,24+i-l+j/2,78+j,27+i-l+j/2,78+j);//right
//hAND-hand at back side
    glColor3f(1.0,0.8,0.6);

six_vertex(24+i-l,78,27+i-l,78+j,27+i-l,77+j,26+i-l,75,25+i-l,75,24+i-l,77);//right
//-bak side palm

    }

        glColor3f(1.0,0.6,0.2);

    four_vertex(12+i,72,23+i,72,20+i,96,14+i,96);//body
    glColor3f(1.0,0.8,0.6);
    drawCircle1(0,360,17+i,107,4,9);//face
    //four_vertex(17,96,19,96,19,99,17,99);//neck
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    handle(15+i,109,16+i,110,18+i,109);//left eye brow
    handle(19+i,110,20+i,111,21+i,111);//right eye brow
    handle(19+i,108,20+i,106,19+i,105);//nose
    handle(14+i,108,14+i,106,15+i,106);
    three_vertex(20+i,103,19+i,101,17+i,102);//mouth
    glLineWidth(4.0);
    two_vertex(17+i,107,17+i,108);//left eye
    two_vertex(20+i,109,20+i,108);//right eye
    //two_vertex(20,114,12,114);//hair
    drawCircle1(0,180,18+i,113,3,5);//hair
    drawCircle1(0,185,16+i,113,3,5);//hair
    three_vertex(12+i,114,17+i,114,13+i,107);//hair

six_vertex(14+i,96,20+i,96,19+i,98,19+i,99,16+i,99,16+i,98);//neck+upper
//body
    if(l<15&&fl==0&&j==0)
    {    glColor3f(1.0,0.4,0.0);

        four_vertex(14+i,96,16+i,90,12+i+l,77,9+i+l,77);//left hand

    glColor3f(1.0,0.8,0.6);

 six_vertex(9+i+l,77,12+i+l,77,12+i+l,76,11+i+l,74,10+i+l,74,9+i+l,76);//left
//palm
     if(fm==1)
     l++;
    }
    if(l==15)
    fl=1;
    if(fl==1&&j==0)
    {
         glColor3f(1.0,0.4,0.0);

        four_vertex(14+i,96,16+i,90,12+i+l-j,77,9+i+l-j,77);//left hand

    glColor3f(1.0,0.8,0.6);

 six_vertex(9+i+l-j,77,12+i+l-j,77,12+i+l-j,76,11+i+l-j,74,10+i+l-j,74,9+i+l-j,76);//left
//palm
     if(fm==1)
     l--;

    }
    //to make hand go up
if(j>0&&j<20&&mov_hand==0)
{
            glColor3f(1.0,0.4,0.0);


four_vertex(14+i,96,16+i,90,12+i+l+j*0.8,77+j,9+i+l+j*0.8,77+j);//left hand

    glColor3f(1.0,0.8,0.6);

 six_vertex(9+i+l+j*0.8,77+j,12+i+l+j*0.8,77+j,12+i+l+j*0.8,76+j,11+i+l+j*0.8,74+j,10+i+l+j*0.8,74+j,9+i+l+j*0.8,76+j);//left
//palm

}
//to make hand movements
if(j>20&&mov_hand==0)
{
      glColor3f(1.0,0.4,0.0);


four_vertex(14+i,96,16+i,90,12+i+l+0.8*20,77+j,9+i+l+0.8*20,77+j);//left
//hand

    glColor3f(1.0,0.8,0.6);

 six_vertex(9+i+l+0.8*20,77+j,12+i+l+0.8*20,77+j,12+i+l+0.8*20,76+j,11+i+l+0.8*20,74+j,10+i+l+0.8*20,74+j,9+i+l+0.8*20,76+j);//left
}

if(mov_hand==1)
{
glColor3f(1.0,0.4,0.0);


four_vertex(14+i,96,16+i,90,12+i+l+0.8*12-2*j,77+12,9+i+l+0.8*12-2*j,77+12);//left
//hand

    glColor3f(1.0,0.8,0.6);

 six_vertex(9+i+l+0.8*12-2*j,77+12,12+i+l+0.8*12-2*j,77+12,12+i+l+0.8*12-2*j,76+12,11+i+l+0.8*12-2*j,74+12,10+i+l+0.8*12-2*j,74+12,9+i+l+0.8*12-2*j,76+12);//left
//palm

}
}
void bagscreen()
{
    disp11(105,210,"FANCY BAG SHOP",1);
printf("hey");
    //glPushMatrix();
//glOrtho(0,250,0,250,0,1);

    disp();
    for(j=0;j<40;j++)
    {delay(50900);
    disp();
drawman(0,0,0);
drawtable();
glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);//bag wit shopkeeper
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawborder(108,107,116,107,118,90,106,90);


        drawcustomer(j,0);
bagtobuy(0);
    glFlush();
    }
        disp();
drawman(0,0,0);
drawtable();
glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);//bag wit shopkeeper
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawborder(108,107,116,107,118,90,106,90);

    drawcustomer(39,0);
bagtobuy(0);
printf("%d",j);
wordpop(0,0);

glColor3f(0.0,0.0,0.0);
disp11(70,113,"HOW MUCH",2);
disp11(65,105,"FOR FIRST BAG",2);
glFlush();
delay(500900);
 disp();
drawman(0,0,0);
drawtable();
glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);//bag wit shopkeeper
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawborder(108,107,116,107,118,90,106,90);

 drawcustomer(39,0);
 bagtobuy(0);
wordpop(15,10);
glColor3f(0.0,0.0,0.0);
disp11(80,115,"RS 250 0NLY",2);
glFlush();
delay(500900);
 disp();
drawman(0,0,0);
drawtable();
glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);//bag wit shopkeeper
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawborder(108,107,116,107,118,90,106,90);

drawcustomer(39,0);
bagtobuy(0);
wordpop(0,0);
glColor3f(0.0,0.0,0.0);
disp11(65,105,"I WILL BUY IT",2);
glFlush();
delay(500900);
 disp();
drawman(0,0,0);
drawtable();
glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);//bag wit shopkeeper
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawborder(108,107,116,107,118,90,106,90);

drawcustomer(39,0);
bagtobuy(0);
//drawman(0,10);
//owner side
for(j=0;j<6;j++)
{glClear(GL_COLOR_BUFFER_BIT);
    disp();
    drawman(0,j,0);

drawtable();
glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);//bag wit shopkeeper
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawborder(108,107,116,107,118,90,106,90);

drawcustomer(39,0);
bagtobuy(0);
delay(100900);
glFlush();}
//owner move
for(j=0;j<20;j++)
{
    glClear(GL_COLOR_BUFFER_BIT);
    disp();
    drawman(j,6,0);
fm=0;//to stop hand movement
drawtable();
glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);//bag wit shopkeeper
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawborder(108,107,116,107,118,90,106,90);

drawcustomer(39,0);
bagtobuy(0);
delay(100900);
glFlush();
}
//swing owners hand

for(j=0;j<20;j++)
{
    glClear(GL_COLOR_BUFFER_BIT);
    disp();


    drawman(20,6,j);
    bagtobuy(0);
fm=0;//to stop hand movement
drawtable();
glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);//bag wit shopkeeper
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawborder(108,107,116,107,118,90,106,90);

drawcustomer(39,0);delay(100900);
glFlush();
}
//get bag down with hand
for(j=0;j<26;j++)
{ glClear(GL_COLOR_BUFFER_BIT);
    disp();
    drawman(20,6,20-j);
    drawtable();
    glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);//bag wit shopkeeper
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawborder(108,107,116,107,118,90,106,90);

    bagtobuy(j);
fm=0;//to stop hand movement

drawcustomer(39,0);delay(100900);
glFlush();}
for(j=0;j<12;j++)
{ glClear(GL_COLOR_BUFFER_BIT);
    disp();
    drawman(20,6,-5);
    drawtable();
    glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);//bag wit shopkeeper
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawborder(108,107,116,107,118,90,106,90);

    bagtobuy(25);

fm=1;
    drawcustomer(39+j,0);
delay(100900);
glFlush();}
//takes the bag

for(j=0;j<32;j++)
{ glClear(GL_COLOR_BUFFER_BIT);
    disp();
    drawman(20,6,-5);
    drawtable();
    glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);//bag wit shopkeeper
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawborder(108,107,116,107,118,90,106,90);

    bagtobuy(25);
fm=0;
    drawcustomer(50,j);
delay(100900);
glFlush();}
//bring bag and hand down

printf("done");
for(j=0;j<12;j++)
{ glClear(GL_COLOR_BUFFER_BIT);
    disp();
    drawman(20,6,-5);
    drawtable();
    glColor3f(1.0,0.0,0.0);
    four_vertex(108,107,116,107,118,90,106,90);//bag wit shopkeeper
    glColor3f(0.0,0.0,0.0);
    three_vertex(118,90,119,92,116,107);
    glLineWidth(4.0);
    handle(108,107,112,111,116,107);
    glColor3f(1.0,0.6,0.2);
    handle(108,107,112,98,116,107);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawborder(108,107,116,107,118,90,106,90);

    bagtobuy(25+j);
fm=0;
    drawcustomer(50,32-j);
delay(100900);
glFlush();}

}
void dispcust(int i)
{
    if(h1==0)
    fh1=0;
    if(l1==0)
    fl1=0;

if(l1<10&&fl1==0)
     {glColor3f(0.0,0.0,0.0);
    four_vertex(228-i+l1,30,235-i+l1,30,234-i+l1,35,231-i+l1,35);//left sh1oe
    four_vertex(237-i-l1,29,245-i-l1,29,244-i-l1,34,241-i-l1,34);//righ1t sh1oe
    glColor3f(0.0,0.0,0.2);
    four_vertex(231-i+l1,35,234-i+l1,35,239-i,72,233-i,72);//l1eft leg
    glColor3f(0.0,0.0,0.4);
    four_vertex(234-i,72,242-i,72,244-i-l1,34,241-i-l1,34);//righ1t leg
     if(mov==1)l1++;}
     if(l1==10)
     fl1=1;
     if(fl1==1)
      {glColor3f(0.0,0.0,0.0);
    four_vertex(228-i+l1,30,235-i+l1,30,234-i+l1,35,231-i+l1,35);//left sh1oe
    four_vertex(237-i-l1,29,245-i-l1,29,244-i-l1,34,241-i-l1,34);//righ1t sh1oe
    glColor3f(0.0,0.0,0.2);
    four_vertex(231-i+l1,35,234-i+l1,35,239-i,72,233-i,72);//l1eft leg
    glColor3f(0.0,0.0,0.4);
    four_vertex(234-i,72,242-i,72,244-i-l1,34,241-i-l1,34);//righ1t leg
     if(mov==1)
     l1--;}
if(h1<15&&fh1==0)
{
     glColor3f(0.6,0.6,0.8);
    four_vertex(234-i,96,236-i,90,232-i+h1,77,229-i+h1,77);//left hand
    glColor3f(1.0,0.8,0.6);
    six_vertex(229-i+h1,77,232-i+h1,77,232-i+h1,76,231-i+h1,74,230-i+h1,74,229-i+h1,76);//left palm
}
if(fh1==1)
{
     glColor3f(0.6,0.6,0.8);
    four_vertex(234-i,96,236-i,90,232-i+h1,77,229-i+h1,77);//left hand
    glColor3f(1.0,0.8,0.6);
    six_vertex(229-i+h1,77,232-i+h1,77,232-i+h1,76,231-i+h1,74,230-i+h1,74,229-i+h1,76);//left palm
}
    glColor3f(0.6,0.6,0.8);
    four_vertex(232-i,72,243-i,72,240-i,96,234-i,96);//body
    glColor3f(1.0,0.8,0.6);
    drawCircle1(0,360,237-i,107,4,9);//face
    //four_vertex(17,96,19,96,19,99,17,99);//neck
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    handle(234.5-i,110,235.5-i,111,237.5-i,110);//left eye brow
    handle(239-i,110,240-i,111,241-i,111);//right eye brow
    handle(237-i,108,236-i,106,237-i,105);//nose
    //handle(14-i,108,14-i,106,15-i,106);
    three_vertex(238-i,103,237-i,101,235-i,102);//mouth
    glLineWidth(4.0);
    two_vertex(235-i,109,235-i,108);//left eye
    two_vertex(239-i,107,239-i,108);//right eye
    //two_vertex(20,114,12,114);//hair
    drawCircle1(0,180,238-i,113,3,5);//hair
    drawCircle1(0,185,236-i,113,3,5);//hair
    three_vertex(237-i,114,241-i,114,242-i,107);//hair
    six_vertex(234-i,96,240-i,96,239-i,98,239-i,99,236-i,99,236-i,98);//neck+upper body
if(h1<15&&fh1==0)
{glColor3f(0.6,0.6,0.8);
    four_vertex(240-i,96,241-i,86,244-i-h1,78,247-i-h1,78);//right hAND-hand at back side

    glColor3f(1.0,0.8,0.6);
    six_vertex(244-i-h1,78,247-i-h1,78,247-i-h1,77,246-i-h1,75,245-i-h1,75,244-i-h1,77);//right -bak side palm
if(mov==1)
    h1++;
 }
 if(h1==15)
 fh1=1;
 if(fh1==1)
 {glColor3f(0.6,0.6,0.8);
    four_vertex(240-i,96,241-i,86,244-i-h1,78,247-i-h1,78);//right hAND-hand at back side

    glColor3f(1.0,0.8,0.6);
    six_vertex(244-i-h1,78,247-i-h1,78,247-i-h1,77,246-i-h1,75,245-i-h1,75,244-i-h1,77);//right -bak side palm
if(mov==1)
    h1--;

 }

}
void iceglass(int g)
{
    glLineWidth(1.0);
    glColor3f(0.0,0.0,0.0);
    drawborder(94+90,89,98+90,89,98+90,102,94+90,102);//glass
        glColor3f(1.0,1.0,1.0);
        glRecti(185,111,186,100+g);
	    four_vertex(94+90,89,98+90,89,98+90,90+g,94+90,90+g);//glass
}
void glassfill(int i)
{if(mov_hand==0&&drink==0)
        {glColor3f(0.0,0.0,1.0);
    glLineWidth(4.0);
    glRecti(99,111,100,90+2*i);
    //two_vertex(100,111-i,100,90-i);//juice
glRecti(102,90,98,92+i);}
  //  two}
  //vertex(102,90+i,98,90+i);}
  //in d glass, juice
if(mov_hand==1&&drink==0){
glColor3f(0.0,0.0,1.0);
    glLineWidth(4.0);
    //glRecti(99-i,111,100-i,90+3*7);
    //two_vertex(100,111-i,100,90-i);//juice
glRecti(102-i,90,98-i,92+10);}
  //  two}vertex(102,90+i,98,90+i);
if(drink==1)
{
glColor3f(1.0,1.0,1.0);
    glLineWidth(4.0);
    //glRecti(99-i,111,100-i,90+3*7);
    //two_vertex(100,111-i,100,90-i);//juice
glRecti(102-11,102-i/2,98-11,92+10);
}
}
void screen_juice(int i,int j,int k)
{
  // glClear(GL_COLOR_BUFFER_BIT);

glClearColor(1.0,1.0,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
    bagshopdraw();
    glColor3f(0.0,0.0,0.0);
    four_vertex(60,190,190,190,190,230,60,230);//board
    glLineWidth(4.0);
two_vertex(70,230,65,240);//hanging the board
two_vertex(180,230,185,240);
glColor3f(1.0,0.0,0.0);
//disp11(105,210,"FANCY BAG SHOP",3);
disp11(105,210,"LIME JUICE SHOP",1);
drawborder(65,195,185,195,185,225,65,225);//inner border
drawborder(60,190,190,190,190,230,60,230);//outer border
    //shelfdraw();
    //drawbags();



drawman(i,j,k);

    // drawcustomer();
     drawtable();
     drawmachine(4);

     drawmachine(90);
     //drawglass(90);
glColor3f(0.8,0.8,0.8);
    glRecti(10,210,30,225);
    glLineWidth(1.5);
    glColor3f(0.0,0.0,0.0);
    two_vertex(10,210,30,210);
    two_vertex(30,210,30,225);
    two_vertex(30,225,10,225);
    two_vertex(10,225,10,210);
    disp11(15,217,"BACK",1);
     //to draw the extra handle of gola machine
     glColor3f(0.0,0.0,0.0);
     glLineWidth(4.0);
     handle(187,116,187,120,191,121);
     //to draw bottle

     //glColor3f(1.0,0.0,0.0);
    drawbottle(0,1.0, 0.6, 0.0);
    //glColor3f(0.0,1.0,0.0);
    drawbottle(7,0.2, 1.0, 0.2);
    drawbottle(14,0.2, 0.0, 0.0);
    drawbottle(21,0.8, 0.0, 0.2);
//dustbin

     //dglFlush();//drawglass(4);
    glFlush();
    }
void juicescreen()
{mov=1;
    h1=l1=0;
mov_hand=0;
    for(j=0;j<70;j++)
    {
            delay(60900);

         screen_juice(0,0,0);
    drawcustomer(j,0);
drawglass(4);
    fm=1;
    glFlush();
}
for(j=0;j<8;j++)
{delay(100);
    screen_juice(0,0,0);
drawglass(80900);
drawglass(4);
    fm=0;

    glassfill(j);
    drawcustomer(69,0);
    glFlush();
}
for(j=0;j<12;j++)
{
    delay(80900);
    screen_juice(0,0,0);
drawglass(90);
drawglass(4);
    fm=0;

    glassfill(10);
    drawcustomer(69,j);
glFlush();
}
for(j=0;j<7;j++)
{delay(80900);
screen_juice(0,0,0);
drawglass(90);
//drawglass(4-j);
    mov_hand=1;

// drawglass(4-j);
  drawcustomer(69,j);
glassfill(4+j);
    fm=0;

   // drawcustomer(69,j);
   glFlush();

}
//customer 2
for(j=0;j<20;j++)
{delay(80900);
screen_juice(0,0,0);
drawglass(90);
    drawbottle(0,1.0, 0.6, 0.0);

  drawcustomer(69,7);
glassfill(4+7);
dispcust(j);
    fm=0;
   glFlush();

}
mov=0;

for(j=0;j<88;j++)
{delay(80900);
screen_juice(-j,0,0);
drawglass(90);
    drawbottle(0,1.0, 0.6, 0.0);

  drawcustomer(69,7);
glassfill(4+7);
dispcust(20);
    fm=0;
   glFlush();

}
//make hand up
for(j=0;j<15;j++)
{delay(30900);
screen_juice(-88,0,j);
drawglass(90);
    drawbottle(0,1.0, 0.6, 0.0);

  drawcustomer(69,7);
glassfill(4+7);
dispcust(20);
    fm=0;
   glFlush();

}
for(j=0;j<12;j++)
{delay(300900);
screen_juice(-88,0,15);
drawglass(90);
   drawbottle(0,1.0, 0.6, 0.0);

  drawcustomer(69,7);
glassfill(4+7);
dispcust(20);
iceglass(j);
    fm=0;
   glFlush();

}
mov1=1;

mov1=0;
}


void pillar2(int x)
{
glColor3f(0.658824,0.658824,0.658824);
glRecti(x,70,x+30,170);
          glColor3f(1.0,1.0,1.0);
          glRecti(x,166,x+30,169);
          glRecti(x,116,x+30,119);
          glColor3f(0.858824,0.858824,0.434216);
          glRecti(x,169,x+30,170);
          glRecti(x,165,x+30,166);
          six_vertex(67,170,60,150,62,150,67,167,72,150,74,150);
          six_vertex(167,170,160,150,162,150,167,167,172,150,174,150);
six_vertex(181,170,174,150,176,150,181,167,186,150,188,150);
six_vertex(81,170,74,150,76,150,81,167,86,150,88,150);
glRecti(x,119,x+30,120);
glRecti(x,115,x+30,116);
glColor3f(0.329412,0.329412,0.329412);
      glBegin(GL_POLYGON);
         glVertex2i(x+5,70);
          glVertex2i(x+5,90);
          glVertex2i(x+10,100);
          glVertex2i(x+15,90);
          glVertex2i(x+15,70);
          glEnd();
}
void pillar1(int x,int d)
{    glColor3f(0.658824,0.658824,0.658824);
       glBegin(GL_POLYGON);
          glVertex2i(x,150);
              glColor3f(0.8,0.8,0.8);//
          glVertex2i(x+d,145);
          glVertex2i(x+d,75);
              glColor3f(0.658824,0.658824,0.658824);//
          glVertex2i(x,70);

          glEnd();
  glColor3f(0.858824,0.858824,0.434216);
          four_vertex(x,150,x+d,145,x+d,144,x,149);
          four_vertex(x,146,x+d,141,x+d,140,x,145);
    glColor3f(1.0,1.0,1.0);
          four_vertex(x,146,x,149,x+d,145,x+d,141);
                    glColor3f(0.858824,0.858824,0.434216);
                    glBegin(GL_POLYGON);
          glVertex2i(x+d/2,140);
          glVertex2i(x+(d/2+5),115);
          glVertex2i(x+(d/2+3),115);
          glVertex2i(x+d/2,137);
          glVertex2i(x+(d/2-5),115);
          glVertex2i(x+(d/2-7),115);
          glEnd();

           glColor3f(0.52,0.37,0.26);
           four_vertex(x+d/4,70,x+d/4,100,x+(3*d)/4,100,x+(3*d)/4,73);

            glColor3f(1.0,1.0,1.0);
            glRecti(205,73,207,100);
                   glRecti(195,70,197,100);
 glBegin(GL_POLYGON);
           glVertex2i(x+d/2,110);
          glVertex2i(x+(d/2+5),100);
          glVertex2i(x+(d/2+7),100);
          glVertex2i((x+d/2),113);
           glVertex2i(x+(d/2-5),100);
          glVertex2i(x+(d/2-3),100);
          glEnd();
}

void pillar3(int x,int y,int d)
{

       glColor3f( 0.658824 ,0.658824 ,0.658824);
                        glBegin(GL_POLYGON);
          glVertex2i(x,200);
                 glColor3f( 1.0 ,1.0 ,1.0);

glVertex2f(x+d/3,195);
glVertex2f(x+d/3,y);
       glColor3f( 0.658824 ,0.652941 ,0.652941);

glVertex2f(x,y);
 glEnd();
 glColor3f( 0.658824 ,0.658824 ,0.658824);
                        glBegin(GL_POLYGON);
          glVertex2i(x,200);
                 glColor3f( 1.0 ,1.0 ,1.0);

glVertex2f(x+d/3,195);
       glColor3f( 0.8,0.8,0.8);

glVertex2f(x+(2*d/3),195);
 glColor3f( 0.658824 ,0.658824 ,0.658824);
          glVertex2i(x+d,200);
                 glColor3f( 1.0 ,1.0 ,1.0);

glVertex2f(x+d/2,230);
 glEnd();
   glColor3f( 1.0 ,1.0 ,1.0);
 glBegin(GL_POLYGON);
          glVertex2i(x+d/3,195);
          glColor3f( 0.8 ,0.8 ,0.8);
glVertex2f(x+2*d/3,195);
glVertex2f(x+2*d/3,y);
   glColor3f( 1.0 ,1.0 ,1.0);
glVertex2f(x+d/3,y);
 glEnd();

   glColor3f( 0.8 ,0.8 ,0.8);
                   glBegin(GL_POLYGON);
          glVertex2i(x+2*d/3,195);
          glVertex2f(x+2*d/3,y);
           glColor3f( 0.658824 ,0.652941 ,0.652941);
glVertex2f(x+d,y);
glVertex2f(x+d,200);
 glEnd();
 glColor3f(0.858824,0.858824,0.434216);
 glRecti(x,159,x+d,160);
 glRecti(x,164,x+d,165);
      glRecti(x,135,x+d,136);
           glRecti(x,130,x+d,131);
                              glRecti(x+d/2-1,228,x+d/2+1,250);
 glRecti(x+d/3-1,240,x+2*d/3+2,243);
}


void church()
{
    glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0,0.0,0.1,1.0);
no_of_windows=3;
    glColor3f(0.137255,0.137255 ,0.556863);
        glBegin(GL_POLYGON);

          glVertex2i(250,250);
          glColor3f( 0.22,0.69 ,0.87);
          glVertex2i(250,70);
          glVertex2i(0,70);

glColor3f(0.137255,0.137255 ,0.556863);

          glVertex2i(0,250);
          glEnd();
          glColor3f(0.0,0.0, 0.0);
          four_vertex(110,70,140,70,150,25,100,25);
             four_vertex(150,25,160,0,90,0,100,25);
          glBegin(GL_POLYGON);
          glColor3f( 0.0,0.55,0.0);
    glVertex2i(0,70);
          glVertex2i(110,70);
          glColor3f(0.258824,0.435294,0.258824);
          glVertex2i(100,25);
          glVertex2i(90,0);
          glColor3f( 0.0,0.55,0.0);
                    glVertex2i(0,0);

          glEnd();
          glBegin(GL_POLYGON);
    glVertex2i(250,70);
          glVertex2i(140,70);
          glColor3f(0.258824,0.435294,0.258824);
          glVertex2i(150,25);
          glVertex2i(160,0);
                    glColor3f( 0.0,0.55,0.0);

                    glVertex2i(250,0);

          glEnd();


drawTree(90,40);
drawTree(150,40);
drawTree(80,20);
drawTree(160,20);
          glColor3f(1.0,1.0,1.0);
six_vertex(110,70,100,25,90,0,87,0,97,25,107,70);
 six_vertex(140,70,150,25,160,0,163,0,153,25,143,70);
  glBegin(GL_POLYGON);
                    glVertex2i(140,70);
          glVertex2i(150,25);
          glVertex2i(160,0);
          glVertex2i(163,0);
          glVertex2i(153,25);
          glVertex2i(143,70);
glEnd();
pillar3(90,70,20);
pillar3(140,70,20);
          glColor3f(0.658824,0.658824,0.658824);
             glBegin(GL_POLYGON);
    glVertex2i(110,70);
          glVertex2i(110,180);
          glVertex2i(125,210);
          glVertex2i(140,180);
          glVertex2i(140,70);
          glEnd();
              glColor3f(0.8,0.8,0.8);

drawCircle1(0,360,125,150,8,8);
               pillar2(60);
               pillar2(160);



glColor3f(0.52,0.37,0.26);
         glRecti(120,70,130,100);
          glColor3f(1.0,1.0,1.0);
          four_vertex(125,113,125,110,118,100,120,100);

     glRecti(118,70,120,100);

     four_vertex(125,113,125,110,130,100,132,100);

     glRecti(130,70,132,100);
                  glRecti(110,129,140,130);
glRecti(110,134,140,135);
          glColor3f(0.329412,0.329412,0.329412);
                    glBegin(GL_POLYGON);
         glVertex2i(125,113);
          glVertex2i(118,100);
          glVertex2i(118,110);
          glVertex2i(125,125);
glVertex2i(132,110);
glVertex2i(132,100);
          glEnd();
glColor3f(0.858924,0.858924,0.434216);
          glBegin(GL_POLYGON);
         glVertex2i(125,125);
          glVertex2i(132,110);
          glVertex2i(134,110);
          glVertex2i(125,128);
          glVertex2i(116,110);
          glVertex2i(118,110);

          glEnd();
          glRecti(124,127,126,146);
          glRecti(120,138,130,140);
          glRecti(110,128,140,129);
    glRecti(110,135,140,136);
glColor3f(0.80,0.80,0.80);
glRecti(114,70,118,117);
glRecti(132,70,136,117);

          glColor3f(1.0,1.0,1.0);
             glBegin(GL_POLYGON);
          glVertex2i(118,117);
          glVertex2i(114,117);
          glVertex2i(116,132);

          glEnd();
             glBegin(GL_POLYGON);
          glVertex2i(132,117);
          glVertex2i(136,117);
          glVertex2i(134,132);

          glEnd();
          glColor3f(0.858824,0.858824,0.434216);
                      glRecti(112,136,117,156);
                      glRecti(132,136,137,156);
          glColor3f(1.0,1.0,1.0);
                         glBegin(GL_POLYGON);
          glVertex2i(125,166);
          glVertex2i(117,156);
          glVertex2i(112,156);
glVertex2f(125,176);
glVertex2f(137,156);
glVertex2f(132,156);
          glEnd();
glColor3f(0.858824,0.858824,0.434216);
six_vertex(112,120,114,115,113,115,112,119,111,115,110,115);
      six_vertex(138,120,140,115,139,115,138,119,137,115,136,115);
glColor3f(0.8,0.8,0.8);
           glBegin(GL_POLYGON);

          glVertex2i(110,95);
          glVertex2i(112,105);
          glVertex2i(114,95);
glVertex2i(114,70);
glVertex2i(110,70);
          glEnd();
          glBegin(GL_POLYGON);
          glVertex2i(136,95);
          glVertex2i(138,105);
          glVertex2i(140,95);
glVertex2i(140,70);
glVertex2i(136,70);
          glEnd();

                    glColor3f(0.329412, 0.329412,  0.329412);
                    glBegin(GL_POLYGON);
          glVertex2i(125,176);
glVertex2f(137,156);
glVertex2f(140,156);
glVertex2f(140,180);
          glVertex2i(125,210);
glVertex2f(110,180);
glVertex2f(110,156);
glVertex2f(112,156);

          glEnd();

   glColor3f(0.858824,0.858824,0.434216);
   six_vertex(125,210,140,180,140,183,125,213,110,183,110,180);

pillar1(60,-20);
pillar1(190,20);
glColor3f(0.858824,0.858824,0.434216);

six_vertex(42,120,44,115,43,115,42,119,41,115,40,115);
six_vertex(192,120,194,115,193,115,192,119,191,115,190,115);
six_vertex(57,120,59,115,58,115,57,119,56,115,55,115);
six_vertex(207,120,209,115,208,115,207,119,206,115,205,115);
glColor3f(0.8,0.8,0.8);
    glRecti(10,210,30,225);
    glLineWidth(1.5);
    glColor3f(0.0,0.0,0.0);
    two_vertex(10,210,30,210);
    two_vertex(30,210,30,225);
    two_vertex(30,225,10,225);
    two_vertex(10,225,10,210);
    disp11(15,217,"BACK",1);
    glFlush();
}
void map()
{
glClearColor(0.2,0.6,0.6,0.0);

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.8,0.8,0.8);
    glRecti(10,210,30,225);
    glLineWidth(1.5);
    glColor3f(0.0,0.0,0.0);
    two_vertex(10,210,30,210);
    two_vertex(30,210,30,225);
    two_vertex(30,225,10,225);
    two_vertex(10,225,10,210);
    disp11(15,217,"BACK",1);

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(125,230);
        glVertex2f(158,203);
    glVertex2f(158,147);
    glVertex2f(92,147);
    glVertex2f(92,203);
glEnd();
      glColor3f(0.0,0.0,0.0);
    glLineWidth(4.0);
    two_vertex(125,230,158,203);//outline
    two_vertex(158,203,158,147);
    two_vertex(92,203,92,147);
    two_vertex(92,203,125,230);
two_vertex(125,230,125,240);
two_vertex(120,235,130,235);
glColor3f(0.0,1.0,1.0);//1st shop right to church
four_vertex(170,147,170,200,226,200,226,147);
glColor3f(0.0,0.0,0.0);

    two_vertex(170,147,170,200);
two_vertex(170,200,226,200);
two_vertex(226,200,226,147);
glColor3f(0.0,0.0,1.0);
//1st shop left to church
four_vertex(80,147,80,200,24,200,24,147);

glColor3f(0.0,0.0,0.0);
    two_vertex(80,147,80,200);
two_vertex(80,200,24,200);
two_vertex(24,200,24,147);
glColor3f(0.8,0.8,0.8);
four_vertex(0,147,250,147,250,130,0,130);//straight road
four_vertex(118,130,132,130,132,0,118,0);
four_vertex(132,80,250,80,250,70,132,70);//small road
glColor3f(0.0,0.0,0.0);
two_vertex(118,130,118,0);
two_vertex(132,130,132,80);
two_vertex(132,70,132,0);
two_vertex(0,147,250,147);
two_vertex(0,130,118,130);
two_vertex(132,130,250,130);
two_vertex(132,80,250,80);
two_vertex(132,70,250,70);
glColor3f(1.0,1.0,0.0);
four_vertex(140,90,165,90,165,120,140,120);//right shop1
four_vertex(85,80,110,80,110,120,85,120);//left shop1
//four_vertex(85,30,110,30,110,70,85,70);//left shop2
glColor3f(0.0,0.0,0.0);//outline right shop 1
two_vertex(140,90,165,90);
two_vertex(165,90,165,120);
two_vertex(165,120,140,120);
two_vertex(140,120,140,90);
glColor3f(1.0,1.0,0.0);
four_vertex(140,30,165,30,165,60,140,60);//right shop 2
glColor3f(0.0,0.0,0.0);//outline right shop 2
two_vertex(140,30,165,30);
two_vertex(165,30,165,60);
two_vertex(165,60,140,60);
two_vertex(140,60,140,30);
two_vertex(85,80,110,80);//outline left shop1
two_vertex(110,80,110,120);
two_vertex(110,120,85,120);
two_vertex(85,120,85,80);
/*two_vertex(85,30,110,30);//outline left shop2
two_vertex(110,30,110,70);
two_vertex(110,70,85,70);
two_vertex(85,70,85,30);*/
glColor3f(1.0,1.0,0.0);
four_vertex(116,175,134,175,134,147,116,147);//door
glColor3f(0.0,0.0,0.0);
two_vertex(116,175,134,175);//outline left shop2
two_vertex(134,175,134,147);
two_vertex(116,175,116,147);
glColor3f(1.0,0.0,0.0);
two_vertex(130,75,145,75);
two_vertex(145,75,143,78);
two_vertex(145,75,143,72);
//disp11(150,73,"RIDES",3);
//disp11(87,48,"DRESS SHOP",3);
disp11(92,98,"GAMES",3);
disp11(143,103,"JUICE SHOP",3);
disp11(143,43,"KIDS' TOYS",3);
disp11(184,172,"ICECREAM SHOP",3);
disp11(43,172,"BAG SHOP",3);
glFlush();
}

void entrance(int x)
{
pillar3(x,0,15);
glColor3f(0.858824,0.858824,0.434216);
 glRecti(x,40,x+15,41);
 glRecti(x,45,x+15,46);
glRecti(x,125,x+15,126);
glRecti(x,120,x+15,121);
glRecti(x+6,228,x+8,250);
 glRecti(x+2,240,x+14,243);
 glColor3f(1.0,1.0,1.0);
 glRecti(x,41,x+15,45);
 glRecti(x,121,x+15,125);


glColor3f(0.329412,0.329412,0.329412);
glRecti(x-20,130,x+35,140);
 glColor3f(0.858824,0.858824,0.434216);
glRecti(x-20,138,x+35,140);
glRecti(x-20,130,x+35,132);
glColor3f(1.0,1.0,1.0);
//two_vertex(80,150,90,160);
}

void screen2()//first screen
{glClearColor(0.0,0.0,0.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);

no_of_windows=3;
entrance(65);
entrance(170);
 glColor3f(0.329412,0.329412,0.329412);
 drawCircle1(1,185,125,135,40,80);
 glColor3f(0.858824,0.858824,0.434216);
  drawCircle1(1,185,125,135,30,60);
glColor3f(0.0,0.0,0.0);
 drawCircle1(1,185,125,135,25,55);
 glLineWidth(4.0);
 glColor3f(0.8 ,0.8,0.8);
 four_vertex(20,120,20,140,40,140,40,120);//button for church
 glBegin(GL_POLYGON);
 glVertex2f(20,120);
  glVertex2f(20,140);
   glVertex2f(10,130);
   glEnd();


 four_vertex(210,120,210,140,230,140,230,120);//button for fair
  glBegin(GL_POLYGON);
 glVertex2f(230,120);
  glVertex2f(230,140);
   glVertex2f(240,130);
   glEnd();

 glColor3f(0.0,0.0,0.0);
disp11(20,130,"BACK",1);
disp11(220,130,"NEXT",1);


 glLineWidth(4.0);
 glColor3f(1.0,1.0,1.0);

 two_vertex(90,150,89,156);   //s
  two_vertex(90,150,91,155);
   two_vertex(91,155,92,150);
   // two_vertex(90,155,88,154);

     two_vertex(90,158,91,164);//t
      two_vertex(90,161,93,159);
       two_vertex(92,169,95,165);//l
        two_vertex(95,165,96,169);
         two_vertex(97,170,95,177);//a
          two_vertex(95,177,99,177);
           two_vertex(96,173,97,177);
two_vertex(100,179,97,182);//w
two_vertex(100,179,99,184);
two_vertex(99,184,102,184);
two_vertex(102,184,99,188);
two_vertex(100,190,103,186);//r
two_vertex(100,190,103,192);
two_vertex(103,192,102,188);

two_vertex(104,188,102,188);

two_vertex(103,195,105,190);//e
two_vertex(103,195,104,196); //e top line continue
two_vertex(104,196,105,197);//"
two_vertex(104,192,106,194);
two_vertex(105,190,107,193);
two_vertex(106,199,108,194);//n
two_vertex(106,199,110,197);
two_vertex(110,197,108,202);
two_vertex(109,203,111,198);//c
two_vertex(109,203,111,205);
two_vertex(113,200,111,198);
two_vertex(112,206,114,200);//e
two_vertex(112,206,114,208);
two_vertex(113,203,115,205);
two_vertex(114,200,116,202);
two_vertex(119,201,118,209);//c
two_vertex(118,209,120,210);
two_vertex(119,202,121,203);
two_vertex(121,211,122,203);//h
two_vertex(123,211,124,203);
two_vertex(121,207,124,207);
two_vertex(125,211,125,204);//u
two_vertex(125,204,127,204);
two_vertex(127,204,127,211);
two_vertex(128,203,129,211);//r
two_vertex(129,211,131,208);
two_vertex(131,208,128,207);
two_vertex(129,207,130,202);
two_vertex(131,202,132,209);//c
two_vertex(132,209,134,208);
two_vertex(131,202,133,201);
two_vertex(134,200,135,208);//h
two_vertex(136,199,137,207);
two_vertex(134,204,137,203);
//two_vertex(142,198,141,197);//comma
two_vertex(144,191,147,197);//k
two_vertex(146,194,148,194);
two_vertex(146,194,146,189);
two_vertex(146,188,150,190);//a
two_vertex(150,190,148,184);
two_vertex(148,189,149,186);


 two_vertex(149,183,152,186);//r
 two_vertex(152,186,152,183);
 two_vertex(152,183,150,185);
 two_vertex(151,185,150,181);

 two_vertex(150,179,154,182);//k
two_vertex(152,181,151,176);
two_vertex(152,181,154,179);
two_vertex(152,174,156,176);//a

two_vertex(156,176,154,170);
two_vertex(154,175,155,173);
two_vertex(154,169,158,172);//l
two_vertex(155,169,156,165);//l

two_vertex(156,164,160,163);//a
two_vertex(160,163,157,158);
two_vertex(158,164,159,160);
 glFlush();

}

void drawgameman(int p,float a,float b,float c)
{
    glColor3f(0.0,0.0,0.0);//head
    drawCircle1(0,360,50+p,105,7,12);
    glColor3f(a, b, c);//body
    four_vertex(40+p,60,60+p,60,60+p,93,40+p,93);
    //left leg
    glColor3f(0.0,0.0,0.0);
    four_vertex(40+p,60,40+p,18,48+p,18,51+p,60);
    //right leg
    four_vertex(49+p,60,52+p,18,60+p,18,60+p,60);
    glColor3f(0.2, 0.0, 0.0);
    glLineWidth(4.0);
    four_vertex(41+p,18,47+p,18,47+p,16,41+p,16);//left shoe
    four_vertex(53+p,18,59+p,18,59+p,16,53+p,16);//right shoe


}

void drawtarget(int i)
{

    glColor3f(0.2, 0.0, 0.6);
    drawCircle1(0,360,65+i,150,16,31);
    glColor3f(1.0,0.0,0.0);
    drawCircle1(0,360,65+i,150,15,30);
    glColor3f(0.2, 0.0, 0.6);
    drawCircle1(0,360,65+i,150,10,20);
    glColor3f(1.0,0.0,0.0);
    drawCircle1(0,360,65+i,150,5,10);
    glColor3f(0.2, 0.0, 0.6);
    drawCircle1(0,360,65+i,150,3,6);
}
void screen_games()
{
   glClear(GL_COLOR_BUFFER_BIT);

glClearColor(1.0,1.0,1.0,0.0);
//glClear(GL_COLOR_BUFFER_BIT);
   bagshopdraw();
   //drawman(-70,0,0);
glColor3f(1.0,0.0,0.0);
disp11(101,210,"            GAMES   ",1);
   //  drawcustomer();
     drawtable();
     drawtarget(0);
     drawtarget(58);
     //to draw the bowl
     //glColor3f(1.0,0.0,0.0);
     //four_vertex(45,78,50,78,52,82,43,82);

drawgameman(5,0.8, 0.2, 0.0);
drawgameman(62,0.8, 0.0, 0.2);

glColor3f(0.8,0.8,0.8);
    glRecti(10,210,30,225);
    glLineWidth(1.5);
    glColor3f(0.0,0.0,0.0);
    two_vertex(10,210,30,210);
    two_vertex(30,210,30,225);
    two_vertex(30,225,10,225);
    two_vertex(10,225,10,210);
    disp11(15,217,"BACK",1);



     glFlush();



    //glFlush();
    }



void arrowin(int ar)
{

    glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
screen_games();
    glColor3f(0.0,0.0,0.0);
    glLineWidth(4.0);
    two_vertex(62,105+ar,64,110+ar);
    three_vertex(63,111+ar,65,108+ar,65,113+ar);
    if(arr<40)
    glutTimerFunc(50,arrowin,arr++);
    glFlush();
}
void arrowout(int aot)
{
  glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
screen_games();
    glColor3f(0.0,0.0,0.0);
    glLineWidth(4.0);
    two_vertex(63,105+aot,66,110+aot);
    three_vertex(65,111+aot,67,108+aot,67,113+aot);

    if(ao<25)
    glutTimerFunc(50,arrowout,ao++);
    glFlush();
}

void dispgamescreen()
{
    glClearColor(1.0,1.0,1.0,1.0);
    screen_games();
    //arrow(0);

}

void mouse5(int btn,int state,int x,int y)
{
printf("\t%d\t%d",x,y);

    if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN )
{
   // windoswitch=1;
    //glutInitWindowPosition(0,0);
    //glutInitWindowSize(1350,1500);
  //rif(no_of_windows==2)
    if(x>=335&&x<=365&&y>=279&&y<=311)//actual x-563,717,y-786,861
          {glutDisplayFunc(screen_games);
          arrowin(0);
//glutMouseFunc(mouse_screen2);
//arrow(0);

      }
   else   if(x>=378&&x<=433 &&y>=227&&y<=367)
      {

          glutDisplayFunc(screen_games);
          arrowout(0);
      }




  else  if(x>=54&&x<=161&&y<=116&&y>=73)
         {  glutInitWindowPosition(0,0);
    glutInitWindowSize(1350,1500);
    glutDisplayFunc(map);
    glutMouseFunc(mouse_screen3);

}
//else if(x>=  && x<=    &&y<=   &&y>= )

   glFlush();
    glutSwapBuffers();
   }
   glutPostRedisplay();
}
void drawballoonkid(int i,int j)
{

if(l==0)
fl=0;
if(h==0)
fh=0;
if(h<10&&fh==0)
 {glColor3f(0.0,0.0,0.0);
    four_vertex(10+i+h,30,17+i+h,30,14+i+h,35,11+i+h,35);//left shoe
    four_vertex(21+i-h,34,24+i-h,34,27+i-h,29,20+i-h,29);//right shoe
    glColor3f(0.0,0.0,0.2);
    four_vertex(11+i+h,35,14+i+h,35,19+i,72,13+i,72);//left leg
    glColor3f(0.0,0.0,0.4);
    four_vertex(14+i,72,22+i,72,24+i-h,34,21+i-h,34);//right leg

    if(fm==1)
    h++;
 }
 if(h==10)
 fh=1;
 if(fh==1)
 {glColor3f(0.0,0.0,0.0);
    four_vertex(10+i+h,30,17+i+h,30,14+i+h,35,11+i+h,35);//left shoe
    four_vertex(21+i-h,34,24+i-h,34,27+i-h,29,20+i-h,29);//right shoe
    glColor3f(0.0,0.0,0.2);
    four_vertex(11+i+h,35,14+i+h,35,19+i,72,13+i,72);//left leg
    glColor3f(0.0,0.0,0.4);
    four_vertex(14+i,72,22+i,72,24+i-h,34,21+i-h,34);//right leg
    if(fm==1)
    h--;
 }
    if(l<15&&fl==0)
    {glColor3f(1.0,0.4,0.0);
            four_vertex(20+i,96,21+i,86,24+i-l,78,27+i-l,78);//right
//hAND-hand at back side
    glColor3f(1.0,0.8,0.6);

six_vertex(24+i-l,78,27+i-l,78,27+i-l,77,26+i-l,75,25+i-l,75,24+i-l,77);//right
//-bak side palm

    }
        if(fl==1)
    {glColor3f(1.0,0.4,0.0);

four_vertex(20+i,96,21+i,86,24+i-l+j/2,78+j,27+i-l+j/2,78+j);//right
//hAND-hand at back side
    glColor3f(1.0,0.8,0.6);

six_vertex(24+i-l,78,27+i-l,78+j,27+i-l,77+j,26+i-l,75,25+i-l,75,24+i-l,77);//right
//-bak side palm

    }

        glColor3f(1.0,0.6,0.2);

    four_vertex(12+i,72,23+i,72,20+i,96,14+i,96);//body
    glColor3f(1.0,0.8,0.6);
    drawCircle1(0,360,17+i,107,4,9);//face
    //four_vertex(17,96,19,96,19,99,17,99);//neck
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    handle(15+i,109,16+i,110,18+i,109);//left eye brow
    handle(19+i,110,20+i,111,21+i,111);//right eye brow
    handle(19+i,108,20+i,106,19+i,105);//nose
    handle(14+i,108,14+i,106,15+i,106);
    three_vertex(20+i,103,19+i,101,17+i,102);//mouth
    glLineWidth(4.0);
    two_vertex(17+i,107,17+i,108);//left eye
    two_vertex(20+i,109,20+i,108);//right eye
    //two_vertex(20,114,12,114);//hair
    drawCircle1(0,180,18+i,113,3,5);//hair
    drawCircle1(0,185,16+i,113,3,5);//hair
    three_vertex(12+i,114,17+i,114,13+i,107);//hair

six_vertex(14+i,96,20+i,96,19+i,98,19+i,99,16+i,99,16+i,98);//neck+upper
//body
    if(l<15&&fl==0&&j==0)
    {    glColor3f(1.0,0.4,0.0);

        four_vertex(14+i,96,16+i,90,12+i+l,77,9+i+l,77);//left hand

    glColor3f(1.0,0.8,0.6);

 six_vertex(9+i+l,77,12+i+l,77,12+i+l,76,11+i+l,74,10+i+l,74,9+i+l,76);//left
//palm
     //to draw balloon
     glColor3f(0.0,0.0,0.0);
     glLineWidth(1.0);

   two_vertex(10+i+l,74,10+i+l,150);
   glColor3f(1.0,0.0,0.0);
   drawCircle1(0,360,9+i+l,155,5,10);
   //glColor3f(1.0,0.0,0.0);
   three_vertex(4+i+l,155,14+i+l,155,10+i+l,135);

     if(fm==1)
     l++;
    }
    if(l==15)
    fl=1;
    if(fl==1&&j==0)
    {
         glColor3f(1.0,0.4,0.0);

        four_vertex(14+i,96,16+i,90,12+i+l-j,77,9+i+l-j,77);//left hand

    glColor3f(1.0,0.8,0.6);

 six_vertex(9+i+l-j,77,12+i+l-j,77,12+i+l-j,76,11+i+l-j,74,10+i+l-j,74,9+i+l-j,76);//left
//palm
     //to draw balloon
     glColor3f(0.0,0.0,0.0);
     glLineWidth(1.0);
   two_vertex(10+i+l-j,74,10+i+l,150);//thread
   glColor3f(1.0,0.0,0.0);
   drawCircle1(0,360,9+i+l,155,5,10);
   three_vertex(4+i+l,155,14+i+l,155,10+i+l,135);
   //glColor3f(1.0,0.0,0.0);
   //three_vertex(3+i+l,155,16+i+l,155,8+i+l,135);
     if(fm==1)
     l--;

    }
    //to make hand go up
if(j>0&&j<20&&mov_hand==0)
{
            glColor3f(1.0,0.4,0.0);


four_vertex(14+i,96,16+i,90,12+i+l+j*0.8,77+j,9+i+l+j*0.8,77+j);//left hand

    glColor3f(1.0,0.8,0.6);

 six_vertex(9+i+l+j*0.8,77+j,12+i+l+j*0.8,77+j,12+i+l+j*0.8,76+j,11+i+l+j*0.8,74+j,10+i+l+j*0.8,74+j,9+i+l+j*0.8,76+j);//left
//palm
glColor3f(1.0,0.0,0.0);
   //two_vertex(10+i+l+0.8*12-2*j,74+12,10+i+l+0.8*12-2*j,200);
  //two_vertex(10,24,10,120);
}
//to make hand movements
if(j>20&&mov_hand==0)
{
      glColor3f(1.0,0.4,0.0);


four_vertex(14+i,96,16+i,90,12+i+l+0.8*20,77+j,9+i+l+0.8*20,77+j);//left
//hand

    glColor3f(1.0,0.8,0.6);


 six_vertex(9+i+l+0.8*20,77+j,12+i+l+0.8*20,77+j,12+i+l+0.8*20,76+j,11+i+l+0.8*20,74+j,10+i+l+0.8*20,74+j,9+i+l+0.8*20,76+j);//left}

//glColor3f(1.0,0.0,0.0);
  // two_vertex(10+i+l+0.8*12-2*j,74+12,10+i+l+0.8*12-2*j,200);

}
if(mov_hand==1)
{
glColor3f(1.0,0.4,0.0);


four_vertex(14+i,96,16+i,90,12+i+l+0.8*12-2*j,77+12,9+i+l+0.8*12-2*j,77+12);//left
//hand

    glColor3f(1.0,0.8,0.6);

 six_vertex(9+i+l+0.8*12-2*j,77+12,12+i+l+0.8*12-2*j,77+12,12+i+l+0.8*12-2*j,76+12,11+i+l+0.8*12-2*j,74+12,10+i+l+0.8*12-2*j,74+12,9+i+l+0.8*12-2*j,76+12);//left
//palm
   //glColor3f(1.0,0.0,0.0);
   //two_vertex(10+i+l+0.8*12-2*j,74+12,10+i+l+0.8*12-2*j,200);
}
}
/*void balloonoption()
{

}*/
void drawup(int a,int b,int c)
{
    glColor3f(1.0,0.0,0.0);
    two_vertex(25+a,94,25+a,95+c);//thing which goes up
   //drawCircle1(0,360,25+a,94+a,2-a,3-a);
   two_vertex(25+a,95+c,26+a,94+c);

}
void drawdown(int a,int b,int c)
{
    glColor3f(1.0,0.0,0.0);
    two_vertex(25+a,94,25+a,95+20-c);//to come down
    two_vertex(25+a,95+20-c,26+a,94+20-c);
}
void dispkidscreen()
{   //glClear(GL_COLOR_BUFFER_BIT);
    //glClearColor(1.0,1.0,1.0,1.0);
    //kidscreen();
    glClearColor(1.0,1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.8,0.8,0.8);
        four_vertex(0,0,250,0,250,35,0,35);
        glBegin(GL_POLYGON);
        glColor3f(0.8, 0.8, 1.0);
        glVertex2i(0,250);
        //glColor3f(0.8, 0.8, 1.0);
        glVertex2i(250,250);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(250,35);
        glVertex2i(0,35);
        glEnd();
        glColor3f(0.8,0.8,0.8);
    glRecti(10,210,30,225);
    glLineWidth(1.5);
    glColor3f(0.0,0.0,0.0);
    two_vertex(10,210,30,210);
    two_vertex(30,210,30,225);
    two_vertex(30,225,10,225);
    two_vertex(10,225,10,210);
    disp11(15,217,"BACK",1);

    glColor3f(0.0, 0.4, 0.0);
    glRecti(200,210,220,225);
    glRecti(200,180,220,195);
    glLineWidth(1.5);
    glColor3f(0.0, 0.8, 0.2);
    drawborder(200,210,200,225,220,225,220,210);
    drawborder(200,180,220,180,220,195,200,195);
    disp11(202,217,"BALLOON",3);
    disp11(204,187,"TOY",3);

}

void kidscreenballoon()
{

  glClear(GL_COLOR_BUFFER_BIT);

glClearColor(1.0,1.0,1.0,0.0);
//dispkidscreen();
    //drawtable();
    for(j=0;j<260;j++)
    {
        glClearColor(1.0,1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.8,0.8,0.8);
        four_vertex(0,0,250,0,250,35,0,35);
        glBegin(GL_POLYGON);
        glColor3f(0.8, 0.8, 1.0);
        glVertex2i(0,250);
        //glColor3f(0.8, 0.8, 1.0);
        glVertex2i(250,250);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(250,35);
        glVertex2i(0,35);
        glEnd();
        glColor3f(0.8,0.8,0.8);
    glRecti(10,210,30,225);
    glLineWidth(1.5);
    glColor3f(0.0,0.0,0.0);
    two_vertex(10,210,30,210);
    two_vertex(30,210,30,225);
    two_vertex(30,225,10,225);
    two_vertex(10,225,10,210);
    disp11(15,217,"BACK",1);

    glColor3f(0.0, 0.4, 0.0);
    glRecti(200,210,220,225);
    glRecti(200,180,220,195);
    glLineWidth(1.5);
    glColor3f(0.0, 0.8, 0.2);
    drawborder(200,210,200,225,220,225,220,210);
    drawborder(200,180,220,180,220,195,200,195);
    disp11(202,217,"BALLOON",3);
    disp11(204,187,"TOY",3);
    drawballoonkid(j,0);

     //glLineWidth(1.5);

        //two_vertex(11+j,74,11+j,90);
        //glClear(GL_COLOR_BUFFER_BIT);
        delay(40300);
        glFlush();
    }
   // drawman(30,0,0);
    glFlush();
}

void drawkidwithtoy(int i,int j)
{

if(l==0)
fl=0;
if(h==0)
fh=0;
if(h<10&&fh==0)
 {glColor3f(0.0,0.0,0.0);
    four_vertex(10+i+h,30,17+i+h,30,14+i+h,35,11+i+h,35);//left shoe
    four_vertex(21+i-h,34,24+i-h,34,27+i-h,29,20+i-h,29);//right shoe
    glColor3f(0.0,0.0,0.2);
    four_vertex(11+i+h,35,14+i+h,35,19+i,72,13+i,72);//left leg
    glColor3f(0.0,0.0,0.4);
    four_vertex(14+i,72,22+i,72,24+i-h,34,21+i-h,34);//right leg
    glColor3f(0.8, 0.4, 0.0);
      four_vertex(14+i,96,17+i,96,18+i,84,15+i,84);//left hand
      four_vertex(18+i,84,17+i,87,21+i,94,25+i,94);//left hand lowerpart
      glColor3f(1.0,0.8,0.6);
      four_vertex(21+i,94,25+i,94,24+i,96,22+i,96);//left palm

      glColor3f(0.2, 0.0, 0.6);
         glLineWidth(4.0);
         two_vertex(25+i,94,19+i,102);//thing in his hand
         glColor3f(1.0,0.0,0.0);
         /*do{


         jk++;
         delay(100);
         //glFlush();
         }while(jk!=10);*/

        // two_vertex(25+i,94,25+i,95+i);//thing which goes up


    if(fm==1)
    h++;
 }
 if(h==10)
 fh=1;
 if(fh==1)
 {glColor3f(0.0,0.0,0.0);
    four_vertex(10+i+h,30,17+i+h,30,14+i+h,35,11+i+h,35);//left shoe
    four_vertex(21+i-h,34,24+i-h,34,27+i-h,29,20+i-h,29);//right shoe
    glColor3f(0.0,0.0,0.2);
    four_vertex(11+i+h,35,14+i+h,35,19+i,72,13+i,72);//left leg
    glColor3f(0.0,0.0,0.4);
    four_vertex(14+i,72,22+i,72,24+i-h,34,21+i-h,34);//right leg
    glColor3f(0.8, 0.4, 0.0);
       four_vertex(14+i,96,17+i,96,18+i,84,15+i,84);//left hand
       four_vertex(18+i,84,17+i,87,21+i,94,25+i,94);
        glColor3f(1.0,0.8,0.6);
       four_vertex(21+i,94,25+i,94,24+i,96,22+i,96);

       glColor3f(0.2, 0.0, 0.6);
         glLineWidth(4.0);
         two_vertex(25+i,94,19+i,102);
//two_vertex(25+59-i,94,25+59-i,95+59-i);//thing which goes up

    if(fm==1)
    h--;
 }
    /*if(l<15&&fl==0)
    {glColor3f(1.0,0.4,0.0);
            four_vertex(20+i,96,21+i,86,24+i-l,78,27+i-l,78);//right
hAND-hand at back side
    glColor3f(1.0,0.8,0.6);

six_vertex(24+i-l,78,27+i-l,78,27+i-l,77,26+i-l,75,25+i-l,75,24+i-l,77);//right
-bak side palm

    }
        if(fl==1)
    {glColor3f(1.0,0.4,0.0);

four_vertex(20+i,96,21+i,86,24+i-l+j/2,78+j,27+i-l+j/2,78+j);//right
hAND-hand at back side
    glColor3f(1.0,0.8,0.6);

six_vertex(24+i-l,78,27+i-l,78+j,27+i-l,77+j,26+i-l,75,25+i-l,75,24+i-l,77);//right
-bak side palm

    }*/

        glColor3f(1.0,0.6,0.2);

    four_vertex(12+i,72,23+i,72,20+i,96,14+i,96);//body
    glColor3f(1.0,0.8,0.6);
    drawCircle1(0,360,17+i,107,4,9);//face
    //four_vertex(17,96,19,96,19,99,17,99);//neck
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    handle(15+i,109,16+i,110,18+i,109);//left eye brow
    handle(19+i,110,20+i,111,21+i,111);//right eye brow
    handle(19+i,108,20+i,106,19+i,105);//nose
    handle(14+i,108,14+i,106,15+i,106);
    three_vertex(20+i,103,19+i,101,17+i,102);//mouth
    glLineWidth(4.0);
    two_vertex(17+i,107,17+i,108);//left eye
    two_vertex(20+i,109,20+i,108);//right eye
    //two_vertex(20,114,12,114);//hair
    drawCircle1(0,180,18+i,113,3,5);//hair
    drawCircle1(0,185,16+i,113,3,5);//hair
    three_vertex(12+i,114,17+i,114,13+i,107);//hair

six_vertex(14+i,96,20+i,96,19+i,98,19+i,99,16+i,99,16+i,98);//neck+upper
//body
    if(l<15&&fl==0&&j==0)
    {    glColor3f(0.8, 0.4, 0.0);
         four_vertex(14+i,96,17+i,96,18+i,84,15+i,84);//left hand
         four_vertex(18+i,84,17+i,87,21+i,94,25+i,94);

         glColor3f(1.0,0.8,0.6);
         four_vertex(21+i,94,25+i,94,24+i,96,22+i,96);//palm
         glColor3f(0.2, 0.0, 0.6);
         glLineWidth(4.0);
         two_vertex(25+i,94,19+i,102);
     if(fm==1)
     l++;
    }
    if(l==15)
    fl=1;
    if(fl==1&&j==0)
    {
       /*  glColor3f(1.0,0.4,0.0);

        four_vertex(14+i,96,16+i,90,12+i+l-j,77,9+i+l-j,77);//left hand

    glColor3f(1.0,0.8,0.6);

 six_vertex(9+i+l-j,77,12+i+l-j,77,12+i+l-j,76,11+i+l-j,74,10+i+l-j,74,9+i+l-j,76);//left
palm*/
     //to draw balloon
    /* glColor3f(0.0,0.0,0.0);
     glLineWidth(1.0);
   two_vertex(10+i+l-j,74,10+i+l,150);//thread
   glColor3f(1.0,0.0,0.0);
   drawCircle1(0,360,9+i+l,155,5,10);
   three_vertex(4+i+l,155,14+i+l,155,10+i+l,135);*/
   //glColor3f(1.0,0.0,0.0);
   //three_vertex(3+i+l,155,16+i+l,155,8+i+l,135);
   glColor3f(0.8, 0.4, 0.0);
     four_vertex(14+i,96,17+i,96,18+i,84,15+i,84);//left hand
     four_vertex(18+i,84,17+i,87,21+i,94,25+i,94);
     glColor3f(1.0,0.8,0.6);
     four_vertex(21+i,94,25+i,94,24+i,96,22+i,96);


     glColor3f(0.2, 0.0, 0.6);
         glLineWidth(4.0);
         two_vertex(25+i,94,19+i,102);
    //four_vertex(17+i,92,18+i,87,26+i,97,24+i,100);//left lower half
     if(fm==1)
     l--;

    }
    //to make hand go up
if(j>0&&j<20&&mov_hand==0)
{
            glColor3f(1.0,0.4,0.0);

       //
four_vertex(14+i,96,16+i,90,12+i+l+j*0.8,77+j,9+i+l+j*0.8,77+j);//left hand

    glColor3f(1.0,0.8,0.6);

 //six_vertex(9+i+l+j*0.8,77+j,12+i+l+j*0.8,77+j,12+i+l+j*0.8,76+j,11+i+l+j*0.8,74+j,10+i+l+j*0.8,74+j,9+i+l+j*0.8,76+j);//left
//palm
glColor3f(1.0,0.0,0.0);
   //two_vertex(10+i+l+0.8*12-2*j,74+12,10+i+l+0.8*12-2*j,200);
  //two_vertex(10,24,10,120);
}
//to make hand movements
if(j>20&&mov_hand==0)
{
      glColor3f(1.0,0.4,0.0);

       //
four_vertex(14+i,96,16+i,90,12+i+l+0.8*20,77+j,9+i+l+0.8*20,77+j);//left
//hand

    glColor3f(1.0,0.8,0.6);


 //six_vertex(9+i+l+0.8*20,77+j,12+i+l+0.8*20,77+j,12+i+l+0.8*20,76+j,11+i+l+0.8*20,74+j,10+i+l+0.8*20,74+j,9+i+l+0.8*20,76+j);//left
}

//glColor3f(1.0,0.0,0.0);
  // two_vertex(10+i+l+0.8*12-2*j,74+12,10+i+l+0.8*12-2*j,200);
if(mov_hand==1)
{
glColor3f(1.0,0.4,0.0);

       //
four_vertex(14+i,96,16+i,90,12+i+l+0.8*12-2*j,77+12,9+i+l+0.8*12-2*j,77+12);//left
//hand

    glColor3f(1.0,0.8,0.6);

 //six_vertex(9+i+l+0.8*12-2*j,77+12,12+i+l+0.8*12-2*j,77+12,12+i+l+0.8*12-2*j,76+12,11+i+l+0.8*12-2*j,74+12,10+i+l+0.8*12-2*j,74+12,9+i+l+0.8*12-2*j,76+12);//left
//palm

}
}
void kidscreentoy()
{

  glClear(GL_COLOR_BUFFER_BIT);

glClearColor(1.0,1.0,1.0,0.0);
//dispkidscreen();
    //drawtable();
    for(j=0;j<260;j++)
    {
        glClearColor(1.0,1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.8,0.8,0.8);
        four_vertex(0,0,250,0,250,35,0,35);
        glBegin(GL_POLYGON);
        glColor3f(0.8, 0.8, 1.0);
        glVertex2i(0,250);
        //glColor3f(0.8, 0.8, 1.0);
        glVertex2i(250,250);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(250,35);
        glVertex2i(0,35);
        glEnd();
        glColor3f(0.8,0.8,0.8);
    glRecti(10,210,30,225);
    glLineWidth(1.5);
    glColor3f(0.0,0.0,0.0);
    two_vertex(10,210,30,210);
    two_vertex(30,210,30,225);
    two_vertex(30,225,10,225);
    two_vertex(10,225,10,210);
    disp11(15,217,"BACK",1);

    glColor3f(0.0, 0.4, 0.0);
    glRecti(200,210,220,225);
    glRecti(200,180,220,195);
    glLineWidth(1.5);
    glColor3f(0.0, 0.8, 0.2);
    drawborder(200,210,200,225,220,225,220,210);
    drawborder(200,180,220,180,220,195,200,195);
    disp11(202,217,"BALLOON",3);
    disp11(204,187,"TOY",3);
    drawkidwithtoy(j,0);
        if(down==1)
        {
            u++;

        if(u<20)
        {
        drawup(j,0,u);
        }
        if(u==20)
        {glColor3f(1.0,0.0,0.0);
    two_vertex(25+j,94,25+j,95+20);
        down=0;
        u=0;
        }}
        else if(down==0)
        {
            u++;
            if(u<20)
        {
        drawdown(j,0,u);
    }
         if(u==20)
         {


            down=1;
            u=0;}
        }
        //two_vertex(11+j,74,11+j,90);
        //glClear(GL_COLOR_BUFFER_BIT);
        delay(30060);
        glFlush();
     //glLineWidth(1.5);

        //two_vertex(11+j,74,11+j,90);
        //glClear(GL_COLOR_BUFFER_BIT);

    }
   // drawman(30,0,0);
    glFlush();
}
/*void dispkidscreen()
{   //glClear(GL_COLOR_BUFFER_BIT);
    //glClearColor(1.0,1.0,1.0,1.0);
    //kidscreen();
    glClearColor(1.0,1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.8,0.8,0.8);
        four_vertex(0,0,250,0,250,35,0,35);
        glBegin(GL_POLYGON);
        glColor3f(0.8, 0.8, 1.0);
        glVertex2i(0,250);
        //glColor3f(0.8, 0.8, 1.0);
        glVertex2i(250,250);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(250,35);
        glVertex2i(0,35);
        glEnd();
        glColor3f(0.8,0.8,0.8);
    glRecti(10,210,30,225);
    glLineWidth(1.5);
    glColor3f(0.0,0.0,0.0);
    two_vertex(10,210,30,210);
    two_vertex(30,210,30,225);
    two_vertex(30,225,10,225);
    two_vertex(10,225,10,210);
    disp11(15,217,"BACK",1);

    glColor3f(0.0, 0.4, 0.0);
    glRecti(200,210,220,225);
    glRecti(200,180,220,195);
    glLineWidth(1.5);
    glColor3f(0.0, 0.8, 0.2);
    drawborder(200,210,200,225,220,225,220,210);
    drawborder(200,180,220,180,220,195,200,195);
    disp11(202,217,"BALLOON",3);
    disp11(202,187,"tintin",3);

}*/

void page1()
{//glutMouseFunc(mouse);
glClearColor(0.556863,0.137255,0.137255,0.0);
glClear(GL_COLOR_BUFFER_BIT);

 glColor3f(0.858824,0.858824,0.434216);
 glRecti(20,20,230,230);
 no_of_windows=2;
 glColor3f(0.556863,0.137255,0.137255);
    disp11(100,190,"WELCOME  TO  ATTUR  FAIR",1);
disp11(125,170,"BY,",3);
disp11(40,140,"VALISHA SHINY DSOUZA",3);
disp11(40,130,"4nm11cs139",3);
disp11(190,140,"VARSHA RAO M",3);
disp11(190,130,"4nm11cs140",3);
disp11(108,110,"UNDER THE GUIDANCE OF,",3);
disp11(110,100,"MR.PRADEEP KANCHAN",3);
disp11(85,80,"DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING",3);
disp11(92,70,"N.M.A.M INSTITUTE OF TECHNOLOGY, NITTE",3);
glColor3f(0.8, 0.8, 0.8);
 glRecti(110,25,140,45);
glColor3f(0.0,0.0,0.0);
glLineWidth(2.0);
two_vertex(110,25,140,25);
two_vertex(140,25,140,45);
two_vertex(140,45,110,45);
two_vertex(110,45,110,25);
disp11(117,35,"ENTER",1);
glFlush();}
void mouse4(int btn,int state,int x,int y)
{
printf("\t%d\t%d",x,y);
 if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN )
{
    windoswitch=1;
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1350,1500);

    if(x>=54&&x<=161&&y<=116&&y>=73)
         { glutDisplayFunc(map);
    glutMouseFunc(mouse_screen3);

}   glFlush();
    glutSwapBuffers();}
    glutPostRedisplay();
    }

void mouse_kidscreen(int btn,int state,int x,int y)
{
 printf("\n%d\t%d",x,y);
 if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN )
{
    windoswitch=1;
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1350,1500);


/*if(x>=335&&x<=365&&y>=279&&y<=311)//actual x-563,717,y-786,861
          {glutDisplayFunc(kidscreen);
          drawballoonkid(0);
//glutMouseFunc(mouse_screen2);
//arrow(0);

      }
   else   if(x>=378&&x<=433 &&y>=227&&y<=367)
      {

          glutDisplayFunc(screen_games);
          arrowout(0);
      }*/
       if(x>=54&&x<=161&&y<=116&&y>=73)
         { glutDisplayFunc(map);
    glutMouseFunc(mouse_screen3);
    }
else if(x>=1080 &&x<=1186&&y>=73&&y<=115)
{
    //dispkidscreen();
    kidscreenballoon();

}
else if(x>=1080 &&x<=1186&&y>=163&&y<=202)
{
    kidscreentoy();
}
else{}






}
glFlush();
    glutSwapBuffers();

    glutPostRedisplay();

}

void mouse_screen3(int btn,int state,int x,int y)
{
    printf("\n%d\t%d",x,y);
    if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN )
{
    windoswitch=1;
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1350,1500);

    if(x>=54&&x<=161&&y<=116&&y>=73)
         { glutDisplayFunc(screen2);
    glutMouseFunc(mouse_screen2);

}
else if(x>=495&&x<=852&&y>=116&&y<=300)
{glutDisplayFunc(church);
glutMouseFunc(mouse4);}
else if(x>=129&&x<=431&&y>=147&&y<=301)
{l=h=l1=h1=0;
fm=1;
mov_hand=0;
printf("djd");
    glutDisplayFunc(bagscreen);
glutMouseFunc(mouse4);}

if(x>=915&&x<=1219&&y<=300&&y>=148)
{openb=in=ih=icc1=lp1=ch1=fch1=mov_hand=l=h=0;
fm=1;
hand=0;
    glutDisplayFunc(disp_icecream);
    glutMouseFunc(mouse4);
}

else if(x>=755&&x<=889&&y<=469&&y>=386)
{
l=h=l1=h1=0;
fm=1;
mov_hand=0;
    glutDisplayFunc(juicescreen);
    glutMouseFunc(mouse4);
}
else if(x>=460 && x<=592  &&y<=503  &&y>=384 )
{
    glutDisplayFunc(dispgamescreen);
    glutMouseFunc(mouse5);
}
else if(x>=756&&  x<=889&&   y<=648 && y>=563  )
{
    l=h=l1=h1=0;
fm=1;
mov_hand=0;
    glutDisplayFunc(dispkidscreen);
    glutMouseFunc(mouse_kidscreen);
}

glFlush();
}
  //  glutSwapBuffers();}
    //glutPostRedisplay();
    }

void mouse_screen2(int btn,int state,int x,int y)
{
 if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN )
{
    windoswitch=1;
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1350,1500);

    if(x>=108&&x<=218&&y<=367&&y>=311)//x-102,203y-497,424
         { glutDisplayFunc(page1);
    glutMouseFunc(mouse);
      }

else
if(x>=1148&&x<=1257&&y<=367&&y>=311)//x-1078,1179y-496,423
{glutDisplayFunc(map);
glutMouseFunc(mouse_screen3);
 }   glFlush();
    glutSwapBuffers();
   }
   glutPostRedisplay();

}



void mouse(int btn,int state,int x,int y)
{


    if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN )
{
    windoswitch=1;
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1350,1500);
  if(no_of_windows==2)
    if(x>=600&&x<=766&&y<=631&&y>=579)//actual x-563,717,y-786,861
          {glutDisplayFunc(screen2);
glutMouseFunc(mouse_screen2);

      }

    glFlush();
    glutSwapBuffers();
   }
   glutPostRedisplay();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
glutInitWindowSize(1350,1500);
glutInitWindowPosition(0,25);
glutCreateWindow("ATTUR FAIR");
glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);


glutDisplayFunc(page1);

glutMouseFunc(mouse);
   glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
 glOrtho(0,250,0,250,0,1);
//glutKeyboardFunc(keyboard);


glutMainLoop();
return 0;
}
