// maximum subarray sum is subarry with maximum sum.
#include <iostream>
#include <vector>
using namespace std;
// O(n^3) time complexity and O(1) space complexity
int bruteForce(vector<int> vec)
{
    int maxSum = INT_MIN; // negative infinity
    for (int start = 0; start < vec.size(); start++)
    {
        for (int end = start; end < vec.size(); end++)
        {
            int sum = 0;
            for (int k = start; k <= end; k++)
            {
                sum += vec[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
// O(n^2) time complexity and O(1) space complexity
int betterBruteForce(vector<int> vec)
{
    int maxSum = INT_MIN; // negative infinity
    for (int start = 0; start < vec.size(); start++)
    {
        int sum = 0;
        for (int end = start; end < vec.size(); end++)
        {
            sum += vec[end];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
// O(n) time complexity and O(1) space complexity
int kadenesAlgorithm(vector<int> vec)
{
    int maxSum = INT_MIN; // negative infinity
    int currentSum = 0;
    for (int val : vec)
    {
        currentSum += val; // 0+(-2)=-2, currsum=0,maxsum=0

        maxSum = max(maxSum, currentSum);
        // for the edge case when all the elements are negative, we need to update maxSum before resetting currentSum to 0.
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << bruteForce(vec) << endl;
    cout << betterBruteForce(vec) << endl;
    cout << kadenesAlgorithm(vec) << endl;
}