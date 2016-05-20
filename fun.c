#include "fun.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
	Esta funcion elimina los caracteres pendientes si es necesario.
	Se usa junto con fgets para leer la entrada hasta cierta longitud.
*/

void clear_if_needed(char *str){
	if (str[strlen(str) - 1] != '\n')
	{
		int c;
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}

void error(){
	printf("Se ha producido un error, revise los datos introducidos.\n");
}

void readLib(){
	FILE* f;
        char c;
        char leer[100];
        char linea[100];

	//abrir fichero para lectura
	f = fopen("libros.txt", "r");

    if (f==NULL){
    	printf("Error al abrir el fichero\n");

    }else{
		//leer mientras no se llegue al final del fichero EOF (leer cualquier archivo de texto)
		//while ((c = fgetc(f)) != EOF){ //leemos caracter a caracter y escribirlo.
    	while (fgets(linea, 100, f)) {
    		
    		clear_if_needed(linea);
			sscanf(linea, "%[^\n]", &leer);
			printf("ISBN: %s\n", leer);

			clear_if_needed(linea);
			sscanf(linea, "%[^\n]", &leer);
			printf("TITULO: %s\n", leer);
			
			clear_if_needed(linea);
			sscanf(linea, "%[^\n]", &leer);
			printf("AUTOR: %s\n", leer);
			
			clear_if_needed(linea);
			sscanf(linea, "%[^\n]", &leer);
			printf("GENERO: %s\n", leer);
			
			clear_if_needed(linea);
			sscanf(linea, "%[^\n]", &leer);
			printf("PRECIO: %s\n", leer);
			
			clear_if_needed(linea);
			sscanf(linea, "%[^\n]", &leer);
			printf("DESCRIPCION: %s\n", leer);
			
			clear_if_needed(linea);
			sscanf(linea, "%[^\n]", &leer);
			printf("ANYO: %s\n", leer);
			
			clear_if_needed(linea);
			sscanf(linea, "%[^\n]", &leer);
			printf("EDITORIAL: %s\n", leer);
			clear_if_needed(linea);
			printf("\n");
			//fscanf(f, " %[^\n]", &leer); -----> ES ESTA LA QUE HACE QUE SE SALTE UNA LÍNEA, PERO SI SE DEJA ASÍ, AÑADE UN LIBRO MÁS.****************

			//putchar(c); //escribir el caracter en la linea de comandos
		}
	}

	//cerrar fichero
	fclose(f);
}