#include "fun.h"
#include "funAdmin.h"
#include "funClientes.h"
#include <iostream>
#include "sqlite3.h"
#include <string.h>

using namespace std;

class DBConnector {

private:
		sqlite3 *db = NULL;

public:
	int mostrarLibros() { //para un query
		sqlite3_stmt *stmt;

		char sql[] = "select id, name from country";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (SELECT)\n");

		int id;
		char name[100];

		printf("\n");
		printf("\n");
		printf("Showing countries:\n");
		do {
			result = sqlite3_step(stmt) ; //cojo el resultado
			if (result == SQLITE_ROW) {
				id = sqlite3_column_int(stmt, 0); //cógeme una columna que su integer es 0
				strcpy(name, (char *) sqlite3_column_text(stmt, 1));
				printf("ID: %d Name: %s\n", id, name);
			}
		} while (result == SQLITE_ROW);  //cuando no sea ROW quiere decir que ya no hay más

		printf("\n");
		printf("\n");

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (SELECT)\n");

		return SQLITE_OK;
	}
	/*
	int deleteAllCountry() {
		sqlite3_stmt *stmt;

		char sql[] = "delete from country";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ; //declaramos el pointer stmt y le pasamos la direccion del pointer.
		if (result != SQLITE_OK) {
			printf("Error preparing statement (DELETE)\n"); //lo saca por cmd
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (DELETE)\n");

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error deleting data\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (DELETE)\n");

		return SQLITE_OK; //hago la comprobacion de SQLITE_OK para mandar fuera que todo va bien
	}*/
	/*
	int insertNewCountry(std::string country) { //el parámetro es un string (en C no existen los strings, pero en C++ sí)
		sqlite3_stmt *stmt;

		char sql[] = "insert into country (id, name) values (NULL, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");

		result = sqlite3_bind_text(stmt, 1, country.c_str(), country.length(), SQLITE_STATIC); //funcion que transforma el string a char pointer, c_str devuelve un string de C
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_step(stmt); //hay que mirarlo con el DONE
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into country table\n");
			return result;
		}

		result = sqlite3_finalize(stmt); //hay que mirarlo con el OK
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (INSERT)\n");

		return SQLITE_OK;
	}*/

	int insertarLibro(int id, std::string name) {
		sqlite3_stmt *stmt;

		char sql[] = "insert into country (id, name) values (?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ; //el NULL significa que no le hemos puesto ningun valor a id
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");

		result = sqlite3_bind_int(stmt, 1, id);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 2, name.c_str(), name.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into country table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (INSERT)\n");

		return SQLITE_OK;
	}

	DBConnector(std::string dbFile) { //en el constructor es donde iniciamos la BD
		int result = sqlite3_open("Amazonas.sqlite", &db); //nombre de la BD, y le pasamos la dirección del puntero
		if (result != SQLITE_OK) {
			printf("Error opening database\n");

		}
	}

	~DBConnector() {
		int result = sqlite3_close(db); //cerramos la base de datos, le pasamos el puntero
		if (result != SQLITE_OK) {
			printf("Error opening database\n");
			printf("%s\n", sqlite3_errmsg(db));
		}	
	}
};

int main(){
	
	DBConnector dbConnector("Amazonas.sqlite");

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

	return 0;
}