#include "disk.h"
#include <stdio.h>

typedef struct{
    int num_disks;
    Disk **towers;
}HanoiGame;

typedef Disk StackElem;

typedef struct{
    StackElem *elems;
    int top;
    int capacity;
}Stack;

Disk diskCreate(int size) {
    Disk d;
    d.size = size;
    return d;
}

void diskPrint(Disk disk) {
    printf("--(_%d_)--", disk.size);
}