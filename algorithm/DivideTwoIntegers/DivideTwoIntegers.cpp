/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/


//Wrong Answer
int divide(int dividend, int divisor) {
    int cnt = 0;
    
    // note can not use the multiplication, how to determine negative? postive?
    while( dividend >=  divisor){
        dividend = dividend - divisor;
        cnt++;
    }
     
    return cnt;
}
