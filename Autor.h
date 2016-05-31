#ifndef AUTOR_H_
#define AUTOR_H_

#include "Persona.h"
#include <string>

class Autor: public Persona{

	string premio;

public:
	Autor(string nombre, int edad, string premio);
	~Autor();
	
};

#endif