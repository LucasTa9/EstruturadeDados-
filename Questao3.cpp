#include <iostream>
#include <string>
using namespace std;

struct NoAVL
{
    int chave;
    int fb;
    NoAVL* dir;
    NoAVL* esq;
};

bool rodou = false;

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

        if (v->fb == 1) {
            u->fb = 0;
            p->fb = -1;
        } else if (v->fb == -1) {
            u->fb = 1;
            p->fb = 0;
        } else {
            u->fb = 0;
            p->fb = 0;
        }

        v->fb = 0;
        if (rodou)
        {
        cout<< " LR;";
        }else{
         cout<< "LR";
        }
        rodou = true;
        

        return v;
    }

    /* Rotação LL */
    p->esq = u->dir;
    u->dir = p;
    p->fb = 0;
    u->fb = 0;
    if (rodou)
        {
        cout<< " LL;";
        }else{
         cout<< "LL";
        }
        rodou = true;
        
    return u;
}

NoAVL* RotacaoR(NoAVL* p){
    NoAVL* u = p->dir;

    if (u->fb == 1)
    {
        /* Rotação RL */
        NoAVL* v = u->esq;
        u->esq = v->dir;
        v->dir = u;
        p->dir = v->esq;
        v->esq = p;

        if (v->fb == 1) {
            p->fb = 0;
            u->fb = -1;
        } else if (v->fb == -1) {
            p->fb = 1;
            u->fb = 0;
        } else {
            p->fb = 0;
            u->fb = 0;
        }

        v->fb = 0;
        if (rodou)
        {
        cout<< " RL;";
        }else{
         cout<< "RL";
        }
        rodou = true;
        

        return v;
    }

    p->dir = u->esq;
    u->esq = p;
    p->fb = 0;
    u->fb = 0;
    return u;
}

NoAVL* Inserir (NoAVL*& raiz, int chave, bool& cresceu){

    if(raiz == nullptr){
        cresceu = true;
        raiz = CriarNo(chave);
    }

    else if(chave < raiz->chave){
        Inserir (raiz->esq, chave, cresceu);
        if (cresceu){
            if (raiz->fb == 0)
                raiz->fb = 1;
            else if (raiz->fb == -1)
                raiz->fb = 0, cresceu = false;
            else if (raiz->fb == 1)
            {
                raiz = RotacaoL (raiz);
                cresceu = false;
            }
        }
    }
    else {
        Inserir (raiz->dir, chave, cresceu);
        if (cresceu){
            if (raiz->fb == 0)
                raiz->fb = -1;
            else if (raiz->fb == 1)
                raiz->fb = 0, cresceu = false;
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
    int prontp1;
    int prontp2;


    cin >> prontp1;
    Inserir(raiz, cin, cresceu)

    

   

    return 0;
}
