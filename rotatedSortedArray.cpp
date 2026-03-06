#include <iostream>
#include <vector>
using namespace std;

int rotatedSortedArray(vector<int> vec, int target)
{
    int start = 0;
    int end = vec.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target == vec[mid])
        {
            return mid;
        }
        if (vec[start] <= vec[mid])
        { // left part is sorted
            if (vec[start] <= target && target <= vec[mid])
            {
                end = mid - 1; // serch in sorted part
            }
            else
            {
                start = mid + 1;
            } // serch in unsorted part
        }
        else
        { // right part is sorted
            if (vec[mid] <= target && target <= vec[end])
            {
                start = mid + 1; // serch in sorted part
            }
            else
            {
                end = mid - 1; // search in unsorted part
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> vec = {4, 5, 6, 7, 0, 1, 2};    // left part is sorted
    cout << rotatedSortedArray(vec, 0) << endl; // 4
    return 0;
}