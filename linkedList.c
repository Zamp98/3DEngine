#include "linkedList.h"
#include <string.h>

void  *init()
{
    return NULL;
}

void *allocateList(int flag)////flag = 1 is text, on load OBJ mode. flag = 2 is vector mode. flag = 3 is face mode. flag = 4 is object mode.
{
    if(flag == 1)
    {
        textNode *newNode = malloc(sizeof(textNode));
        newNode->line = malloc(sizeof(char)*MAX);
        newNode->next = NULL;
        newNode->previous = NULL;
        return newNode;
    }
    else if(flag == 2)
    {
        Vector3D *newVector = malloc(sizeof(Vector3D));
        for(int i = 0; i < 4; i++){
            newVector->coordinates[i] = 0.0f;
        }
        newVector->next = NULL;
        newVector->id = 0;
        return newVector;
    }
    else if(flag == 3)
    {
        Face *newFace = malloc(sizeof(Face));
        newFace->id = 0;
        newFace->vectors = NULL;
        return newFace;
    }
    else if(flag == 4)
    {
        Object3D *newObject = malloc(sizeof(Object3D));
        newObject->id = 0;
        newObject->name = "New Object";
        newObject->next = NULL;
        newObject->vectors = NULL;
        return newObject;
    }
    else
    {
        return NULL;
    }

}


textNode *insertTextNode(char *line, textNode *root)
{
    textNode *newNode = allocate(1);//create the new node
        strcpy(newNode->line, line);//add content into him
        if(!root){
            //if the list have zero elements
            root = newNode;
        }else{
            Node *temp = root;
            while(temp->next){//find the end of the list
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->previous = temp;
        }
        return root;
}

Vector3D *insertVector(float *coordinates, Vector3D *root)
{
    Vector3D *newVector = allocate(2);//create the new node
        //strcpy(newNode->line, line);//add content into him
    for(int i = 0; i < 4; i++)
    {
        newVector->coordinates[i] = coordinates[i];
    }
    if(!root){
        //if the list have zero elements
        root = newVector;
    }else{
        Vector3D *temp = root;
        while(temp->next){//find the end of the list
            temp = temp->next;
            newVector->id++;
        }
        temp->next = newVector;
        newVector->previous = temp;
    }
    return root;
}

Face *insertFace(Vector3D *vectors, Face *root)
{
    Face *newFace = allocate(3);//create the new node
        //strcpy(newNode->line, line);//add content into him
    newFace->vectors = vectors;
    if(!root){
        //if the list have zero elements
        root = newFace;
    }else{
        Face *temp = root;
        while(temp->next){//find the end of the list
            temp = temp->next;
            newFace->id++;
        }
        temp->next = newFace;
        newFace->previous = temp;
    }
    return root;
}



void *insertNode(void *data, void *root, int flag)//flag = 1 is text, on load OBJ mode. flag = 2 is vector mode. flag = 3 is face mode. flag = 4 is object mode.
{
    if (flag == 1) //if is text type
    {
        return insertTextNode(data, root);
    }
    else if(flag == 2)//if is vector type
    {
        return insertVector(data, root);
    }
    else if(flag == 3)//if is face type
    {
        return insertFace(data, root);
    }
    else if(flag == 4)//if is object type
    {
        return NULL;//TODO?
    }
    return NULL
}



void printTextNode(textNode *text)
{
    printf("%s\n", text->line);
}
void printVector(Vector3D *vector)
{
    printf("vector id: %d", vector->id)
    for(int i = 0; i < 4; i++)
        printf("%f ", vector->coordinates[i]);
}
void printFace(Face *face)
{
    printf("Face id: %d", face->id);
    printList(face->vectors, 2);
}


void printList(void *root, int flag)//flag = 1 is text, on load OBJ mode. flag = 2 is vector mode. flag = 3 is face mode. flag = 4 is object mode.
{
    void * temp = root;
    if(!temp)
    {
        printf("NULL LIST!");
    }
    while(temp){
        if(flag == 1){//if is textNode
            printTextNode(temp);
        }
        else if(flag == 2){//if is vector3d
            printVector(temp)
        }
        else if(flag == 3){
            //if is face
            printFace(temp);
        }
        temp = temp->next;
    }
}


void *destroyList(void *root)
{
    if(!root)return NULL;
    root = destroyList(root->next);
    free(root);
    return NULL;
}
