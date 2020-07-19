#include "source.h"



Object *load(char *filename, int id){
    FILE *objeto = fopen(filename, "r");
    if (objeto){
        //fseek(objeto, 0, SEEK_END);
        //int t_arquivo = ftell(objeto);
        //printf("Tamanho: %d", t_arquivo);
        //int buffer[t_arquivo];
        //fread(buffer, sizeof(char), t_arquivo, objeto);
        int i = 0;
        int linha = 0;
        char buffer[2*MAX][256];
        char c;
        //fscanf(objeto, "%c", &c);
        Vertice *v = NULL;
        //Object *o = malloc(sizeof(*Object));
        //o->id = id;
        int numVertices = 0;
        while(!feof(objeto)){
            /*while(c !='\n'){
                buffer[linha][i++] = c;
                fscanf(objeto, "%c", &c);
                printf("%d\n",ftell(objeto));
            }*/
            fscanf(objeto,"%[^\n]%",buffer[linha]);
            i = 0;
            printf("%s\n", buffer[linha]);
            //procedure that build a vertice
            if(buffer[linha][0] = 'v'){//if the line describe a vertice

                float x, y, z;
                char temp[256];
                int counter = 1;
                numVertices++;

                while(buffer[linha][counter] != '\0'){
                    temp[counter - 1] = buffer[linha][counter];
                    counter++;
                }
                //printf("temp: %s\n", temp);
                sscanf(temp, "%e %e %e", &x, &y, &z);
                printf("coordenadas: %lf %lf %lf\n", x, y, z);
            }//procedure to build a face
            else if(buffer[linha][0] = 'f'){//if the line describe a face
                printf("oi");
                char temp[MAX];
                int counter = 1;
                    while(buffer[linha][counter] != '\0'){
                        temp[counter - 1] = buffer[linha][counter];
                        counter++;
                    }
                //printf("temp: %s\n", temp);
            }
            //i++;
            linha++;
            //Sleep(1000);
            fscanf(objeto, "%c", &c);//isso aqui é deus agindo
        }
        //printf("%d\n", i);
    }else{
        printf("error");
    }
    return NULL;
}
