#include <iostream>
using namespace std;

struct NoAVL
{
    int chave;
    int fb;
    NoAVL* dir;
    NoAVL* esq;
};

NoAVL* CriarNo(int chave){
    NoAVL* novoNo = new NoAVL;
    novoNo->chave = chave;
   
    novoNo->dir = nullptr;
    novoNo->esq = nullptr;
    novoNo->fb = 0;
    return novoNo;
}

void Buscar (int chave, NoAVL* raiz){
    if (raiz == nullptr){
        cout << "Valor não encontrado!" << endl;
    } 
    else if (raiz->chave == chave){
        cout << "Valor encotrado!" << endl;
    }   
    else if(chave < raiz->chave)
        Buscar (chave, raiz->esq);
    else
        Buscar (chave, raiz->dir);
}

int Contagem (NoAVL* raiz){
    if (raiz == nullptr)
        return 0;
    else
    {
        return Contagem(raiz->esq) + 1 + Contagem(raiz->dir);
    }
}

void EmOrdem (NoAVL* raiz){
    if (raiz != nullptr)
    {
        EmOrdem(raiz->esq);
        cout << raiz->chave << " - ";
        EmOrdem(raiz->dir);
    }
}

void PreOrdem (NoAVL* raiz){
    if (raiz != nullptr)
    {
        cout << raiz->chave << " - ";
        PreOrdem(raiz->esq);
        PreOrdem(raiz->dir);
    }
}

void PosOrdem (NoAVL* raiz){
    if (raiz != nullptr)
    {
        PosOrdem(raiz->esq);
        PosOrdem(raiz->dir);
        cout << raiz->chave << " - ";
    }
}

NoAVL* RotacaoL(NoAVL* p){
    NoAVL* u = p->esq;

    if (u->fb == -1)
    {
        /* Rotação LR */
        NoAVL* v = u->dir;
        u->dir = v->esq;
        v->esq = u;
        p->esq = v->dir;
        v->dir = p;

        if (v->fb == -1) {
            p->fb = 0;
            u->fb = 1;
        } else if (v->fb == 1) {
            p->fb = -1;
            u->fb = 0;
        }

        v->fb = 0;

        return Cout << LR;
    }

    /* Rotação LL */
    p->esq = u->dir;
    u->dir = p;
    p->fb = 0;
    u->fb = 0;
    return cout << LL;

    if (u->fb == 1)
    {
        /* Rotação RL */
        NoAVL* v = u->esq;
        u->esq = v->dir;
        v->dir = u;
        p->dir = v->esq;
        v->esq = p;

        if (v->fb == -1) {
            p->fb = 1;
            u->fb = 0;
        } else if (v->fb == 1) {
            p->fb = 0;
            u->fb = -1;
        }

        v->fb = 0;

        return cout << RL;
    }

    p->dir = u->esq;
    u->esq = p;
    p->fb = 0;
    u->fb = 0;
    return cout << RR;
}

NoAVL* Inserir (NoAVL*& raiz, int chave,  bool& cresceu){

    if(raiz == nullptr){
        cresceu = true;
        raiz = CriarNo(chave);
    }

    else if(chave < raiz->chave){
        Inserir (raiz->esq, chave, &cresceu);
        if (cresceu){
            if (raiz->fb == 0)
                raiz->fb = 1;
            else if (raiz->fb == -1)
                raiz->fb = 0;
            else if (raiz->fb == 1)
            {
                raiz = RotacaoL (raiz);
                cresceu = false;
            }
        }
    }
    else {
        Inserir (raiz->dir, chave, chave1, chave2, chave3, chave4, cresceu);
        if (cresceu){
            if (raiz->fb == 0)
                raiz->fb = -1;
            else if (raiz->fb == 1)
                raiz->fb = 0;
            else if (raiz->fb == -1)
            {
                raiz = RotacaoR (raiz);
                cresceu = false;
            }
        }
    }

    return raiz;
}

int main()
{
    NoAVL* raiz = nullptr;
    bool cresceu = false;
Inserir (raiz, 9, cresceu);
    Inserir (raiz, 7, cresceu);
    Inserir (raiz, 10, cresceu);
    Inserir (raiz, 8, cresceu);
    Inserir (raiz, 4, cresceu);

    raiz = RotacaoL (raiz);
    PreOrdem (raiz);
   cout << raiz;

    
   
    return 0;
}