//#include <windows.h>
//#include <GL/freeglut.h>         //laedt alles fuer OpenGL
#include <GLUT/glut.h>
#include <iostream>
#include <cmath>
#include "car.h"


// draw a cylinder with caps
void cylinderdisk(GLUquadric *qobj, double innerRadius, double outerRadius, double height, int slices)
{
	glPushMatrix();
		glRotatef(180, 0, 1, 0);
		gluDisk(qobj, innerRadius, outerRadius, slices, 1);
	glPopMatrix();
	gluCylinder(qobj, outerRadius, outerRadius, height, slices, 1);
	glTranslatef(0, 0, height);
	gluDisk(qobj, innerRadius, outerRadius, slices, 1);
}

// draw a parallelepiped whith dimensions lx ly lz and centered at [cx, cy, cz];
void parallelepiped(float lx, float ly, float lz, float cx, float cy, float cz) {
	lx *= 0.5f;
	ly *= 0.5f;
	lz *= 0.5f;
	glNormal3f(0, 0, 1);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(cx - lx, cy + ly, cz + lz);
		glVertex3f(cx - lx, cy - ly, cz + lz);
		glVertex3f(cx + lx, cy + ly, cz + lz);
		glVertex3f(cx + lx, cy - ly, cz + lz);
	glEnd();
	glNormal3f(0, 0, -1);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(cx + lx, cy + ly, cz - lz);
		glVertex3f(cx + lx, cy - ly, cz - lz);
		glVertex3f(cx - lx, cy + ly, cz - lz);
		glVertex3f(cx - lx, cy - ly, cz - lz);
	glEnd();
	glNormal3f(1, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(cx + lx, cy - ly, cz + lz);
		glVertex3f(cx + lx, cy - ly, cz - lz);
		glVertex3f(cx + lx, cy + ly, cz + lz);
		glVertex3f(cx + lx, cy + ly, cz - lz);
	glEnd();
	glNormal3f(-1, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(cx - lx, cy + ly, cz + lz);
		glVertex3f(cx - lx, cy + ly, cz - lz);
		glVertex3f(cx - lx, cy - ly, cz + lz);
		glVertex3f(cx - lx, cy - ly, cz - lz);
	glEnd();
	glNormal3f(0, 1, 0);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(cx - lx, cy + ly, cz - lz);
		glVertex3f(cx - lx, cy + ly, cz + lz);
		glVertex3f(cx + lx, cy + ly, cz - lz);
		glVertex3f(cx + lx, cy + ly, cz + lz);
	glEnd();
	glNormal3f(0, -1, 0);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(cx + lx, cy - ly, cz - lz);
		glVertex3f(cx + lx, cy - ly, cz + lz);
		glVertex3f(cx - lx, cy - ly, cz - lz);
		glVertex3f(cx - lx, cy - ly, cz + lz);
	glEnd();
}

void tirezp()
{
	GLUquadric *qobj = gluNewQuadric();
	glColor4f(0.1f, 0.1f, 0.1f, 1);
	cylinderdisk(qobj, 0.16, 0.3, 0.2, 32);
	glColor4f(0.6f, 0.6f, 0.7f, 1);
	gluDisk(qobj, 0, 0.16, 32, 1);
	gluDeleteQuadric(qobj);
}

void light()
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glRotatef(-90, 0, 1, 0);
		glTranslatef(0, 0, -0.025);
		glutSolidCone(0.1f, 0.1f, 16, 1);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void drawcar()
{
	glColor4f(0.4f, 0.6f, 0.4f, 1);
	// +z side
	glNormal3f(0, 0, 1);
	glBegin(GL_QUAD_STRIP);
		glVertex3f(-1.90f, 0.25f, 0.75f);
		glVertex3f(-1.90f, 0.70f, 0.75f);
		glVertex3f(-1.35f, 0.25f, 0.75f);
		glVertex3f(-1.80f, 0.95f, 0.75f);
		glVertex3f(-1.25f, 0.45f, 0.75f);
		glVertex3f(-1.00f, 1.00f, 0.75f);
		glVertex3f(-0.85f, 0.45f, 0.75f);
		glVertex3f( 0.00f, 1.00f, 0.75f);
		glVertex3f(-0.75f, 0.25f, 0.75f);
		glVertex3f( 0.75f, 0.25f, 0.75f);
	glEnd();
	glBegin(GL_QUAD_STRIP);
		glVertex3f( 0.75f, 0.25f, 0.75f);
		glVertex3f( 0.00f, 1.00f, 0.75f);
		glVertex3f( 0.85f, 0.45f, 0.75f);
		glVertex3f( 0.95f, 1.00f, 0.75f);
		glVertex3f( 1.25f, 0.45f, 0.75f);
		glVertex3f( 2.00f, 0.85f, 0.75f);
		glVertex3f( 1.35f, 0.25f, 0.75f);
		glVertex3f( 2.05f, 0.25f, 0.75f);
	glEnd();
	glNormal3f(0, 0.2631174f, 0.9647638f);
	glBegin(GL_QUAD_STRIP);
		glVertex3f(-0.90f, 1.00f, 0.75f);
		glVertex3f(-1.00f, 1.00f, 0.75f);
		glVertex3f(-0.75f, 1.45f, 0.6272727f);
		glVertex3f(-0.80f, 1.55f, 0.60f);
		glVertex3f( 0.55f, 1.45f, 0.6272727f);
		glVertex3f( 0.60f, 1.55f, 0.60f);
		glVertex3f( 0.70f, 1.00f, 0.75f);
		glVertex3f( 0.80f, 1.00f, 0.75f);
	glEnd();
	glBegin(GL_QUAD_STRIP);
		glVertex3f(-0.10f, 1.00f, 0.75f);
		glVertex3f(-0.10f, 1.45f, 0.6272727f);
		glVertex3f( 0.00f, 1.00f, 0.75f);
		glVertex3f( 0.00f, 1.45f, 0.6272727f);
	glEnd();

	// -z side
	glNormal3f(0, 0, -1);
	glBegin(GL_QUAD_STRIP);
		glVertex3f( 1.35f, 0.25f,-0.75f);
		glVertex3f( 2.05f, 0.25f,-0.75f);
		glVertex3f( 1.25f, 0.45f,-0.75f);
		glVertex3f( 2.00f, 0.85f,-0.75f);
		glVertex3f( 0.85f, 0.45f,-0.75f);
		glVertex3f( 0.95f, 1.00f,-0.75f);
		glVertex3f( 0.75f, 0.25f,-0.75f);
		glVertex3f( 0.00f, 1.00f,-0.75f);
	glEnd();
	glBegin(GL_QUAD_STRIP);
		glVertex3f(-0.75f, 0.25f,-0.75f);
		glVertex3f( 0.75f, 0.25f,-0.75f);
		glVertex3f(-0.85f, 0.45f,-0.75f);
		glVertex3f( 0.00f, 1.00f,-0.75f);
		glVertex3f(-1.25f, 0.45f,-0.75f);
		glVertex3f(-1.00f, 1.00f,-0.75f);
		glVertex3f(-1.35f, 0.25f,-0.75f);
		glVertex3f(-1.80f, 0.95f,-0.75f);
		glVertex3f(-1.90f, 0.25f,-0.75f);
		glVertex3f(-1.90f, 0.70f,-0.75f);
	glEnd();
	glNormal3f(0, 0.2631174f, -0.9647638f);
	glBegin(GL_QUAD_STRIP);
		glVertex3f( 0.70f, 1.00f,-0.75f);
		glVertex3f( 0.80f, 1.00f,-0.75f);
		glVertex3f( 0.55f, 1.45f,-0.6272727f);
		glVertex3f( 0.60f, 1.55f,-0.60f);
		glVertex3f(-0.75f, 1.45f,-0.6272727f);
		glVertex3f(-0.80f, 1.55f,-0.60f);
		glVertex3f(-0.90f, 1.00f,-0.75f);
		glVertex3f(-1.00f, 1.00f,-0.75f);
	glEnd();
	glBegin(GL_QUAD_STRIP);
		glVertex3f( 0.00f, 1.00f,-0.75f);
		glVertex3f( 0.00f, 1.45f,-0.6272727f);
		glVertex3f(-0.10f, 1.00f,-0.75f);
		glVertex3f(-0.10f, 1.45f,-0.6272727f);
	glEnd();

	// hood
	glNormal3f(0, 1, 0);
	glBegin(GL_TRIANGLES);
		glVertex3f( 0.80f, 1.00f, 0.75f);
		glVertex3f( 0.95f, 1.00f, 0.60f);
		glVertex3f( 0.95f, 1.00f, 0.75f);
		glVertex3f( 0.95f, 1.00f,-0.75f);
		glVertex3f( 0.95f, 1.00f,-0.60f);
		glVertex3f( 0.80f, 1.00f,-0.75f);
	glEnd();
	glNormal3f(0.14142136f, 0.98994949f,	0);
	glBegin(GL_QUADS);
		glVertex3f( 0.95f, 1.00f, 0.75f);
		glVertex3f( 0.95f, 1.00f,-0.75f);
		glVertex3f( 2.00f, 0.85f,-0.75f);
		glVertex3f( 2.00f, 0.85f, 0.75f);
	glEnd();

	//front
	glNormal3f(1, 0, 0);
	glBegin(GL_QUADS);
		glVertex3f( 2.00f, 0.85f, 0.75f);
		glVertex3f( 2.00f, 0.85f,-0.75f);
		glVertex3f( 2.05f, 0.25f,-0.75f);
		glVertex3f( 2.05f, 0.25f, 0.75f);
	glEnd();

	//rear
	glNormal3f(-0.93979342f, 0.34174306f, 0);
	glBegin(GL_QUAD_STRIP);
		glVertex3f(-1.00f, 1.00f, 0.65f);
		glVertex3f(-1.00f, 1.00f, 0.75f);
		glVertex3f(-0.83636364f, 1.45f, 0.52727273f);
		glVertex3f(-0.80f, 1.55f, 0.60f);
		glVertex3f(-0.83636364f, 1.45f,-0.52727273f);
		glVertex3f(-0.80f, 1.55f,-0.60f);
		glVertex3f(-1.00f, 1.00f,-0.65f);
		glVertex3f(-1.00f, 1.00f,-0.75f);
	glEnd();

	glBegin(GL_QUADS);
		glNormal3f(-0.06237829f, 0.99805258f, 0);
		glVertex3f(-1.80f, 0.95f, 0.75f);
		glVertex3f(-1.80f, 0.95f,-0.75f);
		glVertex3f(-1.00f, 1.00f,-0.75f);
		glVertex3f(-1.00f, 1.00f, 0.75f);
		glNormal3f(-0.92847669f, 0.37139068f, 0);
		glVertex3f(-1.90f, 0.70f, 0.75f);
		glVertex3f(-1.90f, 0.70f,-0.75f);
		glVertex3f(-1.80f, 0.95f,-0.75f);
		glVertex3f(-1.80f, 0.95f, 0.75f);
		glNormal3f(-1, 0, 0);
		glVertex3f(-1.90f, 0.25f, 0.75f);
		glVertex3f(-1.90f, 0.25f,-0.75f);
		glVertex3f(-1.90f, 0.70f,-0.75f);
		glVertex3f(-1.90f, 0.70f, 0.75f);
	glEnd();

	//roof
	glBegin(GL_QUADS);
		glNormal3f(0.44721360f, 0.89442719f, 0);
		glVertex3f( 0.70f, 1.50f,-0.55f);
		glVertex3f( 0.70f, 1.50f, 0.55f);
		glVertex3f( 0.60f, 1.55f, 0.60f);
		glVertex3f( 0.60f, 1.55f,-0.60f);
		glNormal3f(0, 1, 0);
		glVertex3f( 0.60f, 1.55f,-0.60f);
		glVertex3f( 0.60f, 1.55f, 0.60f);
		glVertex3f(-0.80f, 1.55f, 0.60f);
		glVertex3f(-0.80f, 1.55f,-0.60f);
	glEnd();

	// other front
	glBegin(GL_TRIANGLES);
	glNormal3f(0.56225353f, 0.40160966f, 0.72289740f);
		glVertex3f( 0.80f, 1.00f, 0.75f);
		glVertex3f( 0.60f, 1.55f, 0.60f);
		glVertex3f( 0.70f, 1.50f, 0.55f);
	glNormal3f(0.56225353f, 0.40160966f,-0.72289740f);
		glVertex3f( 0.70f, 1.50f,-0.55f);
		glVertex3f( 0.60f, 1.55f,-0.60f);
		glVertex3f( 0.80f, 1.00f,-0.75f);
	glEnd();
	
	
	// windshield
	glColor4f(0.8f, 0.8f, 1, 1);
	glBegin(GL_TRIANGLES);
	glNormal3f(0.65094455f, 0.39056673f, 0.65094455f);
		glVertex3f( 0.80f, 1.00f, 0.75f);
		glVertex3f( 0.70f, 1.50f, 0.55f);
		glVertex3f( 0.95f, 1.00f, 0.60f);
	glNormal3f(0.65094455f, 0.39056673f,-0.65094455f);
		glVertex3f( 0.95f, 1.00f,-0.60f);
		glVertex3f( 0.70f, 1.50f,-0.55f);
		glVertex3f( 0.80f, 1.00f,-0.75f);
	glEnd();
	glNormal3f(0.85749293f, 0.51449576f, 0);
	glBegin(GL_QUADS);
		glVertex3f( 0.95f, 1.00f,-0.60f);
		glVertex3f( 0.95f, 1.00f, 0.60f);
		glVertex3f( 0.70f, 1.50f, 0.55f);
		glVertex3f( 0.70f, 1.50f,-0.55f);
	glEnd();

	// back window
	glNormal3f(-0.93979342f, 0.34174306f, 0);
	glBegin(GL_QUADS);
		glVertex3f(-1.00f, 1.00f, 0.65f);
		glVertex3f(-1.00f, 1.00f,-0.65f);
		glVertex3f(-0.83636364f, 1.45f,-0.52727273f);
		glVertex3f(-0.83636364f, 1.45f, 0.52727273f);
	glEnd();
	
	// side windows
	glBegin(GL_QUADS);
	// z+
		glNormal3f(0, 0.2631174f, 0.9647638f);
		glVertex3f( 0.00f, 1.00f, 0.75f);
		glVertex3f( 0.00f, 1.45f, 0.6272727f);
		glVertex3f( 0.55f, 1.45f, 0.6272727f);
		glVertex3f( 0.70f, 1.00f, 0.75f);
	
		glVertex3f(-0.90f, 1.00f, 0.75f);
		glVertex3f(-0.75f, 1.45f, 0.6272727f);
		glVertex3f(-0.10f, 1.45f, 0.6272727f);
		glVertex3f(-0.10f, 1.00f, 0.75f);
	// z+
		glNormal3f(0, 0.2631174f,-0.9647638f);
		glVertex3f( 0.70f, 1.00f,-0.75f);
		glVertex3f( 0.55f, 1.45f,-0.6272727f);
		glVertex3f( 0.00f, 1.45f,-0.6272727f);
		glVertex3f( 0.00f, 1.00f,-0.75f);
	
		glVertex3f(-0.10f, 1.00f,-0.75f);
		glVertex3f(-0.10f, 1.45f,-0.6272727f);
		glVertex3f(-0.75f, 1.45f,-0.6272727f);
		glVertex3f(-0.90f, 1.00f,-0.75f);
	glEnd();

	glColor4f(0.6f, 0.6f, 0.6f, 1);
	parallelepiped(0.1f, 0.15f, 1.6f, 2.05f, 0.275f, 0);
	parallelepiped(0.05f, 0.35f, 0.8f, 2.025f, 0.575f, 0);
	parallelepiped(0.1f, 0.15f, 1.5f, -1.9f, 0.325f, 0);
}

