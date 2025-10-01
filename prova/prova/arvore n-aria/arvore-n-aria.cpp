//Programa com Árvore N-Árias (Inserir, Contar, Exibir, Buscar e Liberar Memória)
#include <iostream>
#include <cstdlib> //pra malloc
using namespace std;

struct No
{
    int chave;
    No* primeiro_filho; //vertical
    No* proximo_irmao;  //horizontal
};

No* criar_no(int chave)
{
    No* novo_no = (No*)malloc(sizeof(No)); //aloca memoria pro novo nó

    novo_no->chave = chave;
    novo_no->primeiro_filho = nullptr;
    novo_no->proximo_irmao = nullptr;

    return novo_no;
}

void inserir(No* pai, int chave)
{
    No* novo_no = criar_no(chave);

    //se o pai ainda nao tem filhos, insere o primeiro filho como o novo nó
    if (pai->primeiro_filho == nullptr)
        pai->primeiro_filho = novo_no;
    else //se o pai ja tem filhos
    {
        No* irmao = pai->primeiro_filho;

        //percorre até o ultimo irmao
        while (irmao->proximo_irmao != nullptr)
            irmao = irmao->proximo_irmao;

        //e insere o novo nó como ultimo irmao
        irmao->proximo_irmao = novo_no;
    }
}

int contagem(No* raiz)
{
    if(raiz == nullptr)
        return 0;

    return contagem(raiz->primeiro_filho) + 1 + contagem(raiz->proximo_irmao);
}

void exibir(No* raiz, int nivel) //o nivel é só pra apresentar bonito
{
    if (raiz == nullptr) return;

    for (int i = 0; i < nivel; i++)
        cout << "  ";

    cout << raiz->chave << endl;
    exibir(raiz->primeiro_filho, nivel + 1); //exibe os filhos com nivel maior
    exibir(raiz->proximo_irmao, nivel); //exibe os irmaos com o mesmo nivel
}

//busca em profundidade (DFS)
No* buscar(No* raiz, int chave)
{
    //se a arvore estiver vazia retorna nullptr
    if (raiz == nullptr) return nullptr;

    //se ja for a chave da raiz, retorna ela
    if (raiz->chave == chave) return raiz;

    //se nao for a raiz
    //entao enquanto o filho da raiz for diferente de nulo
    No* filho = raiz->primeiro_filho;
    while(filho != nullptr)
    {
        //busca na subarvore do filho
        No* encontrado = buscar(filho, chave);
        if (encontrado != nullptr) return encontrado;

        //se nao encontrar filho = irmao
        filho = filho->proximo_irmao;
    }

    //se nao encontrou, retorna nada
    return nullptr;
}

//pra nao ocorrer vazamento de memoria, ja que usou alocacao de memoria dinamica com malloc
void liberar_memoria(No* raiz)
{
    if (raiz == nullptr) return;

    liberar_memoria(raiz->primeiro_filho); //libera os filhos
    liberar_memoria(raiz->proximo_irmao);  //libera os irmaos
    free(raiz);                            //libera o proprio nó  //free pra liberar a memoria alocada pela funcao malloc
}

int main(void)
{
    No* raiz = criar_no(1); //cria o nó raiz com chave 1

    inserir(raiz, 2);
    inserir(raiz, 3);
    inserir(raiz, 4);

    //busca o nó 2 e insere filhos nele
    No* no2 = buscar(raiz, 2);
    if (no2 != nullptr)
    {
        inserir(no2, 5);
        inserir(no2, 6);
    }

    //busca o nó 3 e insere um filho nele
    No* no3 = buscar(raiz, 3);
    if (no3 != nullptr)
        inserir(no3, 7);

    cout << "Total de Nos: " << contagem(raiz) << endl << endl;

    cout << "Arvore N-aria:" << endl;
    exibir(raiz, 0);

    liberar_memoria(raiz);
    return 0;
}
