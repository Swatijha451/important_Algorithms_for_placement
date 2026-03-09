#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// leetcode 875: aggressive cows problem
// we are given an array of stalls which represents the position of stalls and we are given a number of cows. we are the stalls to cows in such a way that there is maximum distance possible betweeb two cows and retirn that distance.
bool isVAlid(vector<int> vec, int cows, int n, int maxPossibleDist) // O(n)
{
    int cowCount = 1;
    int lastStallPos = vec[0];

    for (int i = 1; i < n; i++)
    {
        if (vec[i] - lastStallPos >= maxPossibleDist)
        {

            cowCount++;
            lastStallPos = vec[i];
        }
        if (cowCount == cows)
        {
            return true;
        }
    }
    return false;
}
int aggressiveCowsProble(vector<int> vec, int cows) // O(nlog(range))
{
    int ans = -1;
    sort(vec.begin(), vec.end());
    int start = vec[0];
    int end = vec[vec.size() - 1] - vec[0]; //
    while (start <= end)                    // O(log(range))
    {
        int mid = start + (end - start) / 2;
        if (isVAlid(vec, cows, vec.size(), mid)) // O(n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> vec = {2, 8, 6, 9, 0};
    cout << aggressiveCowsProble(vec, 3);
}
