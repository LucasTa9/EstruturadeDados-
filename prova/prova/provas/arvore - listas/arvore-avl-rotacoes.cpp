//Exercicio 03 da Prova
#include <iostream>
#include <windows.h>
using namespace std;

// Variáveis globais para controlar os números de rotações
int LL = 0;
int LR = 0;
int RR = 0;
int RL = 0;

// Estrutura do nó da árvore AVL
struct No
{
    int chave;
    int bal;
    No* esq;
    No* dir;
};

// Funcão para criar um novo nó
No* criarNo(int chave)
{
    No* novo = new No;

    novo->chave = chave;
    novo->bal = 0;
    novo->esq = nullptr;
    novo->dir = nullptr;

    return novo;
}

// Rotação simples à direita (caso a subárvore esquerda tenha crescido muito)
No* rotacaoL(No* p)
{
    No* u = p->esq;

    // Rotação LR
    if(u->bal == -1)
    {
        No* v = u->dir;

        u->dir = v->esq;
        v->esq = u;
        p->esq = v->dir;
        v->dir = p;

        if(v->bal == -1)
            p->bal = 1;
        else
            p->bal = 0;

        if(v->bal == 1)
            u->bal = -1;
        else
            u->bal = 0;

        v->bal = 0;

        LR++;
        return v;
    }

    // Rotação LL (quando u->bal != -1)
    p->esq = u->dir;
    u->dir = p;
    p->bal = 0;
    u->bal = 0;
    LL++;
    return u;
}

// Rotação simples à esquerda (caso a subárvore da direita tenha crescido muito)
No* rotacaoR(No* p)
{
    No* u = p->dir;

    // Rotação RL
    if(u->bal == 1)
    {
        No* v = u->esq;

        u->esq = v->dir;
        v->dir = u;
        p->dir = v->esq;
        v->esq = p;

        if(v->bal == 1)
            p->bal = -1;
        else
            p->bal = 0;

        if(v->bal == -1)
            u->bal = 1;
        else
            u->bal = 0;

        v->bal = 0;

        RL++;
        return v;
    }

    // Rotação RR
    p->dir = u->esq;
    u->esq = p;
    p->bal = 0;
    u->bal = 0;
    RR++;
    return u;
}

// Função para inserir um nó na árvore AVL
No* inserir(No* raiz, int chave, bool& cresceu)
{
    if(raiz == nullptr)
    {
        cresceu = true;
        return criarNo(chave);
    }

    if(chave == raiz->chave)
    {
        cout << chave << " (ja foi inserido anteriormente)" << endl;
        return nullptr;
    }

    if(chave < raiz->chave)
    {
        raiz->esq = inserir(raiz->esq, chave, cresceu);

        if(cresceu)
        {
            if(raiz->bal == 1)
            {
                raiz = rotacaoL(raiz);
                cresceu = false;
            }
            else if(raiz->bal == 0)
                raiz->bal = 1;
            else if(raiz->bal == -1)
                raiz->bal = 0;
        }
    }
    else if(chave > raiz->chave)
    {
        raiz->dir = inserir(raiz->dir, chave, cresceu);

        if(cresceu)
        {
            if(raiz->bal == -1)
            {
                raiz = rotacaoR(raiz);
                cresceu = false;
            }
            else if(raiz->bal == 0)
                raiz->bal = -1;
            else if(raiz->bal == 1)
                raiz->bal = 0;
        }
    }

    return raiz;
}

// Função principal
int main(void)
{
    No* raiz = nullptr;
    bool cresceu = false;
    int chave;

    raiz = inserir(raiz, 3, cresceu);
    raiz = inserir(raiz, 0, cresceu);
    raiz = inserir(raiz, 2, cresceu);
    raiz = inserir(raiz, 8, cresceu);
    raiz = inserir(raiz, 9, cresceu);
    raiz = inserir(raiz, 4, cresceu);
    raiz = inserir(raiz, 1, cresceu);
    raiz = inserir(raiz, 18, cresceu);
    raiz = inserir(raiz, 06, cresceu);

    //pra mostrar as rotacoes só dos 3 ultimos
    LL = 0;
    LR = 0;
    RR = 0;
    RL = 0;

    for(int i = 0; i < 3; i++)
    {
        cout << "Entre o primeiro valor: ";
        cin >> chave;
        raiz = inserir(raiz, chave, cresceu);
    }

    cout << "Rotacoes LL = " << LL << endl;
    cout << "Rotacoes LR = " << LR << endl;
    cout << "Rotacoes RR = " << RR << endl;
    cout << "Rotacoes RL = " << RL << endl;

    // 3, 0, 2, 8, 9, 4, 1, 18, 06, 3 (ja foi inserido anteriormente), 5, 7

    return 0;
}
