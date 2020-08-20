#ifndef OBJECTLOADER_H_INCLUDED
#define OBJECTLOADER_H_INCLUDED
#include "linkedList.h"//library that includes linked lists of 3d vectors, and faces.

typedef struct object3d{
    int id;
    char name[32];
    Vector3D *vectors;
    Face *faces;
    struct object3d *next;//to load a scene?
    struct object3d *previous;
}Object3D;


#endif // OBJECTLOADER_H_INCLUDED
