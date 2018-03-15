#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int pntX, pntY, r1,r2,r3;

int X_3[3],Y_3[3],r_3[3],flag =1;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+pntX, y+pntY);
	glEnd();
}

void plot2(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+pntX, y+pntY);
	glEnd();
}

void plot3(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+pntX, y+pntY);
	glEnd();
}

void plot_off(int x, int y)
{
	glBegin(GL_POINTS);
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glVertex2i(x+pntX, y+pntY);
	glEnd();
}


void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void midPointCircleAlgo()
{
	int x = 0;
	int y = r1;
	float p = 5/4 - r1;
	plot(x, y);

	while (y > x)
	{
		if (p < 0)
		{
			x++; 
			p += 2*x+1;
		}
		else
		{
			y--;
			x++;
			p += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}
void midPointCircleAlgo2()
{
	int x = 0;
	int y = r2;
	float p = 5/4 - r2;
	plot2(x, y);

	while (y > x)
	{
		if (p < 0)
		{
			x++; 
			p += 2*x+1;
		}
		else
		{
			y--;
			x++;
			p += 2*(x-y)+1;
		}
		plot2(x, y);
		plot2(x, -y);
		plot2(-x, y);
		plot2(-x, -y);
		plot2(y, x);
		plot2(-y, x);
		plot2(y, -x);
		plot2(-y, -x);
	}

}
void midPointCircleAlgo3()
{
	int x = 0;
	int y = r3;
	float p = 5/4 - r3;
	plot3(x, y);

	while (y > x)
	{
		if (p < 0)
		{
			x++; 
			p += 2*x+1;
		}
		else
		{
			y--;
			x++;
			p += 2*(x-y)+1;
		}
		plot3(x, y);
		plot3(x, -y);
		plot3(-x, y);
		plot3(-x, -y);
		plot3(y, x);
		plot3(-y, x);
		plot3(y, -x);
		plot3(-y, -x);
	}

}

void midPointCircleAlgo_off()
{
	int x = 0;
	int y = r1;
	float p = 5/4 - r1;
	plot_off(x, y);

	while (y > x)
	{
		if (p < 0)
		{
			x++; 
			p += 2*x+1;
		}
		else
		{
			y--;
			x++;
			p += 2*(x-y)+1;
		}
		plot_off(x, y);
		plot_off(x, -y);
		plot_off(-x, y);
		plot_off(-x, -y);
		plot_off(y, x);
		plot_off(-y, x);
		plot_off(y, -x);
		plot_off(-y, -x);
	}

}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	midPointCircleAlgo();
	midPointCircleAlgo2();
	midPointCircleAlgo3();
	

	glFlush ();
	while(1)
	{
		int tempr=r2;
		//r1=r2;
		r2=r3;
		//cout << "\nEnter the radius of a new circle:  "; cin >> r3;
		r3=r3+20;
		flag++; 
		midPointCircleAlgo_off();
		printf("\nOld circle removed");
		//glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);
		midPointCircleAlgo3();
		glFlush ();
		printf("\nNew circle drawn");
		r1=tempr;
		//glFlush ();
		glutSwapBuffers();
		Sleep(500);
	}
	glFlush();
}

void main(int argc, char** argv)
{	
	cout << "\nEnter the coordinates and radius of the circle:\n\n" << endl;
	
	cout << "X-coordinate   : "; cin >> pntX;
	cout << "\nY-coordinate : "; cin >> pntY;
	cout << "1st radius   : "; cin >> r1;
	r2=r1+20;
	r3=r2+20;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Mid point circle drawing alogrithm");
	glutDisplayFunc(myDisplay);

	myInit ();
	glutMainLoop();

}