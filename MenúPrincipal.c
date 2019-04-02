//Menú principal

#include <stdio.h>

void MENU1();//FUNCION MENU	

void main () {
	int opcion1;
	
	do {
		//system("cls");
		MENU1();
		scanf("%d", &opcion1);
		getchar();
		switch (opcion1) {
			case 1:
				printf("Aqui iria la lista de conactos\n");
				break;
		
			case 2:
				printf("Aqui iria el calendario\n");
				break;
		
			case 3:
				printf("Aqui se cerraria el programa\n");
				break;

			default:printf("Elija entre las opciones del menu\n");
			}//Final del menu principal	
	}while (opcion1 !=3 );//Se repite hasta que se decida salir del programa
	
	

}

void MENU1() //FUNCION MENU
{ 
	printf("\tElija entre nuestras opciones\n");
	printf("-->1. Lista de contactos\n"); //MENU: Ver contactos, añadir contacto, eliminar contacto.
	printf("-->2. Calendario\n");//MENU: Ver calendario, añadir evento, eliminar evento
	printf("-->3. Salir de la agenda\n");
	
	return;
}

