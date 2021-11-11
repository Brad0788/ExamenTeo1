#include "Seq.h"
#include <iostream>
class Grafo{
    public:
        Grafo();
        Grafo(Seq);
        Seq seq;
        bool tagged = false;
        /*Grafo(Seq s){
            seq=s;
        };*/
        void printGrafo();
        void etiquetarGrafo();
};