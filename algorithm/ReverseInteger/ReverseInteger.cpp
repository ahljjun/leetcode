/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. 
Your function should return 0 when the reversed integer overflows.
*/



#include <iostream>
using namespace std;

const int cIntMax = ~(1<<31);

int reverse(int x)
{
    long long y = x; // need to use the long long type , if int y;  y=-y might overflow already
    if (y<0)
        y=-y; 
    else
        y=y;

    int result=0;
    while(y){
        result = 10*result + y%10;
        y=y/10;
        if ( y && (result > (cIntMax /10) ||( (result == (cIntMax/10)) && y > 2))) // cIntMax 
            return 0;
    }

    if (x<0)
        return -result;
    else
        return result;
}

int main()
{
    cout<<sizeof(long long)<<endl;
    cout<<cIntMax<<endl;

    cout<<reverse(1534236469)<<endl;
    cout<<reverse(-2147483412)<<endl;
    cout<<reverse(-2147483648)<<endl;
}
