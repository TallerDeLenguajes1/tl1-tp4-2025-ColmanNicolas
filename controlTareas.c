#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int idTareas = 999;

typedef struct {
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;

typedef struct Nodo {
Tarea tarea;
struct Nodo *siguiente;
}Nodo;

void limpiarbuffer(){
    char c;
    while((c=getchar()) != '\n' && c != EOF );
}
Nodo *crearListaVacia(){
    return NULL;
}
Nodo *crearNodo(Tarea unaTarea){
    Nodo *nuevoNodo = (Nodo *) malloc(sizeof(Nodo));
    nuevoNodo->tarea = unaTarea;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}
void insertarNodo(Nodo **start,Nodo *nodoNuevo){
    nodoNuevo->siguiente = *start;
    *start = nodoNuevo;
}

Tarea *crearTarea(){
    Tarea * nueva = (Tarea *) malloc (sizeof(Tarea)); 
    char buff[100];
    int duracion;
    printf("\nDescriba la tarea a realizar:");
    scanf("%s",&buff);
    limpiarbuffer();

    printf("\nIngrese la duracion de la tarea:");
    scanf("%d",&duracion);
    getchar();
    nueva->Descripcion = (char *) malloc(strlen(buff) + 1);
    idTareas ++;
    nueva->TareaID = idTareas;
    strcpy(nueva->Descripcion,buff);
    nueva->Duracion = duracion; 

    return nueva;
}

int main(){
    Nodo *startPendientes, *startRealizadas, *nodoAux;
    nodoAux = (Nodo * ) malloc(sizeof(Nodo));
    Tarea *unaTarea;
    startPendientes = crearListaVacia(); 
    startRealizadas = crearListaVacia();
    unaTarea = crearTarea();
    nodoAux = crearNodo(*unaTarea);
    insertarNodo(&startPendientes,nodoAux);
    
    return 0;
}