#include <iostream>
#include <cstring>

using namespace std;
void printCharArr(char arr[])
{
    for (int i = 0; i < strlen(arr); i++)
    {
        cout << arr[i];
    }
}

void charcterArray()
{
    // charater can be used as string of fixed length
    char charArr[] = {'s', 'w', 'a', 't', '\0'}; // "\0" will be ignored while print
    char charArr1[] = "swati";                   // last character is \0 size is 1B
    cout << charArr[3] << endl;                  // locations can also be accessed like array
    cout << charArr[4] << endl;                  // null character printed i.e nothing
    cout << strlen(charArr) << endl;
    printCharArr(charArr1);
    printCharArr(charArr);

    // input of character array
    char charArr2[50];
    cin >> charArr2; // it will all the space in inputs
    printCharArr(charArr2);
    //  to get all the inputs including space we use cin.getline(charArr.#of charcters, delimiter)// delimiter is optional
    char charArr3[50];
    cin.getline(charArr3, 10); // take all the input until 10 avharcter
    // printCharArr(charArr3);
    char charArr4[50];
    cin.getline(charArr3, 12, '$'); // it will take input before delimiter character
    printCharArr(charArr4);
}
void stringsInC()
{
    // strings are dynamc in nature i.e the lenghth of strings can be modified at runtime i.e. which is not possible in charcter array.
    // strings is class in c++ we can make object of string class
    string str = "swati jha";
    cout << str;
    // input of str
    string str1;
    cin >> str1; // take input unti sapce
    cout << str1;
    string str2;
    getline(cin, str2);
    cout << str2;
}
void reverseString(char str[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
}

int main()

{
    // charcterArray();
    // stringsInC();
    char str[] = "swati";
    reverseString(str, strlen(str));
    cout << str;
}
