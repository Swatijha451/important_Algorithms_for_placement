// permutation in string-> return true if there exists permutationof the other string
//  str1 is abcerfhjgdjuhg and str 2= ab if there exists any permutaion of ab or ba in str1 return true
// all the input string is smaallcase alphabets which makes the question easier
#include <iostream>
using namespace std;
/*
approach
step 1: Make a index array which will store frequency of all the permutaion as count of alphabets remains same on all pemutaion of a string
step 2: search str 1 in str2 using  sliding window algorithm -> make second array of array 1 lenght and size window is equal to size of permutaion string;
step 3:check the two array for freaquancy of the character if its same-> permution exist in the string
*/

bool checkFreqencyArray(int arr1[], int arr2[])
{
    for (int i = 0; i < 26; i++) // fixed lenth loop //Tc=O(1)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}
bool permutationInString(string str1, string str2)
{
    int permFreq[26] = {0};                 // there are 26 smallcase english alphabets
    for (int i = 0; i < str1.length(); i++) // O(n)
    {
        int idx = str1[i] - 'a'; // index a->96-96=0, similarly b-1,c-2 and so on. if the str1[i] match with index freq++
        permFreq[idx]++;
    }

    int windowSize = str1.length();

    for (int i = 0; i < str2.length(); i++) // O(n2)
    {
        int windFreq[26] = {0};

        int idx = i;
        int windIdx = 0;

        while (windIdx < windowSize && idx < str2.length())
        {

            windFreq[str2[idx] - 'a']++;
            idx++;
            windIdx++;
        }
        if (checkFreqencyArray(permFreq, windFreq))
        {
            return true;
        }
    }

    return false;
}
int main()
{
    string str2 = "eidabwe";
    string str1 = "ab";
    cout << permutationInString(str1, str2);
}
