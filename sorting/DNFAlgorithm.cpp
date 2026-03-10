#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// leetecode 75: sort the three colors assigned code 0,1,2 only.
// DNF= Dutch National Flag ALgorithm

void BruteForce(vector<int> &vec)
{
    sort(vec.begin(), vec.end()); // sort function takes O(nlogn)
}
// optimal approach O(n)
void optimal(vector<int> &vec)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    // 1st pass for counting
    for (int i = 0; i < vec.size(); i++)
    { // o(n)
        if (vec[i] == 0)
        {
            count0++;
        }
        else if (vec[i] == 1)
        {
            count1++;
        }
        else
        { // 2
            count2++;
        }
    }
    // 2nd pass for altering array
    int idx = 0;
    for (int i = 0; i < count0; i++)
    { // O(n)
        vec[idx++] = 0;
    }
    for (int i = 0; i < count1; i++)
    { // O(n)
        vec[idx++] = 1;
    }
    for (int i = 0; i < count2; i++)
    { // o(n)
        vec[idx++] = 2;
    }
}
// O(N) but with single pass -> DNF algorithm. three pointers low =0, mid=0, high= n-1;
// 0's in ist partition 0 to low -1, 1's in 2nd partition low to mid -1, 2's in 4th partition high+1 to n-1, 3rd partion mid too high contain unsorted elements which need to be minimized
void DNFalgorithm(vector<int> &vec)
{
    int high = vec.size() - 1;
    int low = 0;
    int mid = 0;
    while (mid <= high)
    {
        if (vec[mid] == 0)
        {
            swap(vec[low], vec[mid]);
            low++;
            mid++;
        }
        else if (vec[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(vec[high], vec[mid]);
            high--;
        }
    }
}
int main()
{
    vector<int> vec = {0, 1, 2, 1, 0, 2, 1, 1, 0};
    // sort(vec.begin(), vec.end());
    // BruteForce(vec);
    DNFalgorithm(vec);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}