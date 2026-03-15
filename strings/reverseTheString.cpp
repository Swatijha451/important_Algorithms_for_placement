//"the sky is blue" output->"blue is sky the"
// reverse the wstrings
#include <iostream>
#include <algorithm>

using namespace std;

string reverseTheString(string &s) // O(N)
{
    reverse(s.begin(), s.end()); // original string reversed and word in their correct position
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    { // to revese the words
        string word = " ";
        while (i < s.length() && s[i] != ' ')
        { // find individual word until space
            word += s[i];
            i++; // extra space will be handles
        }
        reverse(word.begin(), word.end());
        if (word.length() > 0)
        {
            ans += " " + word;
        }
    }
    return ans.substr(1);
}

int main()
{
    string s = "the sky is blue";
    cout << reverseTheString(s);
}
