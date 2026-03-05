#include <iostream>
#include <vector>
using namespace std;
// leetcode problem 50: Pow(x, n)
// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
// constraints: -100.0 < x < 100.0,-->number can be negative, n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]=>it will work in log(n) time complexity

double binaryExponentiation(double x, int n)
{
    if (n == 0 || x == 1)
    {
        return 1.0;
    }
    if (n = 1)
    {
        return x;
    }
    if (x == 0)
    {
        return 0.0;
    }
    if (x == -1)
    {
        if (n % 2 == 0)
        {
            return 1.0;
        }
        else
        {
            return -1.0;
        }
    }
    double ans = 1.0;
    long binForm = n;
    // IF POWER IS NEGATIVE THEN CONVERT IT TO POSITIVE AND TAKE RECIPROCAL OF THE BASE
    if (n < 0)
    {
        x = 1 / x;
        binForm = -binForm; //-5-->5
    }

    while (binForm > 0)
    {
        if (binForm % 2 == 1)
        {
            ans = ans * x;
        }
        x = x * x;
        binForm = binForm / 2;
    }
    return ans;
}
int main()
{
    double x = 2.00000;
    int n = 10;
    double result = binaryExponentiation(x, n);
    cout << result << endl;
}
