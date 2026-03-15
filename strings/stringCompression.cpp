// array of charcter=['a','a','b','b','c] output = ['a','2','b','2',c]; return the size of the compressed array
#include <iostream>
#include <vector>
using namespace std;

int compressString(vector<char> &arr)
{
    int n = arr.size();
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        {
            char ch = arr[i];
            while (i < n && arr[i] == ch)
            {
                count++; // frequency of achracter
                i++;
            }
            if (count == 1)
            {
                arr[idx++] = ch;
            }
            else
            {
                arr[idx++] = ch;
                string str = to_string(count); // convert count to string
                for (char digit : str)         // onput every digit of count to array
                {
                    arr[idx++] = digit;
                }
            }
            i--;
        }
    }
    arr.resize(idx);
    return idx;
}

int main()
{
    vector<char> array = {'a', 'a', 'b', 'b', 'b', 'c'};
    cout << compressString(array); // 5
}
