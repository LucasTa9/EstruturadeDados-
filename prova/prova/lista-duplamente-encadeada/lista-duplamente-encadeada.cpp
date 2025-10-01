//Prova Prática de Revisão – Estrutura de Dados
#include <iostream>
#include <string>
using namespace std;

//-------------------------------------------------------------------------------------------------------------------------
// EXERCÍCIO 01 - Lista Duplamente Encadeada como Fila e Pilha ------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------
//Nó em Lista Duplamente Encadeada
struct No
{
    int valor;
    No* proximo;
    No* anterior;
};

//Operar a lista como Fila (FIFO) ------------------------------------------------------------------------------------------
No* primeiro;
No* ultimo;

void inserir_fila(int valor)
{
    No* novoNo = new No{valor, nullptr, nullptr};

    //se a fila estiver vazia
    if(ultimo == nullptr)
        ultimo = primeiro = novoNo; //então insere em primeiro na fila
    else //se não estiver vazia
    {
        ultimo->proximo = novoNo; //então conecta o novoNo como próximo do último nó
        novoNo->anterior = ultimo; //aponta o aterior do novoNo para o nó que antes era o último
        ultimo = novoNo; //novoNo passa a ser o último da fila
    }

    cout << valor << " ";
}

void remover_fila()
{
    //se ultimo = nullptr, então a fila está vazia
    if(ultimo == nullptr)
    {
        cout << "A fila está vazia, nenhum valor pode ser removido!" << endl;
        return;
    }

    //se não estiver vazia
    No* temp = primeiro; //ponteiro temporário para guardar o nó que será removido para depois liberar a memória
    cout << temp->valor << " ";

    //primeiro passa a apontar pro próximo nó
    primeiro = primeiro->proximo;

    //se o nó que estava depois do atual ainda existir
    if(primeiro != nullptr)
        primeiro->anterior = nullptr; //então o novo primeiro tem como anterior nulo
    else
        ultimo = nullptr; //se a fila ficou vazia, então o ultimo passa a ser nulo também

    delete temp; //libera a memória
}

//Operar a lista como Pilha (LIFO) ------------------------------------------------------------------------------------------
No* topo;

void inserir_pilha(int valor)
{
    No* novoNo = new No{valor, nullptr, nullptr};

    //se a pilha estiver vazia
    if(topo == nullptr)
        topo = novoNo; //então insere no topo da pilha
    else //se não estiver vazia
    {
        novoNo->anterior = topo; //então anterior do novoNo passa a apontar ao antigo topo
        topo->proximo = novoNo; //antigo topo passa a apontar para o novoNo
        topo = novoNo; //topo da pilha passa a ser o novoNo
    }

    cout << valor << " ";
}

void remover_pilha()
{
    //se o topo for nulo, então a pilha está vazia
    if(topo == nullptr)
    {
        cout << "A pilha está vazia, nenhum valor pode ser removido!" << endl;
        return;
    }

    //se não estiver vazia
    No* temp = topo;
    cout << temp->valor << " ";

    topo = topo->anterior; //topo passa a apontar para o nó anterior

    //se o topo não for nulo
    if(topo != nullptr)
        topo->proximo = nullptr; //então o proximo do topo fica nulo

    delete temp; //libera a memória
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    cout << "------------------------";
    cout << "\n|     EXERCÍCIO 01     |" << endl;
    cout << "------------------------\n";
    cout << "\n-------- Fila --------" << endl;
    cout << "Valores inseridos ...:" << endl;
    inserir_fila(5);
    inserir_fila(3);
    inserir_fila(7);
    inserir_fila(8);

    cout << "\n\nValores removidos ...:" << endl;
    remover_fila();
    remover_fila();

    cout << "\n\n-------- Pilha -------" << endl;
    cout << "Valores inseridos ...:" << endl;
    inserir_pilha(5);
    inserir_pilha(3);
    inserir_pilha(7);
    inserir_pilha(8);

    cout << "\n\nValores removidos ...:" << endl;
    remover_pilha();
    remover_pilha();

    return 0;
}
