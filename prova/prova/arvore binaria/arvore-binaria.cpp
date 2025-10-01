//Programa com Arvore Binaria (Inserir, Buscar e Contagem)
#include <iostream>
using namespace std;

/**
   no max 2 filhos por no
   esquerda = valor menor
   direita = valor maior
*/

struct No
{
    int valor;
    No* esq;
    No* dir;
};

void inserir(int valor, No*& raiz)
{
    if(raiz == nullptr)
        raiz = new No{valor, nullptr, nullptr};
    else
    {
        if(valor < raiz->valor)
            inserir(valor, raiz->esq);
        else
            inserir(valor, raiz->dir);
    }
}

void buscar(int valorProcurado, No* raiz)
{
    if(raiz == nullptr) //se a raiz estiver vazia
    {
        cout << "Valor " << valorProcurado << " nao foi encontrado na arvore. \n\n";
        return;
    }

    if(valorProcurado == raiz->valor)
    {
        cout << "Valor " << valorProcurado << " foi encontrado na arvore. \n\n";
        return;
    }

    if(valorProcurado < raiz->valor)
        buscar(valorProcurado, raiz->esq); //subarvore da esquerda
    else
        buscar(valorProcurado, raiz->dir); //subarvore da direita
}

int contagem(No* raiz) //tem que ser uma função
{
    if(raiz == nullptr)
        return 0; //nesse caso nao pode ser return 1 (erro), pq se nao o valor retorna errado

    return contagem(raiz->esq) + 1 + contagem(raiz->dir);
}

int main(void)
{
    No* raiz = nullptr;

    inserir(5, raiz);
    inserir(7, raiz);
    inserir(2, raiz);
    inserir(1, raiz);
    inserir(9, raiz);

    buscar(2, raiz);
    buscar(8, raiz);

    cout << "Contagem: " << contagem(raiz) << endl;

    return 0;
}
