
/*
Write a function to find the longest common prefix string 
amongst an array of strings.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
        int size = strs.size();
        if ( size ==0 )
            return "" ;

        int i=0;
        int j=0;
        int minLen = strs[0].size();
        for(i=1; i < strs.size(); i++) {
            minLen =min(minLen, (int)strs[i].size());
        }

        while(j<minLen){
            for(i=0; i < size; i++) {
                if ( strs[i][j] != strs[i][0] )
                    return strs[0].substr(0,j);
            }
            j++;
        }

        return "";
}

int main()
{
    string a = "abc";
    string b="abd";
    vector<string> vecStr={a,b};
    
    cout << longestCommonPrefix(vecStr) <<endl;
}
