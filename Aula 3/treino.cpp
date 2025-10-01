#include <iostream>
using namespace std;

int n [3] = {4, 5, 6};

void pesquisafor(int p){
    for (int i = 0; i < 3; i++)
    {
        if(p == n[i]){
          cout << "valor encontrado";
          break;} else(p != n[i]);{
            cout << "Valor nao encontrado";
            break;}
            
          
        
    }
    

}



int main(void){
    int p;
    cout << "Entre o valor que deseja pesquisar ;3" << endl;
    cin >> p;
    pesquisafor(p);

   
}