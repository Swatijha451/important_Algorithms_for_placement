#include <iostream>
#include <vector>
using namespace std;
// product of array except itself
vector<int> bruteForce(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int product = 1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j)
            {
                product *= nums[j];
            }
        }
        ans.push_back(product);
    }
    return ans;
}
vector<int> prefixSuffixApproach(vector<int> &nums)
{
    vector<int> prefix(nums.size(), 1);
    vector<int> suffix(nums.size(), 1);
    vector<int> ans(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++)
    {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        ans[i] = prefix[i] * suffix[i];
    }
    return ans;
}
vector<int> spaceOptimalApproach(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }
    int suffix = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suffix = suffix * nums[i + 1];
        ans[i] = ans[i] * suffix;
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    // vector<int> result = bruteForce(nums);
    // vector<int> result = prefixSuffixApproach(nums);
    vector<int> result = spaceOptimalApproach(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}