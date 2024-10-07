#include <stdio.h>

#include "SortFunc.h"
#include "SearchFunc.h"

/**********************************************************************/
/**************** função troca: comum aos algoritmos *****************/

void troca(int *vetor, int pos1, int pos2)
{
	int temp = vetor[pos1];
	vetor[pos1] = vetor[pos2];
	vetor[pos2] = temp;
}

/**********************************************************************/
/************************** insertion sort ***************************/

int insere(int *vetor, int tam, int *numComp)
{	
	int indexToPlace = buscaSequencial(vetor, tam-1, vetor[tam-1], numComp);
	int indexCur = tam-1;

	while (indexCur > indexToPlace+1){
		troca(vetor, indexCur, indexCur-1);
		indexCur--;
	}

	return *numComp;
}

void insertionSortAux(int *vetor, int tam, int *numComp)
{	
	if ((tam-1) <= 0)
		return;
	
	insertionSortAux(vetor, tam-1, numComp);
	
	insere(vetor, tam, numComp);

	return;
}

int insertionSort(int *vetor, int tam)
{
	int numComp = 0;
	
	insertionSortAux(vetor, tam, &numComp);
	
	return numComp;
}

/**********************************************************************/
/************************** selection sort ***************************/

int minimo(int *vetor, int inicio, int fim, int *numComp)
{
    if (inicio == fim)
        return inicio;
        
    int min = minimo(vetor, inicio, fim-1, numComp);
    
    if(vetor[fim] < vetor[min]){
        min = fim;
	}
    	
	(*numComp)++;

    return min;
}

void selectionSortAux(int *vetor, int inicio, int fim, int *numComp)
{   
    if (inicio >= fim)
        return;
    
    troca(vetor, inicio, minimo(vetor, inicio, fim, numComp));
    
    selectionSortAux(vetor, inicio+1, fim, numComp);

	return;
}

int selectionSort(int *vetor, int tam)
{    
    int inicio = 0;
    int fim = tam-1;
    int numComp = 0;
    
    selectionSortAux(vetor, inicio, fim, &numComp);

	return numComp;
}

/**********************************************************************/
/**************************** merge sort *****************************/

int intercala(int *vetor, int inicio, int meio, int fim, int *numComp)
{
	if (inicio >= fim)
		return *numComp;

	int vetAux[fim-inicio+1];
	int i = inicio;
	int j = meio+1;

	for (int k = 0; k <= fim-inicio; k++)
	{
		if ((j > fim) || (i <= meio && vetor[i] <= vetor[j])){
			(*numComp)++;
			vetAux[k] = vetor[i];
			i++;
		} else {
			(*numComp)++;
			vetAux[k] = vetor[j];
			j++;
		}
	}

	for (i = inicio, j = 0; i <= fim; i++, j++)
		vetor[i] = vetAux[j];

	return *numComp;
}

int mergeSortAux(int *vetor, int inicio, int fim, int *numComp)
{
	if (inicio >= fim)
		return *numComp;
	
	int meio = (inicio+fim)/2;

	mergeSortAux(vetor, inicio, meio, numComp);
	mergeSortAux(vetor, meio+1, fim, numComp);
	return intercala(vetor, inicio, meio, fim, numComp);
}

int mergeSort(int *vetor, int tam)
{
    int inicio = 0;
    int fim = tam-1;
    int numComp = 0;
	
	mergeSortAux(vetor, inicio, fim, &numComp);

	return numComp;
}

/**********************************************************************/
/**************************** quick sort *****************************/

int particiona(int *vetor, int inicio, int fim, int pivo, int *numComp)
{
    int aux = inicio-1;

    for (int i = inicio; i <= fim; i++)
	{
        if (vetor[i] <= pivo){
            aux++;
            troca(vetor, aux, i);
        }

		(*numComp)++;
    }

    return aux;
}

int quickSortAux(int *vetor, int inicio, int fim, int *numComp)
{
    if (inicio >= fim)
        return *numComp;
    
    int engessado = (particiona(vetor, inicio, fim, vetor[fim], numComp));

    quickSortAux(vetor, inicio, engessado-1, numComp);
    quickSortAux(vetor, engessado+1, fim, numComp);

	return *numComp;
}

int quickSort(int *vetor, int tam)
{   
    int inicio = 0;
    int fim = tam-1;
    int numComp = 0;
    
    return quickSortAux(vetor, inicio, fim, &numComp);
}

/**********************************************************************/
