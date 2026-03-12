/*
next permutation -> lexicographically next larger element -> eg. 12345 nextPermutation-> 12354->12453->12534->12543
1. find pivot
2.find rightmost element greater than pivot and swap it pivot
reverse the  decreasing order elements from pivot+1 to n-1 to increasing order elements
without using extra scpace that is change the original array of elemnts
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &vec)
{
    // step -> find pivot -> in baclwards loop element graeter that a[i]
    int pivot = -1;
    int n = vec.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (vec[i] < vec[i + 1])
        { // 5 is pivot
            pivot = i;
            break;
        }
    }
    // in casea pivot does not exist like 5 4 3 2 1 revese the array and return.
    if (pivot == -1)
    {
        reverse(vec.begin(), vec.end());
    }
    // step 2-> elemnt just greater than pivot in the right of array and swap it with pivot
    for (int i = n - 1; i >= pivot; i--)
    {
        if (vec[i] > vec[pivot])
        {
            swap(vec[pivot], vec[i]);
            break;
        }
    }
    // step 3-> reverse the array from pivot+1 to n-1 to find nexrt permutation;
    int i = pivot + 1;
    int j = n - 1;
    while (j >= i)
    {
        swap(vec[i], vec[j]);
        i++;
        j--;
    }
}
void printArray(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec = {1, 2, 3, 5, 4};
    nextPermutation(vec);

    printArray(vec);
}