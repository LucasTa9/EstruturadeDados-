#include <iostream>
using namespace std;

struct No
{
    int chave;
    No* dir;
    No* esq;
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



void Inserir (int chave, No*& raiz){
    if(raiz == nullptr){
        raiz = new No;
        raiz->chave = chave;
        raiz->dir = nullptr;
        raiz->esq = nullptr;
    }
    else if(chave < raiz->chave)
        Inserir (chave, raiz->esq);
    else
        Inserir (chave, raiz->dir);
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

void Remover(No*& raiz, int chave){
    if(raiz == nullptr){
        cout << "Valor não encontrado!" << endl;
        return;
    }
    if(chave < raiz->chave)
        Remover (raiz->esq, chave);
    else if(chave > raiz->chave)
        Remover (raiz->dir, chave);
    else {
        No* aux = raiz;
        if (raiz->dir == nullptr && raiz->esq == nullptr){
            delete aux;
        }
        else if (raiz->esq == nullptr){
            raiz = raiz->dir;
        }
        else if (raiz->dir == nullptr){
            raiz = raiz->esq;
        }
        else{
            No* sucessor = raiz->dir;
            while (sucessor->esq != nullptr)
            {
                sucessor = sucessor->esq;
            }
            raiz->chave = sucessor->chave;
            Remover(raiz->dir, sucessor->chave);
        }
    }
}



No* BuscaAux(No* raiz, int chave, No*& no) {
    if (raiz == nullptr)
        return nullptr;

    if (raiz->esq != nullptr && raiz->esq->chave == chave) {
        no = raiz->esq;
        return raiz;
    }
    if (raiz->dir != nullptr && raiz->dir->chave == chave) {
        no = raiz->dir;
        return raiz;
    }

    if (chave < raiz->chave)
        return BuscaAux(raiz->esq, chave, no);
    else
        return BuscaAux(raiz->dir, chave, no);
}

void RemoverInterativo(No*& raiz, int chave) {
    if (raiz == nullptr) {
        cout << "Árvore vazia!" << endl;
        return;
    }

    if (raiz->chave == chave) {
        No* temp = raiz;
        if (raiz->esq == nullptr && raiz->dir == nullptr) {
            delete temp;
            raiz = nullptr;
        } else if (raiz->esq == nullptr) {
            raiz = raiz->dir;
            delete temp;
        } else if (raiz->dir == nullptr) {
            raiz = raiz->esq;
            delete temp;
        } else {
            
            No* paiSucessor = raiz;
            No* sucessor = raiz->dir;
            while (sucessor->esq != nullptr) {
                paiSucessor = sucessor;
                sucessor = sucessor->esq;
            }

            raiz->chave = sucessor->chave;

            if (paiSucessor->esq == sucessor)
                paiSucessor->esq = sucessor->dir;
            else
                paiSucessor->dir = sucessor->dir;

            delete sucessor;
        }
        return;
    }

    No* no = nullptr;
    No* pai = BuscaAux(raiz, chave, no);

    if (pai == nullptr || no == nullptr) {
        cout << "Valor não encontrado!" << endl;
        return;
    }

    bool isLeftChild = (pai->esq == no);

    if (no->esq == nullptr && no->dir == nullptr) {
        if (isLeftChild)
            pai->esq = nullptr;
        else
            pai->dir = nullptr;
        delete no;
    }

    
    else if (no->esq == nullptr || no->dir == nullptr) {
        No* filho = (no->esq != nullptr) ? no->esq : no->dir;
        if (isLeftChild)
            pai->esq = filho;
        else
            pai->dir = filho;
        delete no;
    }

    else {
        No* paiSucessor = no;
        No* sucessor = no->dir;
        while (sucessor->esq != nullptr) {
            paiSucessor = sucessor;
            sucessor = sucessor->esq;
        }

        no->chave = sucessor->chave;

        if (paiSucessor->esq == sucessor)
            paiSucessor->esq = sucessor->dir;
        else
            paiSucessor->dir = sucessor->dir;

        delete sucessor;
    }
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
