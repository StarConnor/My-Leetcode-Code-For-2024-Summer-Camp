/**
 * Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 * Output: "apple"
 * Example 2:
 * 
 * Input: s = "abpcplea", dictionary = ["a","b","c"]
 * Output: "a"
 *  
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 1000
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 1000
 * s and dictionary[i] consist of lowercase English letters.
 */
#include<iostream>
#include<vector>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    string solv(string s, vector<string>& dictionary){
        int matches[1000] = {0};
        int choice = -1;
        for (int i = 0; i < s.size(); ++i){
            for (int j = 0; j < dictionary.size(); ++j){
                if (dictionary[j][matches[j]] == s[i]){
                    ++matches[j];
                }
            }
        }
        for (int j = 0; j < dictionary.size(); ++j){
            if (matches[j] == dictionary[j].size()){
                if (choice != -1){
                    if (dictionary[choice].size() < dictionary[j].size()){
                        choice = j;
                    } else if (dictionary[choice].size() == dictionary[j].size()){
                        if (dictionary[choice] > dictionary[j]){
                            choice = j;
                        }
                    }
                } else {
                    choice = j;
                }
            }
        }
        return choice == -1 ? "" : dictionary[choice];
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    string s = "abpcplea";
    vector<string> dictionary = {"ale","apple","monkey","plea"};
    // return value should be modified according to the implementation of Solution.solv()
    string result;

    result = solv.solv(s, dictionary);
    
    cout << "Input:" << s << endl;
    for (string& s : dictionary){
        cout << "\"" << s << "\"" << endl;
    }
    cout << "Result:" << result << endl;
    return 0;
}