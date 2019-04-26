//Menú principal

#include <stdio.h>

//Funciones de menus y logotipos
void MENU1();
void MENUCONTACTOS();
void MENUTAREAS();
void LOGOTIPO();

int main () {
	int opcion1;
	int salida = 2;//Salir del programa
	int opcion2;
	
	do {
		system("cls");
		LOGOTIPO();
		MENU1();
		scanf("%d", &opcion1);
		fflush (stdin);	
		getchar();
		switch (opcion1) {
			case 1:
				do{
					system ("cls");
					LOGOTIPO();
					MENUCONTACTOS();
					scanf("%d", &opcion2);
					fflush (stdin);	
					getchar();
					switch (opcion2) {
						case 1:
							printf("aqui se ven los contactos"); //ESTO ES UN EJEMPLO PARA VER SI SALE
							break;
						case 2:
							printf("aqui se crea un contacto");
						case 3:
							printf("aqui se crea un contacto"); 
					
					}
				}while (opcion2 != 4);			
				break;
		
			case 2:
				printf("Aqui iria el calendario\n");
				break;
		
			case 3:
				printf("Aqui se cerraria el programa\n");
				break;

			default:printf("Elija entre las opciones del menu\n");
			}//Final del menu principal	
	}while (salida == 2);//Se repite hasta que se decida salir del programa 
}

void MENU1() {  
	printf("\tElija entre nuestras opciones\n");
	printf("-->1. Lista de contactos\n");//MENU: Ver contactos, añadir contacto, eliminar contacto.
	printf("-->2. Calendario\n");//MENU: Ver calendario, añadir evento, eliminar evento
	printf("-->3. Salir de la agenda\n");	
	return;
}

void MENUCONTACTOS() {
	printf("\t\tZona CONTACTOS\n");
	printf("->1. Ver mis contactos\n->2. Guardar un contacto\n->3. Borrar un contacto\n->>4. Volver al menu principal\n");
	return;
}

void MENUTAREAS() {
	printf("\t\tZona TAREAS\n");
	printf("->1. Ver mis tareas\n->2. Guardar una tarea nueva\n->3. Borrar una tarea\n->>4. Volver al menu principal\n");
	return;
}

void LOGOTIPO(){
	printf("\t\t ____________________________\n");
	printf("\t\t|         LOGOTIPO           |\n");
	printf("\t\t|  DE LA AGENDA O CALENDARIO |\n");
	printf("\t\t|____________________________|\n");
	printf("\n\n");
}
