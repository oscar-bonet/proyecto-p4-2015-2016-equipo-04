#include "Autor.h"
#include <string>

Autor::Autor(string nombre, int edad, string premio): Persona(nombre, edad){

	this->premio = premio;
}

Autor::~Autor(){}
