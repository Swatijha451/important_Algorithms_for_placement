#include <iostream>
#include <vector>
using namespace std;
// leetcode problem 852: peak index in a mountain array
int bruteFOrceApproach(vector<int> vec)
{
    for (int i = 1; i <= vec.size() - 2; i++)
    {
        if (vec[i] > vec[i - 1] && vec[i] > vec[i + 1])
        {
            return i;
        }
    }
    return -1;
}
int peakOfTheMountain(vector<int> vec)
{
    int start = 1;
    int end = vec.size() - 2;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (vec[mid] > vec[mid - 1] && vec[mid] > vec[mid + 1])
        {
            return mid;
        }
        else if (vec[mid] < vec[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 3, 1};
    // cout << bruteFOrceApproach(vec) << endl;
    cout << peakOfTheMountain(vec) << endl;
    return 0;
}