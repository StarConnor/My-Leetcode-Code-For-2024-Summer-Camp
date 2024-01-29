/**
*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
*
*P   A   H   N
*A P L S I I G
*Y   I   R
*And then read line by line: "PAHNAPLSIIGYIR"
*
*Write the code that will take a string and make this conversion given a number of rows:
*
*string convert(string s, int numRows);
* 
*
*Example 1:
*
*Input: s = "PAYPALISHIRING", numRows = 3
*Output: "PAHNAPLSIIGYIR"
*Example 2:
*
*Input: s = "PAYPALISHIRING", numRows = 4
*Output: "PINALSIGYAHRPI"
*Explanation:
*P     I    N
*A   L S  I G
*Y A   H R
*P     I
*Example 3:
*
*Input: s = "A", numRows = 1
*Output: "A"
* 
*
*Constraints:
*
*1 <= s.length <= 1000
*s consists of English letters (lower-case and upper-case), ',' and '.'.
*1 <= numRows <= 1000
 */
#include<iostream>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
// copied
class Solution {
public:
    string solv(string s, int numRows){
        if (numRows <= 1 || s.size() <= 1)
            return s;
        string result;
        for (int i = 0; i < numRows; i ++){
            for (int j = 0, index = i; index < s.size();
                    j ++, index = (2 * numRows - 2) * j + i){
                result.append(1, s[index]);
                if (i == 0 || i == numRows - 1)
                    continue;
                if (index + (numRows - 1 - i) * 2 < s.size())
                    result.append(1, s[index + (numRows - i - 1) * 2]);
            }
        }
        return result;
    }
};

//mine. GEAT!
class Solution1 {
public:
    string solv(string s, int numRows){
        int epoch = 2 * numRows - 2;
        int length = s.size();
        string result;
        if (numRows == 1)
            result = s;
        else {
            for (int i = 0; i < numRows; i ++){
                int j = i;
                while (j < length){
                    result.append(1, s[j]);
                    if ((i != 0 && i != numRows - 1) && (j + 2 * (numRows - i - 1)) < length)
                        result.append(1, s[j + 2 * (numRows - i - 1)]);
                    j += epoch;
                }
            }
        }
        return result;
    }
};

class Solution0 {
public:
    string solv(string s, int numRows){
        string row[numRows];
        string result;
        int i = 0, j = 0;
        int length = s.size();
        if (numRows == 1){
            result = s;
        } else {
            while (i < length){
                if (j % (numRows - 1)){
                    for (int k = 0; k < numRows - 1 - j % (numRows - 1); k ++){
                        row[k] += ' ';
                    }
                    row[numRows - 1 - j % (numRows - 1)] += s[i];
                    i ++;
                    for (int k = numRows - j % (numRows - 1); k < numRows; k ++){
                        row[k] += ' ';
                    }
                } else {
                    for (int k = 0; k < numRows && i < length; k ++){
                        row[k] += s[i];
                        i ++;
                    }
                }
                j ++;
            } 
            for (i = 0; i < numRows; i ++){
                j = 0;
                while (row[i][j]){
                    if (row[i][j] != ' ')
                        result += row[i][j];
                    j ++;
                }
            }
        }
        return result;
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    // return value should be modified according to the implementation of Solution.solv()
    string result;

    result = solv.solv(s, numRows);
    
    cout << "Input:" << s << "numRows:" << numRows << endl; 
    cout << "result:" << result << endl;
    return 0;
}