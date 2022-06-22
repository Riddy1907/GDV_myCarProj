#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>         //laedt alles fuer OpenGL
#endif
#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979324
#endif
#include "terrain.h"
#include "car.h"

void mydisktex(float innerradius, float outerradius, int numtexures, int slicesbytex)
{
	int slices = numtexures*slicesbytex;
	float delta = 2*M_PI/slices;
	float deltatex = 1.0f/slicesbytex;
	float angle = 0.0f, s = 0.0f;
	glBegin(GL_QUAD_STRIP);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(innerradius, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(outerradius, 0.0f, 0.0f);
		for (int i = 0; i < slices; i++)
		{
			s += deltatex;
			angle += delta;
			float cs = cos(angle), sn = sin(angle);
			glTexCoord2f(s, 0.0f); glVertex3f(innerradius*cs, 0.0f, innerradius*sn);
			glTexCoord2f(s, 1.0f); glVertex3f(outerradius*cs, 0.0f, outerradius*sn);
		}
	glEnd();
}

void terrain(GLuint tex_road)
{
	GLUquadric *qobj = gluNewQuadric();

	glPushMatrix();
		glColor3f(0.35f, 0.35f, 0.35f); // dark grey
		glTranslatef(0.0f, 0.0f, -6.5f);
		parallelepiped(2.0f, 0.1f, 2.0f, 0.0f, 0.05f, 0.0f);
		parallelepiped(1.0f, 0.4f, 1.0f, 0.0f, 0.3f, 0.0f);
		parallelepiped(0.5f, 2.0f, 0.5f, 0.0f, 1.0f, 0.0f);
		glTranslatef(0.0f, 2.3f, 0.0f);
		glColor3f(0.27f, 0.27f, 0.27f); // dark grey
		glutSolidSphere(0.3, 32, 32);
	glPopMatrix();

	glNormal3f(0.0f, 1.0f, 0.0f);
	glColor4f(0.7f, 0.6f, 0.5f, 1.0f);
	glPushMatrix();
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		gluDisk(qobj, 0.0f, 8.0f, 120, 16);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex_road);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	mydisktex(8.0f, 16.0f, 8, 15);
	glDisable(GL_TEXTURE_2D);
	glColor4f(0.7f, 0.6f, 0.5f, 1.0f);
	glEnable(GL_LIGHTING);
	glPushMatrix();
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		gluDisk(qobj, 16.0f, 24.0f, 120, 16);
	glPopMatrix();
	glColor4f(0.33f, 0.125f, 0.0f, 1.0f);
	glPushMatrix();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(qobj, 24.0f, 24.0f, 10, 120, 1);
	glPopMatrix();
	gluDeleteQuadric(qobj);
}

void Sky()
{
	glPushMatrix();
		glDisable(GL_LIGHTING);
		glBegin(GL_QUAD_STRIP); // partly cloudy sky
			glColor4f(0.0f, 0.08f, 0.5f, 1.0f);
			glVertex3f(100.0f, 10.0f, -25.0f);
			glVertex3f(-100.0f, 10.0f, -25.0f);
			glColor4f(0.47f, 0.667, 0.937f, 1.0f);
			glVertex3f(100.0f, -10.0f, -25.0f);
			glVertex3f(-100.0f, -10.0f, -25.0f);
			glVertex3f(100.0f, -100.0f, -25.0f);
			glVertex3f(-100.0f, -100.0f, -25.0f);
		glEnd();
		glEnable(GL_LIGHTING);
	glPopMatrix();
}


