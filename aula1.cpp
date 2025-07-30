#include<iostream>
#include<vector>
using namespace std;

float CadastroNota(float nota[]);

int main () {
     int opcao = 0;
     float notas[10];

    do {

        cout << "===MENU===";
        cout << "1.Cadasto Notas";
        cout << "2.Exibir Notas";
        cout << "3.Calcular Média";
        cout << "4.Mostrar Maior ou Menos Nota";
        cout << "5.Sair";
        switch (opcao)
        {
            case 1:
                CadastroNota(notas);
            break;
            case 2:

            break;
        }
    
    } while(opcao != 5);

    return 0;
}

float CadastroNota(float nota[]) {
    for (size_t i = 0; i < 10; i++){
        cin >> nota[i];
    }
}