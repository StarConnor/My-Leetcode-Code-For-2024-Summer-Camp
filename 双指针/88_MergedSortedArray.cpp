/**
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * 
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * 
 * The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * Output: [1,2,2,3,5,6]
 * Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
 * The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
 * Example 2:
 * 
 * Input: nums1 = [1], m = 1, nums2 = [], n = 0
 * Output: [1]
 * Explanation: The arrays we are merging are [1] and [].
 * The result of the merge is [1].
 * Example 3:
 * 
 * Input: nums1 = [0], m = 0, nums2 = [1], n = 1
 * Output: [1]
 * Explanation: The arrays we are merging are [] and [1].
 * The result of the merge is [1].
 * Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 *  
 * 
 * Constraints:
 * 
 * nums1.length == m + n
 * nums2.length == n
 * 0 <= m, n <= 200
 * 1 <= m + n <= 200
 * -109 <= nums1[i], nums2[j] <= 109
 *  
 * 
 * Follow up: Can you come up with an algorithm that runs in O(m + n) time?
 */
#include<iostream>
#include<vector>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    void solv(vector<int>& nums1, int m, vector<int>& nums2, int n){
        vector<int> ans;
        int i = 0, j = 0;
        while (i < m && j < n){
            while (i < m && nums1[i] <= nums2[j]){
                ans.push_back(nums1[i]);
                ++ i;
            }
            while (j < n && nums1[i] > nums2[j]){
                ans.push_back(nums2[j]);
                ++ j;
            }
        }
        if (i < m){
            while (i < m){
                ans.push_back(nums1[i]);
                ++ i;
            }
        }
        if (j < n){
            while (j < n){
                ans.push_back(nums2[j]);
                ++ j;
            }
        }
        for (int i = 0; i < m + n; ++ i){
            nums1[i] = ans[i];
        }
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
    int m = 3, n = 3;
    // return value should be modified according to the implementation of Solution.solv()

    cout << "Input:" << endl;
    cout << "nums1:[";
    for (int i = 0; i < m; ++i)
        cout << nums1[i] << ", ";
    cout << "]\nnums2:[";
    for (int i = 0; i < n; ++i)
        cout << nums2[i] << ", ";

    solv.solv(nums1, m, nums2, n);
    
    cout << "]\nResult:" << endl;
    cout << "nums1:[";
    for (int i = 0; i < m + n; ++i)
        cout << nums1[i] << ", ";
    cout << "]";
    return 0;
}