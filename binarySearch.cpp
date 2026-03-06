#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// binary search
int binarySearch(vector<int> nums, int target)
{

    int first = 0;
    int end = nums.size() - 1;
    while (first <= end)
    {
        int mid = first + (end - first) / 2; // to avoid overflow

        if (target < nums[mid])
        {
            end = mid - 1;
        }
        else if (target > nums[mid])
        {
            first = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int binarySearchRecursive(vector<int> nums, int target, int first, int end)
{
    if (first <= end)
    {
        int mid = first + (end - first) / 2;
        if (target < nums[mid])
        {
            return binarySearchRecursive(nums, target, first, mid - 1);
        }
        else if (target > nums[mid])
        {
            return binarySearchRecursive(nums, target, mid + 1, end);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {0, 1, 2, 3, 5, 6, 7}; // 0,1,2,3,6,8,9
    // sort(vec.begin(), vec.end());
    cout << binarySearch(vec, 6) << endl;                     // 4
    cout << binarySearchRecursive(vec, 6, 0, vec.size() - 1); // 4
    return 0;
}