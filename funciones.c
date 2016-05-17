#include "funciones.h"
#include <stdio.h>
#include <string.h>

#define varLib 8


/**
	Esta funcion saca por pantalla el menu de log in
	y devuelve el número de la opción seleccionada.
*/
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

/**
	Esta funcion saca un mensaje de error cuando el usuario escoge un número no válido en algún menu.
*/
void error(){
	printf("Se ha producido un error, revise los datos introducidos.\n");
}


/**
	Esta funcion saca por pantalla el menu de los administradores
	y devuelve el número de la opción seleccionada.
*/
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


/**
	Esta funcion saca por pantalla el menu de los clientes
	y devuelve el número de la opción seleccionada.
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


/**
	Esta funcion saca por pantalla el menu de buscar algún
	libro y devuelve el número de la opción seleccionada.
*/
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


/**
	Esta funcion saca por pantalla el menu de añadir un libro
	a la tienda y lo almacenará en el fichero de 'libros.txt'.
*/
void anyadirLibro (){

	Libro *lib;
	char str[50];

	lib = (Libro*) malloc (sizeof(Libro));

	printf("\nANYADIR LIBRO:\n");

	printf("\tISBN: ");
		fgets(str, 20, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", lib->isbn);

	printf("\tTitulo: ");
		fgets(str, 50, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", lib->titulo);


	printf("\tAutor: ");
		fgets(str, 50, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", lib->autor);

	printf("\tGenero: ");
		fgets(str, 20, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", lib->genero);

	printf("\tPrecio: ");
		fgets(str, 20, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", lib->precio);

	printf("\tDescripcion: ");
		fgets(str, 50, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", lib->desc);

	printf("\tAnyo: ");
		fgets(str, 5, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", lib->anyo);

	printf("\tEditorial: ");
		fgets(str, 20, stdin);
		clear_if_needed(str);
		sscanf(str, "%s", lib->editorial);

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


/**
	Esta funcion se le pasa un libro con todos sus datos
	y lo almacena en el fichero 'libros.txt'.
*/
void writeLib(Libro* lib){

	FILE* f;
    int c;

	f = fopen("libros.txt", "a");

	fprintf(f, "0%s\n", lib->isbn);
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


/**
	Esta funcion saca por pantalla los libros que hay en la tienda (almacenados en 'libros.txt').
*/
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

/* ******************SACAR POR PANTALLA USANDO ARRAYS DE STRINGS******************(intento)

	FILE* f;
        char c;

        int i, x;
        int num_lines=0;

	//abrir fichero para lectura
	f = fopen("libros.txt", "r");

	while ((c = fgetc(f)) != EOF) //leemos caracter a caracter y escribirlo; y además, contar el numero de lineas
	{
		if (c == '\n')
			num_lines++;
	}

	int li = (num_lines/varLib);

	char libro[li][varLib];

  	for(x = 0; x < li; x++){
	   for(i = 0; i < varLib; i++){
			fscanf(f, " %s", libro[x][i]);
		}
	}

	printf("Numero de libros: %d\n",li);


	for (i=0; i<li; i++){
		printf("ISBN: %s\n", libro[i][0]);
		printf("TITULO: %s\n", libro[i][1]);
		printf("AUTOR: %s\n", libro[i][2]);
		printf("GENERO: %s\n", libro[i][3]);
		printf("PRECIO: %s\n", libro[i][4]);
		printf("DESCRIPCION: %s\n", libro[i][5]);
		printf("ANYO: %s\n", libro[i][6]);
		printf("EDITORIAL: %s\n\n", libro[i][7]);
	}

	//cerrar fichero
	fclose(f);
	*/

void writeCl(Cliente* cl){

	FILE* f;
        int c;

	f = fopen("clientes.txt", "a");

	fprintf(f, "0%s\n", cl->usuario);
	fprintf(f, "%s\n", cl->password);

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
