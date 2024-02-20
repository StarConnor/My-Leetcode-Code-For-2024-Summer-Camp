/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
 * 
 * A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * 
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * Example 2:
 * 
 * Input: digits = ""
 * Output: []
 * Example 3:
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *  
 * 
 * Constraints:
 * 
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 */
#include<iostream>
#include<vector>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    vector<string> ref = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> solv(string digits){
        vector<string> result;
        auto ptr = digits.begin();
        if (digits.size()){
            for (int i = 0; i < ref[*ptr - '2'].size(); ++i){
                string temp;
                temp += ref[*ptr - '2'][i];
                result.push_back(temp);
            }
            ptr ++;
        } else
            return result;
        while (*ptr){
            string chset = ref[*ptr - '2'];
            int size = result.size();
            for (int i = 0; i < size; i ++){
                string temp = result[i];
                result[i] += chset[0];
                for (auto i = chset.begin() + 1; i < chset.end(); ++i){
                    result.push_back(temp + *i);
                }
            }
            ptr ++;
        }
        return result;
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    string digits = "23";
    // return value should be modified according to the implementation of Solution.solv()
    vector<string> result;

    result = solv.solv(digits);
    
    cout << "Input:" << digits << endl;
    cout << "Result:" << endl;
    for (auto i = result.begin(); i < result.end(); ++i)
        cout << *i << endl;
    return 0;
}