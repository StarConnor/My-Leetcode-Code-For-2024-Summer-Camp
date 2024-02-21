/**
 * Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
 * Example 2:
 * 
 * Input: intervals = [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
 * Example 3:
 * 
 * Input: intervals = [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 *  
 * 
 * Constraints:
 * 
 * 1 <= intervals.length <= 105
 * intervals[i].length == 2
 * -5 * 104 <= starti < endi <= 5 * 104
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
    int solv(vector<vector<int>>& intervals){
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
        {return a[1] < b[1];});
        int removed = 0, prev = intervals[0][1];
        for (int i = 1; i < n; ++i){
            if (intervals[i][0] < prev){
                ++removed;
            } else {
                prev = intervals[i][1];
            }
        }
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    vector<vector<int>> intervals;
    // return value should be modified according to the implementation of Solution.solv()
    int result;

    result = solv.solv(intervals);
    
    cout << "Input:[";
    for (auto i = intervals.begin(); i < intervals.end(); ++i){
        vector<int> temp = *i;
        cout << "[";
        for (auto j = temp.begin(); j < temp.end(); ++j){
            cout << *j << ", "; 
        }
        cout << "], ";
    }
    cout << "]\nResult:" << result << endl;
    return 0;
}