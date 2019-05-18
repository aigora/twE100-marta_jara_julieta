#include <stdio.h>
#include <string.h>


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

struct tareas{
	char nombre[50];
	char fecha[50];
	char lugar [50];	
};


struct contactos PedirContacto (void);
struct tareas PedirTarea (void);
void MostrarFichero  (FILE *p_f);


int main () {
	
	//menu general
	int opcion1;
	int salida = 2;//Salir del programa
	
	//opcion contactos
	int opcion2;
	struct contactos contacto;
	char continuar;
	
	//opcion tareas
	int opcion3;
	struct tareas tarea;
	char continuar2;

	
	//Fichero
	FILE *p_archivo;

	
	
	do {
		system("cls");
		LOGOTIPO();
		MENU1();
		scanf("%d", &opcion1);
		fflush (stdin);	
		switch (opcion1) {
			case 1:
					system ("cls");
					LOGOTIPO();
					MENUCONTACTOS();
					scanf("%d", &opcion2);
					fflush (stdin);	
					switch (opcion2) {
						case 1: //mostrar lista contactos
						
							//abrimos fichero
							p_archivo = fopen ("ListaContactos.txt", "r");
							
							puts ("\n\nContactos guardados:\n");
							MostrarFichero (p_archivo);
							puts ("\n\nPulse 'V' para volver al menu principal\n");
							system("pause");

							
						break;
						case 2: //guardar un contacto
							do{
							contacto = PedirContacto ();
							
							// Paso a un archivo
							p_archivo = fopen ("ListaContactos.txt", "a+");
							// Verificar o no...
							// Se escribe en el archivo:
							fprintf (p_archivo, "\n%s\n%s\n%s", contacto.nombre, contacto.telefono, contacto.email);
		
							fclose (p_archivo);

							printf("\nDesea guardar otro contacto? s-si , n-no\n");
							scanf("%s", &continuar);
							fflush (stdin);
							system ("cls");
							} while (continuar=='s');

						break;
					}
			case 2:
					system ("cls");
					LOGOTIPO();
					MENUTAREAS();
					scanf("%d", &opcion3);
					fflush (stdin);	
					switch (opcion3) {
						case 1: //mostrar lista tareas
						
							//abrimos fichero
							p_archivo = fopen ("ListaTareas.txt", "r");
							
							puts ("\n\nTareas pendientes:\n");
							MostrarFichero (p_archivo);
							puts ("\n\nPulse 'V' para volver al menu principal\n");
							system("pause");

						break;
						case 2: //guardar una tarea
							do{
							tarea = PedirTarea ();
							
							// Paso a un archivo
							p_archivo = fopen ("ListaTareas.txt", "a+");
							// Verificar o no...
							// Se escribe en el archivo:
							fprintf (p_archivo, "\n%s\n%s\n%s", tarea.nombre, tarea.fecha, tarea.lugar); //poner ejemplo
		
							fclose (p_archivo);

							printf("\nTiene otra tarea pendiente? s-si , n-no\n");
							scanf("%s", &continuar2);
							fflush (stdin);
							system ("cls");
							} while (continuar2=='s');
					}

				break;
			case 3:
				printf ("Los contactos permaneceran en la agenda, almacenandose en el archivo ListaContactos.tmx \nAsi como las tareas pendientes en ListaTareas.tmx\n");
				sleep(1200);
				break;
					
			case 4:
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
	printf("-->1. Lista de contactos\n");//MENU: Ver contactos, añadir contacto, eliminar contacto.
	printf("-->2. Calendario\n");//MENU: Ver calendario, añadir evento, eliminar evento
	printf("-->3. Observaciones del uso de la agenda\n");	
	printf("-->4. Salir de la agenda\n");
	
	return;
}

void MENUCONTACTOS() {
	printf("\t\tZona CONTACTOS\n");
	printf("->1. Ver mis contactos\n->2. Guardar un contacto\n->>3. Volver al menu principal\n");
	return;
}

void MENUTAREAS() {
	printf("\t\tZona TAREAS\n");
	printf("->1. Ver mis tareas\n->2. Guardar una tarea nueva\n->>3. Volver al menu principal\n");
	return;
}

void LOGOTIPO(){
	printf("\t\t ____________________________\n");
	printf("\t\t|         BIENVENIDO         |\n");
	printf("\t\t|         A SU AGENDA        |\n");
	printf("\t\t|____________________________|\n");
	printf("\n\n");
}

struct contactos PedirContacto(void) {
	struct contactos contacto;
	
	printf("Introduzca el nombre del contacto que desea guardar:\n");
	scanf("%s", &contacto.nombre);
	fflush (stdin);	
	printf("Introduzca el numero de telefono:\n");
	scanf("%s", &contacto.telefono);
	fflush (stdin);	
	printf("Introduzca el email:\n");
	scanf("%s", &contacto.email);
	fflush (stdin);	
	return contacto;
}

struct tareas PedirTarea(void) {
	struct tareas tarea;
	
	printf("Que tarea tiene pendiente proximamente?:\n");
	scanf("%s", &tarea.nombre);
	fflush (stdin);	
	printf("Indique la fecha de la tarea (ejemplo: dd/mm/aaaa):\n");
	scanf("%s", &tarea.fecha);
	fflush (stdin);	
	printf("Donde tendra lugar la tarea? (ejemplo: C/Emabajadores, Madrid):\n");
	scanf("%s", &tarea.lugar);
	fflush (stdin);	
	return tarea;
}

void MostrarFichero (FILE *p_f)
{
	char c[50];
	while (feof(p_f)==0)
	{
		fgets (c,49,p_f);
		printf ("%s", c);
	}
}
