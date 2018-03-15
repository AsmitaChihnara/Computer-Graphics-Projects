#include <gl/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;

void myInit() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	//glColor3f(0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void half_pixel(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glColor3f(1.0,0.0,0.0);
	glEnd();
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glColor3f(1.0,1.0,1.0);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;
	int flag=0;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
				
			}
			else
			{
				e += inc2;
				flag=1;
				

			}
			x += incx;
			if(flag==0)
			{
				half_pixel(x-1,y);
			}
			else
			{
				half_pixel(x,y);
			}
			draw_pixel(x, y);
			flag=0;
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
			{
				e += inc2;
				flag=1;
			}
			y += incy;
			if(flag==0)
			{
				half_pixel(x-1,y);
			}
			else
			{
				half_pixel(x,y);
			}
			flag=0;
			draw_pixel(x, y);
		}
	}
}

void myDisplay() {
	draw_line(x1, x2, y1, y2);
	glFlush();
}

void main(int argc, char **argv) {

	printf( "Enter (x1, y1, x2, y2)\n");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}