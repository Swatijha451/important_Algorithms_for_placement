#include <iostream>
#include <vector>
using namespace std;
// we are given two sorted array. vec1=m+n size and vec2 =n size, merge the two arrays and sort them. without using extra space merge and sort two sorted array

void mergeTwoSortedArray(vector<int> &vec1, int m, vector<int> &vec2, int n) // O(1) space
{

    int i = m - 1;       // idx used for larger array
    int j = n - 1;       // idex used for smaller array
    int idx = m + n - 1; // index used for larger array backward for sorting

    while (j >= 0 && i >= 0) // O(n)//)(n+m)
    {
        if (vec2[j] >= vec1[i])
        {
            vec1[idx] = vec2[j];
            idx--;
            j--;
        }
        else
        {
            vec1[idx] = vec1[i];
            idx--;
            i--;
        }
    }
    while (j >= 0) //)(n)
    {
        vec1[idx] = vec2[j];
        idx--;
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
    vector<int> vec1 = {4, 5, 6, 0, 0, 0, 0};
    vector<int> vec2 = {1, 2, 3, 4};
    // bruteForce(vec1, vec2);
    mergeTwoSortedArray(vec1, 3, vec2, 4);
    printArray(vec1);
}