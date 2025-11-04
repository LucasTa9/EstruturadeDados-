#include <iostream>
using namespace std;

const int MAX = 100;
int grafo[MAX][MAX];
bool visitado[MAX];
bool pilhaDFS[MAX]; 
int pai[MAX];
int n = 10;
int ciclos = 0;


void imprimeCiclo(int v, int u) {
    int caminho[MAX];
    int tam = 0;

   
    int x = v;
    caminho[tam++] = u; 
    while (x != u) {
        caminho[tam++] = x;
        x = pai[x];
    }

   
    for (int i = 1; i < tam / 2 + 1; i++) {
        int temp = caminho[i];
        caminho[i] = caminho[tam - i];
        caminho[tam - i] = temp;
    }

   
    cout << "Ciclo encontrado: ";
    for (int i = 0; i < tam; i++) {
        cout << caminho[i] << " ";
    }
    cout << caminho[0] << endl; 
}



void DFS(int v) {
    visitado[v] = true;
    pilhaDFS[v] = true;

    for (int u = 0; u < n; u++) {
        if (grafo[v][u] == 1) {

            if (!visitado[u]) {
                pai[u] = v;
                DFS(u);
            }
            else if (pilhaDFS[u]) { 
               
                imprimeCiclo(v, u);
                ciclos++;
               
            }
        }
    }

    pilhaDFS[v] = false; 
}

int main() {

    
    for (int i = 0; i < n; i++) {
        visitado[i] = false;
        pilhaDFS[i] = false;
        pai[i] = -1;
        for (int j = 0; j < n; j++)
            grafo[i][j] = 0;
    }

   
    grafo[0][1] = 1; 
    grafo[1][2] = 1;
    grafo[2][3] = 1;
    grafo[3][4] = 1;
    grafo[4][5] = 1;
    grafo[5][0] = 1;
    grafo[1][0] = 1; 
    grafo[5][1] = 1; 
    grafo[3][1] = 1; 
    grafo[4][1] = 1; 

  
   

    cout << "Iniciando DFS no vertice 0:\n\n";
    DFS(0);

    cout << "\nTotal de ciclos encontrados: " << ciclos << endl;

    return 0;
}
