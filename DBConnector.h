#include "fun.h"
#include "funAdmin.h"
#include "funClientes.h"
#include <iostream>
#include "sqlite3.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class DBConnector {

private:
		sqlite3 *db = NULL;

public:
	int mostrarLibros() { //para un query
		sqlite3_stmt *stmt;

		char sql[] = "select * from Libros";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << " Error preparando sentencia (SELECT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}
		cout << "SQL query preparada (SELECT)" << endl;

		Libro *lib;
	//	int id;
	//	char name[100];
		cout << endl;
		cout << "Mostrando Libros" << endl;
		do {
			result = sqlite3_step(stmt) ; //cojo el resultado
			if (result == SQLITE_ROW) {
	//			id = sqlite3_column_int(stmt, 0); //cógeme una columna que su integer es 0
	//			strcpy(name, (char *) sqlite3_column_text(stmt, 1));
				strcpy(lib->isbn, (char *) sqlite3_column_text(stmt, 0));
				strcpy(lib->titulo, (char *) sqlite3_column_text(stmt, 1));
				strcpy(lib->autor, (char *) sqlite3_column_text(stmt, 2));
				strcpy(lib->genero, (char *) sqlite3_column_text(stmt, 3));
			//	lib->precio = sqlite3_column_double(stmt, 4);
				strcpy(lib->precio, (char *) sqlite3_column_text(stmt, 4));
				strcpy(lib->desc, (char *) sqlite3_column_text(stmt, 5));
				strcpy(lib->anyo, (char *) sqlite3_column_text(stmt, 6));
				strcpy(lib->editorial, (char *) sqlite3_column_text(stmt, 7));
	//			printf("ID: %d Name: %s\n", id, name);
			}
		} while (result == SQLITE_ROW);  //cuando no sea ROW quiere decir que ya no hay más

		cout << endl;

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizando sentencia (SELECT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}
		cout << "Sentencia finalizada (SELECT)" << endl;

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

	int insertarLibro(Libros *lib) {
		sqlite3_stmt *stmt;

		char sql[] = "insert into Libros values (?, ?, ?, ?, ?, ?, ?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ; //el NULL significa que no le hemos puesto ningun valor a id
		if (result != SQLITE_OK) {
			cout << "Error preparando sentencia (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		cout << "SQL query preparada (INSERT)" << endl;
/*
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
*/


		result = sqlite3_bind_text(stmt, 1, lib->isbn.c_str(), lib->isbn.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout << "Error uniendo parametros" << endl;
			cout << sqlite3_errmsg(db) << endl;
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 2, lib->titulo.c_str(), lib->titulo.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout << "Error uniendo parametros" << endl;
			cout << sqlite3_errmsg(db) << endl;
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 3, lib->autor.c_str(), lib->autor.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout << "Error uniendo parametros" << endl;
			cout << sqlite3_errmsg(db) << endl;
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 4, lib->genero.c_str(), lib->genero.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout << "Error uniendo parametros" << endl;
			cout << sqlite3_errmsg(db) << endl;
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

/*		result = sqlite3_bind_int(stmt, 5, lib->precio);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
*/
		result = sqlite3_bind_double(stmt, 5, lib->precio);
		if (result != SQLITE_OK) {
			cout << "Error uniendo parametros" << endl;
			cout << sqlite3_errmsg(db) << endl;
		//	printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 6, lib->desc.c_str(), lib->desc.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout << "Error uniendo parametros" << endl;
			cout << sqlite3_errmsg(db) << endl;
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 7, lib->anyo.c_str(), lib->anyo.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout << "Error uniendo parametros" << endl;
			cout << sqlite3_errmsg(db) << endl;
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 8, lib->editorial.c_str(), lib->editorial.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout << "Error uniendo parametros" << endl;
			cout << sqlite3_errmsg(db) << endl;
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			cout << "Error insertando nuevos datos en tabla Libros" << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizando sentencia (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}
		cout << "Sentencia finalizada (INSERT)" << endl;

		return SQLITE_OK;
	}

	DBConnector(std::string dbFile) { //en el constructor es donde iniciamos la BD
		int result = sqlite3_open("Amazonas.sqlite", &db); //nombre de la BD, y le pasamos la dirección del puntero
		if (result != SQLITE_OK) {
			cout << "Error abriendo BD" << endl;

		}
	}

	~DBConnector() {
		int result = sqlite3_close(db); //cerramos la base de datos, le pasamos el puntero
		if (result != SQLITE_OK) {
			cout << "Error abriendo BD" << endl;
			cout << sqlite3_errmsg(db) << endl;
		}	
	}
};