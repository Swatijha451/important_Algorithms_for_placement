#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// leetcode problem 169: Majority Element
// Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// time complexity: O(n^2) for brute force, O(n log n) for sorting and O(n) for moore voting algorithm
int bruteForce(vector<int> vec)
{
    for (int val : vec)
    {
        int freq = 0;
        for (int ele : vec)
        {
            if (ele == val)
            {
                freq++;
            }
        }
        if (freq > vec.size() / 2)
        {
            return val;
        }
    }
    return -1;
}
int optimal(vector<int> &vec)
{
    // sort the given vector;
    sort(vec.begin(), vec.end());
    int freq = 1;
    int ans = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] == vec[i - 1])
        {
            freq++;
        }
        else
        {
            // reset the frequency count for the new element
            freq = 1;
            ans = vec[i];
        }
        if (freq > vec.size() / 2)
        {
            return ans;
        }
    }
    return ans;
}
// applicable when majority elemnet always exists in the array
int mooreVoting(vector<int> &vec)
{
    int freq = 0;
    int ans;
    for (int i = 0; i < vec.size(); i++)
    {
        if (freq == 0)
        {
            ans = vec[i];
        }
        if (vec[i] == ans)
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}
// in case majority element may not exist in the array, we can do a second pass to verify the candidate
int mooreVotingWithVerification(vector<int> &vec)
{
    int freq = 0;
    int ans = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (freq == 0)
        {
            ans = vec[i];
        }
        if (vec[i] == ans)
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    // second pass to verify the candidate
    freq = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == ans)
        {
            freq++;
        }
    }
    if (freq > vec.size() / 2)
    {
        return ans;
    }
    return -1; // no majority element found
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 4, 4, 4};
    int result = mooreVoting(vec); // ans 4
    // int result = mooreVotingWithVerification(vec); // ans -1, no majority element
    cout << result << endl;
}