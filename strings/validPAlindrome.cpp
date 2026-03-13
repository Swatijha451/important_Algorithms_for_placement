// leetcode problem
// contains alphanumeric string with special character. while checking special character needs to be ignored// create function to check wherther character is alpjanumeric or not and if not ignore
//  check aplindrome

#include <iostream>
#include <cstring>
using namespace std;

bool isAlphanumeric(char ch)
{
    if (!(tolower(ch) >= 'a' && tolower(ch) <= 'z' || ch >= 0 && ch <= 9))
    {
        return false;
    }
    return true;
}
bool validPalindrome(string &str)
{

    int i = 0;
    int j = str.length() - 1;
    while (i < j)
    {
        if (!(isAlphanumeric(str[i])))
        {
            i++;
            continue;
        }
        if (!(isAlphanumeric(str[j])))
        {
            j++;
            continue;
        }
        if (tolower(str[i]) != tolower(str[j]))
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
    string str;
    getline(cin, str);
    cout << validPalindrome(str);
}