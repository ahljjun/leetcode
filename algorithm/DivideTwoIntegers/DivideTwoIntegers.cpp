/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/


//Time-Limit exceed version
int divide(int dividend, int divisor) {
        int cnt = 0;
        bool isneg = false;
        bool overflow = false;
        long long ldividend = dividend;
        long long ldivisor = divisor;
        if ( dividend < 0 ){
            isneg = true;
            //dividend = -dividend; // this could overflow
            ldividend = - dividend;
            if ( ldividend != -dividend){
                overflow = true;
            }
        }
            
        
        if ( divisor < 0 ){
            isneg = !isneg;
            //divisor = -divisor; // this could overflow
            ldivisor = -divisor;
            if ( Ldivisor != -divisor){
                overflow = true;
            }
        }
        
        if ( overflow )
            return INT_MAX;
        
        while( Ldividend >=  Ldivisor){
            dividend = dividend - divisor;
            cnt++;
        }
        
        return isNeg ? -cnt:cnt;
  }

}
