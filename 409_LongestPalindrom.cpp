
/**
 *Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
 *
 *Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
 *
 * 
 *
 *Example 1:
 *
 *Input: s = "abccccdd"
 *Output: 7
 *Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
 *Example 2:
 *
 *Input: s = "a"
 *Output: 1
 *Explanation: The longest palindrome that can be built is "a", whose length is 1.
 * 
 *
 *Constraints:
 *
 *1 <= s.length <= 2000
 *s consists of lowercase and/or uppercase English letters only.
 */
#include<iostream>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    int solv(string s){
        const int ASCII_MAX = 255;
        int last[ASCII_MAX];
        int length = s.size();
        int result = 0;
        bool odd = false;

        fill(last, last+ASCII_MAX, 0);
        for (int i = 0; i < length; i ++){
            last[s[i]] ++; 
        }
        for (int i = 0; i < ASCII_MAX; i++){
            result += last[i];
            // result += last[i] / 2;
            if (last[i] % 2){
                result --;
                odd = true;
            }
        }
        if (odd)
            result ++;
        return result;
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    string s = "abccccdd";
    int result;

    result = solv.solv(s);
    
    cout << "Input:" << s << endl;
    cout << "result:" << result << endl;
    return 0;
}