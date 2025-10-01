//Remover Recusivamente Nó em Árvore Binária de Busca
#include <iostream>
using namespace std;

struct No
{
    int valor;
    No* dir;
    No* esq;
};

No* inicializar()
{
    return nullptr;
}

void adicionar(No*& raiz, int valor)
{
    if (raiz == nullptr) // Se a árvore estiver vazia
    {
        raiz = new No; // Cria um novo nó
        raiz->valor = valor; // Atribui o valor ao nó
        raiz->esq = nullptr; // Inicializa o filho esquerdo como nulo
        raiz->dir = nullptr; // Inicializa o filho direito como nulo
    }
    else
        if (valor < raiz->valor)         // Se o valor for menor que o valor do nó atual
            adicionar(raiz->esq, valor); // Adiciona à subárvore esquerda
        else
            if (valor > raiz->valor)         // Se o valor for maior que o valor do nó atual
                adicionar(raiz->dir, valor); // Adiciona à subárvore direita
}

void inorder(No* raiz)
{
    if (raiz != nullptr) // Se o nó não for nulo
    {
        inorder(raiz->esq);         // Visita a subárvore esquerda
        cout << raiz->valor << " "; // Imprime o valor do nó atual
        inorder(raiz->dir);         // Visita a subárvore direita
    }
}

void remover(No*& raiz, int valor)
{
    if (raiz == nullptr) // Se a árvore estiver vazia
    {
        cout << "Valor nao encontrado." << endl;
        return;
    }

    if (valor < raiz->valor)       // Se o valor buscado for menor que o valor do nó atual
        remover(raiz->esq, valor); // Busca na subárvore esquerda
    else
        if (valor > raiz->valor)       // Se o valor buscado for maior que o valor do nó atual
            remover(raiz->dir, valor); // Busca na subárvore direita
        else // Se o valor buscado for igual ao valor do nó atual
        {
            No* temp = raiz; // Armazena o nó a ser removido

            if (raiz->esq == nullptr) // Se não houver filho esquerdo
                raiz = raiz->dir;     // Substitui pelo filho direito
            else
                if (raiz->dir == nullptr) // Se não houver filho direito
                    raiz = raiz->esq;     // Substitui pelo filho esquerdo
                else // Se houver ambos os filhos
                {
                    No* sucessor = raiz->dir; // Encontra o sucessor (menor na subárvore direita)

                    while (sucessor->esq != nullptr)
                        sucessor = sucessor->esq;

                    raiz->valor = sucessor->valor;       // Substitui o valor do nó atual pelo sucessor
                    remover(raiz->dir, sucessor->valor); // Remove o sucessor da subárvore direita
                }

                delete temp; // Libera a memória do nó removido
        }
}

int main(void)
{
    No* no = inicializar();

    adicionar(no, 5);
    adicionar(no, 8);
    adicionar(no, 3);
    adicionar(no, 9);
    adicionar(no, 4);
    remover(no, 8);
    inorder(no);

    return 0;
}
