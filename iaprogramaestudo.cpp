#include <iostream>
#include <string>
#include <queue>
#include <algorithm> // Para a função std::max

// Estrutura para um nó da árvore AVL
struct No {
    char dado;
    No* esq;
    No* dir;
    int altura;

    No(char valor) {
        dado = valor;
        esq = nullptr;
        dir = nullptr;
        altura = 1;
    }
};

// --- Funções Auxiliares para AVL ---
int altura(No* no) {
    if (no == nullptr)
        return 0;
    return no->altura;
}

int fatorBalanceamento(No* no) {
    if (no == nullptr)
        return 0;
    return altura(no->esq) - altura(no->dir);
}

No* rotacionaDireita(No* y) {
    No* x = y->esq;
    No* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = std::max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = std::max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

No* rotacionaEsquerda(No* x) {
    No* y = x->dir;
    No* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = std::max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = std::max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

// --- Função de Inserção na Árvore AVL ---
No* insere(No* no, char dado) {
    if (no == nullptr)
        return new No(dado);

    if (dado < no->dado)
        no->esq = insere(no->esq, dado);
    else if (dado > no->dado)
        no->dir = insere(no->dir, dado);
    else // Dados iguais não são permitidos em uma ABB
        return no;

    no->altura = 1 + std::max(altura(no->esq), altura(no->dir));
    int balanco = fatorBalanceamento(no);

    // Rotação à direita (Caso LL)
    if (balanco > 1 && dado < no->esq->dado)
        return rotacionaDireita(no);

    // Rotação à esquerda (Caso RR)
    if (balanco < -1 && dado > no->dir->dado)
        return rotacionaEsquerda(no);

    // Rotação dupla esquerda-direita (Caso LR)
    if (balanco > 1 && dado > no->esq->dado) {
        no->esq = rotacionaEsquerda(no->esq);
        return rotacionaDireita(no);
    }

    // Rotação dupla direita-esquerda (Caso RL)
    if (balanco < -1 && dado < no->dir->dado) {
        no->dir = rotacionaDireita(no->dir);
        return rotacionaEsquerda(no);
    }

    return no;
}

// --- Percurso em Largura (BFS) ---
void percursoLargura(No* raiz) {
    if (raiz == nullptr)
        return;

    std::queue<No*> q;
    q.push(raiz);

    while (!q.empty()) {
        No* noAtual = q.front();
        q.pop();

        std::cout << noAtual->dado << " ";

        if (noAtual->esq != nullptr)
            q.push(noAtual->esq);
        if (noAtual->dir != nullptr)
            q.push(noAtual->dir);
    }
    std::cout << std::endl;
}

// --- Função Principal ---
int main() {
    // 1. Inicialize a árvore com as letras do seu primeiro nome.
    // Substitua "SEUNOME" pelo seu primeiro nome.
    std::string meuNome = "LUCAS";
    No* raiz = nullptr;
    std::string letrasUnicas;
    bool letrasExistentes[256] = {false};

    for (char c : meuNome) {
        char letra = toupper(c);
        if (!letrasExistentes[letra]) {
            raiz = insere(raiz, letra);
            letrasExistentes[letra] = true;
        }
    }

    std::cout << "Arvore inicial com as letras do nome (percurso em largura):" << std::endl;
    percursoLargura(raiz);
    std::cout << "---" << std::endl;

    // 2. Receba uma palavra do usuário.
    std::string palavra;
    std::cout << "Digite uma palavra para inserir na arvore: ";
    std::cin >> palavra;

    // 3. Insira as letras não repetidas da palavra na arvore.
    for (char c : palavra) {
        char letra = toupper(c);
        if (!letrasExistentes[letra]) {
            raiz = insere(raiz, letra);
            letrasExistentes[letra] = true;
        }
    }

    // 4. Exiba a árvore resultante em percurso em largura.
    std::cout << "\nArvore resultante (percurso em largura):" << std::endl;
    percursoLargura(raiz);

    return 0;
}