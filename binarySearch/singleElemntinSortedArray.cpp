#include <iostream>
#include <vector>
using namespace std;
// laaetcode problrm 540: single element in a sorted array
//  hert the array is sorted and each element appears twice except for ooe that apperas once. we need to find that elemnt.
int bruteForceApproach(vector<int> vec) // O(n) time comlexity;
{
    int ans = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        ans = ans ^ vec[i]; // bitwise xor operator approach
        // ifvec[i]!=vec[i+1] &&vect[i]!=vec[i-1]// return vec[i];//linear search approach
    }
    return ans;
}
int singleElementSortedArry(vector<int> vec) // O()
{
    int start = 0;
    int end = vec.size() - 1;
    if (vec.size() == 1)
        return vec[0];
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (vec[mid] != vec[mid + 1] && vec[mid] != vec[mid - 1])
        {
            return vec[mid];
        }
        else if (mid % 2 == 0)
        { // when mid is even there are even numbe elemnt on both sizes of mid
            if (vec[mid] == vec[mid - 1])
            {                  // mid pairs up on left side
                end = mid - 1; // left side has odd elemnt so serch in left sude
            }
            else
            {
                start = mid + 1; // mid pairs up on right side search in rigjt side
            }
        }
        else
        { // mid indeex is odd there are odd no of elemnts on both sides of mid
            if (vec[mid] == vec[mid - 1])
            {                    // mid pairs up left side which leaves perfect pair on left side;
                start = mid + 1; // search in right side of array
            }
            else
            { //
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    cout << bruteForceApproach(vec) << endl;
    cout << singleElementSortedArry(vec) << endl;
    return 0;
}