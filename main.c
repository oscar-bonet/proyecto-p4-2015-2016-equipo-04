#include <stdio.h>
#include "funciones.h"
#include <string.h>

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


/**********************************MENU PRINCIPAL**********************************/

int main(){
	
	int opcAdmin=0;
	int opcCliente=0;
	int opcAnCl=0;
	int opc = 0;
	Cliente *cl;
	char str[20];



	do{
		opc = menuLogin();

		switch(opc){

			case 1: opcAdmin = menuAdmin();
					break;
			case 2: opcCliente = menuCliente();
					break;
			case 3: cl = (Cliente*) malloc (sizeof(Cliente));
					printf("Nombre de usuario: ");
						fgets(str, 20, stdin);
						clear_if_needed(str); 
						sscanf(str, "%s", cl->usuario);
					printf("Password: ");
						fgets(str, 20, stdin);
						clear_if_needed(str); 
						sscanf(str, "%s", cl->password);
					writeCl(cl);
					free(cl);
					cl=0;
					main();
					break;
			default: error(); break;
		}
	} while((opc < 1) || (opc > 3));


	if(opcAdmin != 0){
		do{
				switch(opcAdmin){

					case 1: anyadirLibro();
							opcAdmin = menuAdmin();
							break;
					case 2: opcAdmin = menuAdmin();
							break;
					case 3: readCl();
							opcAdmin = menuAdmin();
							break;
					case 4: break; //salimos de la aplicacion
					default: error();
				}
		
		} while((opcAdmin > 1) && (opcAdmin < 4));
	}

	if(opcCliente != 0){
		do{
				switch(opcCliente){

					case 1: menuComprarLibro();
							opcCliente = menuCliente();
							break;
					case 2: opcCliente = menuCliente();
							break;
					case 3:	opcCliente = menuCliente();
							break;
					case 4: opcCliente = menuCliente();
							break;
					case 5: opcCliente = menuCliente();
							break;
					case 6: break; //salimos de la aplicacion
					default: error();
				}
		} while((opcCliente > 1) && (opcCliente < 6));
	}
}