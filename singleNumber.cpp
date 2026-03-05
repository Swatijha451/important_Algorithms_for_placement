#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int> vec)
{
    int ans = 0;
    for (int val : vec)
    {
        ans = ans ^ val; // XOR operator
        // xor operator returns 0 if both bits are the same and 1 if both bits are different.
    }
    return ans;
}
int main()
{
    vector<int> nums = {2, 2, 3, 3, 4, 4, 1};
    // 0^2=2, 2^2=0, 0^3=3, 3^3=0, 0^4=4, 4^4=0, 0^1=1
    cout << singleNumber(nums) << endl;
}