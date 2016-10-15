/*
 * https://leetcode.com/problems/single-number/
* Given an array of integers, every element appears twice except for one. Find that single one.

* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*
*/

//Solution: 两个相等的数异或结果为0. 数字与0异或数字不变


class Solution {
    public:
        int singleNumber(vector<int>& nums) {
                    int num = nums[0];
                    for(int i=1;i<nums.size();i++){
                                    num ^= nums[i];

                    }

                            return num;

        }

};
