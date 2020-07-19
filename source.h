#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <string>

#define MAX 2048

typedef struct vertice{
    int id;
    float c[4];
}Vertice;

typedef struct object{
    int id;
    Vertice *vertices;
    int *faces;
}Object;

Object *load(char *filename, int id);

#endif // SOURCE_H_INCLUDED
