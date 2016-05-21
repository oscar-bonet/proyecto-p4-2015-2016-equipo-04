#include "funClientes.h"
#include "fun.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
int menuLogin(){
	char str[2];
	int num;

		printf("\nLOGIN:\n");
		printf("\t1. Administrador\n");
		printf("\t2. Cliente\n");
		printf("\t3. Nuevo cliente\n");
		printf("Seleccione una opcion: ");

		fgets(str, 2, stdin);
		clear_if_needed(str);

		sscanf(str, "%d", &num);
		printf("\n");

	return num;
}
*/
int menuCliente(){
	char str[2];
	int num;

	printf("\nCLIENTES:\n");
	printf("\t1. Buscar un libro\n");
	printf("\t2. Ver la cesta\n");
	printf("\t3. Lista de deseos\n");
	printf("\t4. Modificar perfil\n");
	printf("\t5. Agregar fondos a la cuenta\n");
	printf("\t6. Salir\n");
	printf("Seleccione una opcion: ");

	fgets(str, 2, stdin);
	clear_if_needed(str);

	sscanf(str, "%d", &num);
	printf("\n");

	return num;
}
void menuComprarLibro(){
	char str[2];
	int num;

	printf("\nBUSCAR:\n");
	printf("\t1. Mostrar libros.\n");
	printf("\t2. Buscar por autor.\n");
	printf("\t3. Buscar por titulo.\n");
	printf("\t4. Atras\n");
	printf("Seleccione una opcion: ");

	fgets(str, 2, stdin);
	clear_if_needed(str);
	sscanf(str, "%d", &num);

	switch(num){
		case 1: readLib();
				menuComprarLibro();
				break;
		case 2: menuComprarLibro();
				break;
		case 3: menuComprarLibro();
				break;
		case 4: menuCliente(); //volvemos al anterior menu
				break;
		default: error();
	}

	sscanf(str, "%d", &num);
	printf("\n");
}

void writeCl(Cliente* cl){
	FILE* f;
        int c;

	f = fopen("clientes.txt", "a");

	fprintf(f, "0%s\n", cl->usuario);
	fprintf(f, "%s\n", cl->password);

	//cerrar fichero
	fclose(f);
}