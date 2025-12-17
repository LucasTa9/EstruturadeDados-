#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

void insertionSort(int vetor[], int tamanho){
    int atual, cont;
    for (int i = 1; i < tamanho; i++)
    {
        atual = vetor[i];
        cont = i - 1;
        while (cont >= 0 && vetor[cont] > atual)
        {
            vetor[cont + 1] = vetor[cont];
            cont--;
        }
        vetor[cont + 1] = atual;
    }
}
/*
Merge Sort
Complexidade:
- Melhor caso: O(n log n)
- Médio caso: O(n log n)
- Pior caso: O(n log n)
*/
void merge(int arr[], int l, int m, int r)
{
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
for(int i = 0; i < n1; i++)
L[i] = arr[l + i];
for(int j = 0; j < n2; j++)
R[j] = arr[m + 1 + j];
int i = 0, j = 0, k = l;
while(i < n1 && j < n2)
{
if(L[i] <= R[j])
arr[k++] = L[i++];
else
arr[k++] = R[j++];
}
while(i < n1)
arr[k++] = L[i++];
while(j < n2)
arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r)
{
if(l < r)
{
int m = l + (r - l) / 2;
mergeSort(arr, l, m);
mergeSort(arr, m + 1, r);
merge(arr, l, m, r);
}
}
// Imprime apenas os primeiros 20 elementos
void imprimirPrimeiros(int arr[], int n)
{
for(int i = 0; i < 10; i++)
cout << arr[i] << " ";
cout << endl;
}
int main()
{
const int N = 1000;
int original[N], sel[N], mer[N];
srand(time(NULL));
// Gera números aleatórios entre 1 e 10000
for(int i = 0; i < N; i++)
{
original[i] = rand() % 10000 + 1;
sel[i] = original[i];
mer[i] = original[i];
}
cout << "Array Original (primeiros 20):" << endl;
imprimirPrimeiros(original, N);

auto inicio = high_resolution_clock::now();
insertionSort(sel, N);
auto fim = high_resolution_clock::now();
auto tempoSelection = duration_cast<milliseconds>(fim - inicio);
cout << "\ninsert Sort:" << endl;
cout << "Array Ordenado (primeiros 10):" << endl;
imprimirPrimeiros(sel, N);
cout << "Tempo de execucao: " << tempoSelection.count() << " ms" << endl;

inicio = high_resolution_clock::now();
mergeSort(mer, 0, N - 1);
fim = high_resolution_clock::now();
auto tempoMerge = duration_cast<milliseconds>(fim - inicio);
cout << "\nMerge Sort:" << endl;
cout << "Array Ordenado (primeiros 10):" << endl;
imprimirPrimeiros(mer, N);
cout << "Tempo de execucao: " << tempoMerge.count() << " ms" << endl;



return 0;
}

/*
O insertshort pode ser mais rapido do que o mergeshort ou se igular  quando ele é utilizado com uma baixa quantidade de numeros em um array,
como em exemplos didaticos em faculdades e escolas, mas perde quando o volue de dados é muito grande.
*/