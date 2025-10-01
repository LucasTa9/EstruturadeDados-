

// Implemente um programa que trabalhe com árvores AVL da seguinte forma:
    
    // A árvore deve ser inicializada contendo, em ordem de inserção, as letras do seu primeiro nome.
    // O programa deve receber como entrada uma palavra digitada pelo usuário.
    // As letras dessa palavra devem ser inseridas na árvore, considerando apenas as letras não repetidas.
    // Após todas as inserções, a árvore resultante deve ser exibida em percurso em largura (nível a nível).

// Primeiro peguei o código base de uma árvore AVL, disponível no classroom, depois adaptei para fazer o que o exercício pede.
#include <iostream>
using namespace std;

struct No
{
    // Altere o tipo da chave para char
    char chave;
 
    No* dir;
    No* esq;
};

// Peguei o código base de uma ABB, disponível no classroom, para usar a função de percurso em largura.
No* fila[100]; // Aumentei o tamanho da fila para 100, para evitar problemas com muitas letras.
int inicio = 0;
int fim = 0;

void Enfileirar(No* valor){
    if (fim == 100)
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

// Ajustei a função Largura para percorrer a lista maior
void Largura(No* raiz){
    if (!raiz) return;

    inicio = 0;
    fim = 0;
    Enfileirar(raiz);

    while (inicio < fim){
        No* atual = fila[inicio];
        inicio++;

        cout << atual->chave << " - ";

        if (atual->esq) Enfileirar(atual->esq);
        if (atual->dir) Enfileirar(atual->dir);
    }
}

// Ajustei a função CriarNo para o tipo char
No* CriarNo(char chave){
    No* novoNo = new No;
    novoNo->chave = chave;
    novoNo->dir = nullptr;
    novoNo->esq = nullptr;
   
    return novoNo;
}


// Ajustei a função Inserir para o tipo char{

void inserir(char chave, No*& raiz)
{
   
    if(raiz == nullptr)
        raiz = new No{chave, nullptr, nullptr};
    else
    {
        if(chave < raiz->chave)
            inserir(chave, raiz->dir);
        else
            inserir(chave, raiz->esq);
    }
}


// Alterei a função Buscar para rerotnar um bool e usar char
bool Buscar (char chave, No* raiz){
    if (raiz == nullptr){
        return false;
    } 
    else if (raiz->chave == chave){
        return true;
    }   
    else if(chave < raiz->chave)
        return Buscar (chave, raiz->esq);
    else
        return Buscar (chave, raiz->dir);
}
void EmOrdem (No* raiz){
    if (raiz != nullptr)
    {
        EmOrdem(raiz->esq);
        cout << raiz->chave<< " - ";
        EmOrdem(raiz->dir);
    }
}


int main()
{
 
   No* raiz = nullptr;
    std::string palavra;
    std::cin >> palavra;
    for(char c : palavra)
        inserir(c ,raiz ); 
    
     
    
    Largura(raiz);
    cout << endl;
    EmOrdem(raiz);

    cout << endl;

    return 0;
}
