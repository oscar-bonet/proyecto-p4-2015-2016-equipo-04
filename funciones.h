#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

typedef struct{
	char isbn[20];
	char titulo[40];
	char autor[20];
	char genero[20];
	char precio[10];
	char desc[40];
	char anyo[5];
	char editorial[20];
}Libro;

typedef struct{
	char usuario[20];
	char password[20];
}Cliente;

int menuLogin();
void error();
int menuAdmin();
int menuCliente();
void menuComprarLibro();

void anyadirLibro ();
void writeLib(Libro* lib);
void readLib();
void writeCl(Cliente* cl);


#endif