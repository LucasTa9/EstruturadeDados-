//Lista Dinâmica - Lista encadeada
#include <iostream>

struct Node
{
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value)
{
    //cria um novo nó na memória heap com o valor value, e o ponteiro next apontando pra nullptr (ou seja, sem próximo nó ainda), e armazene o endereço desse novo nó no ponteiro newNode
    Node* newNode = new Node{value, nullptr};

    //se a cabeca tiver vazia, entao insere nela o novo nó
    if (head == nullptr)
    {
        head = newNode;
    }
    //se a cabeca não estiver vazia, faz isso:
    else
    {
        Node* temp = head; //cria um ponteiro temporario armazenando o endereco da cabeca

        //enquanto o ponteiro temporario que aponta para o proximo for diferente de nulo, faz isso:
        while (temp->next != nullptr)
        {
            temp = temp->next; //o ponteiro temporario armazena o endereço do proximo até chegar no vazio
        }
        temp->next = newNode; //chegou no vazio insere o novo nó
    }
}

void printList(const Node* head)
{
    const Node* temp = head; //cria um ponteiro temporario armazenando o endereco da cabeca

    //enquanto o ponteiro temporario for diferente de nulo, faz isso:
    while (temp != nullptr)
    {
        std::cout << temp->data << " "; //apresenta atraves do apontamento do ponteiro os valores inseridos
        temp = temp->next; //e vai pro proximo da lista
    }
    std::cout << std::endl;
}

void freeList(Node*& head) //essa função pode mudar o ponteiro cabeca original, pois é uma passagem de parametro por referencia
{
    Node* temp; //cria um ponteiro temporario pra segurar o nó atual

    //enquanto o ponteiro cabeca não apontar pra lugar nenhum, faz isso:
    while (head != nullptr)
    {
        temp = head; //temporario guarda  o nó atual que é a cabeca
        head = head->next; //a cabeca pula pro proximo nó
        delete temp; //como o proximo nó esta guardado na cabeca, entao é seguro apagar o temporario e assim apaga todos os nós
    }
}

int main(void)
{
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    std::cout << "Lista encadeada: ";
    printList(head);

    std::cout << "\nLista encadeada: ";
    freeList(head);

    std::cout << std::endl;
    return 0;
}
