#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
enum {Nuevo, Continuar, Tutorial, Creditos, Salir};
int trampas = 2;
int tesoro = 2;
int descartes_faciles [6]={0};
int descartes_medias [6]={0};
int descartes_dificiles [6]={0};

char respuesta_del_usuario;
char faciles [6][300]= {
	"Que es una constante en programacion?\n a) Un dato cuyo valor cambia durante la ejecucion.\n b) Un dato cuyo valor permanece constante durante la ejecucion.\n c) Un tipo de estructura de control.",
	"Que es una variable? \n a) Un espacio de memoria donde se almacenan datos que pueden variar. \n b) Un conjunto de instrucciones.\n c) Una funcion matematica en el programa.",
    "Que tipo de estructura de control se usa para realizar acciones en secuencia? \n a) Estructuras repetitivas.\n b) Estructuras condicionales.\n c) Estructuras secuenciales.",
    "Que significa que un registro sea heterogeneo? \n a) Todos los elementos son iguales. \n b) Contiene diferentes tipos de datos. \n c) No tiene datos.",
    "Que es un tipo de dato en pseudocodigo? \n a) Un tipo de bucle. \n b) Una categoria de informacion como enteros o caracteres. \n c) Un conjunto de variables.",
    "Cual es el proposito de una estructura condicional? \n a) Repetir acciones. \n b) Decidir entre diferentes acciones. \n c) Almacenar datos."
};
char medias [6][300]= {
    "Que caracteristica es comun a todas las estructuras secuenciales?\n a) Una accion depende de una condicion. \n b) Las acciones se ejecutan en orden de aparicion. \n c) Las acciones se repiten hasta cumplir una condicion.",
    "Que es una secuencia de datos elementales? \n a) Un conjunto de variables sin relacion. \n b) Un conjunto de datos relacionados entre si que cumplen ciertas caracteristicas. \n c) Un archivo de texto plano.",
    "Cual es una funcion principal de los archivos indexados? \n a) Mantener un registro sin organizacion. \n b) Permitir el acceso directo a los datos mediante una clave. \n c) Almacenar datos sin estructura.",
    "Como es un archivo maestro en procesos de actualizacion? \n a) Un archivo que se usa como respaldo. \n b) Un archivo que contiene los datos principales que se van a actualizar. \n c) Un archivo de solo lectura.",
    "Que se entiende por 'actualizacion secuencial'? \n a) Cambiar datos aleatoriamente en el archivo. \n b) Actualizar registros uno tras otro en orden. \n c) Eliminar registros obsoletos.",
    "Que es una funcion en pseudocodigo? \n a) Un bloque de codigo que realiza una tarea especifica y devuelve un valor. \n b) Una variable de tipo especial. \n c) Una estructura de control."
};
char dificiles [6][300]= {
    "¿Cual es el proposito de un 'usuario inteligente' en sistemas de archivos indexados? \na) Ejecutar todos los procesos de actualizacion automaticamente. \nb) Controlar las actualizaciones y cambios en los registros. \nc) Almacenar las claves de los registros.",
    "En una secuencia de datos, A que elemento se considera el ''primer objeto'? \na) El elemento con el valor mas alto. \nb) El primer elemento que permite acceso a los demas. \nc) El ultimo elemento en la secuencia.",
    "¿Cual es la funcion de una subaccion en pseudocodigo? \na) Dividir el algoritmo principal en funciones y procedimientos. \nb) Ejecutar una accion condicional en bucle. \nc) Almacenar datos temporales.",
    "¿Cual es el beneficio de usar parametros en una subaccion? \na) Permiten definir nuevas variables. \nb) Permiten que la subaccion use datos externos especificos. \nc) Aseguran que la subaccion no devuelva valores.",
    "¿Como se organiza un archivo indexado? \na) Sin clave especifica. \nb) Por valores aleatorios. \nc) Mediante un campo clave que permite el acceso directo.",
    "¿Cual es el proposito de definir un ambitode variables en pseudocodigo? \na) Limitar el acceso a las variables a ciertas partes del programa. \nb) Hacer que todas las variables sean globales. \nc) Evitar la declaracion de constantes."
};
char resp_faciles [6] = {
    'b',
    'a',
    'c',
    'b',
    'b',
    'b'
};
char resp_medias [6] = {
    'b',
    'b',
    'b',
    'b',
    'b',
    'a'
};
char resp_dificiles [6] = {
    'b',
    'b',
    'a',
    'b',
    'c',
    'a'
};
int numero_aleatorio(){
    return ((rand() % 6) + 1);
}
void hacer_pregunta(int descartes[],int numero_pregunta,char pregunta[][300],char resp_[], int * bandera){
    while (descartes [numero_pregunta]==1){
       numero_pregunta=numero_aleatorio()-1;
    }
    printf("%s\n\n", pregunta[numero_pregunta]);
    descartes[numero_pregunta]=1;
    scanf(" %c", &respuesta_del_usuario);
    if (respuesta_del_usuario==resp_[numero_pregunta]){
        *bandera=1;
        printf("Respuesta Correcta! Tu vida se restablece y has derrotado al enemigo.\n");
    }
    else{
        *bandera=0;
        printf("Respuesta incorrecta! El enemigo te ha hecho daño.");
    }
}
void actualizar_vida(int * x, int contador_vida, int bandera_respuesta, int * bandera_derrota){
	
	if(*x>100){
		*x = 100;
	}
	if (bandera_respuesta==1){
		* x+= contador_vida;
	}
	else{
			* x-= contador_vida;
		};
	if (* x > 100){
		*x = 100;
		}
		else{
			if(* x<=0){
				*bandera_derrota = 1;
			};
		};
};
int controlar_derrota(int*bandera_derrota, int * x){
	if(1==*bandera_derrota){
	   	sleep(3);
	    system("cls");
	   	printf("Has perdido el juego! Vuelve a intentarlo.\n\n");
	   	printf("      *Tu vida: %d", *x);
		printf("      *Tu Puntuacion final: %d", (*x)*10000);
		sleep(5);
	   	return(1);
	}else{
		return(0);
	}
}
void cargar_menu(){
    char a[20] = "Cave Crawlers";
    printf("^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^n^m^n^m^n^m^n^m^n^m^n");
    printf("\n"); printf("%65s", a);
    printf("\n\n");
    printf("             0) Nuevo Juego\n");
    printf("             1) Continuar Juego (No Disponible)\n");
    printf("             2)Tutorial\n");
    printf("             3)Creditos\n");
    printf("             4)Salir\n\n\n");
    printf("^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^m^n^n^m^n^m^n^m^n^m^n^m^n\n\n\n");
}
void cargarMapa0(char mapa[23][23], char personaje) {
    int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __                #",
        "#  |  |               #",
        "#  |  |               #",
        "#   --                #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    mapa[2][2] = personaje;
}
void mostrarMapa(char mapa[23][23]) {
	int i,j;
    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}
void habitacionA(int * x, int * contador_trampas, int * contador_tesoro, int *bandera_derrota){
	int bandera_respuesta;
	int vida = 100;
	int contador_vida = 10;
	int numero_pregunta;
	int bandera_salir = *bandera_derrota;
	srand(time(NULL));
	int sorteo = (rand() % 3);
	if (sorteo==0){
		printf("Te encontraste a un enemigo! Para derrotarlo, responde bien a la siguiente pregunta:\n");
		int dificultad = 1;
		hacer_pregunta(descartes_faciles,numero_pregunta, faciles, resp_faciles, &bandera_respuesta);
		actualizar_vida(&vida, contador_vida, bandera_respuesta, &bandera_salir);
		*x=vida;
	}else{
		if(sorteo == 1){
			printf("\nEnhorabuena! Has encontrado un tesoro, pero al estar tu vida al maximo, no reclamaras tu premio.");
			*contador_tesoro-=1;
		}else{
			printf("\nQue mal! Has entrado a la primera habitacion y ya encuentras una trampa! Una trampa para osos te atrapa el pie y te deja cojeando. Tu vida se disminuye en 15 puntos.");
			*x-=15;
			*contador_trampas-=1;
		}
	}
}
void cargarMapa1(char mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __          #",
        "#  |  |  |  |         #",
        "#  |  |--|  |         #",
        "#   --    --          #",
        "#    |                #",
        "#    |                #",
        "#    |                #",
        "#    |                #",
        "#    |                #",
        "#   _|                #",
        "#  |  |               #",
        "#  |  |               #",
        "#   --                #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    mapa[4][5] = personaje;	
}
void atajo_H(int * x, int * bandera_derrota, int * contador_trampas, int * contador_tesoro){
	int bandera_respuesta;
	int numero_pregunta;
	
	srand(time(NULL));
	int sorteo = (rand() % 2);
	if (sorteo==0){
		printf("Te encontraste a un enemigo! Para derrotarlo, responde bien a la siguiente pregunta, si fallas, perderas el juego:\n");
		int dificultad = 3;
		hacer_pregunta(descartes_dificiles, numero_pregunta, dificiles, resp_dificiles, &bandera_respuesta);
		if(bandera_respuesta==1){
			printf("Muchas Felicidades!!! Has avanzado muchisimo de un solo movimiento!");
			*x=100;
		}else{
			*x=0;
			*bandera_derrota=1;
		}
	}else{
		if(sorteo == 1){
			printf("\nQue mal! Tiras de una cuerda al pasar por la puerta y caes sobre restos de vidrio. Tu vida se disminuye en 50 puntos.");
			*x-=50;
			*contador_trampas-=1;
		}
	}
}
void cargarMapa2(char mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __          #",
        "#  |  |  |  |         #",
        "#  |  |--|  |         #",
        "#   --    --          #",
        "#    |                #",
        "#    |                #",
        "#    |                #",
        "#    |                #",
        "#    |                #",
        "#   _|                #",
        "#  |  |               #",
        "#  |  |               #",
        "#   --                #",
        "#    |                #",
        "#   _|                #",
        "#  |  |               #",
        "#  |  |               #",
        "#   --                #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    mapa[12][5] = personaje;
}
void habitacionI(int*x, int *bandera_derrota, int *contador_trampas, int *contador_tesoro){
	int bandera_respuesta;
	int vida;
	int contador_vida = 35;
	int numero_pregunta;
	int bandera_salir= *bandera_derrota;
	srand(time(NULL));
	int sorteo = (rand() % 3);
	if((*contador_trampas==0)&&(*contador_tesoro==0)&&((sorteo==1)||(sorteo==2))){
		sorteo=0;
	}
	if (sorteo==0){
		printf("Te encontraste a un enemigo! Para derrotarlo, responde bien a la siguiente pregunta:\n");
		int dificultad = 3;
		hacer_pregunta(descartes_dificiles, numero_pregunta, dificiles, resp_dificiles, &bandera_respuesta);
		actualizar_vida(&vida, contador_vida, bandera_respuesta, &bandera_salir);
		*x=vida;
	}else{
		if(sorteo == 1){
			printf("\nEnhorabuena! Has encontrado un tesoro, un artefacto antiguo restablece tu vida.");
			*x+=20;
			*contador_tesoro-=1;
		}else{
			printf("\nQue mala suerte! Al pasar por la puerta, tres flechas se disparan hacia ti y una te deja malherido. Pierdes 20 puntos de vida.");
			*x-=20;
			*contador_trampas-=1;
		}
	}
	if(*x>100){
	*x=100;
	}else{
		if(*x<=0){
			*bandera_derrota=1;
		}
	}
}
void cargarMapa3(char mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __          #",
        "#  |  |  |  |         #",
        "#  |  |--|  |         #",
        "#   --    --          #",
        "#    |                #",
        "#    |                #",
        "#    |                #",
        "#    |                #",
        "#    |                #",
        "#   _|                #",
        "#  |  |               #",
        "#  |  |               #",
        "#   --                #",
        "#    |                #",
        "#   _|     __         #",
        "#  |  |   |  |        #",
        "#  |  |---|  |        #",
        "#   --     --         #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    mapa[18][5] = personaje;
}
void habitacionJ(int*x, int *bandera_derrota, int *contador_trampas, int *contador_tesoro){
	int bandera_respuesta;
	int vida=*x;
	int contador_vida = 30;
	int numero_pregunta;
	int i;
	int bandera_salir=*bandera_derrota;
	printf("Has entrado a la habitacion del jefe! Derrotalo para completar el juego.");
	sleep(5);
	system("cls");
	srand(time(NULL));
	for(i=0; i<3; i++){
		int dificultad = 3;
		hacer_pregunta(descartes_dificiles, numero_pregunta, dificiles, resp_dificiles, &bandera_respuesta);
		actualizar_vida(&vida, contador_vida, bandera_respuesta, &bandera_salir);
		*x=vida;
		if(*x>100){
		*x=100;
		}else{
			if(*x<=0){
				*bandera_derrota=1;
				continue;
			}
		}
		sleep(3);
		system("cls");
	}
}
void habitacionB(int*x, int *bandera_derrota, int *contador_trampas, int *contador_tesoro){
	int bandera_respuesta;
	int vida = *x;
	int contador_vida = 15;
	int numero_pregunta;
	int bandera_salir= *bandera_derrota;
	srand(time(NULL));
	int sorteo = (rand() % 3);
	if((*contador_trampas==0)&&(*contador_tesoro==0)&&((sorteo==1)||(sorteo==2))){
		sorteo=0;
	}
	if (sorteo==0){
		printf("Te encontraste a un enemigo! Para derrotarlo, responde bien a la siguiente pregunta:\n");
		int dificultad = 1;
		hacer_pregunta(descartes_faciles,numero_pregunta, faciles, resp_faciles, &bandera_respuesta);
		actualizar_vida(&vida, contador_vida, bandera_respuesta, &bandera_salir);
		*x=vida;
	}else{
		if(sorteo == 1){
			printf("\nEnhorabuena! Has encontrado un tesoro, un artefacto antiguo restablece tu vida.");
			*x+=20;
			*contador_tesoro-=1;
		}else{
			printf("\nQue mala suerte! Al pasar por la puerta, no ves el desnivel y caes de una altura considerable. Pierdes 20 puntos de vida.");
			*x-=20;
			*contador_trampas-=1;
		}
	}
	if(*x>100){
	*x=100;
	}else{
		if(*x<=0){
			*bandera_derrota=1;
		}
	}
}
void cargarMapa4(char Mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __    __    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |     |          #",
        "#    |    _|          #",
        "#    |   |  |         #",
        "#    |   |  |         #",
        "#    |    --          #",
        "#   _|                #",
        "#  |  |               #",
        "#  |  |               #",
        "#   --                #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            Mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    Mapa[4][11] = personaje;
}
void habitacionC(int*x, int *bandera_derrota, int *contador_trampas, int *contador_tesoro){
	int bandera_respuesta;
	int vida=*x;
	int contador_vida = 15;
	int numero_pregunta;
	int bandera_salir= *bandera_derrota;
	srand(time(NULL));
	int sorteo = (rand() % 3);
	if((*contador_trampas==0)&&(*contador_tesoro==0)&&((sorteo==1)||(sorteo==2))){
		sorteo=0;
	}
	if (sorteo==0){
		printf("Te encontraste a un enemigo! Para derrotarlo, responde bien a la siguiente pregunta:\n");
		int dificultad = 1;
		hacer_pregunta(descartes_faciles,numero_pregunta, faciles, resp_faciles, &bandera_respuesta);
		actualizar_vida(&vida, contador_vida, bandera_respuesta, &bandera_salir);
		*x=vida;
	}else{
		if(sorteo == 1){
			printf("\nEnhorabuena! Has encontrado un tesoro, un artefacto antiguo restablece tu vida.");
			*x+=20;
			*contador_tesoro-=1;
		}else{
			printf("\nQue mala suerte! La habitacion esta a total oscuridad y tu mente resulta afectada. Pierdes 20 puntos de vida.");
			*x-=20;
			*contador_trampas-=1;
		}
	}
	if(*x>100){
	*x=100;
	}else{
		if(*x<=0){
			*bandera_derrota=1;
		}
	}
}
void cargarMapa5(char Mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __    __    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |     |          #",
        "#    |    _|    __    #",
        "#    |   |  |  |  |   #",
        "#    |   |  |--|  |   #",
        "#    |    --    --    #",
        "#   _|                #",
        "#  |  |               #",
        "#  |  |               #",
        "#   --                #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            Mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    Mapa[9][11] = personaje;
}
void habitacionE(int*x, int *bandera_derrota, int *contador_trampas, int *contador_tesoro){
	int bandera_respuesta;
	int vida=*x;
	int contador_vida = 20;
	int numero_pregunta;
	int bandera_salir= *bandera_derrota;
	srand(time(NULL));
	int sorteo = (rand() % 3);
	if((*contador_trampas==0)&&(*contador_tesoro==0)&&((sorteo==1)||(sorteo==2))){
		sorteo=0;
	}
	if (sorteo==0){
		printf("Te encontraste a un enemigo! Para derrotarlo, responde bien a la siguiente pregunta:\n");
		int dificultad = 2;
		hacer_pregunta(descartes_medias, numero_pregunta, medias,resp_medias, &bandera_respuesta);
		actualizar_vida(&vida, contador_vida, bandera_respuesta, &bandera_salir);
		*x=vida;
	}else{
		if(sorteo == 1){
			printf("\nEnhorabuena! Has encontrado un tesoro, un artefacto antiguo restablece tu vida.");
			*x+=20;
			*contador_tesoro-=1;
		}else{
			printf("\nQue mala suerte! Pasas por la puerta y la profe te pregunta sobre la tarea(No sabes ni a que se refiere). Pierdes 25 puntos de vida.");
			*x-=25;
			*contador_trampas-=1;
		}
	}
	if(*x>100){
	*x=100;
	}else{
		if(*x<=0){
			*bandera_derrota=1;
		}
	}
}	
void cargarMapa6(char Mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __    __    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |     |          #",
        "#    |    _|    __    #",
        "#    |   |  |  |  |   #",
        "#    |   |  |--|  |   #",
        "#    |    --    --    #",
        "#   _|          _|    #",
        "#  |  |        |  |   #",
        "#  |  |        |  |   #",
        "#   --          --    #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            Mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    Mapa[9][17] = personaje;
}
void habitacionF(int*x, int *bandera_derrota, int *contador_trampas, int *contador_tesoro){
	int bandera_respuesta;
	int vida=*x;
	int contador_vida = 20;
	int numero_pregunta;
	int bandera_salir= *bandera_derrota;
	srand(time(NULL));
	int sorteo = (rand() % 3);
	if((*contador_trampas==0)&&(*contador_tesoro==0)&&((sorteo==1)||(sorteo==2))){
		sorteo=0;
	}
	if (sorteo==0){
		printf("Te encontraste a un enemigo! Para derrotarlo, responde bien a la siguiente pregunta:\n");
		int dificultad = 2;
		hacer_pregunta(descartes_medias, numero_pregunta, medias,resp_medias, &bandera_respuesta);
		actualizar_vida(&vida, contador_vida, bandera_respuesta, &bandera_salir);
		*x=vida;
	}else{
		if(sorteo == 1){
			printf("\nEnhorabuena! Has encontrado un tesoro, un artefacto antiguo restablece tu vida.");
			*x+=20;
			*contador_tesoro-=1;
		}else{
			printf("\nQue mala suerte! Te encontras con un duende que te manipula y te quita tus pertenencias. Pierdes 25 puntos de vida.");
			*x-=25;
			*contador_trampas-=1;
		}
	}
	if(*x>100){
	*x=100;
	}else{
		if(*x<=0){
			*bandera_derrota=1;
		}
	}
}
void cargarMapa7(char Mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __    __    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |     |          #",
        "#    |    _|    __    #",
        "#    |   |  |  |  |   #",
        "#    |   |  |--|  |   #",
        "#    |    --    --    #",
        "#   _|    __    _|    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |  |  |--|  |   #",
        "#   --    --    --    #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            Mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    Mapa[13][17] = personaje;
}
void habitacionG(int*x, int *bandera_derrota, int *contador_trampas, int *contador_tesoro){
	int bandera_respuesta;
	int vida=*x;
	int contador_vida = 20;
	int numero_pregunta;
	int bandera_salir= *bandera_derrota;
	srand(time(NULL));
	int sorteo = (rand() % 3);
	if((*contador_trampas==0)&&(*contador_tesoro==0)&&((sorteo==1)||(sorteo==2))){
		sorteo = 0;
	}
	if (sorteo==0){
		printf("Te encontraste a un enemigo! Para derrotarlo, responde bien a la siguiente pregunta:\n");
		int dificultad = 2;
		hacer_pregunta(descartes_medias, numero_pregunta, medias,resp_medias, &bandera_respuesta);
		actualizar_vida(&vida, contador_vida, bandera_respuesta, &bandera_salir);
		*x=vida;
	}else{
		if(sorteo == 1){
			printf("\nEnhorabuena! Has encontrado un tesoro, un artefacto antiguo restablece tu vida.");
			*x+=10;
			*contador_tesoro-=1;
		}else{
			printf("\nQue mala suerte! Te toman parcial de algoritmos y no estudiaste. Pierdes 10 puntos de vida.");
			*x-=10;
			*contador_trampas-=1;
		}
	}
	if(*x>100){
	*x=100;
	}else{
		if(*x<=0){
			*bandera_derrota=1;
		}
	}
}
void cargarMapa8(char Mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __    __    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |     |          #",
        "#    |    _|    __    #",
        "#    |   |  |  |  |   #",
        "#    |   |  |--|  |   #",
        "#    |    --    --    #",
        "#   _|    __    _|    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            Mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    Mapa[13][11] = personaje;
}
void habitacionH(int*x, int *bandera_derrota, int *contador_trampas, int *contador_tesoro){
	int bandera_respuesta;
	int vida=*x;
	int contador_vida = 25;
	int numero_pregunta;
	int bandera_salir= *bandera_derrota;
	srand(time(NULL));
	int sorteo = (rand() % 3);
	if((*contador_trampas==0)&&(*contador_tesoro==0)&&((sorteo==1)||(sorteo==2))){
		sorteo = 0;
	}
	if (sorteo==0){
		printf("Te encontraste a un enemigo! Para derrotarlo, responde bien a la siguiente pregunta:\n");
		int dificultad = 3;
		hacer_pregunta(descartes_dificiles, numero_pregunta, dificiles, resp_dificiles, &bandera_respuesta);
		actualizar_vida(&vida, contador_vida, bandera_respuesta, &bandera_salir);
		*x=vida;
	}else{
		if(sorteo == 1){
			printf("\nEnhorabuena! Has encontrado un tesoro, un artefacto antiguo restablece tu vida.");
			*x+=10;
			*contador_tesoro-=1;
		}else{
			printf("\nQue mala suerte! Caes enfermo un dia antes del parcial. Pierdes 10 puntos de vida.");
			*x-=10;
			*contador_trampas-=1;
		}
	}
	if(*x>100){
	*x=100;
	}else{
		if(*x<=0){
			*bandera_derrota=1;
		}
	}
}
void cargarMapa9(char Mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __    __    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |     |          #",
        "#    |    _|    __    #",
        "#    |   |  |  |  |   #",
        "#    |   |  |--|  |   #",
        "#    |    --    --    #",
        "#   _|    __    _|    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |                #",
        "#   _|                #",
        "#  |  |               #",
        "#  |  |               #",
        "#   --                #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            Mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    Mapa[13][5] = personaje;
}
void cargarMapa10(char Mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __    __    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |     |          #",
        "#    |    _|    __    #",
        "#    |   |  |  |  |   #",
        "#    |   |  |--|  |   #",
        "#    |    --    --    #",
        "#   _|    __    _|    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |                #",
        "#   _|    __          #",
        "#  |  |  |  |         #",
        "#  |  |--|  |         #",
        "#   --    --          #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            Mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    Mapa[18][5] = personaje;
}
void cargarMapa11(char Mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __    __    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |     |     |    #",
        "#    |    _|    _|    #",
        "#    |   |  |  |  |   #",
        "#    |   |  |  |  |   #",
        "#    |    --    --    #",
        "#   _|                #",
        "#  |  |               #",
        "#  |  |               #",
        "#   --                #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            Mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    Mapa[4][17] = personaje;
}
void cargarMapa12(char Mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __    __    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |     |     |    #",
        "#    |    _|    _|    #",
        "#    |   |  |  |  |   #",
        "#    |   |  |  |  |   #",
        "#    |    --    --    #",
        "#   _|          _|    #",
        "#  |  |        |  |   #",
        "#  |  |        |  |   #",
        "#   --          --    #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            Mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    Mapa[9][17] = personaje;
}
void cargarMapa13(char Mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __    __    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |     |     |    #",
        "#    |    _|    _|    #",
        "#    |   |  |  |  |   #",
        "#    |   |  |  |  |   #",
        "#    |    --    --    #",
        "#   _|    __    _|    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |  |  |--|  |   #",
        "#   --    --    --    #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            Mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    Mapa[13][17] = personaje;
}
void cargarMapa14(char Mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __    __    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |     |     |    #",
        "#    |    _|    _|    #",
        "#    |   |  |  |  |   #",
        "#    |   |  |  |  |   #",
        "#    |    --    --    #",
        "#   _|    __    _|    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            Mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    Mapa[13][11] = personaje;
}
void cargarMapa15(char Mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __    __    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |     |     |    #",
        "#    |    _|    _|    #",
        "#    |   |  |  |  |   #",
        "#    |   |  |  |  |   #",
        "#    |    --    --    #",
        "#   _|    __    _|    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |                #",
        "#   _|                #",
        "#  |  |               #",
        "#  |  |               #",
        "#   --                #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            Mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    Mapa[13][5] = personaje;
}
void cargarMapa16(char Mapa[23][23], char personaje){
	int i, j;
    const char *MapaPrincipal[23] = {
        "#######################",
        "#######################",
        "#   __    __    __    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |     |     |    #",
        "#    |    _|    _|    #",
        "#    |   |  |  |  |   #",
        "#    |   |  |  |  |   #",
        "#    |    --    --    #",
        "#   _|    __    _|    #",
        "#  |  |  |  |  |  |   #",
        "#  |  |--|  |--|  |   #",
        "#   --    --    --    #",
        "#    |                #",
        "#   _|    __          #",
        "#  |  |  |  |         #",
        "#  |  |--|  |         #",
        "#   --    --          #",
        "#                     #",
        "#######################",
        "#######################"
    };

    for (i = 0; i < 23; i++) {
        for (j = 0; j < 23; j++) {
            Mapa[i][j] = MapaPrincipal[i][j];
        }
    }
    Mapa[18][5] = personaje;
}
void habitacionD(int*x, int *bandera_derrota, int *contador_trampas, int *contador_tesoro){
	int bandera_respuesta;
	int vida=*x;
	int contador_vida = 20;
	int numero_pregunta;
	int bandera_salir= *bandera_derrota;
	srand(time(NULL));
	int sorteo = (rand() % 3);
	if((*contador_trampas==0)&&(*contador_tesoro==0)&&((sorteo==1)||(sorteo==2))){
		sorteo=0;
	}
	if (sorteo==0){
		printf("Te encontraste a un enemigo! Para derrotarlo, responde bien a la siguiente pregunta:\n");
		int dificultad = 1;
		hacer_pregunta(descartes_faciles,numero_pregunta, faciles, resp_faciles, &bandera_respuesta);
		actualizar_vida(&vida, contador_vida, bandera_respuesta, &bandera_salir);
		*x=vida;
	}else{
		if(sorteo == 1){
			printf("\nEnhorabuena! Has encontrado un tesoro, un artefacto antiguo restablece tu vida.");
			*x+=20;
			*contador_tesoro-=1;
		}else{
			printf("\nQue mala suerte! Pasas por la puerta y la profe te pregunta sobre la tarea(No sabes ni a que se refiere). Pierdes 25 puntos de vida.");
			*x-=25;
			*contador_trampas-=1;
		}
	}
	if(*x>100){
	*x=100;
	}else{
		if(*x<=0){
			*bandera_derrota=1;
		}
	}
}

int main(){
	srand(time(NULL));
    int opcion;
    char nom [20];
    char a [15] ="Mucha Suerte!";
    char personaje;
    char mapa [23][23];
    int numero_pregunta;
    int bandera_respuesta;
    int bandera_derrota = 0;
    int vida = 100;
    int decision0;
    int decision1;
    int control;
    
    
    do
    {
    cargar_menu();
    scanf("%d", &opcion);
    switch (opcion)
    {
    case Nuevo:
        break;
    case Continuar:
        printf("******Esta opcion no esta disponible de momento\n");
        sleep(5);
        break;
    case Tutorial:
        printf("*Este es un prototipo de juego de mazmorras.\n\n\n");
        printf("*El objetivo principal es llegar a la salida tomando el camino mas conveniente.\n\n\n");
        printf("*Cada habitacion puede contener tanto un enemigo como un tesoro o una trampa.\n\n\n");
        printf("*A mayor cantidad de habitaciones que recorras, mayor sera la dificultad de los enemigos.\n\n\n");
        printf("*Llegando a la batalla final, debera responder bien dos de tres preguntas. Si no logra responder correctamente, debera\niniciar desde cero.\n\n\n");
        printf("%65s\n\n", a);
        sleep(15);
        break;
    case Creditos:
    	printf("\n\n\n");
            printf("*Hecho y elaborado por:\n");
            printf("             _Suster Maximiliano\n");
            printf("             _Ahlbom Tomas\n");
            printf("             _Cerqueiro Octavio.\n");
            printf("\n\n\n");
            printf("#Especial agradecimiento a la catedra Algoritmos y Estructuras de Datos por la oportunidad de realizar este proyecto en post de incentivar la creatividad y\n");printf("poder ver los contenidos de la materia en un sentido mas practico aplicado a la programacion.\n\n\n");
            printf("#Gracias por jugar y esperamos haya sido de su agrado esta experiencia que les regalamos.\n\n\n");
            sleep(15);
        break;
    default:
        break;
    }
    system("cls");
    } while (opcion!=4&&opcion!=0);
    if(opcion==0){
    	printf("******A continuacion ingrese su nombre.(por favor no mas de 20 caracteres)\n");
    	scanf("%s", nom);
    	personaje = nom[0];
    	cargarMapa0(mapa, personaje);
    	mostrarMapa(mapa);printf("\n\n");
    	sleep(3);
    	system("cls");
    	habitacionA(&vida, &trampas, &tesoro, &bandera_derrota);
    	printf("\n\n      *Tu vida actual = %d", vida);
    	sleep(8);
    	system("cls");
    	cargarMapa1(mapa, personaje);
    	mostrarMapa(mapa);printf("\n");
    	sleep(3);
    	printf("Hacia donde decides ir?0(abajo)/1(derecha)\n");
    	printf("Ten cuidado! Si eliges ir hacia abajo puede tener consecuencias desastrosas..\n");
    	scanf("%d", &decision0);
    	if(0==decision0){
    		system("cls");
    		atajo_H(&vida, &bandera_derrota, &trampas, &tesoro);
    		printf("\n      *Tu vida actual es: %d\n", vida);
    		if(bandera_derrota){
    			sleep(3);
    			system("cls");
    			printf("Te lo advertimos! Tendras que volver a empezar.\n");
    			sleep(3);
    			return(0);
			}
			sleep(8);
			system("cls");
			cargarMapa2(mapa, personaje);
			mostrarMapa(mapa);printf("\n");
			sleep(3);
			system("cls");
			habitacionI(&vida, &bandera_derrota, &trampas, &tesoro);
			if(bandera_derrota){
    			sleep(3);
    			system("cls");
    			printf("Has perdido el juego! Vuelve a intentarlo.\n");
    			return(0);
			}
			printf("\n      *Tu vida actual: %d", vida);
			sleep(8);
			system("cls");
			cargarMapa3(mapa, personaje);
			mostrarMapa(mapa);printf("\n");
			sleep(3);
			system("cls");
			habitacionJ(&vida, &bandera_derrota, &trampas, &tesoro);
			if(bandera_derrota){
				system("cls");
				printf("\n\nHas perdido la batalla! Mejor suerte la proxima.");
				sleep(3);
				return(0);
			}
			printf("Felicidades! Has completado el juego %s.\n\n", nom);
			printf("      *Tu vida: %d", vida);
			printf("      *Tu Puntuacion final: %d", vida*10000);
			sleep(5);
			return(0);
		}else{
			if(1==decision0){
				system("cls");
				habitacionB(&vida, &bandera_derrota, &trampas, &tesoro);
				control = controlar_derrota(&bandera_derrota, &vida);
				if(1==control){
					return(0);
				}
				printf("\n      *Tu vida actual: %d", vida);
				sleep(8);
				system("cls");
				cargarMapa4(mapa, personaje);
				mostrarMapa(mapa);
				printf("Elige un camino.\nDerecha(1)/Abajo(0)");
				scanf("%d", &decision1);
				if(0==decision1){
					system("cls");
					habitacionC(&vida, &bandera_derrota, &trampas, &tesoro);
					control = controlar_derrota(&bandera_derrota, &vida);
					if(1==control){
						return(0);
					}
					printf("\n      *Tu vida actual: %d", vida);
					sleep(8);
					system("cls");
					cargarMapa5(mapa, personaje);
					mostrarMapa(mapa);
					sleep(3);
					system("cls");
					habitacionE(&vida, &bandera_derrota, &trampas, &tesoro);
					control = controlar_derrota(&bandera_derrota, &vida);
					if(1==control){
						return(0);
					}
					printf("\n      *Tu vida actual: %d", vida);
					sleep(8);
					system("cls");
					cargarMapa6(mapa, personaje);
					mostrarMapa(mapa);
					sleep(3);
					system("cls");
					habitacionF(&vida, &bandera_derrota, &trampas, &tesoro);
					control = controlar_derrota(&bandera_derrota, &vida);
					if(1==control){
						return(0);
					}
					printf("\n      *Tu vida actual: %d", vida);
					sleep(8);
					system("cls");
					cargarMapa7(mapa, personaje);
					mostrarMapa(mapa);
					sleep(3);
					system("cls");
					habitacionG(&vida, &bandera_derrota, &trampas, &tesoro);
					control = controlar_derrota(&bandera_derrota, &vida);
					if(1==control){
						return(0);
					}
					printf("\n      *Tu vida actual: %d", vida);
					sleep(8);
					system("cls");
					cargarMapa8(mapa, personaje);
					mostrarMapa(mapa);
					sleep(3);
					system("cls");
					habitacionH(&vida, &bandera_derrota, &trampas, &tesoro);
					control = controlar_derrota(&bandera_derrota, &vida);
					if(1==control){
						return(0);
					}
					printf("\n      *Tu vida actual: %d", vida);
					sleep(8);
					system("cls");
					cargarMapa9(mapa, personaje);
					mostrarMapa(mapa);
					sleep(3);
					system("cls");
					habitacionI(&vida, &bandera_derrota, &trampas, &tesoro);
					if(bandera_derrota){
    					sleep(3);
    					system("cls");
    					printf("Has perdido el juego! Vuelve a intentarlo.\n");
    					return(0);
					}
					printf("\n      *Tu vida actual: %d", vida);
					sleep(8);
					system("cls");
					cargarMapa10(mapa, personaje);
					mostrarMapa(mapa);printf("\n");
					sleep(3);
					system("cls");
					habitacionJ(&vida, &bandera_derrota, &trampas, &tesoro);
					if(bandera_derrota){
						system("cls");
						printf("\n\nHas perdido la batalla! Mejor suerte la proxima.");
						sleep(5);
						return(0);
					}
					printf("Felicidades! Has completado el juego %s.\n\n", nom);
					printf("      *Tu vida: %d", vida);
					printf("      *Tu Puntuacion final: %d", vida*10000);
					sleep(5);
					return(0);
				}else{
					if(1==decision0){
						system("cls");
						habitacionD(&vida, &bandera_derrota, &trampas, &tesoro);
						control = controlar_derrota(&bandera_derrota, &vida);
						if(1==control){
							return(0);
						}
						printf("\n      *Tu vida actual: %d", vida);
						sleep(8);
						system("cls");
						cargarMapa11(mapa, personaje);
						mostrarMapa(mapa);
						sleep(3);
						system("cls");
						habitacionE(&vida, &bandera_derrota, &trampas, &tesoro);
						control = controlar_derrota(&bandera_derrota, &vida);
						if(1==control){
							return(0);
						}
						printf("\n      *Tu vida actual: %d", vida);
						sleep(8);
						system("cls");
						cargarMapa12(mapa, personaje);
						mostrarMapa(mapa);
						sleep(3);
						system("cls");
						habitacionF(&vida, &bandera_derrota, &trampas, &tesoro);
						control = controlar_derrota(&bandera_derrota, &vida);
						if(1==control){
							return(0);
						}
						printf("\n      *Tu vida actual: %d", vida);
						sleep(8);
						system("cls");
						cargarMapa13(mapa, personaje);
						mostrarMapa(mapa);
						sleep(3);
						system("cls");
						habitacionG(&vida, &bandera_derrota, &trampas, &tesoro);
						control = controlar_derrota(&bandera_derrota, &vida);
						if(1==control){
							return(0);
						}
						printf("\n      *Tu vida actual: %d", vida);
						sleep(8);
						system("cls");
						cargarMapa14(mapa, personaje);
						mostrarMapa(mapa);
						sleep(3);
						system("cls");
						habitacionH(&vida, &bandera_derrota, &trampas, &tesoro);
						control = controlar_derrota(&bandera_derrota, &vida);
						if(1==control){
							return(0);
						}
						printf("\n      *Tu vida actual: %d", vida);
						sleep(8);
						system("cls");
						cargarMapa15(mapa, personaje);
						mostrarMapa(mapa);
						sleep(3);
						system("cls");
						habitacionI(&vida, &bandera_derrota, &trampas, &tesoro);
						if(bandera_derrota){
	    					sleep(3);
	    					system("cls");
	    					printf("Has perdido el juego! Vuelve a intentarlo.\n");
	    					sleep(5);
	    					return(0);
						}
						printf("\n      *Tu vida actual: %d", vida);
						sleep(8);
						system("cls");
						cargarMapa16(mapa, personaje);
						mostrarMapa(mapa);printf("\n");
						sleep(3);
						system("cls");
						habitacionJ(&vida, &bandera_derrota, &trampas, &tesoro);
						if(bandera_derrota){
							return(0);
						}
						printf("Felicidades! Has completado el juego %s.\n\n", nom);
						printf("      *Tu vida: %d", vida);
						printf("      *Tu Puntuacion final: %d", vida*10000);
						sleep(5);
						return(0);
					}
				}
			}
		}
	}
}
