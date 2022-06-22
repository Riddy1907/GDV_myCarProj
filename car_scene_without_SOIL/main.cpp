#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>         //laedt alles fuer OpenGL
#endif
//#include <GL/soil.h>
#include "LoadTexture.h"
#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979324
#endif
#include "car.h"
#include "terrain.h"

GLuint tex_wheel, tex_tree0, tex_tree1, tex_road, tex_sign0, tex_sign1;
GLfloat extent = 2.2f;// Mass fuer die Ausdehnung des Modells
GLfloat alpha = -96.0f, theta = 2.0f;
GLfloat angleb = 0.02f, anglew = 84.0f;
GLfloat ybody = 0.0f, anglec = 0.0f, anglet = 0.0f;
float xcar, zcar, anglecar = -alpha;
bool wiperon = false, caron = false, follow = false;
int windowwidth = 600, windowheight = 600;
GLfloat light0_pos[] = {22.0f, 6.0f, 0.0f, 1.0f};
GLfloat light1_pos[] = {-11.0f, 6.0f, 19.05f, 1.0f};
GLfloat light2_pos[] = {-11.0f, 6.0f, -19.05f, 1.0f};

void Init()	
{
// Hier finden jene Aktionen statt, die zum Programmstart einmalig 
// durchgefuehrt werden muessen
	float light_ambient[4] = {0.05f, 0.05f, 0.05f, 1.0f};
	float light0_diffuse[4] = {0.9f, 0.9f, 0.9f, 1.0f};
	float light1_diffuse[4] = {1.0f, 1.0f, 1.0f, 1.0f};
	float light2_diffuse[4] = {0.8f, 0.8f, 0.6f, 1.0f};

	float mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	float mat_shininess[] = { 50.0 };

	glEnable(GL_LIGHT0); // Enabling light0 with its default setting
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_diffuse);

	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_diffuse);

	glEnable(GL_LIGHT2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light2_diffuse);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient); // modify the global ambient light

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glEnable(GL_COLOR_MATERIAL); // the objects have color
	glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

	glShadeModel(GL_SMOOTH);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor (0.0f, 0.08f, 0.5f, 1.0f);	//Hintergrundfarbe definieren
//	glClearColor ( 0.33f, 0.225f, 0.0f, 1.0f);	//Hintergrundfarbe definieren
	glClearDepth(1.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	/*
	tex_tree0 = SOIL_load_OGL_texture("tree0.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT );
	tex_tree1 = SOIL_load_OGL_texture("tree1.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT );
	tex_wheel = SOIL_load_OGL_texture("rims.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT );
	tex_road = SOIL_load_OGL_texture("road.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT );
	tex_sign0 = SOIL_load_OGL_texture("Schulbus.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT );
	tex_sign1 = SOIL_load_OGL_texture("do-not-drink-drive.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT );
	*/
	stbi_set_flip_vertically_on_load(1);
	tex_tree0 = LoadTexture("tree0.png");
	tex_tree1 = LoadTexture("tree1.png");
	tex_wheel = LoadTexture("rims.png");
	tex_road = LoadTexture("road.png");
	tex_sign0 = LoadTexture("Schulbus.png");
	tex_sign1 = LoadTexture("do-not-drink-drive.png");
}

void Trafficsign0(float x, float z, float angle)
{
	GLUquadric *qobj = gluNewQuadric();
	glPushMatrix();
		glTranslatef(x, 0.0f, z);
		glRotatef(angle, 0.0f, 1.0f, 0.0f);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
		gluCylinder(qobj, 0.05f, 0.05f, 3.0f, 12, 1);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex3f(-0.48f, -0.05f, 2.02f);
			glVertex3f(0.48f, -0.05f, 2.02f);
			glVertex3f(0.48f, -0.05f, 3.48f);
			glVertex3f(-0.48f, -0.05f, 3.48f);
		glEnd();
		glNormal3f(0.0f, -1.0f, 0.0f);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex_sign0);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f);   glVertex3f(-0.5f, -0.07f, 2.0f);
			glTexCoord2f(1.0f, 0.0f);   glVertex3f(0.5f, -0.07f, 2.0f);
			glTexCoord2f(1.0f, 1.0f);   glVertex3f(0.5f, -0.07f, 3.5f);
			glTexCoord2f(0.0f, 1.0f);   glVertex3f(-0.5f, -0.07f, 3.5f);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	gluDeleteQuadric(qobj);	
}

void Trafficsign1(float x, float z, float angle)
{
	GLUquadric *qobj = gluNewQuadric();
	glPushMatrix();
		glTranslatef(x, 0.0f, z);
		glRotatef(angle, 0.0f, 1.0f, 0.0f);
		glPushMatrix();
			glTranslatef(0.0f, 2.5f, 0.05f);
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			glNormal3f(0.0f, 0.0f, -1.0f);
			gluDisk(qobj, 0.0f, 0.48f, 24, 1);
			glTranslatef(0.0f, 0.0f, 0.02f);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, tex_sign1);
			gluQuadricTexture(qobj, GL_TRUE);
			gluDisk(qobj, 0.0f, 0.5f, 24, 1);
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
		gluCylinder(qobj, 0.05f, 0.05f, 2.5f, 24, 1);
	glPopMatrix();
	gluDeleteQuadric(qobj);	
}


void rendertree(GLuint tex_id, float x, float z, float w, float h, float angle)
{
	glPushMatrix();
		glTranslatef(x, 0.0f, z);
		glRotatef(angle, 0.0f, 1.0f, 0.0f);
		glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex_id);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f);   glVertex3f(-0.5f*w, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);   glVertex3f(0.5f*w, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);   glVertex3f(0.5f*w, h, 0.0f);
			glTexCoord2f(0.0f, 1.0f);   glVertex3f(-0.5f*w, h, 0.0f);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
	glPopMatrix();
}

void lamppost(float x, float z, float h)
{
	GLUquadric *qobj = gluNewQuadric();
	glPushMatrix();
		glTranslatef(x, 0.0f, z);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		parallelepiped(0.4f, 0.7f, 0.4f, 0.0f, 0.35f, 0.0f);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glTranslatef(0.0f, 0.0f, 0.7f);
		glColor4f(0.55f, 0.65f, 0.6f, 1.0f);
		cylinderdisk(qobj, 0.0f, 0.16f, 0.05f, 16, TOP);
//		glTranslatef(0.0f, 0.0f, 0.05f);
		gluCylinder(qobj, 0.12f, 0.08f, 0.15f, 8, 1);
		glTranslatef(0.0f, 0.0f, 0.15f);
		gluCylinder(qobj, 0.08f, 0.08f, h - 1.05f, 8, 1);
		glTranslatef(0.0f, 0.0f, h - 1.05f);
		glDisable(GL_LIGHTING);
		glColor4f(1.0f, 0.9f, 0.7f, 1.0f);
		gluCylinder(qobj, 0.08f, 0.08f, 0.05f, 16, 1);
		glTranslatef(0.0f, 0.0f, 0.05f);
		gluCylinder(qobj, 0.08f, 0.2f, 0.15f, 16, 1);
		glTranslatef(0.0f, 0.0f, 0.15f);
		cylinderdisk(qobj, 0.0f, 0.2f, 0.05f, 16, TOP);
		glEnable(GL_LIGHTING);
	glPopMatrix();
	gluDeleteQuadric(qobj);	
}

void RenderScene(void)
{
// Hier befindet sich der Code der in jedem frame ausgefuehrt werden muss
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Puffer loeschen
	glLoadIdentity();
	Sky();
	glRotatef(theta, 1.0f, 0.0f, 0.0f);
	glRotatef(alpha, 0.0f, 1.0f, 0.0f);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
	lamppost(light0_pos[0], light0_pos[2], light0_pos[1]);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
	lamppost(light1_pos[0], light1_pos[2], light1_pos[1]);
	glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);
	lamppost(light2_pos[0], light2_pos[2], light2_pos[1]);

	terrain(tex_road);

//	Trafficsign0(0.0f, -7.5f, 180.0f);
	Trafficsign0(-6.495f, 3.75f, -60.0f);
	Trafficsign1(6.495f, 3.75f, 60.0f);

	glPushMatrix();
		glTranslatef(xcar, 0.0f, zcar);
		glRotatef(anglecar, 0.0f, 1.0f, 0.0f);
		glPushMatrix();
			glTranslatef(1.05f, 0.3f, 0.5f);
			glRotatef(anglet, 0.0f, 0.0f, -1.0f);
			tirezp();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-1.05f, 0.3f, 0.5f);
			glRotatef(anglet, 0.0f, 0.0f, -1.0f);
			tirezp();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.05f, 0.3f, -0.5f);
			glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
			glRotatef(anglet, 0.0f, 0.0f, 1.0f);
			tirezp();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-1.05f, 0.3f, -0.5f);
			glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
			glRotatef(anglet, 0.0f, 0.0f, 1.0f);
			tirezp();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0f, ybody, 0.0f);
			glRotatef(anglec, 0.0f, 0.0f, 1.0f);
			glPushMatrix();
				glTranslatef(-1.10f, 1.00f, 0.0f);
				glRotatef(-angleb, 0.0f, 0.0f, 1.0f);
				boot_door();
			glPopMatrix();
			bodycar();
			glPushMatrix();
				glTranslatef(0.97f, 1.00f, -0.31f);
				glRotatef(26.56505f, 0.0f, 0.0f, 1);
				glPushMatrix();
					glRotatef(anglew, 1.0f, 0.0f, 0.0f);
					wiper1();
				glPopMatrix();
				glTranslatef(0.0f, 0.0f, 0.42f);
				glPushMatrix();
					glRotatef(anglew + 3.0f, 1.0f, 0.0f, 0.0f);
					wiper2();
				glPopMatrix();
			glPopMatrix();
			glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
			glPushMatrix();
				glTranslatef(2.02f, 0.65f, 0.6f);
				light();
				glTranslatef(0.0f, 0.0f, -1.2f);
				light();
			glPopMatrix();
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
	glMatrixMode(GL_PROJECTION); //Matrix fuer Transf.
	glLoadIdentity();
	glViewport(0,0,width,height);
	float extentx = extent*(float)width/height;
	glOrtho(-extentx,+extentx,-extent,+extent,-35.0,+35.0);
	glMatrixMode(GL_MODELVIEW); //Modellierungs/Viewing-Matrix
	windowwidth = width;
	windowheight = height;
}

	void KeyboardFunc ( unsigned char key, int , int )
{
	switch (key) {
	case '\r':
		if (caron)
			follow = false;
		caron = !caron;
		break;
	case ' ':
		wiperon = !wiperon;
		break;
	case 'f':
		follow = !follow;
		break;
	case 'd':
		alpha -= 1.0f;
		if (alpha < -180.0f)
			alpha += 360.0f;
		break;
	case 'a':
		alpha += 1.0f;
		if (alpha > 180.0f)
			alpha -= 360.0f;
		break;
	case 's':
		theta -= 1.0f;
		if (theta < -10.0f)
			theta = -10.0f;
		break;
	case 'w':
		theta += 1.0f;
		if (theta > 60.0f)
			theta = 60.0f;
		break;
	case 'l':
		angleb -= 2.5f;
		if (angleb < 0.2f)
			angleb = 0.2f;
		break;
	case 'k':
		angleb += 2.5f;
		if (angleb > 90.2f)
			angleb = 90.2f;
		break;
	case '-':
		extent *= 1.01f;
		if (extent > 25.0f)
			extent = 25.0f;
		Reshape(windowwidth, windowheight);
//std::cout << extent << std::endl;
		break;
	case '+':
		extent *= 1.0f/1.01f;
		if (extent < 1.0f)
			extent = 1.0f;
		Reshape(windowwidth, windowheight);
		break;
	}
	// RenderScene aufrufen.
	glutPostRedisplay();
}

void setcarpos()
{
	float rangle = anglecar*(M_PI/180);
	xcar = 14.0f*sin(rangle);
	zcar = 14.0f*cos(rangle);
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
		anglecar += 0.2f;
		if (anglecar > 180.0f)
			anglecar -= 360.0f;
		setcarpos();
		if (follow)
			alpha = -anglecar;
	}
	glutPostRedisplay();
	// Timer wieder registrieren; Animate also nach wait_msec Milli-Sekunden wieder aufrufen
	int wait_msec = 10;
	glutTimerFunc(wait_msec, Animate, ++value);		  
}


int main(int argc, char **argv)
{
/*   std::cout<<"Grundlegende Interaktionen:"<<std::endl;
	std::cout<<"Klicken Sie zunaechst ins Grafikfenster;"<<std::endl;
	std::cout<<"druecken Sie eine der 'normalen' Tasten "<<std::endl;
	std::cout<<"und beobachten Sie die Konsole-Ausgabe."<<std::endl<<std::endl;
	std::cout<<"Zum Beenden Graphik-Fenster schliessen!"<<std::endl<<std::endl;
*/
	glutInit ( &argc, argv );
	glutInitDisplayMode ( GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH );
	glutInitWindowSize ( windowwidth, windowheight );
	glutCreateWindow ("*** Szene mit Auto ***");
	glutDisplayFunc ( RenderScene );
	glutReshapeFunc ( Reshape );
	glutKeyboardFunc( KeyboardFunc );  // NEU
	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	glutTimerFunc(10,Animate,0);
	Init();
	setcarpos();
	glutMainLoop ();
	return 0;
}
