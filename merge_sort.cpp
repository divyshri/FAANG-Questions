#include <bits/stdc++.h>
using namespace std;

void merge(int ar[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int ar1[n1];
    int ar2[n2];
    for (int i = 0; i < n1; i++)
        ar1[i] = ar[start + i];
    for (int j = 0; j < n2; j++)
        ar2[j] = ar[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = start;
    while (i < n1 and j < n2)
    {
        if (ar1[i] <= ar2[j])
            ar[k++] = ar1[i++];
        else
            ar[k++] = ar2[j++];
    }
    while (i < n1)
        ar[k++] = ar1[i++];
    while (j < n2)
        ar[k++] = ar2[j++];
}

void mergeSort(int ar[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(ar, start, mid);
        mergeSort(ar, mid + 1, end);
        merge(ar, start, mid, end);
    }
}

int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    mergeSort(ar, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
}