/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    int size = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> ret;
    
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            int twoSum = nums[i]+nums[j];
            int k = j+1;
            int h = size-1;
            while( k < h ){
                if ( nums[k]+nums[h] + twoSum < target ){
                    k++;
                }
                else if ( nums[k] + nums[h] + twoSum> target ){
                    h--;
                }
                else{
                    ret.insert({nums[i],nums[j],nums[k],nums[h]});
                    k++;
                    h--;
                }
            }
        }
    }

    return vector<vector<int>>(ret.begin(), ret.end());
}



void dumpResult(const vector<vector<int>> &ret)
{
    for(auto v : ret){
        cout << "[";
        for(auto val : v){
            cout<<val<<",";
        }
        cout<<"]\n";
    }
}

int main()
{
    vector<int> nums={1, 0, -1, 0, -2, 2};
    int target=0;
    vector<vector<int>> result = fourSum(nums, target);
    dumpResult(result);
}
