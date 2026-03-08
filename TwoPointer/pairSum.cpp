#include <iostream>
#include <vector>
using namespace std;
// leetcode problem 1: Two Sum
// Given an sorted array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.
// time complexity: O(n^2) for brute force and O(n) for two pointer approach
vector<int> bruteForce(vector<int> vec, int target)
{
    vector<int> ans;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[i] + vec[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}

vector<int> twoPointerPairSum(vector<int> nums, int target)
{
    vector<int> ans;
    int first = 0;
    int last = nums.size() - 1;
    while (first < last)
    {
        int pairSum = nums[first] + nums[last];
        if (pairSum == target)
        {
            ans.push_back(first);
            ans.push_back(last);
            return ans;
        }
        else if (pairSum < target)
        {
            first++;
        }
        else
        {
            last--;
        }
    }
    return ans;
}

int main()
{
    vector<int> vec = {2, 7, 11, 15};
    // vector<int> result = bruteForce(vec, 9);
    vector<int> result2 = twoPointerPairSum(vec, 17);
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << result[i] << " ";
    // }
    cout << endl;
    for (int i = 0; i < result2.size(); i++)
    {
        cout << result2[i] << " ";
    }
    cout << endl;
}