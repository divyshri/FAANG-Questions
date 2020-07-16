#include <bits/stdc++.h>
using namespace std;
int ans[100];
void mergeSort(vector<pair<int, int>> &ar, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    vector<pair<int, int>> v1(n1);
    vector<pair<int, int>> v2(n2);
    for (int i = start; i <= mid; i++)
        v1[i - start] = ar[i];
    for (int i = mid + 1; i <= end; i++)
        v2[i - mid - 1] = ar[i];

    int i = 0, j = 0, k = start;
    int count = 0;
    while (i < n1 and j < n2)
    {
        if (v2[j].second < v1[i].second)
        {
            count++;
            ar[k++] = v1[j++];
        }

        else
        {
            ans[v1[i].first] += count;
            ar[k++] = v1[i++];
        }
    }
    while (i < n1)
    {
        ans[v1[i].first] += count;
        ar[k++] = v1[i++];
    }
    while (j < n2)
    {
        ar[k++] = v2[j++];
    }
}

void mergeSort(vector<pair<int, int>> &ar, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(ar, start, mid);
        mergeSort(ar, mid + 1, end);
        mergeSort(ar, start, mid, end);
    }
}

int main()
{
    int n, temp;
    cin >> n;
    vector<pair<int, int>> ar;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ar.push_back({i, temp});
    }
    mergeSort(ar, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}