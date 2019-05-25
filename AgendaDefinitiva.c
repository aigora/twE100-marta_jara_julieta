#include <stdio.h>
#include <string.h>


//Funciones de menus, logotipos y ficheros
void MENU1();
void MENUCONTACTOS();
void MENUTAREAS();
void LOGOTIPO();
void MostrarFichero  (FILE *p_f);

//estructuras principales
struct contactos{
		char nombre [50];
		char telefono [50];
		char email [25];	
};

struct tareas{
	char nombre[50];
	char fecha[10];
	char lugar [50];	
};


struct contactos PedirContacto (void);
struct tareas PedirTarea (void);

//Menú principal

int main () {
	
	system("color 2F"); //Color verde y letras blancas
	
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
	
	//opcion observaciones
	int opcion4;

	
	//Fichero
	FILE *p_archivo;

	
	
	do {
		system("cls");
		LOGOTIPO();
		printf ("  Sus datos han sido cargados, es hora de organizarse...\n\n");
		MENU1();
		scanf("%d", &opcion1);
		fflush (stdin);	
		switch (opcion1) {
			case 1://CONTACTOS
					system ("cls");
					LOGOTIPO();
					MENUCONTACTOS();
					scanf("%d", &opcion2);
					fflush (stdin);	
					switch (opcion2) {
						case 1: //mostrar lista contactos
							system ("cls");
							LOGOTIPO();
						
							//abrimos fichero
							p_archivo = fopen ("ListaContactos.txt", "r");
							
							puts ("\n\nContactos guardados:\n");
							MostrarFichero (p_archivo);
							puts ("\n\nPulse 'V' para volver al menu principal\n");
							system("pause");
						break;
						case 2: //guardar un contacto
							do{
							system ("cls");
							LOGOTIPO();
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
							} while (continuar=='s');
					}
				break;
			case 2://CALENDARIO
					system ("cls");
					LOGOTIPO();
					MENUTAREAS();
					scanf("%d", &opcion3);
					fflush (stdin);	
					switch (opcion3) {
						case 1: //mostrar lista tareas
							system ("cls");
							LOGOTIPO();
						
							//abrimos fichero
							p_archivo = fopen ("ListaTareas.txt", "r");
							
							puts ("\n\nTareas pendientes:\n");
							MostrarFichero (p_archivo);
							puts ("\n\nPulse 'V' para volver al menu principal\n");
							system("pause");

						break;
						case 2: //guardar una tarea
							do{
							system ("cls");
							LOGOTIPO();
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
							} while (continuar2=='s');
					}

				break;
			case 3://pequeñas observaciones de la app
				system ("cls");
				LOGOTIPO();
				do{
					printf ("\n  Esta agenda esta pensada para su uso personal, aqui podra guardar"); 
					printf ("\n  los contactos que permaneceran en la agenda, almacenandose en el");
					printf ("\n  archivo ListaContactos.txt \n ");
					printf ("\n  Ademas dispone de una parte en la que tambien es posible guardar"); 
					printf ("\n  las tareas pendientes, almacenandose en ListaTareas.txt\n");
					printf("  \n\nPulse 1 para volver al menu principal\n");
					scanf ("%d", &opcion4);
				} while (opcion4 =! 1);
			
				break;
					
			case 4://salida
				printf("\n\nEsperemos que haya puesto en orden sus asuntos...\n\n");
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
	printf("-->1. Contactos\n");//MENU: Ver contactos, añadir contacto.
	printf("-->2. Calendario\n");//MENU: Ver calendario, añadir evento.
	printf("-->3. Observaciones del uso de la agenda\n");	
	printf("-->4. Salir de la agenda\n");
	
	return;
}

void MENUCONTACTOS() {
	printf("\t\tZona CONTACTOS\n");
	printf("->1. Ver mis contactos\n");
	printf("->2. Guardar un contacto\n");
	printf("->>3. Volver al menu principal\n");
	return;
}

void MENUTAREAS() {
	printf("\t\tZona TAREAS\n");
	printf("->1. Ver mis tareas\n");
	printf("->2. Guardar una tarea nueva\n");
	printf("->>3. Volver al menu principal\n");
	return;
}

void LOGOTIPO(){
	printf("\t\t ____________________________\n");
	printf("\t\t|                            |\n");
	printf("\t\t|      ~~ BIENVENIDO ~~      |\n");
	printf("\t\t| ~~ A SU AGENDA PERSONAL ~~ |\n");
	printf("\t\t|____________________________|\n");
	printf("\n\n");
}

struct contactos PedirContacto(void) {
	struct contactos contacto;
	void nombreValido(char nombre[50]);//para comprobar que mete un nombre de entre 3 y 10 caracteres
	void telefonoValido(char telefono[10]);//Para comprobar que el telefono es valido
	
	printf("Introduzca el nombre del contacto que desea guardar:\n");
	nombreValido(contacto.nombre);
	fflush (stdin);	
	printf("Introduzca el numero de telefono:\n");
	telefonoValido(contacto.telefono);
	fflush (stdin);	
	printf("Introduzca el email:\n");
	gets(contacto.email);
	fflush (stdin);	
	return contacto;
}

struct tareas PedirTarea(void) {
	struct tareas tarea;
	
	printf("Que tarea tiene pendiente proximamente?:\n");
	gets(tarea.nombre);
	fflush (stdin);	
	printf("Indique la fecha de la tarea (ejemplo: dd/mm/aaaa):\n");
	gets(tarea.fecha);
	fflush (stdin);	
	printf("Donde tendra lugar la tarea? (ejemplo: C/Emabajadores, Madrid):\n");
	gets(tarea.lugar);
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

void nombreValido(char nombre[50]) {
	int i, longitud, final;

	do {
		gets(nombre);
		fflush(stdin);
		longitud = strlen(nombre);
		if (longitud < 3 ) { //Si tiene menos de 3 caracteres
			final = -2;
		}
		else {
			for (i = 0; nombre[i] != '\0'; i++) {

				if ((nombre[i] < 'a' || nombre[i]> 'z') && (nombre[i] < 'A' || nombre[i]> 'Z')) {//Si no hay letras
					final = -1;
				}
				else {
					final = 1;
					break;
				}
			}
		}

		if (final == -2) {
			printf("El nombre debe tener mas de 3 letras, introduzca de nuevo un nombre:\n");
		}
		else if (final == -1) {
			printf("El nombre debe de contener letras, introduzca de nuevo un nombre:\n");
		}

	} while (final != 1);
}

void telefonoValido(char telefono[9]) {
	int i, longitud, final;

	do {
		gets(telefono);
		fflush(stdin);
		longitud = strlen(telefono);
		if (longitud != 9) { //Si no tiene 9 números
			final = -1;
		}
		else {
			final=1;
			break;
		}

		if (final == -1) {
			printf("El telefono debe tener 9 cifras, introduzca de nuevo un numero\n");
		}

	} while (final != 1);
}
