#include <iostream>
using namespace std;
// divide array into sorted and unsorted part -> intially entire arry is unsorted -> i=smallest index -> loop through array to find another smalles indes and update the index -> swap the element -> 0 to n-1 -. inner loop i to n
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smidx = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[smidx])
            {
                smidx = j;
            }
        }
        swap(arr[i], arr[smidx]);
    }
}
int main()
{
    int arr[] = {6, 4, 8, 9, 0};
    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
