#include <iostream>
using namespace std;

const int tamPilha = 10;
int pilha[tamPilha];
int topo = 0;

void empilhar(int valor)
{
    if (topo == tamPilha)
    {
        cout << "Pilha Cheia!";
        return;
    }

    pilha[topo] = valor;
    topo ++;
}

void desempilhar()
{
    if (topo == 0)
    {
        cout << "Pilha Vazia!";
        return;
    }

    topo--;
}

void mostrarPilha()
{
    for (int i = 0; i < topo; i++)
    {
        cout << pilha[i] << " ";
    }
    cout << endl;
}

int main ()
{
    empilhar(10);
    empilhar(20);
    mostrarPilha();
    empilhar(30);
    empilhar(40);
    mostrarPilha();
    desempilhar();
    desempilhar();
    mostrarPilha();
    desempilhar();
    mostrarPilha();

    return 0;
}
