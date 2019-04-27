// guardar contactos dentro de la agenda

switch (opcion2){
	case 2: //guardar un contacto
	do{
		system ("cls");
		LOGOTIPO();
		MENUCONTACTOS();
		scanf("%d", &opcion2);
		fflush (stdin);
		getchar();
		switch (opcion2){
			case 1:
				printf ("Contactos")// aqui hay que hacer que se vean todos los contactos
				break;
			
			case 2:
				printf ("Guardar un contacto"); 
				break;
			
			case 3:
				printf ("Borrar un contacto");
				break;
				
			case 4:
				printf ("volver al menu principal");
				break;
			
		}
	}while (opcion 2 !=4);
	break;
	
}
		

