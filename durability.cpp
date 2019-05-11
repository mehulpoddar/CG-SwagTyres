#include <GL/glut.h>    // Header File For The GLUT Library
#include <GL/gl.h>    // Header File For The OpenGL32 Library
#include <GL/glu.h>
#include<math.h>
#include<stdlib.h>
// Header File For The GLu32 Library
//#include <unistd.h>     // Header File For sleeping.
#include "durability.h"

/* ASCII code for the escape key. */
#define ESCAPE 27

/* The number of our GLUT window */
int windowd;

/* rotation angle for the triangle. */
float rtrid = -7.0f;

/* rotation angle for the quadrilateral. */
float rquadd = 0.0f;

float up1d = 8.6f;
float ft = 0.0f;

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
// We call this right after our OpenGL window is created.
void InitGLD(int Width, int Height)
{
	// This Will Clear The Background Color To Black
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClearDepth(1.0);                // Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS);                // The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);            // Enables Depth Testing
	glShadeModel(GL_SMOOTH);            // Enables Smooth Color Shading

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();                // Reset The Projection Matrix

	gluPerspective(45.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeScene(int Width, int Height)
{
	if (Height == 0)                // Prevent A Divide By Zero If The Window Is Too Small
		Height = 1;

	glViewport(0, 0, Width, Height);        // Reset The Current Viewport And Perspective Transformation

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

float fballud = -0.3f;
float fpartd1u = -0.3;
float fpartd2u = -0.7;
float fpartd3u = -0.9;

float fballdd = 0.55f;
float fpartd1d = 0.6;
float fpartd2d = 0.2;
float fpartd3d = 0.0;

void drawBall1d(void) {
	glColor3f(0.0, 0.0, 0.0); //set ball colour

	glTranslatef(-1.5f, -0.9f, 0.0f);
	glutSolidSphere(0.5, 20, 20); //create ball.

	glTranslatef(2.5f, 0.0f, 0.0f); //moving it toward the screen a bit on creation
	glutSolidSphere(0.5, 20, 20); //
}

void drawBall2d(void) {
	glColor3f(0.0, 0.0, 0.0); //set ball colour

	glTranslatef(-1.5f, -0.98f, 0.0f);
	glutSolidSphere(0.5, 20, 20); //create ball.

	glTranslatef(2.5f, 0.0f, 0.0f); //moving it toward the screen a bit on creation
	glutSolidSphere(0.5, 20, 20); //


}

void drawFlatBalld()
{
	glColor3f(0.0, 0.0, 0.0); //set ball colour

	glTranslatef(-1.5f, -0.8f, 0.0f);
	glutSolidSphere(0.5, 20, 20);

	glColor3ub(80, 80, 80);
	glTranslatef(2.5f, -0.15f, 0.0f); //moving it toward the screen a bit on creation
	glutSolidSphere(0.5, 20, 20);

	ft += 0.008;
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(ft+2.0f, -0.30f, 0.0f); //moving it toward the screen a bit on creation
	glutSolidSphere(0.5, 20, 20);

}

void truck1d() {
	//glRotatef(rtrid,1.0f,0.0f,0.0f);        // Rotate The Triangle On The Y axis
	  // draw a triangle (in smooth coloring mode)
	glBegin(GL_POLYGON);
	// start drawing a polygon

	               // start drawing a polygon
		glColor3f(0.0f, 0.0f, 0.0f);            // Set The Color To Red
		glVertex3f(-2.0f, 1.0f, 0.2f);        // Top left
		glVertex3f(0.0f, 1.0f, 0.2f);
        glVertex3f(1.0f, 0.0f, 0.2f);

		glColor3f(0.0f, 1.0f, 0.0f);            // Set The Color To Green
		glVertex3f(2.0f, 0.0f, 0.2f);        // Bottom Right
		glColor3f(0.0f, 1.0f, 0.5f);
		glVertex3f(2.0f, -1.0f, 0.2f);//
		glVertex3f(-2.0f, -1.0f, 0.2f);// Bottom Left
		glEnd();


                  // we're done with the polygon (smooth color interpolation)
	drawBall1d();

	rtrid += 0.015f;                    // Increase The Rotation Variable For The Triangle
	if (rtrid > 8.3) {
		rtrid = -8.3f;
		ft = 0.0f;
	}



	rquadd -= 10.0f;                    // Decrease The Rotation Variable For The Quad

}

void truck2d() {
	//glRotatef(rtrid,1.0f,0.0f,0.0f);        // Rotate The Triangle On The Y axis
	  // draw a triangle (in smooth coloring mode)
	glBegin(GL_POLYGON);
	// start drawing a polygon

				   // start drawing a polygon
	glColor3f(0.0f, 0.0f, 0.0f);            // Set The Color To Red
	glVertex3f(-2.0f, 1.0f, 0.2f);        // Top left
	glVertex3f(0.0f, 1.0f, 0.2f);
	glVertex3f(1.0f, 0.0f, 0.2f);

	glColor3f(238.0 / 255.0f, 145.0 / 255.0f, 41.0 / 255.0f);            // Set The Color To Green
	glVertex3f(2.0f, 0.0f, 0.2f);        // Bottom Right
	glColor3f(242.0 / 255.0, 242.0 / 255.0, 15.0 / 255.0);
	glVertex3f(2.0f, -1.0f, 0.2f);//
	glVertex3f(-2.0f, -1.0f, 0.2f);// Bottom Left
	glEnd();


	// we're done with the polygon (smooth color interpolation)

	if (rtrid < -5)
	{
		drawBall1d();
	}// Move Left 1.5 Units And Into The Screen 6.0
	else
	{
		drawFlatBalld();
	}

}



void drawRoad() {


	glLineWidth(6);
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);


	glVertex2f(-8.3f, -4.0f);
	glVertex2f(-4.3f, -4.0f);

	glVertex2f(-2.3f, -4.0f);
	glVertex2f(2.3f, -4.0f);

	glVertex2f(4.3f, -4.0f);
	glVertex2f(8.3f, -4.0f);
	glEnd();
	glLineWidth(3);

	glBegin(GL_POLYGON);
	glColor3ub(80, 80, 80);
	glVertex2f(8.3f, -2.0f);
	glVertex2f(-8.3f, -2.0f);
	glVertex2f(-8.3f, -6.2f);
	glVertex2f(8.3f, -6.2f);
	glEnd();
}

void drawBuilding() {

	// Door
	glBegin(GL_POLYGON);
	glColor3ub(183, 184, 188);
	glVertex2f(-1.5f, 0.0f);
	glVertex2f(1.5f, 0.0f);
	glVertex2f(1.5f, -2.0f);
	glVertex2f(-1.5f, -2.0f);
	glEnd();

	// School Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(-1.5f, 0.0f);
	glVertex2f(1.5f, 0.0f);
	glVertex2f(1.5f, -2.0f);
	glVertex2f(-1.5f, -2.0f);
	glEnd();

	//divider

	glBegin(GL_LINES);
	glColor3ub(20, 20, 20);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, -2.0f);
	glEnd();

	//windows
	for (int i = 0; i <= 4; i += 2) {
		for (int j = 0; j <=4 ; j += 2) {
			glBegin(GL_POLYGON);
			glColor3ub(59, 91, 132);
			glVertex2f(-1.5f + i, 5.5f - j);
			glVertex2f(-2.5 + i, 5.5f - j);
			glVertex2f(-2.5 + i, 4.5f - j);
			glColor3ub(97, 131, 159);
			glVertex2f(-1.5f + i, 4.5f - j);
			glEnd();

			glBegin(GL_LINE_LOOP);
			glColor3ub(20, 20, 20);
			glVertex2f(-1.5f + i, 5.5f - j);
			glVertex2f(-2.5 + i, 5.5f - j);
			glVertex2f(-2.5 + i, 4.5f - j);
			glVertex2f(-1.5f + i, 4.5f - j);
			glEnd();

			glLineWidth(4);
			glBegin(GL_LINES);
			glColor3ub(140, 75, 55);
			glVertex2f(-1.5f + i, 4.5f - j);
			glVertex2f(-2.5f + i, 4.5f - j);
			glEnd();
			glLineWidth(1);
		}
	}

	// Building
	glBegin(GL_POLYGON);
	glColor3ub(159, 191, 132);;
	glVertex2f(-3.5f, 6.0f);
	glVertex2f(3.5f, 6.0f);
	glVertex2f(4.0f, -2.0f);
	//glColor3ub(0.241, 0.13, 0.094);
	glVertex2f(-4.0f, -2.0f);
	glEnd();

	// Building Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(-3.5f, 6.0f);
	glVertex2f(3.5f, 6.0f);
	glVertex2f(4.0f, -2.0f);
	//glColor3ub(0.241, 0.13, 0.094);
	glVertex2f(-4.0f, -2.0f);
	glEnd();





	// Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(0.6, 0.175);
	glVertex2f(0.6, 0.28);
	glVertex2f(0.8, 0.28);
	glVertex2f(0.8, 0.175);
	glEnd();

	// Door Divider
	glBegin(GL_LINES);
	glColor3ub(20, 20, 20);
	glVertex2f(0.7, 0.28);
	glVertex2f(0.7, 0.175);
	glEnd();

	//  Windows
	for (int i = 0; i <= 500; i += 100) {
		for (int j = 0; j <= 100; j += 80) {
			glBegin(GL_POLYGON);
			glColor3ub(59, 91, 132);
			glVertex2f(0.425 + i, 0.450 - j);
			glVertex2f(0.475 + i, 0.450 - j);
			glVertex2f(0.475 + i, 0.400 - j);
			glColor3ub(97, 131, 159);
			glVertex2f(0.425 + i, 0.400 - j);
			glEnd();

			glBegin(GL_LINE_LOOP);
			glColor3ub(20, 20, 20);
			glVertex2f(0.425 + i, 0.450 - j);
			glVertex2f(0.475 + i, 0.450 - j);
			glVertex2f(0.475 + i, 0.400 - j);
			glVertex2f(0.425 + i, 0.400 - j);
			glEnd();

			glLineWidth(4);
			glBegin(GL_LINES);
			glColor3ub(140, 75, 55);
			glVertex2f(0.425 + i, 0.400 - j);
			glVertex2f(0.475 + i, 0.400 - j);
			glEnd();
			glLineWidth(1);
		}
	}

	glBegin(GL_POLYGON);
	glColor3ub(59, 91, 132);
	glVertex2f(0.425, 0.280);
	glVertex2f(0.475, 0.280);
	glVertex2f(0.475, 0.200);
	glColor3ub(97, 131, 159);
	glVertex2f(0.425, 0.200);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(0.425, 0.280);
	glVertex2f(0.475, 0.280);
	glVertex2f(0.475, 0.200);
	glVertex2f(0.425, 0.200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(59, 91, 132);
	glVertex2f(0.525, 0.280);
	glVertex2f(0.575, 0.280);
	glVertex2f(0.575, 0.200);
	glColor3ub(97, 131, 159);
	glVertex2f(0.525, 0.200);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(0.525, 0.280);
	glVertex2f(0.575, 0.280);
	glVertex2f(0.575, 0.200);
	glVertex2f(0.525, 0.200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(59, 91, 132);
	glVertex2f(0.825, 0.280);
	glVertex2f(0.875, 0.280);
	glVertex2f(0.875, 0.200);
	glColor3ub(97, 131, 159);
	glVertex2f(0.825, 0.200);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(0.825, 0.280);
	glVertex2f(0.875, 0.280);
	glVertex2f(0.875, 0.200);
	glVertex2f(0.825, 0.200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(59, 91, 132);
	glVertex2f(0.925, 0.280);
	glVertex2f(0.975, 0.280);
	glVertex2f(0.975, 0.200);
	glColor3ub(97, 131, 159);
	glVertex2f(0.925, 0.200);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex2f(0.925, 0.280);
	glVertex2f(0.975, 0.280);
	glVertex2f(0.975, 0.200);
	glVertex2f(0.925, 0.200);
	glEnd();
}

void drawTrees() {

	glBegin(GL_POLYGON);
	glColor3ub(86, 46, 11);
	glVertex2f(-6.0f, 0.0f);
	glVertex2f(-5.5f, 0.0f);
	glColor3ub(71, 36, 6);
	glVertex2f(-5.5f, -2.0f);
	glVertex2f(-6.0f, -2.0f);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(86, 46, 11);
	glVertex2f(6.0f, 0.0f);
	glVertex2f(5.5f, 0.0f);
	glColor3ub(71, 36, 6);
	glVertex2f(5.5f, -2.0f);
	glVertex2f(6.0f, -2.0f);
	glEnd();

	glColor3f(0.0, 1.0, 0.0); //set ball colour

	glTranslatef(-5.75f, 0.6f, 0.0f);
	glutSolidSphere(1.0, 20, 20); //create ball.

	glTranslatef(11.5f, 0.0f, 0.0f); //moving it toward the screen a bit on creation
	glutSolidSphere(1.0, 20, 20);

}

void drawBush()
{

}

/* The main drawing function. */
void durability_display()
{

	glClearColor(115 / 255.0, 194 / 255.0, 251 / 255.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        // Clear The Screen And The Depth Buffer
	glLoadIdentity();                // Reset The View



	glTranslatef(0.0, 0.0f, -15.0f);
	drawRoad();
	drawBuilding();
	drawTrees();
	drawBush();

	//glTranslatef(0.0, -6.3f, 0.0f);
	//hilld();

	glTranslatef(rtrid, up1d - 11.0, 0.0f);        // Move Left 1.5 Units And Into The Screen 6.0
	truck1d();


	if (rtrid <-5)
		glTranslatef(rtrid, -2.0f, 0.0f);       // Move Left 1.5 Units And Into The Screen 6.0
	else
		glTranslatef(-rtrid-7.0, -2.0f, 0.0f);
	truck2d();
	        // Move Left 1.5 Units And Into The Screen 6.0
		   // Move Left 1.5 Units And Into The Screen 6.0




	// swap the buffers to display, since double buffering is used.
	glutSwapBuffers();
}

/* The function called whenever a key is pressed. */
void keyPressedDurability(unsigned char key, int x, int y)
{
	if (key == (unsigned char)'b')
		menuMain();
}

int durabilityMain()
{
	//glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);

	/* get a 640 x 480 window */
	//glutInitWindowSize(640, 480);

	/* the window starts at the upper left corner of the screen */
	//glutInitWindowPosition(0, 0);

	/* Open a window */
	//window = glutCreateWindow("Moving Car");

	glutKeyboardFunc(keyPressedDurability);

	/* Register the function to do all our OpenGL drawing. */
	glutDisplayFunc(&durability_display);

	/* Go fullscreen.  This is as soon as possible. */
	glutFullScreen();

	/* Even if there are no events, redraw our gl scene. */
	glutIdleFunc(&durability_display);

	/* Register the function called when our window is resized. */
	glutReshapeFunc(&ReSizeScene);

	/* Initialize our window. */
	InitGLD(640, 480);

	glEnable(GL_DEPTH_TEST);

	/* Start Event Processing Engine */
	glutMainLoop();

	return 1;
}
