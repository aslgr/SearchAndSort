#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "SortFunc.h"
#include "SearchFunc.h"

#define TAM 10					// Tamanho do vetor criado aleatoriamente.
#define VALOR_BUSCA_SEQ 22			// Valores a serem buscados no vetor através
#define VALOR_BUSCA_BIN 35			// da busca sequencial e binária, respectivamente.

/************************* funções auxiliares *************************/

// Cria e imprime um vetor desordenado aleatoriamente...
void criaVetor(int *vetor, int tam)
{
	srand(time(NULL));
	printf("Vetor desordenado:\n");
	int i;
	for (i = 0; i < tam; i++)
   		vetor[i] = (rand() % 100);

	for (i = 0; i < tam; i++)
    	printf("%d ", vetor[i]);
	printf("\n");
}

// Imprime um vetor que já passou por algum algoritmo de ordenação.
// Indica se iremos realizar uma busca nesse vetor ou se apenas iremos
// analisar o número de comparações feitas pelo algoritmo de ordenação.
void imprimeVetorOrdenado(int *vetor, int tam, int busca, int numComp)
{	
	if (busca == 1)
		printf("Vetor a se fazer a busca:\n");

	for (int i = 0; i < tam; i++)
		printf("%d ", vetor[i]);
	printf("\n");

	if (busca != 1){
		printf("\nNúmero de comparações: %d\n", numComp);
	}
}

/**********************************************************************/

int main()
{
	const unsigned int tam = TAM;    /* tamanho máximo: 1.048.576 = 2^20 */
	int idxBusca;
	int numComp;

	int *vetor;
	if ((vetor = (int*) malloc (tam * sizeof(int))) == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	clock_t start, end;
	double total;

	// -------------------------------------------------------
	/************************************
	-> Vetor ordenado por insertion sort.
	************************************/

	printf("\nInsertion Sort --------------------\n");
	criaVetor(vetor, tam);

	start = clock();
	numComp = insertionSort(vetor, tam);
	end = clock();

	total = ((double)(end - start))/CLOCKS_PER_SEC;

	printf("\nVetor ordenado por insertion sort: \n");
	imprimeVetorOrdenado(vetor, tam, 0, numComp);
	printf("Tempo total: %f\n", total);
	printf("-----------------------------------\n");
	
	// -------------------------------------------------------
	/************************************
	-> Vetor ordenado por selection sort.
	************************************/

	printf("\nSelection Sort ------------------\n");
	criaVetor(vetor, tam);

	start = clock();
	numComp = selectionSort(vetor, tam);
	end = clock();

	total = ((double)end - start)/CLOCKS_PER_SEC;

	printf("\nVetor ordenado por selection sort:\n");
	imprimeVetorOrdenado(vetor, tam, 0, numComp);
	printf("Tempo total: %f\n", total);
	printf("-----------------------------------\n");

	// -------------------------------------------------------
	/********************************
	-> Vetor ordenado por merge sort.
	********************************/

	printf("\nMerge Sort ------------------------\n");
	criaVetor(vetor, tam);

	start = clock();
	numComp = mergeSort(vetor, tam);
	end = clock();

	total = ((double)end - start)/CLOCKS_PER_SEC;

	printf("\nVetor ordenado por merge sort:\n");
	imprimeVetorOrdenado(vetor, tam, 0, numComp);
	printf("Tempo total: %f\n", total);
	printf("-----------------------------------\n");

	// -------------------------------------------------------
	/********************************
	-> Vetor ordenado por quick sort.
	********************************/

	printf("\nQuick Sort ------------------------\n");
	criaVetor(vetor, tam);

	start = clock();
	numComp = quickSort(vetor, tam);
	end = clock();

	total = ((double)end - start)/CLOCKS_PER_SEC;

	printf("\nVetor ordenado por quick sort:\n");
	imprimeVetorOrdenado(vetor, tam, 0, numComp);
	printf("Tempo total: %f\n", total);
	printf("-----------------------------------\n");

	// -------------------------------------------------------
	/********************************
	-> Busca sequencial.
	********************************/

	int valor_busca_seq = VALOR_BUSCA_SEQ;
	printf("\nBusca sequencial (do valor %d)\n", valor_busca_seq);
	imprimeVetorOrdenado(vetor, tam, 1, numComp);
	idxBusca = buscaSequencial(vetor, tam, valor_busca_seq, &numComp);
	printf("Índice do valor: %d | Número de comparações: %d\n", idxBusca, numComp);


	/********************************
	-> Busca binária.
	********************************/

	int valor_busca_bin = VALOR_BUSCA_BIN;
	printf("\nBusca binária (do valor %d)\n", valor_busca_bin);
	imprimeVetorOrdenado(vetor, tam, 1, numComp);
	idxBusca = buscaBinaria(vetor, tam, valor_busca_bin, &numComp);
	printf("Índice do valor: %d | Número de comparações: %d", idxBusca, numComp);
	printf("\n\n");

	// -------------------------------------------------------

	free(vetor);
	return 0;
}
