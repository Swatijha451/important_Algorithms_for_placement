#include <iostream>
#include <vector>
using namespace std;
// leetcode probblem 410: book allocation problem
//  we are given an array of integers where each element represents the number of pages in a book. we have to allocate these books to m students such that each student gets at least one book and the maximum number of pages assigned to a student is minimized. we have to return the minimum possible value of the maximum number of pages assigned to a student.
bool isValid(vector<int> vec, int students, int n, int maxAllowedPages)
{
    int studentCount = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++) // O(n)
    {
        if (vec[i] > maxAllowedPages) // if more pages than allowed pages
        {
            return false;
        }
        if (vec[i] + pageSum <= maxAllowedPages) //
        {
            pageSum += vec[i];
        }
        else
        {
            studentCount++; // increment the student count and allocate the pages to them
            pageSum = vec[i];
        }
    }
    return studentCount > students ? false : true; // if student count greater then actual studen invalid result
}

int bookAllocationProblem(vector<int> vec, int students) // O(nlog(range));
{
    int start = 0;
    int ans = -1;
    int sum;
    for (int i = 0; i < vec.size(); i++) // O(n)
    {
        sum += vec[i];
    }
    int end = sum;
    // binary serach over the posiible range of min to max pages
    while (start <= end) // O(log(range)) *O(n)for isvalid function
    {
        int mid = start + (end - start) / 2;
        if (isValid(vec, students, vec.size(), mid)) // true
        {
            ans = mid;
            end = mid - 1; // try to find smsller possible vslues inleft of array
        }
        else
        {
            start = mid + 1; // if the mid is invalid
        }
    }
    return ans;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    int children = 2;
    cout << bookAllocationProblem(vec, children) << endl;
}
