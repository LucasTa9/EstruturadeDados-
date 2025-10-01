#include <iostream>
#include <vector>

// Função que imprime números de 1 a N
void imprimirNumeros(int n) {
    for (int i = 1; i <= n; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Função que calcula o fatorial
int fatorial(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    imprimirNumeros(5);
    std::cout << "Fatorial de 5: " << fatorial(5) << std::endl;
    return 0;
}