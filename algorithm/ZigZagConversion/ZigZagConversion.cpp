
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


string convert(string s, int numRows){
    if (numRows == 1)
        return s;

    vector<vector<char>> strVec(numRows, vector<char>());
    auto slot = 0;
    bool increase = true;
    for(int i=0; i < s.size(); i++){
        if ( slot == 0 ){
           increase = true; 
        }
        if (slot == numRows-1){
            increase = false;
        }

        strVec[slot].push_back(s[i]);

        if ( increase )
            slot++;
        else
            slot--;
    }

    string retStr;
    for(int i=0;i< numRows; i++)
    {
        //retStr.append(strVec[i]->begin(), strVec[i]->end());
        retStr.append(strVec[i].begin(), strVec[i].end());
    }

    return retStr;
}


int main()
{
    string s = "abcdefgh";

    cout<< convert(s, 1)<<endl;
    cout<< convert(s,2)<<endl;
    cout<< convert(s,3)<<endl;

    return 0;
}
