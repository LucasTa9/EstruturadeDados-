//Exercicio 02 da Prova
#include <iostream>
#include <string>
using namespace std;

struct No
{
    string mes;
    No* esq;
    No* dir;
};

//variavel global para o mes de aniversário para personalizacao
string meu_mesAniversario = "janeiro";

void inserir(string mes, No*& raiz)
{
    if(raiz == nullptr)
        raiz = new No{mes, nullptr, nullptr};
    else
    {
        if(mes < raiz->mes)
            inserir(mes, raiz->esq);
        else
            inserir(mes, raiz->dir);
    }

    //nao faz nada se o mes já existe (pode ser tratado de outra forma, se especificado)
}

void exibir_em_ordem(No* raiz)
{
    if(raiz == nullptr)
        return;

    exibir_em_ordem(raiz->esq);
    cout << raiz->mes;

    //personalizacao obrigatoria: destacar o mes de aniversario
    if(raiz->mes == meu_mesAniversario)
        cout << " (parabens para mim)";

    cout << ", ";
    exibir_em_ordem(raiz->dir);
}

void exibir_em_pre_ordem(No* raiz)
{
    if(raiz == nullptr)
        return;

    cout << raiz->mes;

    if(raiz->mes == meu_mesAniversario)
        cout << " (parabens para mim)";

    cout << ", ";
    exibir_em_pre_ordem(raiz->esq);
    exibir_em_pre_ordem(raiz->dir);
}

int main(void)
{
    No* no = nullptr;

    inserir("abril", no);
    inserir("marco", no);
    inserir("outubro", no);
    inserir("janeiro", no);

    exibir_em_ordem(no);
    cout << endl;
    exibir_em_pre_ordem(no);
    cout << endl;

    return 0;
}
