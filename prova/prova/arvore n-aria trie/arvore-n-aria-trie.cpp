//Programa Árvore N-Ária: Trie
#include <iostream>
#include <string>
using namespace std;

const int N_ALFABETO = 26;

struct TrieNode
{
    TrieNode* filhos[N_ALFABETO];
    bool fim;
};

//inicializa 26 ponteiros do array filhos com nullptr
TrieNode* criarNo()
{
    TrieNode* no = new TrieNode(); //aloca dinamicamente um novo objeto TrieNode na heap (memória dinâmica), e no passa a apontar para ele

    no->fim = false;

    for(int i = 0; i < N_ALFABETO; i++)
        no->filhos[i] = nullptr;

    return no; //retorna o endereco do objeto TrieNode
}

//mapear diretamente um símbolo da chave a uma posição do arranjo de filhos no nó
//nesse caso converte 'c' em um numero entre 0 e 25
//usa a tabela de ASCII - sendo as letras minusculas
int charToIndex(char c)
{
    return c - 'a'; //ex: t = 116 e a = 97, entao t - a = 19  //19 é a posicao do caractere 't'
}

void inserir(TrieNode* raiz, const string& palavra)
{
    TrieNode* atual = raiz;

    //percorre cada caractere da palavra, usando for-each (laço para cada)
    for(char c : palavra)
    {
        //pega a posição do caractere
        int index = charToIndex(c);

        //se nao existir um filho nessa posicao especifica
        if(!atual->filhos[index])
            atual->filhos[index] = criarNo(); //entao insere um novo nó nessa posicao como filho

        //move pra esse filho
        atual = atual->filhos[index];
    }

    //marca o no final como sendo o fim de uma palavra
    atual->fim = true;
}

bool buscar(TrieNode* raiz, const string& palavra)
{
    TrieNode* atual = raiz;

    //percorre cada caractere da palavra, usando for-each (laço para cada)
    for(char c : palavra)
    {
        int index = charToIndex(c);

        //se nao existir um filho nessa posicao
        if(!atual->filhos[index])
            return false; //a palavra nao esta na Trie

        atual = atual->filhos[index];
    }

    return atual->fim; //retorna que achou a palavra
}

void exibirArvore(TrieNode* raiz, string prefixo = "") //prefixo é uma string que vai acumulando os caracteres durante a recursao
{
    //se o no atual (raiz) é o fim de uma palavra, ou seja, se fim = true
    if(raiz->fim)
        cout << prefixo << endl; //se for, isso significa que o caminho de caracteres acumulados até esse no forma uma palavra valida. Entao, ele imprime essa palavra (prefixo)

    for(int i = 0; i < N_ALFABETO; i++)
    {
        if(raiz->filhos[i])
        {
            char c = 'a' + i;
            exibirArvore(raiz->filhos[i], prefixo + c);
        }
    }
}

void exibirPalavra(TrieNode* raiz, const string& palavra)
{
    TrieNode* atual = raiz;

    for(char c : palavra)
    {
        int index = charToIndex(c);

        if(!atual->filhos[index])
        {
            cout << "Palavra '" << palavra << "' nao encontrada na Trie.\n";
            return;
        }

        atual = atual->filhos[index];
    }

    if(atual->fim)
        cout << "Palavra encontrada: " << palavra << endl;
    else
        cout << "Prefixo encontrado, mas nao eh uma palavra completa: " << palavra << endl;
}

int main(void)
{
    TrieNode* raiz = criarNo();

    inserir(raiz, "melancia");
    inserir(raiz, "manga");
    inserir(raiz, "mexerica");
    inserir(raiz, "mamao");

    cout << "Palavras na Trie: \n";
    exibirArvore(raiz);
    cout << endl;

    exibirPalavra(raiz, "mel");
    exibirPalavra(raiz, "melancia");
    exibirPalavra(raiz, "melo");

    return 0;
}
