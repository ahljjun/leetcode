
/*
Given n non-negative integers a1, a2, ..., 
an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of 
line i is at (i, ai) and (i, 0). Find two lines, 
which together with x-axis forms a container, 
such that the container contains the most water.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxArea(vector<int>& height) {
    int len = height.size();
    int left=0, right = len-1;
    int maxArea=0;

    while( left < right ){
        maxArea = max(maxArea, min(height[left], height[right])*(right-left));
        if ( height[left] < height[right] )
            left++;
        else 
            right--;
    }

    return maxArea;
}

int main()
{
    vector<int> height ={1,3,7,9,2,6,5};
    cout<< maxArea(height) << endl;
}


