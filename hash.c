#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo
{
    int k;
    int cod;
    struct nodo * sig;
};

struct nodo *superior = NULL;

void main(){
    int contar=0,ind=0,funcion=0,co=0,libre=0,posision=0;
    char men;
    char codigo[15];
    char cadena[80];
    int bandera=0,i=0;
    FILE* archivo = NULL;
    FILE* crear;
    FILE* abrir;
    int op=0, codigoo=0, listo=0,insertar=0,indicep=0;
    int datos=1761;
    datos=1741;
    int matriz[datos][2];

    archivo = fopen("train.csv", "r");
    abrir= fopen("dataset", "wb");
    crear= fopen("dataset", "r+");

    printf(" Menu Principal\n");
    printf("   1) Buscar objeto.\n");
    printf("   2) Insertar objeto.\n");
    printf("   3) Eliminar Objeto.\n");
    printf(" Mantenimiento archivos\n");
    printf("   4) Reindexar.\n");
    printf("   5) Generar información.\n");
    printf("   6) Salir.\n");

    do{
        printf("Opción:\n");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
              if (listo == 1)
              {
                printf("Codigo: ");
                scanf("%d",&codigoo);

                int fun= codigoo % 1777;
                int datoo=fun;
                int buscar=matriz[datoo][1];
                libre=0;
                bandera=1;
                posision=0;
                memset (codigo, '\0', 15);
                if (matriz[datoo][0] == fun)
                {
                    fseek(crear, buscar*4 , SEEK_SET);
                    while(fread(&men,sizeof(char),1,crear)>0)
                    {
                        if(men>31 && men<127)
                        {
                            if (bandera==1)
                            {
                                if (men==',')
                                {
                                    co=atoi(codigo);
                                    if (co != codigoo)
                                    {
                                        struct nodo * auxi = malloc(sizeof(struct nodo));
                                        auxi=superior;
                                        auxi=auxi->sig;
                                        posision=auxi->k;
                                        i=0;
                                        bandera=0;
                                        break;
                                    }
                                    else
                                    {
                                        printf("%d",co);
                                        libre=1;
                                    }
                                
                                    i=0;
                                    bandera=0;
                                }
                                else
                                {
                                    if (men != 32)
                                    {
                                        codigo[i]=men;
                                        i++;
                                    }  
                                }
                            }
                            if (libre==1)
                            {
                                printf("%c",men);
                            }
                            
                            if (men == ';')
                            {
                                break;
                            }
                        }

                    }
                    if (posision!=0)
                    {
                        fseek(crear, posision*4 , SEEK_SET);
                        while(fread(&men,sizeof(char),1,crear)>0)
                        {
                            if(men>31 && men<127)
                            {
                                printf("%c",men);
                                if (men == ';')
                                {
                                    break;
                                }
                            }
                        }
                    }
                    
                    printf("\n");
                }
                else
                {
                    printf("Codigo no encontrado\n");
                }
                
              }
              else
              {
                printf("No hay datos asociados a la tabla hash \n");
              }
              
              break;
            case 2:
              if (listo == 1)
              {
                printf("Codigo a insertar: ");
                scanf("%d",&codigoo);
                int fun= codigoo % 1777;
                int datoo=fun;
                int buscar=matriz[datoo][1];
                if (matriz[datoo][0] == codigoo)
                {
                    printf("Codigo encontrado, no se puede duplicar llaves\n");
                }
                else
                {
                    printf("Informacion separada por comas: ");
                    scanf("%s",cadena);
                    int d=0;
                    bandera=1;
                    i=0;
                    indicep=ind+8;
                    ind=ind+1;
                    fseek(crear, ind*4 , SEEK_SET);
                    for (int i = 0; i < strlen(cadena); i++)
                    {
                        d=cadena[i];
                        fwrite( &d, sizeof d, 1, crear);

                        ind++;
                        if (bandera==1)
                        {
                            if (d==',')
                            {
                                //Funcion de hash
                                funcion=atoi(codigo)+1;
                                funcion= funcion % 1741;
                                bandera=0;
                                i=0;
                            }
                            else
                            {
                                if (d != 32)
                                {
                                    codigo[i]=d;
                                    i++;
                                }  
                            }
                        }
                    }
                    d=44;
                    fwrite(&d, sizeof d, 1, crear);
                    d=49;
                    fwrite(&d, sizeof d, 1, crear);
                    d=59;
                    fwrite(&d, sizeof d, 1, crear);
                    ind=ind+3;
                    contar++;
                    bandera=1;
                    if (matriz[datoo][0] == fun)
                    {
                        struct nodo * raiz = malloc(sizeof(struct nodo));
                        struct nodo * aux = malloc(sizeof(struct nodo));
                        raiz->cod=matriz[datoo][0];
                        raiz->k=matriz[datoo][1];
                        raiz->sig = NULL;
                        aux->cod=funcion;
                        aux->k=indicep;
                        aux->sig = NULL;
                        raiz->sig = aux;
                        superior=raiz;
                    }
                    else
                    {
                        matriz[funcion][0]=funcion;
                    }
                    printf("Registro insertado\n");
                }
              }
              else
              {
                printf("Tabla de hash  sin crear\n");
              }
              break;
            case 3:
              //eliminar;
              break;
            case 4:
              //reindexar;
              break;
            case 5:
              i=0;
              if (!archivo)
              {
                printf("Error al abrir el fichero\n");
              }
              else
              {
                int c = 0;
                while((c = fgetc(archivo)) != EOF) 
                {
                    fwrite( &c, sizeof c, 1, crear);
                    ind++;
                    if (bandera==1)
                    {
                        if (c==',')
                        {
                            //Funcion de hash
                            funcion=atoi(codigo)+1;
                            funcion= funcion % 1741;
                            matriz[funcion][0]=funcion;
                            bandera=0;
                            i=0;
                        }
                        else
                        {
                            if (c != 32)
                            {
                                codigo[i]=c;
                                i++;
                            }  
                        }
                    }
                    if (c == '\n')
                    {
                        c=44;
                        fwrite(&c, sizeof c, 1, crear);
                        c=49;
                        fwrite(&c, sizeof c, 1, crear);
                        c=59;
                        fwrite(&c, sizeof c, 1, crear);
                        c=32;
                        fwrite(&c, sizeof c, 1, crear);
                        ind=ind+4;
                        contar++;
                        matriz[funcion][1]=ind;
                        bandera=1;
                    } 
                }            
                
                listo=1;
                printf("Archivo binario y tabla hash creada con exito\n");
             }
             break;
             }

    }while(op != 6);
  
   fclose(archivo);
   fclose(crear);
   fclose(abrir);
}
