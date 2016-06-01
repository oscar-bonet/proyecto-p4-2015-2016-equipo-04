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

	int agregarLibro(sqlite3 *db){
		int total;
		std::ifstream f("libros.txt");
		std::string line;
		for (total = 1; std::getline(f, line); total++)
		    ;

	//HASTA AQUÍ DETECTAMOS CUANTAS FILAS HAY EN EL FICHERO PARA AHORA AGREGAR SOLO EL ÚLTIMO 

		FILE* f;
	    char leer[100];
	    char linea[100];
	    int counter =1;
	    int cont = 0;
	    int aux = 1;
	    Libro *lib = (Libro*) malloc (sizeof(Libro));

		f = fopen("libros.txt", "r");

	    if (f==NULL){
	    	printf("Error al abrir el fichero\n");

	    }else{
			
	    	while (fgets(linea, 100, f)) {
	    		if (total-8 == cont)
	    		{
		    		clear_if_needed(linea);
					sscanf(linea, "%[^\n]", &leer);
					switch(aux){
						case 1: lib->isbn = leer; break;
						case 2: lib->titulo = leer; break;
						case 3: lib->autor = leer; break;
						case 4: lib->genero = leer; break;
						case 5: lib->precio = leer; break;
						case 6: lib->desc = leer; break;
						case 7: lib->anyo = leer; break;
						case 8: lib->editorial = leer; break;
					}
					aux++;
					total++;
	    		} cont++;
	    		
			}
		}
		fclose(f);

	//HEMOS LEIDO LOS ATRIBUTOS DEL LIBRO A GUARDAR, AHORA VAMOS A METERLO EN LA BD

		std::stringstream strm;
		strm << "insert into libro values('" << lib->isbn << ",'" << lib->titulo << "','" << lib->autor << "','" << lib->genero
			<< "','" << lib->precio << "','" << lib->desc << "','" << lib->anyo << "','" << lib->editorial << "')";

		char *str = &s[0];
		sqlite3_stmt * statement;
		int result;
		char *query = str;
	    {
	        if(sqlite3_prepare(dbfile,query,-1,&statement,0)==SQLITE_OK)
	        {
	            int res=sqlite3_step(statement);
	            result=res;
	            sqlite3_finalize(statement);
	        }
	        return result;
	    }
	    return 0;
	}
};