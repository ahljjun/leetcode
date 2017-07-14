
/*
Given an array S of n integers, 
are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
/*
vector<vector<int>> threeSum(vector<int>& nums) 
{

}
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>>  ret;
    sort(nums.begin(), nums.end());
    int i=0;
    int j = nums.size()-1;
    int valToFind = 0;
    while( i< j ){
        cout <<"i,j"<<i<<" "<<j<<endl;
        valToFind = -(nums[i] + nums[j]);
        if ( valToFind < nums[i+1] ){
            i++;
            continue;
        }
        if ( valToFind > nums[j-1] ){
            j--;
            continue;
        }
        //try to find the value in the [i+1, j-1]
        for(int k=i+1; k <= j-1; k++){
            if (nums[k] == valToFind){
                ret.push_back({nums[i], nums[k], nums[j]});
                i=k ;
            }
        }
    } 

    return ret;
}   

int main()
{
   vector<int> nums = {-1, 0, 1, 2, -1, -4}; 
   vector<vector<int>> ret = threeSum(nums);
   for(auto v : ret){
      cout<<"[";
      for(auto num : v)
         cout<<num<<",";
      cout<<"]";
   }
}
