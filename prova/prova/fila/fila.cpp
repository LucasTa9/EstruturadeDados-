//Fila usando Array

/*
    Resumo Fila

    quando estática usa: array
    quando dinâmica usa: vetor com ponteiros

    no Array: tamFila, fila[tamFila], primeiro = 0 (usa na desqueue(primeiro++)), ultimo = 0 (usa na enqueue(ultimo++)), primeiro e ultimo (usa na exibição, for(int i = primeiro; i < ultimo; i++))
        (verifica se a lista está vazia e cheia)

    no Vetor: ponteiro pra proximo e anterior
        (verifica somente se a lista está vazia)
*/

#include <iostream>
using namespace std;

const int tamFila = 5;
int fila[tamFila], ultimo = 0, primeiro = 0;

void enfileirar(int valor)
{
    if(ultimo == tamFila)
    {
        cout << "Fila cheia!" << endl;
        return;
    }

    fila[ultimo] = valor;
    ultimo++;
}

void desenfileirar()
{
    if(ultimo == primeiro)
    {
        cout << "Fila vazia!" << endl;
        return;
    }

    primeiro++;
}

void mostrar()
{
    for(int i = primeiro; i < ultimo; i++)
        cout << fila[i] << " ";
    cout << endl;
}

int main(void)
{
    enfileirar(10);
    enfileirar(20);
    mostrar();
    enfileirar(30);
    mostrar();
    desenfileirar();
    desenfileirar();
    mostrar();

    return 0;
}
