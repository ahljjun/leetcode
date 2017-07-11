
/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(int x) 
{
    long result = 0;
    int y = x;
     
    while(y){
       result = 10*result + y%10;
       y = y/10;
    }
   
    if ( result > INT_MAX|| result <  INT_MIN)
       return 0;

    cout << "result: "<<result<<endl;
    return x == result;
}

int main()
{
    int a;
    while(cin >> a){
       cout<<"a="<<a<<","<<isPalindrome(a)<<endl;
    }
}
        
        
