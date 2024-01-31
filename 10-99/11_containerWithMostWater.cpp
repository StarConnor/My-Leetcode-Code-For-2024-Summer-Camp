/**
 * You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * 
 * Return the maximum amount of water a container can store.
 * 
 * Notice that you may not slant the container.
 * 
 *  
 * 
 * Example 1:
 * 
 * 
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
 * Example 2:
 * 
 * Input: height = [1,1]
 * Output: 1
 *  
 * 
 * Constraints:
 * 
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 */
#include<iostream>
#include<vector>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    int solv(int arg1, int arg2){

    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    int arg1, arg2;
    // return value should be modified according to the implementation of Solution.solv()
    int result;

    result = solv.solv(arg1, arg2);
    
    cout << "Input:" << arg1 << "\t" << arg2 << endl;
    cout << "result:" << result << endl;
    return 0;
}