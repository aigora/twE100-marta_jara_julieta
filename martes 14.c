#include <stdio.h>
#include <string.h>
#define NUMCONTACTOS 100
#define NUMTAREAS 100

//Funciones de menus y logotipos
void MENU1();
void MENUCONTACTOS();
void MENUTAREAS();
void LOGOTIPO();
typedef struct contactos{
		char nombre [50];
		char telefono [50];
		char email [25];	
} Tcontactos;
Tcontactos PedirTelefono (void);
void MostrarFichero (FILE *p_f);
//char c;

typedef struct tareas{
	char nombretarea[50];
	char fecha[50];
	char lugar [50];	
}Ttareas;
Ttareas PedirTarea(void);
void MostrarTarea (FILE *p_f);
//char t;


int main (){
	int opcion1;
	int salida = 2;//Salir del programa
	int opcion2;
	int k=0, j=0, l=0;
	typedef struct contactos cont[NUMCONTACTOS];
	struct contactos aux;
	//Tcontactos cont;
	FILE *p_archivo;
	//cont= PedirTelefono ();
	//char c; (char para contactos)
	typedef struct tareas tarea[NUMTAREAS];
	//struct tareas aux;
	//Ttareas tarea;
	FILE *p_archivo;
	//char t; (char para tareas)
	int comp1,auxx=0;
	int comp2, auxx=0;
	FILE *p_archivo;
	//	char c;
	cont = PedirTelefono (); //pedir informacion sobre un contacto para saber si esta guardado
			
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
					switch (opcion1) {
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
					switch (opcion 1) 
						case 1://mostrar si un telefono esta guardado (ver mis contactos)
							do{
								cont = PedirTelefono (); //se pide el telefono
								printf ("\nIntroduzca el numero de telefono: %s", cont.telefono);
	
								// Paso a un archivo
								p_archivo = fopen ("Base.txt", "a+");
				 				// Verificar o no...
								// Se escribe en el archivo:
								fprintf (p_archivo, "\n%s %s %s", cont.nombre, cont.telefono, cont.email);
								rewind (p_archivo);
	
								puts ("\n\nY en Base.txt tenemos...\n");
								MostrarFichero (p_archivo);
	
								fclose (p_archivo);
								return 123;
							}
				}
					
						}
					}
				}while (opcion2 != 4);			
				break;
		
			case 2:
				do {
						do{
					system ("cls");
					LOGOTIPO();
					MENUTAREAS();
					scanf("%d", &opcion2);
					fflush (stdin);	
					getchar();
					switch (opcion 2) {
						case 2: //guardar una tarea
							do {
								printf("nombre de la tarea:");
								scanf("%s", &aux.nombre.tarea);
								strcpy(tarea[l].nombre.tarea, aux.nombre.tarea); //guarda la nueva tarea
								printf("Introduzca la fecha de la tarea");
								scanf("%s", &tarea[l].fecha, 50);
								printf("Introduzca el lugar donde se realizar� la tarea");
								scanf("%s", &tarea[j].lugar, 50);
								printf("Se ha guardado %s como una nueva tarea en su agenda", tarea[l].nombre.tarea);
								Sleep(2000);
										l = l++;
									}
								}
							break;
						
					}
					switch (opcion 2){ //mostrar datos sobre una tarea
					case 1: //ver mis tareas o buscar una tarea
							do{
								tarea = PedirTarea ();
								//se pide el nombre de la tarea (ej:dentista)
								printf ("\nIntroduzca el nombre de la tarea: %s", tarea.nombre.tarea);
								// Paso a un archivo
								p_archivo = fopen ("Base.txt", "a+");
				 				// Verificar o no...
								// Se escribe en el archivo:
								fprintf (p_archivo, "\n%s %s %s", tarea.nombre.tarea, tarea.fecha, tarea.lugar);
								rewind (p_archivo);
								puts ("\n\nY en Base.txt tenemos...\n");
								MostrarFichero (p_archivo);
	
								fclose (p_archivo);
								return 123;
							}
							break;
						}
			}
				break;
		
			case 3:
				printf("Vuelva pronto, hasta la proxima!\n");
				salida = 1;
				Sleep(1200);
				break;

			default:printf("Elija entre las opciones del menu\n");
			}//Final del menu principal	
	}while (salida == 2);//Se repite hasta que se decida salir del programa 
}

void MENU1() {  
	printf("\tElija entre nuestras opciones\n");
	printf("-->1. Lista de contactos\n");//MENU: Ver contactos, a�adir contacto, eliminar contacto.
	printf("-->2. Calendario y tareas\n");//MENU: Ver calendario, a�adir evento, eliminar evento
	printf("-->3. Salir de la agenda\n");	
	return;
}


//CONTACTOS
void MENUCONTACTOS() {
	printf("\t\tZona CONTACTOS\n");
	printf("->1. Ver mis contactos\n->2. Guardar un contacto\n->3. Borrar un contacto\n->>4. Volver al menu principal\n");
	return;
}
void MostrarFichero (FILE *p_f)
{
	char c;
	while (c != EOF)
	{
		c = fgetc (p_f);
		printf ("%c", c);
	}
}
Tcontactos PedirTelefono (void)
{
	Tcontactos c;
	// Se pide la informaci�n
	return c;
}


//TAREAS
void MENUTAREAS() {
	printf("\t\tZona TAREAS\n");
	printf("->1. Ver mis tareas\n->2. Guardar una tarea nueva\n->3. Borrar una tarea\n->>4. Volver al menu principal\n");
	return;
}
void MostrarTarea (FILE *p_f)
{
	char t;
	while (t != EOF)
	{
		t = fgetc (p_f);
		printf ("%t", t);
	}
}
Ttareas PedirTarea (void) //por ejemplo que el usuario escriba "dentista" y la agenda diga el dia de la tarea y lugar
{
	Ttareas t;
	// Se pide la informaci�n

	return t;
}


void LOGOTIPO(){
	printf("\t\t ____________________________\n");
	printf("\t\t|         BIENVENIDO         |\n");
	printf("\t\t|         A SU AGENDA        |\n");
	printf("\t\t|____________________________|\n");
	printf("\n\n");
}
