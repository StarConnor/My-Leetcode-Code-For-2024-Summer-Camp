// 动态规划法
/**
*Given a string s, return the longest 
*palindromic
 
*substring
* in s.

 

*Example 1:

*Input: s = "babad"
*Output: "bab"
*Explanation: "aba" is also a valid answer.
*Example 2:

*Input: s = "cbbd"
*Output: "bb"
 

*Constraints:

*1 <= s.length <= 1000
*s consist of only digits and English letters.
*/
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    string solv(string s) {
        const int n = s.size();
        bool f[n][n];
        fill_n(&f[0][0], n*n, false);
        size_t max_len = 1, start = 0;

        for (size_t i = 0; i < s.size(); i++){
            f[i][i] = true;
            for (size_t j = 0; j < i; j++){
                f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
                if (f[j][i] && max_len < (i - j + 1)){
                    max_len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len);
    }
};


int main(){
    Solution solv;
    string result;
    string s="ababc";

    result = solv.solv(s);
    cout<<"result:"<<result<<endl;
    return 0;
}