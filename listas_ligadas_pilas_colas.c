#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
void lista();
void pilas();
void colas();
struct nodo
{
  int n;
  struct nodo * siguiente;
};

struct nodo *superior = NULL;
struct nodo *inferior = NULL;
void main(){
  srand(0);
  int op=0;
  do{
    printf(" Elija una opción:\n");
    printf("   1) Listas ligadas.\n");
    printf("   2) Pilas.\n");
    printf("   3) Colas.\n");
    printf("   4) Salir.\n");

    printf("Opción:\n");
    scanf("%d",&op);

    switch(op){
      case 1: 
        lista();
        break;
      case 2:
        pilas();   
        break;
      case 3:
        colas();
        break;   
       } 
  }while(op != 4);


}
void lista()
{
  int c=0;
  int al=time(NULL),cont=time(NULL),elementos=0,dato=time(NULL),num=0,n=0;
  int indice=0;
  cont=rand()%30+1;

  for (int i = 0; i < cont; i++)
  {
    al=rand()%3+1;
    
    dato=rand()%20+1;

    //printf("\n");
    if (al==1)
    {
     printf("Insertar elemento a lista ligada      Elemento: %d\n",dato);   
      struct nodo * raiz = malloc(sizeof(struct nodo));
      struct nodo * aux = NULL;
      raiz->n=dato;
      raiz->siguiente = NULL;
      if(superior == NULL)
      {
        superior=raiz;
      }
      else
      {
        aux=superior;
        if (aux->n > dato)
        {
          raiz->siguiente=superior;
          superior=raiz;
          aux=raiz;
        }
        else
        {
          
          int i=0;
          while(aux->siguiente != NULL)
          {
            if (aux ->siguiente-> n > dato)
            {
              raiz->siguiente=aux->siguiente;
              aux->siguiente=NULL;
            }
            else
            {
              aux=aux->siguiente;
            }
            
          }
          aux->siguiente=raiz;
          if (aux->siguiente == NULL)
          {
            superior->siguiente=raiz;
          }
        }
      } 
    }
    if (al==2)
    {
      struct nodo * raiz = malloc(sizeof(struct nodo));
      if (raiz==NULL)
      {
        printf("No hay elementos en la lista");
      }
      else
      {
        printf("Mostrar elementos de la lista ligada\n");
        struct nodo * temporal = superior;
        while (temporal != NULL)
        {
          printf("%d\n",temporal->n);
          temporal = temporal ->siguiente;
        }
      }
    }
    if (al==3)
    {
      struct nodo * raiz = malloc(sizeof(struct nodo));
      if (raiz==NULL)
      {
        printf("No hay elementos en la lista");
      }
      else
      {
        printf("Eliminar elemento de una lista ligada.   Elemento: %d\n",dato);
        struct nodo * aux = superior;
        struct nodo * antes = NULL;
        struct nodo * liberar = NULL;
        int c=0;
        while (aux != NULL)
        {
          if(aux->n == dato)
          {
            c=1;
            printf("Elimino el elemento %d\n",aux->n);
            if (antes==NULL )
            {
              liberar = superior;
              superior=superior->siguiente;
              aux=superior;
              free(liberar);
            }
            else
            {
              antes->siguiente=aux->siguiente;
              liberar=aux;
              free(liberar);
            }
            break;
          }
          antes=aux;
          aux = aux ->siguiente;
        }
        if(c != 1)
        {
          printf("El elemento %d, no se encontro en la lista\n",dato);
        }
      }
    }
    
  }
  while(superior != NULL)
  {
    struct nodo * temporal = superior;
    superior=superior->siguiente;
    free(temporal);
  }
}

void pilas()
{
  
  int num=time(NULL),op=time(NULL),dato=time(NULL);
  num=rand()%30+1;

  for (int i = 0; i < num; i++)
  {
    op=rand()%3+1;
    dato=rand()%20+1;
    if (op==1)
    {
      printf("Insertar elemento a la pila      Elemento: %d\n",dato);
      struct nodo * raiz = malloc(sizeof(struct nodo));
      raiz->n=dato;
      raiz->siguiente = superior;
      superior = raiz;
    }
    if (op==2)
    {
      printf("Eliminar elemento a la pila\n");
      if (superior != NULL)
      {
        struct nodo * temporal = superior;
        printf("Elemento %d eliminado \n",temporal->n);
        superior = superior ->siguiente;
        free(temporal); 
      }
      else
      {
        printf("No hay elementos en la pila\n");
      }
    }
    if (op==3)
    {
      printf("Mostrar elementos de la pila\n");
      struct nodo * temporal = superior;
      while (temporal != NULL)
      {
        printf("%d\n",temporal->n);
        temporal = temporal ->siguiente;
      }
    }
  }
  while(superior != NULL)
  {
    struct nodo * temporal = superior;
    superior = superior ->siguiente;
    free(temporal);
  }
}
void colas()
{
  int num=time(NULL),opp=time(NULL),dato=time(NULL);
  num=rand()%30+1;

  for (int i = 0; i < num; i++)
  {
    opp=rand()%3+1;
    dato=rand()%20+1;
    if (opp==1)
    {
      printf("Insertar elemento a la cola.      Elemento: %d\n",dato);
      struct nodo * nuevo;
      nuevo=malloc(sizeof(struct nodo));
      nuevo->n=dato;
      nuevo->siguiente = NULL;
      if (superior == NULL)
      {
        superior = nuevo;
        inferior=nuevo;
      }
      else
      {
        inferior->siguiente=nuevo;
        inferior=nuevo;
      }
    }
    if (opp==2)
    {
      printf("Eliminar elemento de la cola.\n");
      if(superior != NULL)
      {
        struct nodo * aux = superior;
        printf("Elemento %d eliminado \n",aux->n);
        superior=superior->siguiente;
        if (superior == NULL)
        {
          inferior = superior;
        }
        free(aux);
      }
      else
      {
        printf("No hay elementos en la cola\n");
      }
    }
    if (opp==3)
    {
      printf("Mostrar elementos de la cola\n");
      if (superior == NULL)
      {
        printf("Cola vacia\n");
      }
      else
      {
        struct nodo * aux=superior;
        int i=0;
        while(aux != NULL)
        {
          printf("%d.- %d\n",i++,aux->n);
          aux=aux->siguiente;
        }

      }
    }
  }
  while(superior != NULL)
  {
    struct nodo * temporal = superior;
    superior=superior->siguiente;
    if (superior==NULL)
    {
      inferior=superior;
    }
    free(temporal);
  }
}
