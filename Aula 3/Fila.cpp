#include <iostream>
using namespace std;

int fila[4];
int inicio = 0;
int fim = 0;

void desifileirar(){
    if(inicio==fim){
        cout << "Fila vazia!" << endl;
        return;
    }


    fila[inicio] = 0; 
    inicio++;

    if(inicio == 4){
        inicio = 0;
    }
    
}

void exibirFila(){
    if(inicio==fim){
        cout << "Fila vazia!" << endl;
        return;
    }

    int i = inicio;
    bool finalizar= true;
    while (finalizar)
    {
        cout << fila[i] << " ";
        if(i ==4 ){
            i = 0;
        }
        else
            i++;

        if(i == fim)
            finalizar = false;
    }
    
}

void enfileirar(int valor){

    if(fim == 4){
        cout << "Fila cheia!" << endl;
        return;
    }
    fila [fim] = valor;
    fim++;
}

int main(){

    enfileirar(3);
    enfileirar(3);
    enfileirar(3);
    enfileirar(3);


    exibirFila();

    desifileirar();
    desifileirar();

    cout << endl;
    exibirFila();


    return 0;
}