#include <stdio.h>
#include "fun.h"
#include "funAdmin.h"
#include "funClientes.h"
#include <string.h>
#include <stdlib.h>

/**********************************MENU PRINCIPAL**********************************/

int main(int argc, char *argv[]){

	int opcAdmin=0;
	int opcCliente=0;
	int opcAnCl=0;
	int opc = 0;
	Cliente *cl;
	char str[20];

	//ES UN ERROR
	if (argc>2) 
		printf("Numero de argumentos excesivos.\n");

	//ES UN ERROR
	if((argc == 2) && (strcmp(argv[1], "admin") != 0))
		printf("Argumento no valido.\n");

	//LOGIN COMO ADMIN
	if((argc == 2) && (strcmp(argv[1], "admin") == 0)){
		
		opcAdmin=menuAdmin();

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

		} while((opcAdmin > 0) && (opcAdmin < 4));
	}

	//LOGIN COMO CLIENTE
	if(argc == 1){

		int log = menuLogin();
		int existe = 1;
		
		if (log == 1){ //cliente ya hecho

			do{
				cl = (Cliente*) malloc (sizeof(Cliente));

				printf("Usuario: ");
					fgets(str, 20, stdin);
					clear_if_needed(str);
					sscanf(str, "%s", cl->usuario);

				printf("Password: ");
					fgets(str, 20, stdin);
					clear_if_needed(str);
					sscanf(str, "%s", cl->password);

				existe = comparacion(cl, 1);	

				if (existe == 1){
					printf("Log in correcto.\n");
				}else{
					printf("Usuario y/o contrasenya incorrectos.\n");
				}

			} while (existe == 0);

			free (cl);
			cl = 0;
		}

		if (log == 2){ //crear cliente

			cl = (Cliente*) malloc (sizeof(Cliente));
			
			do{
				printf("NUEVO CLIENTE: \n");
				printf("\tUsuario: ");
					fgets(str, 20, stdin);
					clear_if_needed(str);
					sscanf(str, "%s", cl->usuario);

				printf("\tPassword: ");
					fgets(str, 20, stdin);
					clear_if_needed(str);
					sscanf(str, "%s", cl->password);
				
				existe = comparacion(cl, 2);	

				if (existe == 1){
					printf("El usuario ya existe, por favor, cambia el nombre del usuario.\n");
				}

				if (existe == 0){
					writeCl(cl);
					printf("Usuario creado correctamente.\n");
				}

			}while (existe == 1);

			free (cl);
			cl = 0;
		}

		
		opcCliente=menuCliente();
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
			} while((opcCliente > 0) && (opcCliente < 6));
		}
		
	}
}


/*
do{
			opc = menuLogin();

			switch(opc){

				case 1: opcCliente = menuCliente();
						break;
				case 2: cl = (Cliente*) malloc (sizeof(Cliente));
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
						//HE QUITADO UNA LLAMADA A MAIN
						break;
				default: error(); break;
			}
		} while((opc < 0) && (opc > 4));
*/