/**
 * Given two strings s and t of lengths m and n respectively, return the minimum window 
 * substring
 *  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
 * 
 * The testcases will be generated such that the answer is unique.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
 * Example 2:
 * 
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 * Example 3:
 * 
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 *  
 * 
 * Constraints:
 * 
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 105
 * s and t consist of uppercase and lowercase English letters.
 *  
 * 
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 */
#include<iostream>
#include<vector>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    string solv(string s, string t){
        int need[128] = {0};
        int window[128] = {0};
        int strLength = s.size(), targetLength = t.size();

        for (char& c : t){
            ++need[c];
        }

        int matches = 0;
        int start = 0;
        int minStart = -1;
        int minLength = 0x7fffffff;
        for (int i = 0; i < strLength; ++i){
            ++window[s[i]];
            if (need[s[i]] >= window[s[i]]){
                ++matches;
            }
            while (matches == targetLength){
                if (i - start + 1 < minLength){
                    minLength = i - start + 1;
                    minStart = start;
                }
                if (need[s[start]] >= window[s[start]]){
                    --matches;
                }
                --window[s[start++]];
            }
        }
        return minStart < 0 ? "" : s.substr(minStart, minLength);
    }
};
class Solution0 {
public:
    string solv(string s, string t){
        vector<int> chars(128, 0);
        vector<int> flag(128, false);
        for (int i = 0; i < t.size(); ++i){
            flag[t[i]] = true;
            ++chars[t[i]];
        }
        int cnt = 0, l = 0, min_l = 0, min_size = s.size() + 1;
        for (int r = 0; r < s.size(); ++r){
            if (flag[s[r]]){
                if (--chars[s[r]] >= 0){
                    ++cnt;
                }
                while (cnt == t.size()){
                    if (r - l + 1 < min_size){
                        min_l = l;
                        min_size = r - l + 1;
                    }
                    if (flag[s[l]] && ++chars[s[l]] > 0){
                        --cnt;
                    }
                    ++l;
                }
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    string s = "ADOBECODEBANC", t = "ABC";
    // return value should be modified according to the implementation of Solution.solv()
    string result;

    result = solv.solv(s, t);
    
    cout << "Input:" << s << " | " << t << endl;
    cout << "Result:" << result << endl;
    return 0;
}