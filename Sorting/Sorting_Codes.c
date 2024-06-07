#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int mn = i;
        for (int j = i + 1; j < n; j++)
        {
            mn = arr[mn] > arr[j] ? j : mn;
        }
        swap(&arr[i], &arr[mn]);
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void merge(int arr[], int first, int mid, int last)
{
    int n1 = mid - first + 1;
    int n2 = last - mid;
    int arr1[n1];
    int arr2[n2];
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[first + i];
    }
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0;
    int k = first;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

int partition(int arr[], int first, int last)
{
    int pivot = arr[last];
    int i = first - 1;
    for (int j = first; j < last; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[last]);
    return (i + 1);
}

void quickSort(int arr[], int first, int last)
{
    if (first < last)
    {

        int pi = partition(arr, first, last);

        quickSort(arr, first, pi - 1);
        quickSort(arr, pi + 1, last);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (i != largest)
    {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {12, 1, 1, 4, 26, 76, 843, 23, 46, 11};
    heapSort(arr, 10);
    printArray(arr, 10);

    return 0;
}