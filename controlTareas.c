#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int idTareas = 999;

typedef struct {
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;

typedef struct{
Tarea tarea;
struct Nodo *siguiente;
}Nodo;

void limpiarbuffer();
Nodo * crearListaVacia();
Nodo * crearNodo(Tarea unaTarea);
Tarea *crearTarea();

void insertarNodo(Nodo ** start, Nodo * nodoNuevo);
void mostrarLista(Nodo *start);

Nodo * quitarNodo(Nodo ** start, int ID);
void eliminarNodo(Nodo nodoEliminado);

Nodo * buscarNodoPorID(Nodo *start, int ID);
Nodo * buscarNodoPorPalabra(Nodo *start, char * []);

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

void limpiarbuffer(){
    char c;
    while((c=getchar()) != '\n' && c != EOF );
}
Nodo * crearListaVacia(){
    return NULL;
}
Nodo * crearNodo(Tarea unaTarea){
    Nodo *nuevoNodo = (Nodo *) malloc(sizeof(Nodo));
    nuevoNodo->tarea = unaTarea;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}
void insertarNodo(Nodo ** start,Nodo * nodoNuevo){
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

void mostrarLista(Nodo *start){
    Nodo * aux = start;
    while(aux != NULL){
        printf("\n-----------------------\n");
        printf("Identifidacor de tarea :%d -- Duracion de tarea: %d ", aux->tarea.TareaID, aux->tarea.Duracion);
        printf("\nDescripcion: %s", aux->tarea.Descripcion);
        printf("\n-----------------------\n");
    }
}
Nodo * quitarNodo(Nodo ** start, int ID){
    Nodo ** aux = start;
    while(aux != NULL && (*aux)->tarea.TareaID != ID){
        aux = &(*aux)->siguiente;
    }
    if(*aux){
        Nodo * temp = aux;
        *aux = (*aux)->siguiente;
        temp->siguiente = NULL;
        return temp;
    }
    return NULL;
}
void eliminarNodo(Nodo nodoEliminado){
    free(eliminarNodo);
}

Nodo * buscarNodoPorID(Nodo *start, int ID);
Nodo * buscarNodoPorPalabra(Nodo *start, char * []);
