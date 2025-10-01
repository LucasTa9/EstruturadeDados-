#include <iostream>
using namespace std;

const int tamFila = 10;
int fila[tamFila];
int inicio = 0, fim = 0;

void enfileirar(int valor)
{
    if (fim == tamFila)
    {
        cout << "Fila Cheia";
    }
    else
    {
        fila[fim] = valor;
        fim ++;
    }
}

void desenfileirar()
{
    if (fim == inicio)
    {
        cout << "Fila Vazia";
        return;
    }
    inicio ++;
}

void mostrarLista()
{
    for (int i = inicio; i < fim; i++)
    {
        cout << fila[i] << " ";
    }
    cout << endl;
}

int main()
{
    enfileirar(10);
    enfileirar(20);
    mostrarLista();
    enfileirar(30);
    mostrarLista();
    desenfileirar();
    desenfileirar();
    mostrarLista();
    return 0;
}
