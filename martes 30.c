#include <stdio.h>
#include <string.h>
#define NUMCONTACTOS 100

//Funciones de menus y logotipos
void MENU1();
void MENUCONTACTOS();
void MENUTAREAS();
void LOGOTIPO();
struct contactos{
		char nombre [50];
		char telefono [50];
		char email [25];	
};
struct TAux { //Estructura auxiliar
char nombre[50];
char telefono[50];
char email[25];
};

int main () {
	int opcion1;
	int salida = 2;//Salir del programa
	int opcion2;
	int k=0, j=0;
	struct contactos cont[NUMCONTACTOS];
	struct TAux aux;
	int comp1,auxx=0;
	
	
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
						case 2: //guardar un contacto
							do {
								printf("Introduzca el contacto que desea guardar\n");
								scanf("%s", &aux.nombre);
								for (k = 0; k < j; k++) {
									comp1 = strcmp(aux.nombre, cont[k].nombre); //Compara entre todos los contactos
									if (comp1 == 0) {
									break;
									}
								}
									
								if (comp1 == 0) {
									if (j == NUMCONTACTOS) {
										printf("NO SE PUEDEN GUARDAR MAS CONTACTOS\n");	
									}
									else {
										strcpy(cont[j].nombre, aux.nombre); //guarda el nombre nuevo en contactos
										printf("Introduzca el telefono del contacto\n");
										scanf("%s", &cont[j].telefono, 50);
										printf("Introduzca email del contacto\n");
										scanf("%s", &cont[j].email, 25);
										printf("Se ha guardado %s como nuevo contacto\n", cont[j].nombre);
										Sleep(2000);
										j = j++;
									}
								}
								else {
									printf("Ya existe un contacto con ese nombre, intente con otro nombre\n"); // para que no se guarden dos contactos con el mismo nombre
								}
							} while (comp1 == 0);
							break;
						
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
	printf("\t\t|         BIENVENIDO         |\n");
	printf("\t\t|         A SU AGENDA        |\n");
	printf("\t\t|____________________________|\n");
	printf("\n\n");
}
