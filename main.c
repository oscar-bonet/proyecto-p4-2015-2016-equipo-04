#include <stdio.h>

int main()
{
	int opcAdmin;
	int opcCliente;

	do{
		menuLogin();
		int opc = scanf();
			switch(opc){

				case 1: menuAdmin();
						opcAdmin = scanf();
					break;
				case 2: menuCliente();
						opcCliente = scanf();
					break;
				default: error();
			}
	} while((opc < 1) || (opc > 2));

	if(opcAdmin != 0)
	do{
			switch(opcAdmin){

				case 1: 
					break;
				case 2: 
					break;
				case 3: 
					break;
				case 4: 
					break;
				default: error();
			}
	} while((opcAdmin < 1) || (opcAdmin > 4));

	if(opcCliente != 0)
	do{
			switch(opcCliente){

				case 1: menuComprarLibro();
					break;
				case 2: 
					break;
				case 3:
					break;
				case 4: 
					break;
				case 5: 
					break;
				case 6: 
					break;
				default: error();
			}
	} while((opcCliente < 1) || (opcCliente > 6));



	return 0;
}