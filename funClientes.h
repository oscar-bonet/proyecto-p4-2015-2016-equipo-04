#include "fun.h"

#ifndef _FUNCLIENTES_H_
#define _FUNCLIENTES_H_

#ifdef __cplusplus
extern "C" {
#endif

int menuLogin();

void agregarDeseos(char* usuario);
int menuCliente();
void menuComprarLibro();

void writeCl(Cliente* cl);
int comparacion(Cliente* cl, int opc);

#ifdef __cplusplus
}
#endif

#endif