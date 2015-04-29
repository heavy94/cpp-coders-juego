#pragma once
#include "Vector3D.h"
#include "bitmap.h"



class Jugador
{
public:
	//variables
	float radio;
	Vector3D posicion;
	Vector3D ptomira;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	bool botonpulsado;
	float angrot;
	//metodos
	Jugador(void);
	void Mouse(int, int, int, int);
	void Motion(int, int);
	void PassiveMotion(int, int);
	~Jugador(void);
	void Pinta();
	void Dibuja();
	void Rota();
	void Mueve(unsigned char);
	void Anima();
};
