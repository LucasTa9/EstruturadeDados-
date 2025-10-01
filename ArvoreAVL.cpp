#include <iostream>
using namespace std;

struct NoAVL
{
    int chave;
    int fb;
   NoAVL* dir;
   NoAVL* esq;
};

No* fila[6];
int inicio = 0;
int fim = 0;

void Enfileirar(No* valor){
    if (fim == 6)
    {
        cout << "Fila cheia!!" << endl;
        return;
    }
    
    fila[fim] = valor;
    fim++; 
}

void Desenfileirar(){
    if (inicio == fim){
        cout << "Fila vazia!!" << endl;
        return;
    }

    inicio++;
}




void Buscar (int chave, No* raiz){
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

int Contagem (No* raiz){
    if (raiz == nullptr)
        return 0;
    else
    {
        return Contagem(raiz->esq) + 1 + Contagem(raiz->dir);
    }
}

void EmOrdem (No* raiz){
    if (raiz != nullptr)
    {
        EmOrdem(raiz->esq);
        cout << raiz->chave << " - ";
        EmOrdem(raiz->dir);
    }
}

void PreOrdem (No* raiz){
    if (raiz != nullptr)
    {
        cout << raiz->chave << " - ";
        PreOrdem(raiz->esq);
        PreOrdem(raiz->dir);
    }
}

void PosOrdem (No* raiz){
    if (raiz != nullptr)
    {
        PosOrdem(raiz->esq);
        PosOrdem(raiz->dir);
        cout << raiz->chave << " - ";
    }
}

void Largura(No* raiz){
    Enfileirar(raiz);

    for (int i = 0; i < 6; i++)
    {
        cout << fila[i]->chave << " - ";
        if (fila[i]->esq != nullptr)
            Enfileirar(fila[i]->esq);
        if (fila[i]->dir != nullptr)
            Enfileirar(fila[i]->dir);
        Desenfileirar();
    }
}


NoAVL* RotacaoL(NoAVL* p){
    NoAVL* u = p->esq;
   
if (u->fb == -1)
{
    NoAVL* v = u->dir; 
    u->dir = v->esq;
    v-> esq = u;
   
    p->esq = v->dir;
    v-> dir = p;

    if (v->fb ==-1){
        p->fb =0;
        u->fb = 1;
    } else if (v-> == 1){
        p->fb =-1;
        u->fb = 0;
    }
    v->fb = 0;
    return v;
}
 p->esq = u->dir;
    u->dir = p;
    p->fb = 0;
    u->fb = 0;
    return u;

   
}
NoAVL* RotacaoRR(NoAVL* p){
    NoAVL* u = p->dir;
  if (u->fb == 1)
{
    NoAVL* v = u->esq; 
    u->esq = v->dir;
    v-> dir = u;
    p->dir = v->esq;
    v-> esq = p;

    if (v->fb == -1){
        p->fb =1;
        u->fb = 0;
    } else if (v-> == 1){
        p->fb =0;
        u->fb = -1;
    }
    v->fb = 0;
    return v;
}

    p->dir= u->esq;
    u->esq = p;
    p->fb = 0;
    u->fb = 0;
    return u;

}

NoAVL* Inserir(NoAVL*& raiz, int chave, bool& cresceu){
    if (rais == nullptr){
        cresceu = true;
        raiz = new NoAVL;
        raiz->chave = chave
        raiz->dir = nullptr;
        raiz->esq = nullptr;
        raiz-> fb = 0
    }
    else if (chave < raiz->chave)
        inserir(raiz->esq, chave, cresceu);
        if (cresceu){
          if (raiz->fb == 0)

           raiz->fb = 1;
           
           else if(raiz->fb == -1)
            raiz->fb = 0;

           else if (raiz->fb == 1)
           {
             raiz = rotacaoL (raiz);
             cresceu = false;
           }  
        }
    else
        inserir (raiz->dir, chave, cresceu);
        if (cresceu){
          if (raiz->fb == 0)

           raiz->fb = -1;
           
           else if(raiz->fb == 1)
            raiz->fb = 0;
            
           else if (raiz->fb == 1)
           {
             raiz = rotacaoR (raiz);
             cresceu = false;
           }  
        }
        return raiz;
    }







int main(int argc, char const *argv[])
{
    No* raiz = nullptr;
    Inserir (5, raiz);
    Inserir (3, raiz);
    Inserir (4, raiz);
    Inserir (9, raiz);
    Inserir (8, raiz);
    Inserir (10, raiz);
    //Buscar (5, raiz);
    //Buscar (1, raiz);
    //cout << Contagem(raiz) << endl;
    RemoverInterativo(raiz, 5);
    //EmOrdem(raiz);
    //cout << endl;
    //PreOrdem(raiz);
    //cout << endl;
    //PosOrdem(raiz);
    Largura(raiz);
    return 0;
}
