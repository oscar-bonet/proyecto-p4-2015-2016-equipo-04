#include "funAdmin.h"
#include "fun.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menuLoginAdmin(){
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

int menuAdmin(){
	char str[2];
	int num;

	printf("\nADMINISTRADOR:\n");
	printf("\t1. Anyadir un libro a la tienda\n");
	printf("\t2. Modificar datos de un libro\n");
	printf("\t3. Ver lista de clientes\n");
	printf("\t4. Salir\n");
	printf("Seleccione una opcion: ");

	fgets(str, 2, stdin);
	clear_if_needed(str);

	sscanf(str, "%d", &num);
	printf("\n");

	return num;
}

void anyadirLibro (){
	Libro *lib;
	char str[50];

	lib = (Libro*) malloc (sizeof(Libro));

	printf("\nANYADIR LIBRO:\n");

	printf("\tISBN: ");
		fgets(str, 20, stdin);
		clear_if_needed(str);
		sscanf(str,"%[^\n]", lib->isbn);

	printf("\tTitulo: ");
		fgets(str, 50, stdin);
		clear_if_needed(str);
		sscanf(str, "%[^\n]", lib->titulo);


	printf("\tAutor: ");
		fgets(str, 50, stdin);
		clear_if_needed(str);
		sscanf(str, "%[^\n]", lib->autor);

	printf("\tGenero: ");
		fgets(str, 20, stdin);
		clear_if_needed(str);
		sscanf(str, "%[^\n]", lib->genero);

	printf("\tPrecio: ");
		fgets(str, 20, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", lib->precio);

	printf("\tDescripcion: ");
		fgets(str, 50, stdin);
		clear_if_needed(str);
		sscanf(str, "%[^\n]", lib->desc);

	printf("\tAnyo: ");
		fgets(str, 5, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", lib->anyo);

	printf("\tEditorial: ");
		fgets(str, 20, stdin);
		clear_if_needed(str);
		sscanf(str,"%[^\n]", lib->editorial);

	printf("\nLibro anyadido: \n");
		printf("\tISBN: %s\n", lib->isbn);
		printf("\tTITULO: %s\n", lib->titulo);
		printf("\tAUTOR: %s\n", lib->autor);
		printf("\tGENERO: %s\n", lib->genero);
		printf("\tPRECIO: %s\n", lib->precio);
		printf("\tDESCRIPCION: %s\n", lib->desc);
		printf("\tANYO: %s\n", lib->anyo);
		printf("\tEDITORIAL: %s\n", lib->editorial);

	writeLib(lib);
	free(lib);
	lib = 0;
}



void writeLib(Libro* lib){
	FILE* f;
    int c;

	f = fopen("libros.txt", "a");

	fprintf(f, "%s\n", lib->isbn);
	fprintf(f, "%s\n", lib->titulo);
	fprintf(f, "%s\n", lib->autor);
	fprintf(f, "%s\n", lib->genero);
	fprintf(f, "%s\n", lib->precio);
	fprintf(f, "%s\n", lib->desc);
	fprintf(f, "%s\n", lib->anyo);
	fprintf(f, "%s\n", lib->editorial);

	//cerrar fichero
	fclose(f);
}

void readCl(){

	FILE* f;
        char c;
        char leer[50];

	//abrir fichero para lectura
	f = fopen("clientes.txt", "r");

    if (f==NULL){
    	printf("Error al abrir el fichero\n");

    }else{
		//leer mientras no se llegue al final del fichero EOF (leer cualquier archivo de texto)
		//while ((c = fgetc(f)) != EOF){ //leemos caracter a caracter y escribirlo.
    	while ((c = fgetc(f)) != EOF) {

			fscanf(f, "%s\n", &leer);
			printf("Usuario: %s\n", leer);
			fscanf(f, "%s\n", &leer);
			//fscanf(f, " %[^\n]", &leer); -----> ES ESTA LA QUE HACE QUE SE SALTE UNA LÍNEA, PERO SI SE DEJA ASÍ, AÑADE UN LIBRO MÁS.****************

			//putchar(c); //escribir el caracter en la linea de comandos
		}
	}

	//cerrar fichero
	fclose(f);
}
