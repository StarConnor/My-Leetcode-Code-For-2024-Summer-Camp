//Link: 238, 11
/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 * 
 *  
 * 
 * Example 1:
 * 
 * 
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
 * Example 2:
 * 
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *  
 * 
 * Constraints:
 * 
 * n == height.length
 * 1 <= n <= 2 * 104
 * 0 <= height[i] <= 105
 */
#include<iostream>
#include<vector>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    int solv(vector<int> &height){
        int start = 0, end = height.size() - 1;
        int base = 0;
        int result = 0;
        while (start < end){
            if (height[start] > height[end]){
                if (height[end] > base)
                    base = height[end];
                else
                    result += base - height[end];
                end --;
            } else {
                if (height[start] > base)
                    base = height[start];
                else
                    result += base - height[start];
                start ++;
            }
        }
        return result;
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // return value should be modified according to the implementation of Solution.solv()
    int result;

    result = solv.solv(height);
    
    cout << "Input:";
    for (int i = 0; i < height.size(); i ++)
        cout << height[i] << ", ";
    cout << "result:" << result << endl;
    return 0;
}