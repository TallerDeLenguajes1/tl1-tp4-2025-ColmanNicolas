#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int idTareas = 999;

typedef struct {
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;

typedef struct Nodo{
Tarea tarea;
struct Nodo *siguiente;
}Nodo;

void limpiarbuffer();
Nodo * crearListaVacia();
Nodo * crearNodo(Tarea unaTarea);
Tarea *crearTarea();

void insertarNodo(Nodo ** start, Nodo * nodoNuevo);
void mostrarLista(Nodo *start);
void mostrarNodo(Nodo * nodo);

Nodo * quitarNodo(Nodo ** start, int ID);
void eliminarNodo(Nodo * nodoEliminado);

Nodo * buscarNodoPorID(Nodo *start, int ID);
Nodo * buscarNodoPorPalabra(Nodo *start, char *palabraClave);
void menu(Nodo * pendientes, Nodo * realizadas);

int main(){
    Nodo *startPendientes, *startRealizadas;
    startPendientes = crearListaVacia(); 
    startRealizadas = crearListaVacia();
    Menu(startPendientes,startRealizadas);
    
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
void insertarNodo(Nodo ** start, Nodo * nodoNuevo){
    nodoNuevo->siguiente = *start;
    *start = nodoNuevo;
}

Tarea * crearTarea(){
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
        mostrarNodo(aux);
        aux = aux->siguiente;
    }
}
void mostrarNodo(Nodo * nodo){
    printf("\n-----------------------\n");
    printf("Identifidacor de tarea :%d -- Duracion de tarea: %d ", nodo->tarea.TareaID, nodo->tarea.Duracion);
    printf("\nDescripcion: %s", nodo->tarea.Descripcion);
    printf("\n-----------------------\n");
}

Nodo * quitarNodo(Nodo ** start, int ID){
    Nodo ** aux = start;
    while(aux != NULL && (*aux)->tarea.TareaID != ID){
        aux = &(*aux)->siguiente;
    }
    if(*aux){
        Nodo * temp = *aux;
        *aux = (*aux)->siguiente;
        temp->siguiente = NULL;
        return temp;
    }
    return NULL;
}
void eliminarNodo(Nodo * nodoEliminado){
    free(nodoEliminado);
}

Nodo * buscarNodoPorID(Nodo *start, int ID){
    Nodo * aux = start;
    while(aux != NULL){
        if (aux->tarea.TareaID == ID)
        {
            return aux;
        }
        aux = aux->siguiente;
    }
    return NULL;
}
Nodo * buscarNodoPorPalabra(Nodo *start, char *palabraClave){
    Nodo * aux = start;
    while(aux != NULL){
        if (strstr(aux->tarea.Descripcion, palabraClave))
        {
            return aux;
        }
        aux = aux->siguiente;
    }
    return NULL;
}
void menu(Nodo * pendientes, Nodo * realizadas){
    int eleccion = 1;
    do{
        printf("\nMenu de tareas\n");
        
        printf("Ingrese 1 para registrar una nueva tarea\n");
        printf("Ingrese 2 para marcar una tarea como finalizada\n");
        printf("Ingrese 3 para listar las tareas \n");
        printf("Ingrese 4 para buscar una tarea \n");
        printf("Ingrese 0 para salir del programa \n");
        eleccion = validarEntero();
        
        switch (eleccion)
        {
            case 1:
            menuCrearTareas(&pendientes);
            char opcion[4];
            do{
                printf("\nDesea agregar otra tarea?\n'si' o 'no': ");
                scanf("%3s",&opcion);
                if(strcmp(opcion, "si") == 0){
                    menuCrearTareas(&pendientes);
                }
            }while(strcmp(opcion, "no") != 0);
            break;
            
            default:
            break;
        }
    }while(eleccion != 0);
}
void menuCrearTareas(Nodo ** pendientes){
    Tarea * unaTarea = (Tarea *) malloc (sizeof(Tarea));
    unaTarea = crearTarea();
    Nodo * nuevoNodo = crearNodo(*unaTarea);
    insertarNodo(&pendientes,nuevoNodo);
}
int validarEntero(){
    int numero;
    do{
        printf("Su opcion: ");
        scanf("%d",&numero);
        if(numero< 0 || numero >4){
            printf("\n**Ingrese una opcion valida**\n");
        }
    }while(numero< 0 || numero >4);
    return numero;
}
