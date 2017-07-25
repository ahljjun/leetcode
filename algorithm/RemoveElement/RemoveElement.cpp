
/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.

*/


int removeElement(vector<int>& nums, int val) {
   int size = nums.size();
   sort(nums.begin(), nums.end());
   int start= -1;
   int len = 0;
   
   for(int i =0; i<size; i++){
       if(nums[i] == val){
           if ( start < 0 )
               start = i;
           len++;
       }
       
       if (nums[i] > val )
           break;
   }
   
   //no val found or the vector is empty
   if (start < 0)
       return size;
   
   for(int i=start, j=start+len; j< size; i++,j++){
       nums[i]=nums[j];
   }
   
   return size - len;
}
