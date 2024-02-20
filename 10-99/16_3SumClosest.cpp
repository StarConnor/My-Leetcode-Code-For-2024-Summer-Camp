/**
 * Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
 * 
 * Return the sum of the three integers.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * Example 2:
 * 
 * Input: nums = [0,0,0], target = 1
 * Output: 0
 * Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 *  
 * 
 * Constraints:
 * 
 * 3 <= nums.length <= 500
 * -1000 <= nums[i] <= 1000
 * -104 <= target <= 104
 */
#include<iostream>
#include<vector>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    int partition(vector<int>& A, int low, int high){
        int pivot = A[low];
        while (low < high){
            while(low < high && A[high] >= pivot){
                --high;
            }
            A[low] = A[high];
            while (low < high && A[low] <= pivot){
                ++low;
            }
            A[high] = A[low];
        }
        A[low] = pivot;
        return low;
    }

    void quicksort(vector<int>& A, int low, int high){
        if (low < high){
            int pivot = this->partition(A, low, high);
            this->quicksort(A, low, pivot - 1);
            this->quicksort(A, pivot + 1, high);
        }
    }
    int solv(vector<int>& nums, int target){
        int result;
        int delta = 0x7fffffff;
        this->quicksort(nums, 0, nums.size() - 1);
        auto last = nums.end();
        for (auto i = nums.begin(); i < last - 2; ++i){
            auto j = i + 1;
            auto k = last - 1;
            if (i > nums.begin() && *i == *(i - 1))
                continue;
            while (j < k){
                int sum = *i + *j + *k;
                if (abs(sum - target) < delta){
                    delta = abs(sum - target);
                    result = sum;
                }
                if (sum < target){
                    ++j;
                    while(*j == *(j - 1) && j < k)
                        ++j;
                } else if (sum > target){
                    --k;
                    while (*k == *(k + 1) && j < k)
                        --k;
                } else {
                    ++j;
                    --k;
                    while (*j == *(j - 1) && *k == *(k + 1) && j < k)
                        ++j;
                }
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
    vector<int> nums = {1,1,1,1};
    int target = 3;
    // return value should be modified according to the implementation of Solution.solv()
    int result;

    result = solv.solv(nums, target);
    
    cout << "Input:[";
    for (auto i = nums.begin(); i < nums.end(); i ++)
        cout << *i << ", ";
    cout << "target:" << target << endl;
    cout << "result:" << result << endl;
    return 0;
}