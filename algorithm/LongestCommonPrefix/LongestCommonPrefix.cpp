
/*
Write a function to find the longest common prefix string 
amongst an array of strings.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
 * Horizontal scanning
 *
 * */
string longestCommonPrefix(vector<string>& strs) 
{
        int size = strs.size();
        if ( size ==0 )
            return "" ;

        if ( size == 1 )
           return strs[0];
        
        int prefixLen = 0;
        while(1){
            for(int i=1; i < size; i++) {
                if ( strs[i].size() < prefixLen ||  strs[i][prefixLen] != strs[0][prefixLen] )
                        return strs[0].substr(0, prefixLen);
            }
            prefixLen++;
        }
}


//TODO
//1. THe binary search way
string longestCommonPrefix_1(vector<string>& strs) 
{
}

//TODO
//2. The Divide and Conquer
string longestCommonPrefix_2(vector<string>& strs) 
{
}


int main()
{
    string a = "c";
    string b="c";
    vector<string> vecStr={a,b};
    
    cout << longestCommonPrefix(vecStr) <<endl;
}
