#include <iostream>

#define MAX 10

using namespace std;

// -- ESTRUTURAS DO GRAFO --
int matrizAdj[MAX][MAX];
bool visitado[MAX];
int totalVertices;

// -- ESTRUTURA DA FILA (Manual) --
int fila[MAX];
int inicioFila = 0;
int fimFila = -1;

// Funções auxiliares de Fila
void entrarFila(int valor) {
    if (fimFila < MAX - 1) {
        fimFila++;
        fila[fimFila] = valor;
    }
}

int sairFila() {
    int valor = -1;
    if (inicioFila <= fimFila) {
        valor = fila[inicioFila];
        inicioFila++;
    }
    return valor; // Retorna o valor removido
}

bool filaEstaVazia() {
    return inicioFila > fimFila;
}

void criarAresta(int u, int v) {
    matrizAdj[u][v] = 1;
    matrizAdj[v][u] = 1;
}

// Algoritmo BFS
void buscaLargura(int origem, int destino) {
    // Visita o primeiro e põe na fila
    visitado[origem] = true;
    entrarFila(origem);

    while (!filaEstaVazia()) {
        int u = sairFila();
        cout << u << "->";

        // Verifica vizinhos do nó 'u'
        for (int v = 0; v < totalVertices; v++) {
            if (matrizAdj[u][v] == 1 && visitado[v] == false) {
                visitado[v] = true; // Marca imediatamente ao colocar na fila
                entrarFila(v);
            }
        }
    }
}

int main() {
    totalVertices = 6;
    
     int origem;
     int destino;

    cin >> destino;
    cin >> origem;

    inicioFila = 0; fimFila = -1;
    for(int i=0; i<MAX; i++) {
        visitado[i] = false;
        for(int j=0; j<MAX; j++) matrizAdj[i][j] = 0;
    }

    // Grafo
    criarAresta(0, 1);
    criarAresta(0, 2);
    criarAresta(1, 3);
    criarAresta(1, 4);
    criarAresta(2, 5);
    criarAresta(5, 1);

    cout << "BFS a partir do no 0: ";
    buscaLargura(origem, destino);
    cout << endl;

    return 0;
}

  // Reposta da pergunta: por BFS garante o menor caminho 
  //por que explora o grafo por camadas de disancia, o dps nao garante por que explora por profundiade(percorre todo o array)
  //assim ele pode achar caminhos longos antes dos curtos.