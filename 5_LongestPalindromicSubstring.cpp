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
        int resultl=0, resultr=0;
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                if (i==j){
                    f[i][j]=true;
                }
                else if (j == i+1){
                    f[i][j]=(s[i]==s[j]);
                }
                else {
                    f[i][j]=(s[i]==s[j])&&f[i+1][j-1];
                }
            }
        }
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                if (f[i][j] && max_len<j-i){
                    max_len=j-i;
                    resultl=i;
                    resultr=j;
                }
            }
        }
        return s.substr(resultl, resultr);
    }
};


int main(){
    Solution solv;
    string result;
    string s;

    result = solv.solv(s);
    cout<<"result:"<<result<<endl;
    return 0;
}