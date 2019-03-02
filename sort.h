#ifndef SORT_H
#define SORT_H

/*Todos os algoritmos presente na biblioteca******************/
template<class T> void bubbleSort(T *const &vector, int n);
template<class T> void insertionSort(T *const &vector, int n);
template<class T> void selectionSort(T *const &vector, int n);
template<class T> void mergeSort(T *const &vector, int end);
template<class T> void quickSort(T *const &vector, int end);
template<class T> void heapSort(T *const &vector, int size);
/*************************************************************/


template<class T> void bubbleSort(T *const &vector, int n)
{
 /***************************************
 * complexidade pior caso	O(n^2)
 * complexidade caso médio	O(n^2)
 * complexidade melhor caso	O(n)
 * complexidade de espaços pior caso	O(1) auxiliar
 ************************************************/

    T Taux;
    do{
        for(int i = 0; i < n - 1; i++)
        {
            if(vector[i] > vector[i + 1])
            {
                Taux = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = Taux;
            }
        }
        n--;
    } while (n > 1);
}

template<class T> void insertionSort(T *const &vector, int n)
{
 /******************************
 * complexidade pior caso	O(n^2)
 * complexidade caso médio	O(n^2)
 * complexidade melhor caso	O(n)
 * complexidade de espaços pior caso	O(n) total, O(1) auxiliar
 * **************************************************************/

    T Taux;
    int j;
    for(int i = 1; i < n; i++)
    {
        Taux = vector[i];
        for(j = i; (j > 0 && Taux < vector[j - 1]); j--)
            vector[j] = vector[j - 1];
        vector[j] = Taux;
    }
}

template<class T> void selectionSort(T *const &vector, int n)
{
 /**************************************
 * complexidade pior caso	O(n^2)
 * complexidade caso médio	O(n^2)
 * complexidade melhor caso	O(n^2)
 * complexidade de espaços pior caso O(n) total, O(1) auxiliar
 * ***********************************/

    int minimo;
    T Taux;
    for(int i = 0; i < n; i++)
    {
        minimo = i;
        for(int j = i; j < n; j++)
            if(vector[j] < vector[minimo])
                minimo = j;
        if(minimo != i)
        {
            Taux = vector[i];
            vector[i] = vector[minimo];
            vector[minimo] = Taux;
        }
    }
}

template<class T> void merge(T *const &vector1, T *const &vector2, int size1, int size2)
{
    T *temp = new T[size1 + size2];
    int indexVector1 = 0;
    int indexVector2 = 0;
    for(int i = 0; i < (size1 + size2); i++)
    {
        if(indexVector2 >= size2 || (indexVector1 < size1 && vector1[indexVector1] <= vector2[indexVector2]))
        {
            temp[i] = vector1[indexVector1];
            indexVector1++;
        }
        else
        {
            temp[i] = vector2[indexVector2];
            indexVector2++;
        }
    }
    for(int i = 0; i < (size1 + size2); i++)
    {
        vector1[i] = temp[i];
    }
    delete temp;
}

template<class T> void mergeSort(T *const &vector, int end)
{
    if(end > 0)
    {
        int medium = end/2;
        mergeSort(vector, medium);
        mergeSort(vector + medium + 1, end - (medium + 1));
        merge(vector, vector + medium + 1, medium + 1, (end - (medium + 1)) + 1);
    }
}

namespace sort {
template<class T> void swap(T &value1, T &value2)
{
    T valueAux = value1;
    value1 = value2;
    value2 = valueAux;
}
}

template<class T> T partition(T *const &vector, int end)
{
    int pivo = vector[end];
    int i = -1;
    for(int j = 0; j < end; j++)
    {
        if(vector[j] <= pivo)
        {
            i++;
            sort::swap(vector[i], vector[j]);
        }
    }
    sort::swap(vector[i + 1], vector[end]);
    return i + 1;
}

template<class T> void quickSort(T *const &vector, int end)
{
    if(end > 0)
    {
        int indexPivo = partition(vector, end);
        quickSort(vector, indexPivo - 1);
        quickSort(vector + indexPivo + 1, end - (indexPivo + 1));
    }
}

namespace heap {
inline int parent(int index)
{
    return ((index - 1) / 2);
}
inline int left(int index)
{
    return ((2 * index) + 1);
}
inline int right(int index)
{
    return ((2 * index) + 2);
}
}

template<class T> void maxHeapiFy(T *const &vector, int size, int index)
{
    int sonLeft = heap::left(index);
    int sonRight = heap::right(index);
    int max;
    if(sonLeft < size && vector[sonLeft] > vector[index])
        max = sonLeft;
    else
        max = index;
    if(sonRight < size && vector[sonRight] > vector[max])
        max = sonRight;
    if(max != index)
    {
        sort::swap(vector[index], vector[max]);
        maxHeapiFy(vector, size, max);
    }
}

template<class T> void buildMaxHeap(T *const &vector, int size)
{
    for(int i = size / 2; i >= 0; i--)
        maxHeapiFy(vector, size, i);
}

template<class T> void heapSort(T *const &vector, int size)
{
    buildMaxHeap(vector, size);
    for(int i = size - 1; i > 0; i--)
    {
        sort::swap(vector[0], vector[i]);
        size--;
        maxHeapiFy(vector, size, 0);
    }
}

#endif // SORT_H
