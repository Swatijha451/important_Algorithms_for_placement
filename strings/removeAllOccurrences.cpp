#include <iostream>
using namespace std;

// leetcode problem-> remove all ocurrences of a substring from the given string, make changes in the original string;
// two stl++ fuctions like string.finf(substring) that returns first index of substring in thr string
//  and string.erase(index, lenghtofstring) deletres that substring from the given string;
void removeAllOccurrences(string &str, string part)
{
    while (str.length() > 0 && str.find(part) < str.length())
    {
        str.erase(str.find(part), part.length());
    }
}
int main()
{
    string str = "abcdgjgabdabc abcghdsg";
    string part = "abc";
    removeAllOccurrences(str, part);
    cout << str;
}