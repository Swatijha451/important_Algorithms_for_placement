#include <iostream>
using namespace std;
// arr[0]= sorted array and i=1 to i=n is unsorted, initially. prev=0, curr =1
void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int currElement = arr[i];
        int prev = i - 1;
        currElement = arr[i];
        while (prev >= 0 && arr[prev] > currElement)
        {
            arr[prev + 1] = arr[prev]; // 6 6 8 9 0
            prev--;                    //-1
        }
        arr[prev + 1] = currElement; // prev=1, 4 6 8 9 0
    }
}
int main()
{
    int arr[] = {6, 4, 8, 9, 0};
    insertionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}