#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

int convertToNum(char jug){
    switch (jug)
    {
    case 'T':
        return 0;
        break;
    case 'P':
        return 1;
        break;
    case 'R':
        return 2;
        break;
    case 'L':
        return 3;
        break;
    case 'S':
        return 4;
        break;
    default:
        return -1;
        break;
    }
    return -1;
}

char solicitarJugada1(){
    char jug = ' ';
    cout<<"Jugador 1 ingrese su jugada: "<<endl;
    cin>>jug;
    return jug;
}
char solicitarJugada2(){
    char jug = ' ';
    cout<<"Jugador 2 ingrese su jugada: "<<endl;
    cin>>jug;
    return jug;
}
int main(){
    ifstream file;
    char ch = ' ';
    char opciones [] = {'T', 'P', 'R', 'L', 'S','\0'};
    //  T p r L S
    file.open("tablaverdad.txt");
    if (!file) {
        cout << "No se pudo abrir";
        exit(1);
    }
    char arr [5][5] = {0};
    string s;
    cout<<"La tabla de la verdad del juego:\n";
    cout<<"  T P R L S"<<endl;
    int conteo = 0;
    char ar[6];
    ar[5] = '\0';
    while (getline(file,s))
    {
        cout<<opciones[conteo]<<" ";
        cout<<s<<endl;
        remove(s.begin(),s.end(),' ');
        strncpy(ar,s.c_str(),5);    
        for (int i = 0; i < 5; i++)
        {
            arr[conteo][i] = ar[i];
        }
        conteo++;
    }
    cout<<"Puedes escoger entre T,P,R,L,S : Tijeras, Papel, Rock, Lizard, Spock\n";
    cout<<"Escribe la letra de tu elección"<<endl;
    int gameover = 0;
    do
    {
        char jug1 = solicitarJugada1();
        char jug2 = solicitarJugada2();
        int j1 = convertToNum(jug1);
        int j2 = convertToNum(jug2);
        if (jug1 == jug2)
        {
            cout<<"Empate!";
        }else{
            char check1 = arr[j1][j2];
            char check2 = arr[j2][j1];
            if (check1 == 'V')
            {
                cout<<"Jugador 1 Ganó!"<<endl;
                gameover=1;
            }
            else if(check2 == 'V'){
                cout<<"Jugador 2 Ganó!"<<endl;
                gameover=1;
            }
            
        }
        
    } while (gameover!=1);
    
    
    return 0;
}