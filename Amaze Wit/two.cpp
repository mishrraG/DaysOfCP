/*
 *  This is my solution to today's AmazeWit question
 *  The question states to create a function with the funtion signature
 *  string longestPalindromicSubstring(string str)
 *  {
 *  //your code here
 *  }
 *  which takes one input(str) and returns the longest palindromic substring 
 * */
#include <iostream>
using namespace std;
#define endl '\n'
string longestPalindromicSubstring(string str)
{

    int maxLength = 1;
    int start = 0;
    int len = str.length();
    int low, high;
    for (int i = 0; i < len; ++i)
    {
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    string s="";
    for(int i=start;i<=start+maxLength-1;++i)
    {
        s=s+str[i];
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "ololmadamabc";
    cout << longestPalindromicSubstring(s) << endl;

}

