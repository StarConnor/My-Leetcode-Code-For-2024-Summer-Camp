/**
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation: 
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not matter.
 * Example 2:
 * 
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 * Example 3:
 * 
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 *  
 * 
 * Constraints:
 * 
 * 3 <= nums.length <= 3000
 * -105 <= nums[i] <= 105
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
    vector<vector<int>> solv(vector<int>& nums) {
        // vector<vector<int>>* result = new vector<vector<int>>();
        vector<vector<int>> result;
        int low = 0, high = nums.size() - 1, middle = 0;
        this->quicksort(nums, 0, nums.size() - 1);
        const int target = 0;
        auto last = nums.end();
        for (auto i = nums.begin(); i < last - 2; ++i){
            auto j = i + 1;
            if (i > nums.begin() && *i == *(i - 1))
                continue;
            auto k = last - 1;
            while (j < k){
                if (*i + *j + *k < target){
                    ++j;
                    while (*j == *(j - 1) && j < k)
                        ++j;
                } else if (*i + *j + *k > target){
                    --k;
                    while(*k == *(k + 1) && j < k)
                        --k;
                } else {
                    result.push_back({*i, *j, *k});
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

class Solution0 {
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
    vector<vector<int>> solv(vector<int>& nums) {
        // vector<vector<int>>* result = new vector<vector<int>>();
        vector<vector<int>> result;
        int low = 0, high = nums.size() - 1, middle = 0;
        this->quicksort(nums, 0, nums.size() - 1);
        while (low < high){
            if (nums[low] + nums[high] < 0){
                middle = high - 1;
                while (low < middle && nums[low] + nums[high] + nums[middle] > 0){
                    middle --;
                }
                if (nums[low] + nums[high] + nums[middle] == 0){
                    vector<int> temp;
                    temp.push_back(nums[low]);
                    temp.push_back(nums[middle]);
                    temp.push_back(nums[high]);
                    result.push_back(temp);
                }
                low ++;
            } else {
                middle = low + 1;
                while (middle < high && nums[low] + nums[high] + nums[middle] < 0){
                    middle ++;
                }
                if (nums[low] + nums[high] + nums[middle] == 0){
                    vector<int> temp;
                    temp.push_back(nums[low]);
                    temp.push_back(nums[middle]);
                    temp.push_back(nums[high]);
                    result.push_back(temp);
                }
                high --;
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
    vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    // return value should be modified according to the implementation of Solution.solv()
    vector<vector<int>> result;

    result = solv.solv(nums);
    
    cout << "Input:[";
    for (int i=0; i < nums.size(); i ++)
        cout << nums[i] << ", ";
    cout << ']' << endl << "result:[";
    for (int i=0; i < result.size(); i ++){
        cout << '[';
        for (int j=0; j < 3; j ++){
            cout << result[i][j] << ", ";
        }
        cout << "], ";
    }
    cout << ']' << endl;
    return 0;
}