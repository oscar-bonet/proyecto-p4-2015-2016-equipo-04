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
		sqlite3 *db;

public:

	int mostrarLibros(sqlite3 *db) { 
		
		sqlite3_stmt *stmt;

		char sql[] = "select * from libro";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << " Error preparando sentencia (SELECT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}
		cout << "SQL query preparada (SELECT)" << endl;


		int cont = 0;
		int counter =1;
		cout << endl;
		cout << "Mostrando Libros" << endl;
		cout << endl;
		int total = sqlite3_column_count(stmt);

		string* datos = new string[8];
			datos[0] = "ISBN:";
			datos[1] = "TITULO:";
			datos[2] = "AUTOR:";
			datos[3] = "GENERO:";
			datos[4] = "PRECIO:";
			datos[5] = "DESCRIPCION:";
			datos[6] = "ANYO:";
			datos[7] = "EDITORIAL:";

		do {
			result = sqlite3_step(stmt);
			if (result == SQLITE_ROW) {
				for(int i=0; i<total;i++){
					string s1 = (char*) sqlite3_column_text (stmt, i);
						cout << datos[cont] << s1 << endl;
					if (counter % 8 == 0){
						printf("\n");
						cont=-1;
						cout << endl;
					}
					counter++;
					cont++;
				}
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

		delete[] datos;
		return SQLITE_OK;
	}
};