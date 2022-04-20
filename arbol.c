
#include <stdlib.h>
#include <stdio.h>

typedef struct _nodo {
   int dato;
   struct _nodo *derecho;
   struct _nodo *izquierdo;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;

void Insertar(Arbol *a, int dat);
int Vacio(Arbol r);
void InOrden(Arbol, void (*func)(int*));
void Mostrar(int *d);
void Podar(Arbol *a);
void PreOrden(Arbol a, void (*func)(int*));
void PostOrden(Arbol a, void (*func)(int*));
void imprimirArbol (Arbol a);
int main()
{
  Arbol ArbolInt=NULL;
  int altura;
  int nnodos;


  Insertar(&ArbolInt,2);
  Insertar(&ArbolInt,4);
  Insertar(&ArbolInt,6);
  Insertar(&ArbolInt,9);
  Insertar(&ArbolInt,12);
  Insertar(&ArbolInt,15);
  Insertar(&ArbolInt,17);


  printf("Arbol Inorder: ");
  
  InOrden(ArbolInt, Mostrar);
  printf("\n");
  printf("Arbol Preorder: ");
  PreOrden(ArbolInt, Mostrar);
  printf("\n");
  printf("Arbol Postorder: ");
  PostOrden(ArbolInt, Mostrar);
  printf("\n");
  Podar(&ArbolInt);
}
//Insertar un dato en el árbol
void Insertar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual = *a;
//Buscar el dato en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat < actual->dato) actual = actual->izquierdo;
      else if(dat > actual->dato) actual = actual->derecho;
   }
   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;

/* Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
      el nodo raiz */
   if(Vacio(padre)) {
      *a = (Arbol)malloc(sizeof(tipoNodo));
      (*a)->dato = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;
   }
   /* Si el dato es menor que el que contiene el nodo padre, lo insertamos
      en la rama izquierda */
   else if(dat < padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->izquierdo = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
   }
/* Si el dato es mayor que el que contiene el nodo padre, lo insertamos
      en la rama derecha */
   else if(dat > padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
  }
}

void InOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) InOrden(a->izquierdo, func);
   func(&(a->dato));
   if(a->derecho) InOrden(a->derecho, func);
}
void PreOrden(Arbol a, void (*func)(int*)) {
   func(&(a->dato)); /* Aplicar la función al dato del nodo actual */
   if(a->izquierdo) PreOrden(a->izquierdo, func); /* Subárbol izquierdo */
   if(a->derecho) PreOrden(a->derecho, func);     /* Subárbol derecho */
}
void PostOrden(Arbol a, void (*func)(int*)) {
   if(a->izquierdo) PostOrden(a->izquierdo, func); /* Subárbol izquierdo */
   if(a->derecho) PostOrden(a->derecho, func);     /* Subárbol derecho */
   func(&(a->dato)); /* Aplicar la función al dato del nodo actual */
}
/* Función de prueba para recorridos del árbol */
void Mostrar(int *d)
{
   printf("%d, ", *d);
}
/* Comprobar si un árbol es vacío */
int Vacio(Arbol r)
{
   return r==NULL;
}
/* Poda: borrar todos los nodos a partir de uno, incluido */
void Podar(Arbol *a)
{
   
   if(*a) {
      Podar(&(*a)->izquierdo); 
      Podar(&(*a)->derecho);   
      free(*a);                
      *a = NULL;
   }
}
void imprimirArbol (Arbol a){
    if (a != NULL){
        imprimirArbol (a->izquierdo);
        printf ("%d, ", a->dato);
        imprimirArbol (a->derecho);
    }
}
