#include "fun.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void error(){
	printf("Se ha producido un error, revise los datos introducidos.\n");
}

void readLib(){
	FILE* f;
        char c;
        char leer[50];

	//abrir fichero para lectura
	f = fopen("libros.txt", "r");

    if (f==NULL){
    	printf("Error al abrir el fichero\n");

    }else{
		//leer mientras no se llegue al final del fichero EOF (leer cualquier archivo de texto)
		//while ((c = fgetc(f)) != EOF){ //leemos caracter a caracter y escribirlo.
    	while ((c = fgetc(f)) != EOF) {

			fscanf(f, "%s\n", &leer);
			printf("ISBN: %s\n", leer);
			fscanf(f, "%s\n", &leer);
			printf("TITULO: %s\n", leer);
			fscanf(f, "%s\n", &leer);
			printf("AUTOR: %s\n", leer);
			fscanf(f, "%s\n", &leer);
			printf("GENERO: %s\n", leer);
			fscanf(f, "%s\n", &leer);
			printf("PRECIO: %s\n", leer);
			fscanf(f, "%s\n", &leer);
			printf("DESCRIPCION: %s\n", leer);
			fscanf(f, "%s\n", &leer);
			printf("ANYO: %s\n", leer);
			fscanf(f, "%s\n", &leer);
			printf("EDITORIAL: %s\n\n", leer);
			//fscanf(f, " %[^\n]", &leer); -----> ES ESTA LA QUE HACE QUE SE SALTE UNA LÍNEA, PERO SI SE DEJA ASÍ, AÑADE UN LIBRO MÁS.****************

			//putchar(c); //escribir el caracter en la linea de comandos
		}
	}

	//cerrar fichero
	fclose(f);
}