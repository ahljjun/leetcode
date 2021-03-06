
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;



vector<string> generateParenthesis(int n) {
    if ( n==1 )
        return {"()"};
    set<string> ret;
    auto strVec= generateParenthesis(n-1);
    for(auto s : strVec){
       ret.insert("()"+s) ;
       ret.insert("("+s+")");
       ret.insert(s+"()");
    }

    return vector<string>(ret.begin(), ret.end());
}


/** Wrong Algorithm here
 * right DP, see https://discuss.leetcode.com/topic/18523/a-simplified-c-dp-solution-4ms-8-lines
 * and http://blog.csdn.net/peerlessbloom/article/details/39321303
 * and http://mathforum.org/mathimages/index.php/Catalan_Numbers
 * https://discuss.leetcode.com/topic/39071/elegant-recursive-solution-for-generating-valid-parentheses
 * and https://stackoverflow.com/questions/23413881/understanding-function-to-generate-parentheses
vector<string> generateParenthesis_DP(int n) {
   set<string> ret;
   if ( n == 1 )
       return {"()"};

   ret.insert("()");
   int i = 1;
   for(int i = 1; i<n ; i++){
       set<string> newRet;
       for(auto it=ret.begin(); it!=ret.end(); it++){
           int j = 0;
           int k = 0;
           while((k=getToken(*it, j))!=-1){

           }
       }
       ret = newRet;
   }

    return vector<string>(ret.begin(), ret.end());
}
*/

vector<string> generateParenthesis_recursion(int n) {
    if ( n== 0 )
       return {""};
    if ( n == 1 )
       return {"()"};
    vector<string> ret;
    for(int i=0; i<n; i++){
        vector<string> A=generateParenthesis(i);
        vector<string> B=generateParenthesis(n-1-i);
        for(auto a : A){
          for(auto b : B){
               ret.push_back("(" + a + ")" + b);
           }
       }
    }
     
    return ret;
}



void dumpResult(const vector<string>& ret)
{
    for(auto s : ret){
        cout<<s<<",";
    }
    cout<<endl;
}

int main()
{
    int n = 3;
    vector<string> result = generateParenthesis_recursion(n);
    dumpResult(result);

}
