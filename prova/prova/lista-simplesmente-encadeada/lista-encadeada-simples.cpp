// Programa Lista Encadeada Simples
#include <iostream>
using namespace std;

struct No
{
    int info;
    No* proximo; //ponteiro pro próximo nó da lista
};

//insere um novo nó no final da lista
void inserir(No*& cabeca, int valor) //"No* cabeca" aponta o inicio da lista, "&" diz que o ponteiro original (cabeca) pode ser modificado dentro da função
{
    //cria o objeto No{info recebe valor, proximo recebe nullptr} e armazena o endereço dele no ponteiro novoNo
    No* novoNo = new No{valor, nullptr};

    //se a lista estiver vazia, o novo nó vira o primeiro //senao percorre até o fim da lista pra inserir o novo nó
    if(cabeca == nullptr)
        cabeca = novoNo; //novoNo agora é o topo da lista
    else //se a lista não estiver vazia
    {
        No* temporario = cabeca; //cria um ponteiro temporario que começa na cabeca

        while(temporario->proximo != nullptr) //vai percorrendo até chegar no último nó (aquele que aponta pra nullptr)
            temporario = temporario->proximo;

        temporario->proximo = novoNo; //liga o último nó com o novoNo, fazendo ele apontar para esse novoNo
    }
}

void remover(No*& cabeca)
{
    No* temporario = cabeca;
    No* apagar = cabeca->proximo;

    while(apagar->proximo != nullptr)
    {
        temporario = apagar;
        apagar->proximo;
    }

    temporario->proximo = nullptr;
}

//percorre a lista toda pra mostrar as infos de cada nó
void mostrarLista(No* cabeca)
{
    No* temporario = cabeca; //temporario começando na cabeca pra mostrar desde o começo

    while(temporario != nullptr) //se apontando pra algum lugar diferente de nulo mostra as infos
    {
        //"->" operador para acessar membros de uma estrutura através de um ponteiro
        //temporario (ponteiro) ta acessando a info do registro No
        //nao pode fazer temporario.info, pois temporario é um ponteiro
        cout << temporario->info << " ";
        temporario = temporario->proximo;
    }
    cout << endl;
}

int main(void)
{
    No* cabeca = nullptr; //cria a lista inicialmente vazia com o ponteiro cabeca

    inserir(cabeca, 10);
    inserir(cabeca, 30);
    inserir(cabeca, 20);
    inserir(cabeca, 1);
    mostrarLista(cabeca);
    remover(cabeca);
    mostrarLista(cabeca);

    cout << "Tecle <Enter> para encerrar... ";
    cin.get();
    return 0;
}
