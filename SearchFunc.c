#include <stdio.h>

#include "SearchFunc.h"

/**********************************************************************/
/************************* busca sequencial **************************/

int buscaSequencial(int *vetor, int tam, int valor, int *numComparacoes)
{
	if (tam < 1)
		return -1;
	
	if (valor >= vetor[tam-1]){
	    (*numComparacoes)++;
		return tam-1;
	}	
	
    (*numComparacoes)++;
	return buscaSequencial(vetor, tam-1, valor, numComparacoes);
}

/**********************************************************************/
/*************************** busca binária ***************************/

int buscaBinariaAux(int *vetor, int inicio, int fim, int valor, int *numComparacoes)
{    
    if (inicio > fim)
        return -1;
    
    int meio = (inicio+fim)/2;
    
    if (valor == vetor[meio]){
        (*numComparacoes)++;
        return meio;
    }
    
    (*numComparacoes)++;

    if (valor < vetor[meio]){
        (*numComparacoes)++;
        return buscaBinariaAux(vetor, inicio, meio-1, valor, numComparacoes);
    }
    
    (*numComparacoes)++;

    return buscaBinariaAux(vetor, meio+1, fim, valor, numComparacoes);
}


int buscaBinaria(int *vetor, int tam, int valor, int *numComparacoes)
{    
    int inicio = 0;
    int fim = tam-1;
    (*numComparacoes) = 0;
    
    return buscaBinariaAux(vetor, inicio, fim, valor, numComparacoes);
}

/**********************************************************************/
