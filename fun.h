#ifndef _FUN_H_
#define _FUN_H_

#ifdef __cplusplus
extern "C" {
#endif

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

void clear_if_needed(char *str);

void error();

void readLib();

#ifdef __cplusplus
}
#endif

#endif