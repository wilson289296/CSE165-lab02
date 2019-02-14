#include <iostream>
#include <cmath>
//git test
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "SOIL.h"
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>

using namespace std;

// Store the width and height of the window
int width = 800, height = 800;

//PROTOTYPES FOR ORGANIZATION'S SAKE
void appDrawScene();
void windowToScene(float&, float&);
void appReshapeFunc(int, int);
void appMouseFunc(int, int, int, int);
void appMotionFunc(int, int);
void appKeyboardFunc(unsigned char, int, int);
void idle();

int r, g, b;
float pos_x, pos_y;


int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	// Setup window position, size, and title
	glutInitWindowPosition(500, 60);
	glutInitWindowSize(width, height);
	glutCreateWindow("CSE165 OpenGL Demo");

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);


	// Set callback for drawing the scene
	glutDisplayFunc(appDrawScene);
	// Set callback for resizing th window
    glutReshapeFunc(appReshapeFunc);
	// Set callback to handle mouse clicks
	glutMouseFunc(appMouseFunc);
	// Set callback to handle mouse dragging
	glutMotionFunc(appMotionFunc);
	// Set callback to handle keyboad events
	glutKeyboardFunc(appKeyboardFunc);
    glutIdleFunc(idle);
	// Start the main loop
	glutMainLoop();
}

void appDrawScene() {
	//-------------------------------------------------------
	// A function to draw the scene
	//-------------------------------------------------------
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(1, 1, 1);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(0.333, 1);
	glVertex2f(0.333, -1);
	glVertex2f(-0.333, 1);
	glVertex2f(-0.333, -1);
	glVertex2f(1, 0.333);
	glVertex2f(-1, 0.333);
	glVertex2f(1, -0.333);
	glVertex2f(-1, -0.333);
	glEnd();

	/*
    // Draw stuff here
	//drawing a polygon for interactivity
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(0.25, 0.25);
	glVertex2f(0.75, 0.5);
	glVertex2f(0,0);
	glEnd();
	*/
	glColor3f(0.8, 0.8, 0.2);
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2f(pos_x, pos_y);
	glEnd();
	
	
  /* LAB 1 STUFF
	glColor3f(1.0,1.0,1.0);
	glPointSize(10);
	
	//START W
	glBegin(GL_POLYGON);
	glVertex2f(-0.9,0.8);
	glVertex2f(-0.9,0.7);
	glVertex2f(-0.7,-0.8);
	glVertex2f(-0.7,-0.7);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(-0.7,-0.8);
	glVertex2f(-0.7,-0.7);
	glVertex2f(-0.5,0.8);
	glVertex2f(-0.5,0.7);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(-0.5,0.8);
	glVertex2f(-0.5,0.7);
	glVertex2f(-0.3,-0.7);
	glVertex2f(-0.3,-0.8);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(-0.3,-0.7);
	glVertex2f(-0.3,-0.8);
	glVertex2f(-0.1,0.8);
	glVertex2f(-0.1,0.7);
	glEnd();
	
	//START S
	glBegin(GL_POLYGON);
	glVertex2f(0.9,0.5);
	glVertex2f(0.9,0.4);
	glVertex2f(0.5,0.7);
	glVertex2f(0.5,0.8);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(0.5,0.7);
	glVertex2f(0.5,0.8);
	glVertex2f(0.1,0.5);
	glVertex2f(0.1,0.4);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(0.1,0.5);
	glVertex2f(0.1,0.4);
	glVertex2f(0.9,-0.5);
	glVertex2f(0.9,-0.4);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(0.9,-0.5);
	glVertex2f(0.9,-0.4);
	glVertex2f(0.5,-0.7);
	glVertex2f(0.5,-0.8);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(0.5,-0.7);
	glVertex2f(0.5,-0.8);
	glVertex2f(0.1,-0.5);
	glVertex2f(0.1,-0.4);
	glEnd();
*/
	
	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	//glFlush();
	glutSwapBuffers();
}

void windowToScene(float& x, float& y) {
	
	//-------------------------------------------------------
	// A function to convert window coordinates to scene
	// We use it when a mouse event is handled
	// Arguments: 	
	//	x, y - the coordinates to be updated
	//-------------------------------------------------------
	x = (2.0f*(x / float(width))) - 1.0f;
	y = 1.0f - (2.0f*(y / float(height)));
}

void appReshapeFunc(int w, int h) {\
	//-------------------------------------------------------
	// A function to handle window resizing
	// Called every time the window is resized
	// Arguments: 	
	//	b    - mouse button that was clicked, left or right
	//	s 	 - state, either mouse-up or mouse-down
	//	x, y - coordinates of the mouse when click occured
	//-------------------------------------------------------
	/* Screw that, it messes with the coordinates
	// Window size has changed
	width = w;
	height = h;

	double scale, center;
	double winXmin, winXmax, winYmin, winYmax;

	// Define x-axis and y-axis range
	const double appXmin = -1.0;
	const double appXmax = 1.0;
	const double appYmin = -1.0;
	const double appYmax = 1.0;

	// Define that OpenGL should use the whole window for rendering
	glViewport(0, 0, w, h);

	// Set up the projection matrix using a orthographic projection that will
	// maintain the aspect ratio of the scene no matter the aspect ratio of
	// the window, and also set the min/max coordinates to be the disered ones
	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;

	if ((appXmax - appXmin) / w < (appYmax - appYmin) / h) {
		scale = ((appYmax - appYmin) / h) / ((appXmax - appXmin) / w);
		center = (appXmax + appXmin) / 2;
		winXmin = center - (center - appXmin)*scale;
		winXmax = center + (appXmax - center)*scale;
		winYmin = appYmin;
		winYmax = appYmax;
	}
	else {
		scale = ((appXmax - appXmin) / w) / ((appYmax - appYmin) / h);
		center = (appYmax + appYmin) / 2;
		winYmin = center - (center - appYmin)*scale;
		winYmax = center + (appYmax - center)*scale;
		winXmin = appXmin;
		winXmax = appXmax;
	}

	// Now we use glOrtho to set up our viewing frustum
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(winXmin, winXmax, winYmin, winYmax, -1, 1);*/
	glutReshapeWindow(800, 800); //lmao you thought you could resize the window
}

void appMouseFunc(int b, int s, int x, int y) {
	//-------------------------------------------------------
	// A function to handle mouse clicks
	// Called every time the mouse button goes up or down
	// Arguments: 	
	//	b    - mouse button that was clicked, left or right
	//	s 	 - state, either mouse-up or mouse-down
	//	x, y - coordinates of the mouse when click occured
	//-------------------------------------------------------
	
	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);
	/* Click/release reporter

	if(b == GLUT_LEFT_BUTTON && s == GLUT_DOWN){
		cout << "Left mouse button pressed\n";
	}
	if(b == GLUT_LEFT_BUTTON && s == GLUT_UP){
		cout << "Left mouse button released\n";
	}
	if(b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN){
		cout << "Right mouse button pressed\n";
	}
	if(b == GLUT_RIGHT_BUTTON && s == GLUT_UP){
		cout << "Right mouse button released\n";
	}
*/
	//CLICK SECTOR DETECTOR
	if(s == GLUT_DOWN){
		if(mx > -1 && mx < -0.333){
			if(my < 1 && my > 0.333){
				cout << "Clicked sector 1\n";
			} else if(my < 0.333 && my > -0.333){
				cout << "Clicked sector 4\n";
			} else if(my < -0.333 && my > -1){
				cout << "Clicked sector 7\n";
			}
		} else if(mx > -0.333 && mx < 0.333){
			if(my < 1 && my > 0.333){
				cout << "Clicked sector 2\n";
			} else if(my < 0.333 && my > -0.333){
				cout << "Clicked sector 5\n";
			} else if(my < -0.333 && my > -1){
				cout << "Clicked sector 8\n";
			}
		} else if(mx > 0.333 && mx < 1){
			if(my < 1 && my > 0.333){
				cout << "Clicked sector 3\n";
			} else if(my < 0.333 && my > -0.333){
				cout << "Clicked sector 6\n";
			} else if(my < -0.333 && my > -1){
				cout << "Clicked sector 9\n";
			}
		}
	}
	
	
	// Redraw the scene by calling appDrawScene above
	// so that the point we added above will get painted
	glutPostRedisplay();
}

void appMotionFunc(int x, int y) {
	//-------------------------------------------------------
	// A function to handle mouse dragging
	// Called every time mouse moves while button held down
	// Arguments: 	
	//	x, y - current coordinates of the mouse
	//-------------------------------------------------------
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);
	pos_x = mx;
	pos_y=my;
	cout << mx << " " << my << endl;

	// Again, we redraw the scene
	glutPostRedisplay();
}

void appKeyboardFunc(unsigned char key, int x, int y) {
	//-------------------------------------------------------
	// A function to handle keyboard events
	// Called every time a key is pressed on the keyboard
	// Arguments: 	
	//	key  - the key that was pressed
	//	x, y - coordinates of the mouse when key is pressed
	//-------------------------------------------------------
	
    switch (key) {
        case 'r':
            r=1.0;
			g=0.0;
			b=0.0;
            break;
		case 'g':
			r=0.0;
			g=1.0;
			b=0.0;
        default:
            break;
    }

	// After all the state changes, redraw the scene
	glutPostRedisplay();
}

void idle() {

}


