#include <iostream>
using namespace std;

// palindrome-> racecare, madam etc
bool palindrome(string &str) // O(n)
{
    int i = 0;
    int j = str.length() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    string str = "racecar";
    string str1 = "swati";
    cout << palindrome(str);
}