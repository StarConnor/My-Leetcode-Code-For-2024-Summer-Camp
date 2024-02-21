//Link: 42
/**
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 *
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * 
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * Example 2:
 * 
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 *  
 * 
 * Constraints:
 * 
 * 2 <= nums.length <= 105
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 *  
 * 
 * Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
 */
#include<iostream>
#include<vector>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    vector<int> solv(vector<int> nums){
        int result[nums.size()];
        int numZero = 0, i = 0;
        long long product = 1;
        long long productOneZero = 1;
        for (i = 0; i < nums.size(); i ++){
            if (nums[i] == 0){
                product = 0;
                numZero ++;
                continue;
            }
            product *= nums[i];
            productOneZero *= nums[i];
        }
        if (numZero == 1)
            for (int i = 0; i < nums.size(); i ++){
                if (nums[i])
                    result[i] = product / nums[i];
                else
                    result[i] = productOneZero;
            }
        else if (numZero){
            for (int i = 0; i < nums.size(); i ++)
                result[i] = 0;
        } else {
            for (int i = 0; i < nums.size(); i ++)
                result[i] = product / nums[i];
        }
        vector<int> resultVector(result, result + nums.size());
        return resultVector;
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    vector<int> nums = {1, 4, 3, 4};
    // return value should be modified according to the implementation of Solution.solv()
    vector<int> result;

    result = solv.solv(nums);
    cout <<"Input:" << endl;
    for (int i = 0; i < nums.size(); i ++)
        cout << nums[i] << ", ";
    cout <<"result:" << endl;
    for (int i = 0; i < nums.size(); i ++)
        cout << result[i] << ", ";
    return 0;
}