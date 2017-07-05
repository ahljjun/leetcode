/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

/*
 *
 * using dynamic programming:
 * suppose dp[i][j] is the parlindromic
 * dp[i-1][j+1]:
 *     s[i-1] == s[j+1], dp[i-1][j+1] is parlindromic 2.
 *     s[i-1] != s[j+1]
 * */

#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s)
{
    int size = s.size();
    vector<vector<bool>> dp(size, vector<bool>(size));
    int maxLen = 0;
    int palindromeStart = 0;

    for(int i=size-1; i>=0; i--){
        for(int j=i; j<size; j++){
        // dp[i+1][j-1] only make sense when i+1 <=j-1, so j-i>=2; 
        // when j-i<3, it means, j-i=0,1,2,which equals 'a','aa','aba' situation 
           dp[i][j] = ( s[i] == s[j] ) && ((j-i<3) ||  dp[i+1][j-1]) ;
           if(dp[i][j] && (j-i+1) > maxLen){
               palindromeStart = i;
               maxLen = j-i+1;
           }
        }
    }

    return s.substr(palindromeStart, maxLen);
}


int main()
{
    string s = "babad"; 
    cout<<longestPalindrome(s)<<endl;
}




