#include "V.h"
#include <stdio.h>
V::V(char x_){
    v = x_;
    memset(tag,0,sizeof(tag));
}

void V::setTag(char* tag_){
    strcpy(tag,tag_);
}

void V::printTag(){
    printf("El vértice %c ",v);
    printf("tiene de etiqueta: %s\n",tag);
}