#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <math.h>
#include<stdlib.h>

#define ROUND(x) ((int)(x+0.5))
int xa,xb,ya,yb;

void display (void)
 {
	 int dx=xb-xa,dy=yb-ya,steps,k;				//dx and dy calculation
	 float xIncrement,yIncrement,x=xa,y=ya;
	 glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f (0.0, 1.0, 0.0);
	 if(abs(dx)>abs(dy))						//<45 deg
		steps=abs(dx);							
	 else steps=abs(dy);						//decision of no. of steps
	 xIncrement=dx/(float)steps;			
	 yIncrement=dy/(float)steps;				
	 glBegin(GL_POINTS);
	 glVertex2s(ROUND(x),ROUND(y));
	 for(k=0;k<steps;k++)
	 {
		 x+=xIncrement;
		 y+=yIncrement;
		 glVertex2s(ROUND(x),ROUND(y));
		 printf("x=%lf y=%lf\n",x,y);
	 }
	 glColor3f (1.0, 1.0, 1.0);
	 for(int i=-100 ; i<=100 ; i++)					//draw vertex
	 {
		 glVertex2s(i,0);
		 glVertex2s(0,i);
	 }
	 for(int i=-2; i<=2 ; i++)
	 {
		 glVertex2s(95+i,4+i);
		 glVertex2s(95-i,4+i);
	 }
	 for(int i=0; i<=2 ; i++)
	 {
		 glVertex2s(4+i,95+i);
		 glVertex2s(4-i,95+i);
		 glVertex2s(4,95-i);
	 }

	 glEnd();
	 glFlush();
	 }
void init(void)
{
	 glClearColor (0.0, 0.0, 0.0, 0.0);
	 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
 }

int main(int argc, char** argv)
{
	 printf("Enter the points\nx1 y1 x2 y2\n");
	 scanf("%d\t %d\t %d\t %d",&xa,&ya,&xb,&yb);
	 glutInit(&argc, argv);
	 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	 glutInitWindowSize (500, 500);
	 glutInitWindowPosition (100, 100);
	 glutCreateWindow ("Simple DDA ");
	 init();
	 glutDisplayFunc(display);
	 glutMainLoop();
	 return 0;
}