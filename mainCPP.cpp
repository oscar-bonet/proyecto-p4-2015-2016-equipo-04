#include "fun.h"
#include "funAdmin.h"
#include "funClientes.h"
#include <iostream>
#include "sqlite3.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "DBConnector.h"

using namespace std;

int main(){
	
	DBConnector dbConnector("Amazonas.sqlite");
	int result = dbConnector.mostrarLibros(); //para hacer una query
	if (result != SQLITE_OK) {
		cout << "Error obteniendo todos los libros!" << endl;
		return result;
	}

	result = dbConnector.insertNewCountry("France");
	if (result != SQLITE_OK) {
		cout << "Error insertando datos!"
		return result;
	}

	/*
	int result = dbConnector.deleteAllCountry();
	if (result != SQLITE_OK) {
		printf("Error deleting all countries\n");
		return result;
	}

	result = dbConnector.insertNewCountry("France");
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		return result;
	}*/
/*
	result = dbConnector.insertNewCountryID(200, "France");
	if (result != SQLITE_OK) {
		printf("Error inserting new data with id: 200. Already exists\n");
		return result;
	}

	result = dbConnector.showAllCountries(); //para hacer una query
	if (result != SQLITE_OK) {
		printf("Error getting all countries\n");
		return result;
	}
*/
	return 0;
}