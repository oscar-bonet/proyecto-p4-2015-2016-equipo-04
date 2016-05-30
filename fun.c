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

/**
	Funcion que salta cuando se introduce un dato erróneo.
*/
void error(){
	printf("Se ha producido un error, revise los datos introducidos.\n");
}

/**
	Leer datos del fichero libros.txt
*/
void readLib(){
	FILE* f;
    char leer[100];
    char linea[100];
    int counter =1;
    int cont = 0;

	char **datos=(char**) malloc ((8)*sizeof(char*));
		datos[0] = "ISBN:";
		datos[1] = "TITULO:";
		datos[2] = "AUTOR:";
		datos[3] = "GENERO:";
		datos[4] = "PRECIO:";
		datos[5] = "DESCRIPCION:";
		datos[6] = "ANYO:";
		datos[7] = "EDITORIAL:";

	f = fopen("libros.txt", "r");

    if (f==NULL){
    	printf("Error al abrir el fichero\n");

    }else{
		
    	while (fgets(linea, 100, f)) {
    		
    		clear_if_needed(linea);
			sscanf(linea, "%[^\n]", &leer);
			printf("%s %s\n",datos[cont],leer);

			if (counter % 8 == 0){
				printf("\n");
				cont=-1;
			}
			counter++;
			cont++;
		}
	}

	fclose(f);
}