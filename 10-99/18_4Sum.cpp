/**
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * 
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * You may return the answer in any order.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * Example 2:
 * 
 * Input: nums = [2,2,2,2,2], target = 8
 * Output: [[2,2,2,2]]
 *  
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 200
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    vector<vector<int>> solv(vector<int>& nums, int target){
        vector<vector<int>> result;
        if (nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>>> cache;
        for (size_t a = 0; a < nums.size(); ++a){
            for (size_t b = a + 1; b < nums.size(); ++b){
                cache[nums[a] + nums[b]].push_back(pair<int,int>(a, b));
            }
        }
        for (int c = 0; c < nums.size(); ++c){
            for (size_t d = c + 1; d < nums.size(); ++d){
                const int key = target - nums[c] - nums[d];
                if (cache.find(key) == cache.end())
                    continue;
                const auto& vec = cache[key];
                for (size_t k = 0; k < vec.size(); ++k){
                    if (c <= vec[k].second)
                        continue;
                    result.push_back({nums[vec[k].first],
                            nums[vec[k].second], nums[c], nums[d]});
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
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
    vector<vector<int>> solv(vector<int>& nums, int target){
        vector<vector<int>> result;
        this->quicksort(nums, 0, nums.size() - 1);
        auto last = nums.end();
        for (auto i = nums.begin(); i < last - 3; ++i){
            for (auto l = i + 3; l < last; ++l){
                while (l > i + 3 && *l == *(l - 1) && l < last)
                    l ++;
                auto j = i + 1;
                if (i > nums.begin() && *i == *(i + 1))
                    continue;
                auto k = l - 1;
                while (j < k){
                    if (*i + *l + *j + *k < target){
                        ++j;
                        while (j < k && *j == *(j - 1))
                            j++;
                    } else if (*i + *l + *j + *k > target){
                        --k;
                        while (j < k && *k == *(k + 1))
                            k--;
                    } else{
                        result.push_back({*i, *j, *k, *l});
                        ++j;
                        --k;
                        while (*j == *(j - 1) && *k == *(k + 1) && j < k)
                            ++j;
                    }
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
    vector<int> nums = {-2, -1, -1, 1, 1, 2, 2};
    int target = 0;
    // return value should be modified according to the implementation of Solution.solv()
    vector<vector<int>> result;

    result = solv.solv(nums, target);
    
    cout << "Input:[";
    for (int i=0; i < nums.size(); i ++)
        cout << nums[i] << ", ";
    cout << ']' << endl << "result:[";
    for (int i=0; i < result.size(); i ++){
        cout << '[';
        for (int j=0; j < 4; j ++){
            cout << result[i][j] << ", ";
        }
        cout << "], ";
    }
    cout << ']' << endl;
    return 0;
}