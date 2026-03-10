#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// bubble sort -> i=0 to n-1 then i=0, n-i-1 swaps so inner loop-> j=0 to n-i-1 and comapare adjacent elements j nad j+1
void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag)
        {
            return;
        }
    }
}
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {6, 4, 8, 9, 0};
    bubbleSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}