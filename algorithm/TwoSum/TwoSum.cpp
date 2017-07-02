/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 * */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    int size = nums.size();
    int i, j;
    for(i=0; i < size; i++){
        int valueToFind = target - nums[i];
        for(j=i+1; j < size ; j++){
            if (valueToFind == nums[j]){
                return {i,j};
            }
        }
    }

    return {-1,-1};
}

//O(n) solution here:
//using unordered_map which using the HASH algorithm to find
//notice, in order to consider the duplicate elemetns. 
//1. not initialize the unordered_map with whole vector at first
//2. linear insert the element from vector and before insert, check 
//the target 
vector<int> twoSum1(vector<int> &nums, int target){
    // key is the number and , value is the index
    unordered_map<int, int> hash;
    int size = nums.size();
    for(int i=0; i < size; i++){
        int valueToFind = target - nums[i];
        if ( hash.find(valueToFind) != hash.end() ){
            //find the value
            return {hash[valueToFind], i};
        }

        hash[nums[i]] = i;
    } 

    return {-1,-1};
    
}


int main()
{
    vector<int> IntVec={2, 7, 11 , 15};
    auto result = twoSum1(IntVec, 9);
    cout<<"["<<result[0]<<","<<result[1]<<"]"<<endl;
    return 0;
}

