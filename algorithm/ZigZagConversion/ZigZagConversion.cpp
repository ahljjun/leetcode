
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


string convert(string s, int numRows){
    return "" ;
}


int main()
{
    int numRows = 3;
    vector<std::shared_ptr<vector<char>>> strVec(numRows);
    for(int i=0; i< numRows; i++){
        strVec[i]= std::make_shared<vector<char>>(); 
    }

    string s = "PAYPALISHIRING";
    
    auto slot = 0;
    bool increase = true;
    auto j = 0;
    for(int i=0; i < s.size(); i++){
        j = slot;
        if ( --j == -1 ){
           increase = true; 
        }
        j = slot;
        if (++j == numRows){
            increase = false;
        }
        cout << "slot "<<slot<<": "<<s[i]<<endl;
        strVec[slot]->push_back(s[i]);

        if ( increase )
            slot++;
        else
            slot--;
    }

    string retStr;
    for(int i=0;i< numRows; i++)
    {
        retStr.append(strVec[i]->begin(), strVec[i]->end());
    }


    cout << retStr<<endl;



        
        /*
        if ((i / numRows) % 2)
            direction = -1;
        else
            direction = 1;

        slot = (i+1+direction * (numRows-1)) % (numRows) ;
        */

    /*
    for(auto charVec : strVec){
       for(auto c : *charVec)
          cout<< c<<","; 

       cout<<"\n";
    }
    */


    return 0;
}
