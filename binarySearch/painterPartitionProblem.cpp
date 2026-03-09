#include <iostream>
#include <vector>
using namespace std;
// leetcode Pinter partition problem

bool isValid(vector<int> vec, int painters, int n, int maxTime)
{
    int painterCount = 1;
    int timeSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i] > maxTime)
        {
            return false;
        }
        if (timeSum + vec[i] <= maxTime)
        {
            timeSum += vec[i];
        }
        else
        {
            painterCount++;
            timeSum = vec[i];
        }
    }
    return painterCount > painters ? false : true;
}
int painterPartitionProblem(vector<int> vec, int painters)
{
    int time = INT_MIN;
    int mintime = 0;
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
        time = max(time, vec[i]);
    }
    int start = time;
    int end = sum;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(vec, painters, vec.size(), mid))
        {
            mintime = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return mintime;
}

int main()
{
    vector<int> vec = {10, 20, 30, 40};
    int painters = 3;
    cout << painterPartitionProblem(vec, painters);
}
