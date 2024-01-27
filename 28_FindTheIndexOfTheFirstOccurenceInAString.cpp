// KMP algorithm
/**
*Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*
* 
*
*Example 1:
*
*Input: haystack = "sadbutsad", needle = "sad"
*Output: 0
*Explanation: "sad" occurs at index 0 and 6.
*The first occurrence is at index 0, so we return 0.
*Example 2:
*
*Input: haystack = "leetcode", needle = "leeto"
*Output: -1
*Explanation: "leeto" did not occur in "leetcode", so we return -1.
* 
*
*Constraints:
*
*1 <= haystack.length, needle.length <= 104
*haystack and needle consist of only lowercase English characters.
*/
#include<iostream>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    int solv(string haystack, string needle) {
        int length = needle.size();  
        int next[length];
        this->next(needle, next);
        int i = 0, j = 0;
        while (i < haystack.size() && j < length){
            if (j == -1 || haystack[i] == needle[j]){
                i ++;
                j ++;
            }
            else {
                j = next[j];
            }
        }
        if (j >= length)
            return i-length;
        else
            return -1;
    }

    void next(string needle, int next[]){
        int length = needle.size();  
        int j, k;
        j = 0;
        k = -1;
        next[0] = -1;
        while (j < length - 1){
            if (k == -1 || needle[j] == needle[k]){
                j ++;
                k ++;
                next[j] = k;
            }
            else {
                k = next[k];
            }
        }
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    string haystack = "hatAndhat", needle = "hat";
    // return value should be modified according to the implementation of Solution.solv()
    int result;
    string test = "ababc";
    int next[test.size()];

    result = solv.solv(haystack, needle);

    cout << "result:" << result << endl;
    return 0;
}