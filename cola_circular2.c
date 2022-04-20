#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
void colas();
struct nodo
{
  int n;
  struct nodo * siguiente;
};

struct nodo *superior = NULL;
struct nodo *inferior = NULL;
void main()
{
  srand(0);
  int num=time(NULL),opp=time(NULL),dato=time(NULL);
  //num=rand()%30+1;
  num=25;

  for (int i = 0; i < num; i++)
  {
    opp=rand()%3+1;
    dato=rand()%20+1;
    if (opp==1)
    {
      printf("Insertar elemento a la cola circular.      Elemento: %d\n",dato);
      struct nodo * nuevo;
      nuevo=malloc(sizeof(struct nodo));
      nuevo->n=dato;
      if (superior == NULL)
      {
        nuevo->siguiente = nuevo;
        superior = nuevo;
        inferior=nuevo;
      }
      else
      {
        inferior->siguiente=nuevo;
        inferior=nuevo;
        inferior->siguiente = superior;
      }

    }
    if (opp==2)
    {
      printf("Eliminar elemento de la cola circuar.\n");
      if(superior != NULL)
      {
        struct nodo * aux = superior;
        printf("Elemento %d eliminado \n",aux->n);
        superior=superior->siguiente;
        if (superior->siguiente == superior)
        {
          superior=NULL;
          inferior = superior;
        }
        else
        {
          inferior->siguiente=superior;
        }
        
        free(aux);
      }
      else
      {
        printf("No hay elementos en la cola circular\n");
      }
    }
    if (opp==3)
    {
      printf("Mostrar elementos de la cola circular\n");
      if (superior == NULL)
      {
        printf("Cola vacia\n");
      }
      else
      {
        struct nodo * aux=superior;
        int i=0;
        while(aux->siguiente != inferior->siguiente)
        {
          printf("%d.- %d\n",i++,aux->n);
          aux=aux->siguiente;
        }
        printf("%d.- %d\n",i++,aux->n);
      }
    }
  }
}
