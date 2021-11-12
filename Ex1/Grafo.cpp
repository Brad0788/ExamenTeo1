#include "Grafo.h"

Grafo::Grafo(){

}
Grafo::Grafo(Seq s){
    seq = s;
}

void Grafo::printGrafo(){
    vector<V> aux = seq.set_x.w;
    int conteo = 0;
    bool found = false;
    for (auto n : seq.set_x.w)
    {
        cout<<"  "<<n.v;
        conteo++;   
    }
    char posiciones[conteo+1] = {};
    int newcont = 0;
    for (auto n : seq.set_x.w)
    {
        posiciones[newcont] = n.v;
        newcont++; 
    }
    posiciones[conteo]='\0';
    cout<<endl;
    int arr[conteo][conteo] = {};
    int iterAux = 0;
    for (auto nn : aux)
    {
        //cout<<n.v<<" ";
        for (auto n : seq.set_y.w)
        {
            if (nn.v == n.x)
            {
                found = true;
                for (int i = 0; i < conteo; i++)
                {
                    if (n.y == posiciones[i])
                    {
                        arr[iterAux][i] = n.z;
                        arr[i][iterAux] = n.z;
                    }

                }
            }
            
        }
        
        iterAux++;  
    }
    for (int i = 0; i < conteo; i++)
    {
        cout<<posiciones[i];
        for (int j = 0; j < conteo; j++)
        {
            cout<<" "<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
};