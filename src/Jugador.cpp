#include "Jugador.h"
#include "glut.h"
#include "bitmap.h"

Jugador::Jugador(void)
{
	radio=0.5;
	posicion.x=posicion.y=0;
	posicion.z = 1;
	g=b=200;
	r=0;
	p1.mov.z = 1;
	p1.ang = p1.mov.y;
}


Jugador::~Jugador(void)
{
}

void Jugador::Dibuja(){
	glColor3f(r,g,b);
	glTranslatef(ptomira.x, ptomira.y, 1);
	glutSolidSphere(radio,20,20);
	glTranslatef(-ptomira.x, -ptomira.y,-1);
	glBegin(GL_LINES);
	glVertex3f(posicion.x, posicion.y, posicion.z);
	glVertex3f(ptomira.x, ptomira.y, 1);
	glEnd();
}

void Jugador::Mouse(int button, int state, int x, int y){
	switch (button){
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN){
			botonpulsado = true;
		}
		else
			botonpulsado = false;
	}
}

void Jugador::Motion(int x, int y){
	if (botonpulsado == true){
		ptomira.x = ((float)x - 400) / 16.82f;
		ptomira.y = ((float)y - 300) / -16.82f;
		ptomira.z = 1;
	}
}

void Jugador::PassiveMotion(int x, int y){
	ptomira.x = ((float)x - 400) / 16.82f;
	ptomira.y = ((float)y - 300) / -16.82f;
	ptomira.z = 1;
}

void Jugador::Pinta(){
	GLUquadric* obj = gluNewQuadric();
	
	static bitmap cuerpo("cuerpo.bmp");
	static bitmap cabeza("cabeza.bmp");
	glDisable(GL_LIGHTING);

	glTranslatef(posicion.x,posicion.y,0);

	glRotatef(angrot, 0,0,1);

	glColor3ub(100, 100, 100);//cabeza
	glTranslatef( 0, 0, 3);
	glRotatef(45,0,0,1);
	cabeza.usarTextura();
	glColor3ub(255, 255, 255);
	GLUquadricObj *cab = gluNewQuadric();
	gluQuadricOrientation(cab, GLU_OUTSIDE);
	gluQuadricTexture(cab, GL_TRUE);
	gluCylinder(cab, 0.3,0.3,0.5, 4, 2);
	gluDeleteQuadric(cab);
	glDisable(GL_TEXTURE_2D);
	glRotatef(-45, 0, 0, 1);
	glTranslatef(0,0, -3);

	

	glColor3ub(0, 100, 100);//cuerpo
	glTranslatef(0, 0, 1.4);
	cuerpo.usarTextura();
	glColor3ub(255, 255, 255);
	GLUquadricObj *cue = gluNewQuadric();
	gluQuadricOrientation(cue, GLU_OUTSIDE);
	gluQuadricTexture(cue, GL_TRUE);
	gluCylinder(cue, 0.5,0.5, 1.6,20, 20);
	gluDeleteQuadric(cue);
	glDisable(GL_TEXTURE_2D);
	glTranslatef(0,0,1.6);
	gluDisk(obj,0,0.50,20,20);
	glTranslatef(0,0,-3);

	

	glColor3ub(150,150,150);//pierna izq
	glTranslatef(0, 0.25, 1.2);
	p1.Anima();
	glTranslatef(0, -0.25, -1.2);

	glColor3ub(150, 150, 150);//pierna der
	glTranslatef(0, -0.25, 1.2);
	p2.Anima();
	glTranslatef(0, 0.25, -1.2);

	glColor3ub(100, 255, 100);//brazo izq
	glTranslatef(0, 0.7, 2);
	c1.Anima();
	glTranslatef(0, -0.7, -2);

	glColor3ub(0, 0, 0);//brazo der
	glTranslatef(0, -0.7, 2.8);
	glRotatef(90,0,1,0);
	gluDisk(obj, 0, 0.20, 20, 20);
	gluCylinder(obj, 0.2, 0.2, 1.4, 20, 20);
	glTranslatef(0,0,1.4);
	glColor3ub(100, 255, 100);
	gluDisk(obj, 0.1, 0.20, 20, 20);
	glTranslatef(0, 0, -1.4);
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0.7, -2.8);

	glRotatef(-angrot, 0,0, 1);

	glTranslatef(-posicion.x, -posicion.y, 0);

	glEnable(GL_LIGHTING);
}

void Jugador::Rota(){
	Vector3D v1 = Vector3D::creavector(posicion, ptomira);
	Vector3D dirx;
	dirx.x = 1;
	dirx.y = 0;
	dirx.z = 0;
	if (ptomira.y >= posicion.y)
		angrot = Vector3D::angvect(dirx, v1);
	if (ptomira.y < posicion.y){
		float aux = Vector3D::angvect(dirx, v1);
		angrot = -aux;
	}
}

void Jugador::Mueve(unsigned char key){
	if (key == 'w') posicion.y += 0.5;
	if (key == 's') posicion.y -= 0.5;
	if (key == 'd') posicion.x += 0.5;
	if (key == 'a') posicion.x -= 0.5;
}

void Jugador::Anima(){
	c1.Anima();
}

