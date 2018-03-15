#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define PI 3.14159265

double X1, Y1, X2, Y2;
double theta;
void rotationAboutOriginByTheta(int x, int y){
        
        
        int x_=(int)(x*cos(theta)-y*sin(theta));
        int y_=(int)(x*sin(theta)+y*cos(theta));
        glVertex2d(x_, y_);
}

void Line_Bresenham(void){
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINES);
                glVertex2f(0,500);
                glVertex2f(0,-500);
                glVertex2f(500,0);
                glVertex2f(-500,0);
        glEnd();

        glBegin(GL_POINTS);
        int dx=X2-X1;
        int dy=Y2-Y1;
        
        int Xk=X1;
        int Yk=Y1;
        rotationAboutOriginByTheta(X1,Y1);
        int* p = new int[dx+1];
        p[0]=2*dy-dx;
        for(int k=0;k<dx;k++){
                if(p[k]>0){
                        Xk=Xk+1;
                        Yk=Yk+1;
                        
                        rotationAboutOriginByTheta(Xk,Yk);
                        p[k+1]=p[k]-2*dx+2*dy;

                }
                else{
                        Xk=Xk+1;
                        Yk=Yk;
                        
                        rotationAboutOriginByTheta(Xk,Yk);
                        p[k+1]=p[k]+2*dy;
                }
        }
        glEnd();
        glFlush();
}

void Init()
{
  // Set clear color to white
  glClearColor(0.0,0.0,0.0,0);
  // Set fill color to black
  glColor3f(1.0,1.0,1.0);
  //glViewport(0 , 0 , 500 , 500);
  // glMatrixMode(GL_PROJECTION);
  // glLoadIdentity();
  gluOrtho2D(-500 , 500 , -500 , 500);
}

void main(int argc, char **argv)
{
  printf("Enter two end points of the line to be drawn:\n");
  printf("\n************************************");
  printf("\nEnter Point1( X1 , Y1):\n");
  scanf("%lf%lf",&X1,&Y1);
  printf("\n************************************");
  printf("\nEnter Point1( X2 , Y2):\n");
  scanf("%lf%lf",&X2,&Y2);
  printf("\nEnter theta:\n");
  scanf("%lf",&theta);
  
  theta=theta*PI / 180.0;
  
  // Initialise GLUT library
  glutInit(&argc,argv);
  // Set the initial display mode
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  // Set the initial window position and size
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  // Create the window with title "DDA_Line"
  glutCreateWindow("Line_Bresenham");
  // Initialize drawing colors
  Init();
  // Call the displaying function
  glutDisplayFunc(Line_Bresenham);
  // Keep displaying untill the program is closed
  
  glutMainLoop();
}