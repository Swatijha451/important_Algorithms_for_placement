#include <iostream>
#include <vector>
using namespace std;

int bruteForce(vector<int> vec)
{
    int maxArea = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            int w = j - i;
            int ht = min(vec[i], vec[j]);
            maxArea = max(maxArea, w * ht);
        }
    }
    return maxArea;
}
// time complexity: O(n) space complexity: O(1)
int twoPointer(vector<int> vec)
{
    int maxArea = 0;
    int lp = 0;
    int rp = vec.size() - 1;
    while (lp < rp)
    {
        int width = rp - lp;
        int ht = min(vec[lp], vec[rp]);
        maxArea = max(maxArea, width * ht);
        vec[lp] < vec[rp] ? lp++ : rp--;
    }
    return maxArea;
}
int main()
{
    vector<int> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << bruteForce(vec) << endl;
    cout << twoPointer(vec) << endl;
}