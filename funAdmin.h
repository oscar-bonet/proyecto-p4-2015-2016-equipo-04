#include "fun.h"

#ifndef _FUNADMIN_H_
#define _FUNADMIN_H_

#ifdef __cplusplus
extern "C" {
#endif

int menuLoginAdmin();

int menuAdmin();
void readCl();
void anyadirLibro ();
void modificarLibro();
void writeLib(Libro* lib);

#ifdef __cplusplus
}
#endif

#endif