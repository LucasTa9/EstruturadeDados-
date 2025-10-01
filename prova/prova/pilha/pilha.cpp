//Pilha usando Array
#include <iostream>
using namespace std;

/*
    Resumo Pilha

    quando estática usa: array
    quando dinâmica usa: vetor com ponteiros

    no Array: tamPilha, pilha[tamPilha], topo = 0 (usa na inserção (topo++), remoção (topo--) e exibição for(int i=0; i < topo; i++))
        (verifica se a lista está vazia e cheia)

    no Vetor: ponteiro pra proximo e anterior
        (verifica somente se a lista está vazia)
*/

const int tamPilha = 5;
int pilha[tamPilha], topo = 0;

void empilhar(int valor)
{
    if(topo == tamPilha)
    {
        cout << "Pilha cheia!" << endl;
        return;
    }

    pilha[topo] = valor;
    topo++;
}

void desempilhar()
{
    if(topo == 0)
    {
        cout << "Pilha cheia!" << endl;
        return;
    }

    topo--;
}

void mostrar()
{
    for(int i = 0; i < topo; i++)
        cout << pilha[i] << " ";
    cout << endl;
}

int main(void)
{
    empilhar(10);
    empilhar(20);
    mostrar();
    empilhar(30);
    mostrar();
    desempilhar();
    desempilhar();
    mostrar();

    return 0;
}
