#include "funClientes.h"
#include "fun.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menuLogin(){
	char str[2];
	int num;

		printf("\nLOGIN CLIENTE:\n");
		printf("\t1. Cliente\n");
		printf("\t2. Nuevo cliente\n");
		printf("Seleccione una opcion: ");

		fgets(str, 2, stdin);
		//clear_if_needed(str);

		sscanf(str, "%d", &num);
		printf("\n");

	return num;
}


void menuCliente(){
	char str[2];
	int num;
	printf("\nCLIENTES:\n");
	printf("\t1. Ver libros\n");
	printf("\t2. Agregar a la lista de deseos\n");
	printf("\t3. Ver lista de deseos\n");
	printf("\t4. Salir\n");
	printf("Seleccione una opcion: ");
}

void agregarDeseos(char* usuario){
	
	readLib();
	printf("PARA MI LISTA DE DESEOS:\n");
	char isbn[20];
	printf("Seleccione un ISBN deseado: ");
	clear_if_needed(isbn);
	fgets(isbn, 20, stdin);
	sscanf(isbn, "%s", isbn);
	printf("\n");

	FILE* f;
        int c;

	f = fopen("deseos.txt", "a");

	fprintf(f, "%s\n", usuario);
	fprintf(f, "%s\n", isbn);

	//cerrar fichero
	fclose(f);

}

void writeCl(Cliente* cl){
	FILE* f;
        int c;

	f = fopen("clientes.txt", "a");

	fprintf(f, "%s\n", cl->usuario);
	fprintf(f, "%s\n", cl->password);

	//cerrar fichero
	fclose(f);
}


void verCarrito(char* usuario){
		FILE* f;
        char c;
        char leer[50];
	char linea[100];
		int counter =1;
		int semaforo=0;
	//abrir fichero para lectura
	f = fopen("deseos.txt", "r");

    if (f==NULL){
    	printf("Error al abrir el fichero\n");

    }else{

		while (fgets(linea, 50, f)) {
			clear_if_needed(linea);			
			sscanf(linea, "%[^\n]", &leer);
			if (strcmp(leer,usuario)==0)
				semaforo=1;
			if ((semaforo==1)&&(counter % 2 == 0)){
				//sscanf(linea, "%[^\n]", &leer);
				printf("ISBN: %s\n",leer);
				semaforo = 0;
			}
			counter++;
		}
	}

	//cerrar fichero
	fclose(f);

}
int comparacion (Cliente* cl, int opc){
	FILE* f;
    char c;
    char leer[20];
	char linea[50];
	int counter = 1;
	int comp = 0;
	int aux = 0;

	//abrir fichero para lectura
	f = fopen("clientes.txt", "r");

    if (f==NULL){
    	printf("Error al abrir el fichero\n");

    }else{
		while (fgets(linea, 20, f)) {
			
			if(opc == 1){ //LOG IN
				clear_if_needed(linea);
				if (counter % 2 != 0){
					sscanf(linea, "%s", &leer);
					if (strcmp(leer, cl->usuario) == 0)
						aux = 1;
				}
				if (aux==1){
					counter++;
					clear_if_needed(linea);
					if (counter % 2 == 0){
						sscanf(linea, "%s", &leer);
						if (strcmp(leer,cl->password) == 0)
							comp = 1;
					}
				}
			
			} else if(opc == 2){ //NUEVO CLIENTE
				
				if (counter % 2 != 0){
					sscanf(linea, "%s", &leer);
					if (strcmp(leer, cl->usuario) == 0){
						comp = 1;
					}
				}
			}
			counter++;
		}
	}

	//cerrar fichero
	fclose(f);
	return comp;
}