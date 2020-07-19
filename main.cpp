#include "source.h"


/*class Object{
public://constructor, get, set and atributes
    Object():
    setVertices(Vertice *v){

    }
    setFaces(){

    }
    getVertices(){

    }
    getFaces(){

    }
private://atributes
    Vertice *vertices;//vertices list
    Vertice *faces;//faces list
};



Object::Object(string filename){
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
        fscanf(objeto, "%c", &c);
        while(!feof(objeto)){
            while(c !='\n'){
                buffer[linha][i++] = c;
                fscanf(objeto, "%c", &c);
            }
            i = 0;
            printf("%s\n", buffer[linha]);
            //i++;
            linha++;
            //Sleep(1000);
            fscanf(objeto, "%c", &c);
        }
        //printf("%d\n", i);
    }else{
        printf("error");
    }
}*/
using namespace std;



int main()
{
    int objCount = 0;
    Object *o = NULL;
    o = load("carro.obj", objCount);

    return 0;
}
