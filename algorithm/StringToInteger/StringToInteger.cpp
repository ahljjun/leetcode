
/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the 
first non-whitespace character is found. Then, starting from this character, 
takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, 
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, 
or if no such sequence exists because either str is empty or it contains only whitespace characters, 
no conversion is performed.

If no valid conversion could be performed, a zero value is returned. 
If the correct value is out of the range of representable values, 
INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <climits>
using namespace std;


int myAtoi(string str) 
{
    int wbegin=0;
    int nLen = str.size();
    int sign = 0;

    while(wbegin < nLen &&  str[wbegin]==' ')
        wbegin++;

    if(str[wbegin] == '-')
        sign = -1;
    else if (str[wbegin] == '+')
        sign = 1;

    if ( sign )
        wbegin++;
    else
        sign = 1;

    int wend = wbegin ;
    while(wend < nLen && isdigit(str[wend]))
        wend++;

    if ( wbegin == nLen )
        return 0;

    long long result  = 0;
    for(int i=wbegin; i<wend; i++){
        result = result * 10 + sign*(str[i] - '0');
        if ( result > INT_MAX ) 
           return INT_MAX;

        if ( result < INT_MIN )
           return INT_MIN;
    }
    
    return result;
}




int main()
{
    string str;
    while(cin>>str){
        cout<<myAtoi(str)<<endl;
    }
}
