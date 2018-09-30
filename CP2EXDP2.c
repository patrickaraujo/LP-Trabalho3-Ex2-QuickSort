#include <stdio.h>
#include <stdlib.h>

/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Exercício de Programação 3 do capítulo 2 do livro Conceitos de Linguagens de Programação - Nona Edição de Robert Sebesta
*   QuickSort Recursivo e Iterativo
*   QuickSort Recursive and Iterative 
*/

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int l, int h){
    int j, x = arr[h];
    int i = (l - 1);

    for (j = l; j <= h- 1; j++){
        if (arr[j] <= x){
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quickSortR(int A[], int l, int h){ //  Recursivo
    if (l < h){
        /* Partitioning index */
        int p = partition(A, l, h);
        quickSortR(A, l, p - 1);
        quickSortR(A, p + 1, h);
    }
}

void quickSortIterative (int arr[], int l, int h){
    // Create an auxiliary stack
    int stack[ h - l + 1 ];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;

    // Keep popping from stack while is not empty
    while ( top >= 0 ){
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition( arr, l, h );

        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > l ){
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < h ){
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}

int main(){
    int i, j, n = 5;
    int arr[n];
    for(j = 0; j < n; j++){
        printf("\nEntre com o valor %i do array de %i posicoes:\t", j+1, n);
        scanf("%i", &arr[j]);
    }
    quickSortIterative(arr, 0, n-1);

    for(i = 0; i < n; i++)
        printf("%i ", arr[i]);
    return 0;
}
