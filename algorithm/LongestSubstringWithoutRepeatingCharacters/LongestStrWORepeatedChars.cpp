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
#include <vector>
using namespace std;

/*
 *
 *
 *
 *
 * */
/* DP solution by dragonmigo *
 *  Solution (DP, O(n)):
 *   
 *  Assume L[i] = s[m...i], denotes the longest substring without repeating
 *  characters that ends up at s[i], and we keep a hashmap for every
 *  characters between m ... i, while storing <character, index> in the
 *  hashmap.
 *  We know that each character will appear only once.
 *  Then to find s[i+1]:
 *  1) if s[i+1] does not appear in hashmap
 *  we can just add s[i+1] to hash map. and L[i+1] = s[m...i+1]
 *  2) if s[i+1] exists in hashmap, and the hashmap value (the index) is k
 *  let m = max(m, k), then L[i+1] = s[m...i+1], we also need to update
 *  entry in hashmap to mark the latest occurency of s[i+1].
 *  
 * Since we scan the string for only once, and the 'm' will also move from
 * beginning to end for at most once. Overall complexity is O(n).
 * 
 * If characters are all in ASCII, we could use array to mimic hashmap.
 **/

int lengthOfLongestSubstringDP(string s)
{
	vector<int> charIndex(256, -1);
    int longest = 0, m = 0;

        for (int i = 0; i < s.length(); i++) {
		m = max(charIndex[s[i]] + 1, m);    // automatically takes care of -1 case

	        charIndex[s[i]] = i;
	        longest = max(longest, i - m + 1);
	}

	return longest;
}

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
	int dplen = lengthOfLongestSubstring(s);
	cout<<"max dplen: "<<dplen << endl;
}




class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			            
			        }
};
