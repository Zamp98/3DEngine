#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
//Library used to load big text files in a single data structure
//and also load 3d objects to memory
#define MAX 256

typedef struct textnode{
    char *line;
    struct textnode *next;
    struct textnode *previous;
}textNode;

typedef struct vector3d{
    int id;
    float coordinates[4];//four positions for additional transformations
    struct vector3d *next;
    struct vector3d *previous;
}Vector3D;

typedef struct face{
    int id;
    Vector3D *vectors;
    struct face *next;
    struct face *previous;
}Face;


//flag = 1 is text, on load OBJ mode. flag = 2 is vector mode. flag = 3 is face mode. flag = 4 is object mode.
void *allocateList(int flag);
void *insertNode(void *line, void *root, int flag);
void printList(void *root, int flag);
void *destroyList(void *root);
void *init();

#endif // LINKEDLIST_H_INCLUDED
