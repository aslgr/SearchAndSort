// Header da biblioteca SearchFunc, capaz de buscar por elementos em
// vetores ordenados por meio de dois distintos algoritmos de busca.

// O retorno das funções de busca é o índice do elemento no vetor,
// ou -1 caso o elemento não exista no vetor.

// O ponteiro numComparacoes armazena o número de comparações
// envolvendo elementos do vetor feito pelo algoritmo.


// A busca sequencial é a busca ingênua...
int buscaSequencial(int *vetor, int tam, int valor, int* numComparacoes);

// A busca binária no vetor é O(lg n)...
int buscaBinaria(int *vetor, int tam, int valor, int* numComparacoes);