#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include "Grafo.h"
using namespace std;

void pedirVertices(){

}

int main(){
    SetV sv;
    SetE se;
    char com='y';
    char ch = ' ';
    bool foundx = false;
    bool foundy = false;
    do
    {
        cout<<"Ingrese un caracter como elemento de V:"<<endl;
        cin>>ch;
        V vec(ch);
        if (ch == ' ')
        {
            cout<<"Porfavor, ingresa un caracter válido!"<<endl;
        }
        else{
            sv.w.push_back(vec);
            cout<<"Desea continuar agregando? (y/n)"<<endl;
            cin>>com;
        }
    } while (com=='y');


    char ch2 = ' ';
    int peso = 1; 
    com='y';
    do
    {
        cout<<"Ingrese un vertice de E:"<<endl;
        cin>>ch;
        cout<<"Ingrese el otro vertice de E:"<<endl;
        cin>>ch2;
        cout<<"Ingrese el peso de la arista:"<<endl;
        cin>>peso;
        for (auto i : sv.w)
        {
            if (i.v == ch)
            {
                foundx = true;
            }
            if (i.v == ch2)
            {
                foundy = true;
            }
            
        }
        if (!foundx || !foundy)
        {
            cout<<"Uno de los elementos ingresados no existe! Por favor ingresa un combinacion adecuada."<<endl;
        }
        else{
            E vec(ch,ch2,peso);
            se.w.push_back(vec);
            cout<<"Desea continuar agregando? (y/n)"<<endl;
            cin>>com;
        }
    } while (com=='y');
    /*SetV s;
    V vv('a');
    V vvv('b');
    V vvvv('c');
    s.w = {vv,vvv,vvvv};

    SetE ss;
    E ee('a','b',3);
    E eee('c','a', 4);
    ss.w = {ee,eee};*/
    Seq seq(sv, se);
    //Seq seq(s,ss);
    Grafo grafo(seq);
    grafo.printGrafo();
    int size = 0;
    com = 'y';
    cout<<"Deseas agregar etiquetas al grafo? (y/n)"<<endl;
    cin>>com;
    char tagg [30];
    if (com == 'y')
    {
        for (auto &i : grafo.seq.set_x.w)
        {
            cout<<"Ingresa una etiqueta para "<<i.v<<endl;
            cin>>tagg;
            size = strlen(tagg);
            i.setTag(tagg);
        }
        grafo.tagged = true;
    }
    else{
        cout<<"No se agregaron etiquetas..."<<endl;
    }
    if (grafo.tagged)
    {
        for (auto i : grafo.seq.set_x.w)
        {
            /*cout<<"El vértice "<<i.v<<" tiene etiqueta "<<i.tag<<endl;
            printf("El vertice tiene etiqueta %s\n",i.tag);*/
            i.printTag();
        }
    }
    return 0;
}