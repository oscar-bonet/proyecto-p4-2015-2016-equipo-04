#include <stdio.h>
#include "fun.h"
#include "funAdmin.h"
#include "funClientes.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/**********************************MENU PRINCIPAL**********************************/

int main(int argc, char *argv[]){

	int opcAdmin=0;
	int opcCliente=-1;
	Cliente *cl;

	//ES UN ERROR
	if (argc>2) 
		cout << "Numero de argumentos excesivos." << endl;
	//ES UN ERROR
	if((argc == 2) && (strcmp(argv[1], "admin") != 0))
		cout << "Argumento no valido." << endl;
	//LOGIN COMO ADMIN
	if((argc == 2) && (strcmp(argv[1], "admin") == 0)){
		
		opcAdmin=menuAdmin();

		do{
			switch(opcAdmin){

				case 1: anyadirLibro();
						opcAdmin = menuAdmin();
						break;
				case 2: modificarLibro();
						opcAdmin = menuAdmin();
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
				cout << "Usuario: " << endl;
					cin >> cl->usuario;

				cout << "Password: " << endl;
					cin >> cl->password;
				existe = comparacion(cl, 1);	

				if (existe == 1){
					cout << "Log in correcto." << endl;
				}else{
					cout << "Usuario y/o contrasenya incorrectos." << endl;
				}

			} while (existe == 0);

		}

		if (log == 2){ //crear cliente
			
			do{
				cout << "NUEVO CLIENTE: " << endl;
				cout << "\tUsuario: " << endl;
					cin >> cl->usuario;

				cout << "\tPassword: " << endl;
					cin >> cl->password;
				
				existe = comparacion(cl, 2);	

				if (existe == 1){
					cout << "El usuario ya existe; por favor, cambia el nombre del usuario." << endl;
				}

				if (existe == 0){
					writeCl(cl);
					cout << "Usuario creado correctamente." << endl;
				}

			}while (existe == 1);

		}

		opcCliente=menuCliente();
		if(opcCliente != -1){
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