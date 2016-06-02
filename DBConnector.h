#include "fun.h"
#include "funAdmin.h"
#include "funClientes.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "sqlite3.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void clear_if_needed(char *str){
	if (str[strlen(str) - 1] != '\n')
	{
		int c;
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}

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

	int agregarLibro(sqlite3 *db){
		int total;
		std::ifstream f("libros.txt");
		string line;
		for (total = 0; getline(f, line); total++)
		    ;
		cout <<"Lineas totales: "<<total<<endl;
	//HASTA AQUÍ DETECTAMOS CUANTAS FILAS HAY EN EL FICHERO PARA AHORA AGREGAR SOLO EL ÚLTIMO 

		FILE* fi;
	    char leer[100];
	    char linea[100];
	    int counter =1;
	    int cont = 0;
	    int aux = 1;
	    Libro *lib = new Libro();

		fi = fopen("libros.txt", "r");

	    if (fi==NULL){
	    	cout<<"Error al abrir el fichero" << endl;

	    }else{
			
	    	while (fgets(linea, 100, fi)) {
	    		if (total-8 == cont)
	    		{
		    		clear_if_needed(linea);
					sscanf(linea, "%[^\n]", &leer);
					switch(aux){
						case 1: strcpy(lib->isbn, leer); break;
						case 2: strcpy(lib->titulo, leer); break;
						case 3: strcpy(lib->autor, leer); break;
						case 4: strcpy(lib->genero, leer); break;
						case 5: strcpy(lib->precio, leer); break;
						case 6: strcpy(lib->desc, leer); break;
						case 7: strcpy(lib->anyo, leer); break;
						case 8: strcpy(lib->editorial, leer); break;
					}
					aux++;
					total++;
	    		} cont++;
	    		
			}
		}
		fclose(fi);

	    sqlite3_stmt *stmt;

		char sql[] = "insert into Libro (isbn, titulo, autor, genero, precio, desc, anyo, editorial) values (?, ?, ?, ?, ?, ?, ?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
		cout <<"INSERT preparada"<< endl;

		result = sqlite3_bind_text(stmt, 1, lib->isbn, strlen(lib->isbn), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout <<"Error preparando parametros"<< endl;
			cout << sqlite3_errmsg(db) <<endl;
			return result;
		}
		result = sqlite3_bind_text(stmt, 2, lib->titulo, strlen(lib->titulo), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout <<"Error preparando parametros"<< endl;
			cout << sqlite3_errmsg(db) <<endl;
			return result;
		}
		result = sqlite3_bind_text(stmt, 3, lib->autor, strlen(lib->autor), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout <<"Error preparando parametros"<< endl;
			cout << sqlite3_errmsg(db) <<endl;
			return result;
		}
		result = sqlite3_bind_text(stmt, 4, lib->genero, strlen(lib->genero), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout <<"Error preparando parametros"<< endl;
			cout << sqlite3_errmsg(db) <<endl;
			return result;
		}
		result = sqlite3_bind_text(stmt, 5, lib->precio, strlen(lib->precio), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout <<"Error preparando parametros"<< endl;
			cout << sqlite3_errmsg(db) <<endl;
			return result;
		}
		result = sqlite3_bind_text(stmt, 6, lib->desc, strlen(lib->desc), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout <<"Error preparando parametros"<< endl;
			cout << sqlite3_errmsg(db) <<endl;
			return result;
		}
		result = sqlite3_bind_text(stmt, 7, lib->anyo, strlen(lib->anyo), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout <<"Error preparando parametros"<< endl;
			cout << sqlite3_errmsg(db) <<endl;
			return result;
		}
		result = sqlite3_bind_text(stmt, 8, lib->editorial, strlen(lib->editorial), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			cout <<"Error preparando parametros"<< endl;
			cout << sqlite3_errmsg(db) <<endl;
			return result;
		}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			cout<<"Error insertando nuevos datos a la tablas"<< endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizando sentencia (INSERT)"<< endl;
			cout << sqlite3_errmsg(db)<< endl;
			return result;
		}
		cout << "Sentencia finalizada (INSERT)"<< endl;

	    delete lib;
	    return SQLITE_OK;
	}
};