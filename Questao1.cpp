//Exercicio 01 da Prova
#include <iostream>
#include <string>

// Estrutura para no em lista duplamente encadeada
struct noChar
{
    char letra;
    noChar* proximo;
    noChar* anterior;
};

// Ponteiros globais para a cabeça e cauda da lista, e o tamanho
noChar* cabeca = nullptr;
noChar* cauda = nullptr;
int tamanhoPalavra = 0;

void inserirNoInicio(char letra)
{
    noChar* novoNo = new noChar{letra, cabeca, nullptr};

    if(cabeca != nullptr)
        cabeca->proximo = novoNo;

    cabeca = novoNo;

    //se a lista esta vazia, a cauda também eh o novo no
    if(cauda == nullptr)
        cauda = novoNo;

    tamanhoPalavra++;
}

void inserirNoFim(char letra)
{
    noChar* novoNo = new noChar{letra, nullptr, cauda};

    if(cauda != nullptr)
        cauda->proximo = novoNo;

    cauda = novoNo;

    //se a lista esta vazia, a cabeca também eh o novo no
    if(cabeca == nullptr)
        cabeca = novoNo;

    tamanhoPalavra++;
}

char removerNoInicio()
{
    //se a lista esta vazia
    if(cabeca == nullptr)
    {
        std::cout << "Lista vazia, nao eh possivel remover do inicio.";
        return '\0'; //retorna um caractere nulo se a lista estiver vazia
    }

    char valor = cabeca->letra;
    noChar* temp = cabeca;
    cabeca = cabeca->proximo;

    //se tiver elementos
    if(cabeca != nullptr)
        cabeca->anterior = nullptr;
    else //a lista ficou vazia
        cauda = nullptr;

    delete temp;
    tamanhoPalavra--;
    return valor;
}

char removerNoFim()
{
    //se a lista ta vazia
    if(cauda == nullptr)
    {
        std::cout << "Lista vazia, nao eh possivel remover do fim.";
        return '\0';
    }

    char valor = cauda->letra;
    noChar* temp = cauda;
    cauda = cauda->anterior;

    //se tiver elementos
    if(cauda != nullptr)
        cauda->proximo = nullptr;
    else //a lista ficou vazia
        cabeca = nullptr;

    delete temp;
    tamanhoPalavra--;
    return valor;
}

bool ehPalindromo()
{
    //palavras vazias ou de apenas um caractere sao palindromos
    if(cabeca == nullptr || tamanhoPalavra <= 1)
        return true;

    //criar ponteiros temporarios para nao ficar alterando os ponteiros principais
    noChar* pInicio = cabeca;
    noChar* pFinal = cauda;

    //a quantidade de comparacoes de cada palavra eh dividir ela por 2, descartando os decimais (se houver)
    int comparacoes = tamanhoPalavra / 2;

    for(int i = 0; i < comparacoes; ++i)
    {
        //se na primeira comparacao ja for diferente
        if(pInicio->letra != pFinal->letra)
            return false; //nao eh um palindromo

        //vai comparando ate o centro
        pInicio = pInicio->proximo;
        pFinal = pFinal->anterior;
    }

    //se saiu do for com tudo verdadeiro, retorna que eh palindromo
    return true;
}

int main(void)
{
    std::string palavra;
    std::cin >> palavra;

    
    for(char c : palavra)
        inserirNoFim(c); 

    if(ehPalindromo())
        std::cout << "E um  palindromo" << std::endl;
    else
        std::cout << "Nao E um  palindromo" << std::endl;


    while (cabeca != nullptr)
        removerNoInicio();

    return 0;
}
