/**
 * You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
 * 
 * Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
 * 
 * Return a list of integers representing the size of these parts.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
 * Example 2:
 * 
 * Input: s = "eccbbbbdec"
 * Output: [10]
 *  
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 500
 * s consists of lowercase English letters.
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    vector<int> solv(string s){
        vector<int> ans;
        unordered_map<char, int> um;
        auto last = s.begin();
        auto start = s.begin();
        for (auto i = s.begin(); i < s.end(); ++i){
            if (um.count(*i)){
                if (i == last){
                    ans.push_back(last - start + 1);
                    start = next(i);
                    last = next(i);
                } 
                continue;
            }
            for (auto j = next(i); j < s.end(); ++j){
                if (*j == *i){
                    if (j > last)
                        last = j;
                }
            }
            if (last == start){
                ans.push_back(1);
                start = next(i);
                last = next(i);
            }
            else
                um[*i] = last - s.begin();
        }
        return ans;
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    string s = "caedbdedda";
    // return value should be modified according to the implementation of Solution.solv()
    vector<int> result;

    result = solv.solv(s);
    
    cout << "Input:" << s << endl;
    cout << "Result:[";
    for (auto i = result.begin(); i < result.end(); ++i)
        cout << *i << ", ";
    cout << "]";
    return 0;
}