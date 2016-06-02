#include "fun.h"
#include "funAdmin.h"
#include "funClientes.h"
#include <iostream>
#include "sqlite3.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "DBConnector.h"
#include "Autor.h"

using namespace std;

int main(){

	sqlite3 *db;
	DBConnector dbConnector;

	int result = sqlite3_open("Amazonas.s3db", &db);
		if (result != SQLITE_OK) {
			cout << "Error abriendo BD" << endl;
			return result;
		} else{
			cout << "BD abierta. " << endl;
	}

	int opc;

	cout << "BASE DE DATOS: " << endl;
	cout << "\t1. Anyadir ultimo libro a la base de datos" << endl;
	cout << "\t2. Mostrar libros de la base de datos" << endl;
	cout << "\tx. Salir" << endl;
	cout << "Seleccione una opcion: " << endl;
	cin >> opc;
	cout << endl;

	switch(opc){
		case 1: {
				cout << "AÑADIR LIBRO A LA BASE DE DATOS" << endl; 
				int result = dbConnector.agregarLibro(db);
				if (result != SQLITE_OK) {
					cout << "Error guardando libro!" << endl;
					return result;
				}
			}
				break;
		case 2: {
				int result = dbConnector.mostrarLibros(db); //para hacer una query
				if (result != SQLITE_OK) {
					cout << "Error obteniendo todos los libros!" << endl;
					return result;
				}
			}
				break;
	}

	result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		cout << "Error cerrando la BD. " << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	} else{
		cout << "BD cerrada." << endl;
	}

	return 0;
}