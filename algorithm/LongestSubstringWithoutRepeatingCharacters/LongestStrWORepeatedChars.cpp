/*
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 *
 * */


/**/
#include <iostream>
#include <string>
using namespace std;


int lengthOfLongestSubstring(string s)
{
	int dict[256] = {0};
	int size = s.length();
	dict[s[0]]=1;
	int len  =1;
	int i=0;
	int j=1;
	for(i=0; i<size; i++){
		while( !dict[s[j]] ){ // why sometimes out of array bound in github????
		       dict[s[j]] = 1;
		       j++;		
		}
		if (  len < (j-i) )
			len = j-i; 	

		if ( j > size)
			break;

		dict[s[i]]= 0;
	}

	return len;
}


int main()
{
	string s = "ailghngvnbtulazsqvpftrq";
	int len = lengthOfLongestSubstring(s);
	cout<<"max len: "<<len << endl;
}




class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			            
			        }
};
