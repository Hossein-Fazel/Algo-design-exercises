#include <iostream>
#include <limits.h>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int size1 = mid - start + 2;
    int size2 = end - mid + 1;

    int left[size1], right[size2];
    left[size1 - 1] = INT_MAX;
    right[size2 - 1] = INT_MAX;

    for(int i = 0; i < size1-1; i++)
    {
        left[i] = arr[i];
    }

    for(int i = 0; i < size2 - 1; i++)
    {
        right[i] = arr[mid+1 + i];
    }

    int i = 0, j = 0;
    for(int k = start; k <= end; k++)
    {
        if(left[i] <= right[j] )
        {
            arr[k] = left[i]; i++;
        }
        else
        {
            arr[k] = right[j]; j++;
        }
    }
}

void natural_sort(int arr[], int size)
{
    int edge[size]{-1};

    int j = 0;
    for(int i = 0; i < size; i++)
    {
        if(i+1 != size)
        {
            if(arr[i] > arr[i+1])
            {
                edge[j] = i;
                j++;
            }
        }
    }
    edge[j] = size - 1; j++;

    if(j == 1)
    {
        return;
    }

    for(int i = 0; i < j; i++)
    {
        if(i+2 <= j)
        {
            merge(arr, 0, edge[i], edge[i + 1]);
        }
    }
}

void print(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int size; cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    // merge(arr, 0, 2, 3);
    natural_sort(arr, size);
    print(arr, size);
    return 0;
}