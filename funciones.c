#include "funciones.h"
#include <stdio.h>

void menuLogin(){
	printf("LOGIN:\n");
	printf("\t1. Administrador\n");
	printf("\t2. Cliente\n");
	printf("Seleccione una opcion: ");
}

void error(){
	printf("Se ha producido un error, revise los datos introducidos.\n");
}

void menuAdmin(){
	printf("ADMINISTRADOR:\n");
	printf("\t1. Añadir un libro a la tienda\n");
	printf("\t2. Modificar datos de un libro\n");
	printf("\t3. Ver lista de clientes\n");
	printf("\t4. Salir\n");
	printf("Seleccione una opcion: ");
}

void menuCliente(){
	printf("CLIENTES:\n");
	printf("\t1. Buscar un libro\n");
	printf("\t2. Ver la cesta\n");
	printf("\t3. Lista de deseos\n");
	printf("\t4. Modificar perfil\n");
	printf("\t5. Agregar fondos a la cuenta\n");
	printf("\t6. Salir\n");
	printf("Seleccione una opcion: ");
}

void menuComprarLibro(){
	printf("BUSCAR:\n");
	printf("\t1. Buscar por autor\n");
	printf("\t2. Buscar por titulo\n");
	printf("\t3. Buscar por genero\n");
	printf("\t4. Salir\n");
	printf("Seleccione una opcion: ");
}