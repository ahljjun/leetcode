
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
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;



// This version has some issue
vector<vector<int>> threeSum(vector<int>& nums){
    //vector<vector<int>>  ret;
    set<vector<int>> ret;
    sort(nums.begin(), nums.end());
    int i=0;
    int j = nums.size()-1;
    int valToFind = 0;
    while( i < j-1 ){ //at lease 3 values
        bool found = false;
        valToFind = -(nums[i] + nums[j]);
        cout <<"i,j,val"<<i<<" "<<j<<","<<valToFind<<endl;
        if ( valToFind < nums[i+1] ){
            j--;
            continue;
        }
        if ( valToFind > nums[j-1] ){
            i++; 
            continue;
        }
        //try to find the value in the [i+1, j-1]
        for(int k=i+1; k <= j-1; k++){
            if (nums[k] == valToFind){
                cout <<"ValueFound,k: "<<nums[k]<<endl;
                ret.insert({nums[i], nums[k], nums[j]});
                i++;
                j--;
                found = true;
                break;
            }
        }
        if(!found) //how to handle 
            i++;
    } 

    return vector<vector<int>> (ret.begin(), ret.end());
}   



void printVectors(const vector<vector<int>> &vec)
{
   for(auto v : vec){
      cout<<"[";
      for(auto num : v)
         cout<<num<<",";
      cout<<"]";
   }
}

int main()
{
   vector<int> nums1 = {-1, 0, 1, 2, -1, -4}; 
   vector<int> nums2 = {0, 0,0,0}; 
   vector<int> nums3 = {1,2,-2,-1}; 
   vector<int> nums4 = {-1,0,1,0}; 
   vector<int> nums5 = {-2, 0,1,1,2}; 
   printVectors(threeSum(nums1));
   printVectors(threeSum(nums2));
   printVectors(threeSum(nums3));
   printVectors(threeSum(nums4));
   printVectors(threeSum(nums5));
}
