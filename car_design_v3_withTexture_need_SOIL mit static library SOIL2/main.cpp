/*glutKeyboardFunc sets the keyboard callback for the current window.
Usage
void glutKeyboardFunc(void (*func)(unsigned char key,int x, int y));
func The new keyboard callback function.
Description
glutKeyboardFunc sets the keyboard callback for the current window. 
When a user types into the window, each key press generating an 
ASCII character will generate a keyboard callback. The key callback 
parameter is the generated ASCII character. The state of modifier 
keys such as Shift cannot be determined directly; their only effect 
will be on the returned ASCII data. The x and y callback parameters 
indicate the mouse location in window relative coordinates when 
the key was pressed. When a new window is created, no keyboard 
callback is initially registered, and ASCII key strokes in the
window are ignored. Passing NULL to glutKeyboardFunc disables the 
generation of keyboard callbacks. During a keyboard callback, 
glutGetModifiers may be called to determine the state of modifier 
keys when the keystroke generating the callback occurred.
Also, see glutSpecialFunc for a means to detect non-ASCII key strokes.*/ 

//#include <windows.h>
#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>         //laedt alles fuer OpenGL
#endif
//#include <GL/soil.h>
//#include "src/SOIL2"

#include "/usr/local/include/SOIL2-master"
#include <iostream>
#include <math.h>
#include "car.h"


GLuint tex_wheel, tex_tree0, tex_tree1;
GLfloat extent = 4.0f;// Mass fuer die Ausdehnung des Modells
GLfloat alpha = 0.0f, theta = 0.0f;
GLfloat angleb = 0.02f, anglew = 84.0f;
GLfloat ybody = 0.0f, anglec = 0.0f, anglet = 0.0f;
bool wiperon = false, caron = false;

void Init()	
{
// Hier finden jene Aktionen statt, die zum Programmstart einmalig 
// durchgefuehrt werden muessen
	glShadeModel(GL_SMOOTH);
	
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHT0); // Enabling light0 with its default setting
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor ( 0.33f, 0.225f, 0.0f, 1.0f);	//Hintergrundfarbe definieren
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	tex_tree0 = SOIL_load_OGL_texture("tree0.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT );
	tex_tree1 = SOIL_load_OGL_texture("tree1.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT );
	tex_wheel = SOIL_load_OGL_texture("rims.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT );
std::cout << "tex_wheel: " << tex_wheel << std::endl;
}

void rendertree(GLuint tex_idm, float x, float z, float w, float h, float angle)
{
	glPushMatrix();
		glTranslatef(x, 0, z);
		glRotatef(angle, 0, 1, 0);
		glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex_tree0);
		glBegin(GL_QUADS);
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f);   glVertex3f(-0.5f*w, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);   glVertex3f(0.5f*w, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);   glVertex3f(0.5f*w, h, 0.0f);
			glTexCoord2f(0.0f, 1.0f);   glVertex3f(-0.5f*w, h, 0.0f);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
	glPopMatrix();
}



void RenderScene(void)
{
// Hier befindet sich der Code der in jedem frame ausgefuehrt werden muss
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Puffer loeschen
	glLoadIdentity();
	glRotatef(theta, 1, 0, 0);
	glRotatef(alpha, 0, 1, 0);
	glPushMatrix();
		glTranslatef(1.05f, 0.3f, 0.5f);
		glRotatef(anglet, 0, 0, -1);
		tirezp();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-1.05f, 0.3f, 0.5f);
		glRotatef(anglet, 0, 0, -1);
		tirezp();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(1.05f, 0.3f, -0.5f);
		glRotatef(180, 0, 1, 0);
		glRotatef(anglet, 0, 0, 1);
		tirezp();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-1.05f, 0.3f, -0.5f);
		glRotatef(180, 0, 1, 0);
		glRotatef(anglet, 0, 0, 1);
		tirezp();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, ybody, 0);
		glRotatef(anglec, 0, 0, 1);
		glPushMatrix();
			glTranslatef(-1.10f, 1.00f, 0);
			glRotatef(-angleb, 0, 0, 1);
			boot_door();
		glPopMatrix();
		drawcar();
		glPushMatrix();
			glTranslatef(0.97f, 1.00f, -0.31f);
			glRotatef(26.56505f, 0, 0, 1);
			glPushMatrix();
				glRotatef(anglew, 1, 0, 0);
				wiper1();
			glPopMatrix();
			glTranslatef(0, 0, 0.42f);
			glPushMatrix();
				glRotatef(anglew + 3, 1, 0, 0);
				wiper2();
			glPopMatrix();
		glPopMatrix();
		glColor4f(1, 1, 0, 1);
		glPushMatrix();
			glTranslatef(2.02f, 0.65f, 0.6f);
			light();
			glTranslatef(0, 0, -1.2f);
			light();
		glPopMatrix();
	glPopMatrix();

	if (fabs(alpha) < 90.0f)
	{
		rendertree(tex_tree0, -2.0f, -3.0f, 3.54f, 3.0f, -alpha);
		rendertree(tex_tree1, 3.0f, 1.5f, 3.0f, 3.68f, -alpha);
	}
	else
	{
		rendertree(tex_tree1, 3.0f, 1.5f, 3.0f, 3.68f, -alpha);
		rendertree(tex_tree0, -2.0f, -3.0f, 3.54f, 3.0f, -alpha);
	}

	glutSwapBuffers(); 
	glFlush();
}

void Reshape(int width,int height)
{
// Hier finden die Reaktionen auf eine Veraenderung der Groesse des 
// Graphikfensters statt
	glMatrixMode(GL_PROJECTION); //Matrix fuer Transf. Frustum->viewport
	glLoadIdentity();
	glViewport(0,0,width,height);
	float extentx = extent*(float)width/height;
	glOrtho(-extent,+extent,-extentx,+extentx,-extent*3.0,+extent*3.0); //Frustum
	glMatrixMode(GL_MODELVIEW); //Modellierungs/Viewing-Matrix
}

	void KeyboardFunc ( unsigned char key, int x, int y )
{
//	GLfloat xMousePos = float(x);
//	GLfloat yMousePos = float(y);
//	std::cout <<"key = "<< key <<"  "<< xMousePos<<", "<<yMousePos<<std::endl;
	switch (key) {
	case '\r':
		caron = !caron;
		break;
	case ' ':
		wiperon = !wiperon;
		break;
	case 'a':
		alpha -= 1.0f;
		if (alpha < -180.0f)
			alpha += 360.0f;
		break;
	case 'd':
		alpha += 1.0f;
		if (alpha > 180.0f)
			alpha -= 360.0f;
		break;
	case 'w':
		theta -= 1.0f;
		if (theta < -90.0f)
			theta = -90.0f;
		break;
	case 's':
		theta += 1.0f;
		if (theta > 90.0f)
			theta = 90.0f;
		break;
	case 'l':
		angleb -= 1.0f;
		if (angleb < 0.2f)
			angleb = 0.2f;
		break;
	case 'k':
		angleb += 1.0f;
		if (angleb > 90.2f)
			angleb = 90.2f;
		break;
	}
	// RenderScene aufrufen.
	glutPostRedisplay();
}

void Animate (int value)
{
	// Hier werden Berechnungen durchgefuehrt, die zu einer Animation der Szene  
	// erforderlich sind. Dieser Prozess laeuft im Hintergrund und wird alle 
	// wait_msec Milli-Sekunden aufgerufen. 
	// RenderScene aufrufen.
	static float deltaangle = 1.0f;
	if (wiperon || anglew != 84.0f)
	{
		anglew += deltaangle;
		if (anglew > 84.0f)
		{
			anglew = 84.0f;
			deltaangle = -deltaangle;
		}
		else if (anglew < -30.0f)
		{
			anglew = -30.0f;
			deltaangle = -deltaangle;
		}
	}
	if (caron)
	{
		anglet += 5.0f;
		if (anglet > 360.0f)
			anglet -= 360.0f;
		if (rand() & 2)
		{
			if (rand() & 1)
			{
				ybody += 0.005f;
				if (ybody > 0.05f)
					ybody = 0.05f;
			}
			else
			{
				ybody -= 0.005f;
				if (ybody < -0.05f)
					ybody = -0.05f;
			}
		}
		else
		{
			if (rand() & 1)
			{
				anglec += 0.05f;
				if (anglec > 2.0f)
					anglec = 2.0f;
			}
			else
			{
				anglec -= 0.05f;
				if (anglec < -2.0f)
					anglec = -2.0f;
			}
		}
	}
	glutPostRedisplay();
	// Timer wieder registrieren; Animate also nach wait_msec Milli-Sekunden wieder aufrufen
	int wait_msec = 10;
	glutTimerFunc(wait_msec, Animate, ++value);		  
}


int main(int argc, char **argv)
{
   std::cout<<"Grundlegende Interaktionen:"<<std::endl;
	std::cout<<"Klicken Sie zunaechst ins Grafikfenster;"<<std::endl;
	std::cout<<"druecken Sie eine der 'normalen' Tasten "<<std::endl;
	std::cout<<"und beobachten Sie die Konsole-Ausgabe."<<std::endl<<std::endl;
	std::cout<<"Zum Beenden Graphik-Fenster schliessen!"<<std::endl<<std::endl;

	glutInit ( &argc, argv );
	glutInitDisplayMode ( GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH );
	glutInitWindowSize ( 600,600 );
	glutCreateWindow ("*** KeyboardFunc ***");
	glutDisplayFunc ( RenderScene );
	glutReshapeFunc ( Reshape );
	glutKeyboardFunc( KeyboardFunc );  // NEU
	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	glutTimerFunc(10,Animate,0);
	Init();
	glutMainLoop ();
	return 0;
}
