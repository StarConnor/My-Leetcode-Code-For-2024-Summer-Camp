/**
 * Given a signed 32-bit integer x, return x with its digits reversed. 
 * If reversing x causes the value to go outside the signed 
 * 32-bit integer range [-2^31, 2^31 - 1], then return 0.

 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: x = 123
 * Output: 321
 * Example 2:
 * 
 * Input: x = -123
 * Output: -321
 * Example 3:
 * 
 * Input: x = 120
 * Output: 21
 *  
 * 
 * Constraints:
 * 
 * -231 <= x <= 231 - 1
 */
#include<iostream>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    int solv(int x){
        long long r = 0;
        long long t = x;
        t = t > 0 ? t : -t;
        for (; t; t /=10)
            r = r * 10 + t % 10;
        bool sign = x > 0 ? false : true;
        if (r > 0x7fffffff || (sign && r > 0x80000000)){
            return 0;
        } else {
            if (sign){
                return -r;
            } else {
                return r;
            }
        }
    }
};

class Solution1 {
public:
    int solv(int x){
        long long result = 0;
        long long temp = x < 0 ? - x : x;
        int MAX = 0x7fffffff;
        while (temp){
            int res = temp % 10;
            if (10 * result + res > MAX)
                return 0;
            result = 10 * result + res;
            temp /= 10;
        }
        if (x < 0){
            if (- result < 0)
                result = -result;
            else
                return 0;
        }
        return result;
    }
};
class Solution0 {
public:
    int solv(int x){
        long long y = x;
        string medium = to_string(y < 0 ? - y : y);
        int MAX = 0x7fffffff;
        long long result = 0;
        for (int i = medium.size() - 1; i >= 0; i --){
            if (10 * result + medium[i] - '0' > MAX)
                return 0;
            result = 10 * result + medium[i] - '0'; 
        }
        if (x < 0){
            if (- result < 0)
                result = - result;
            else
                return 0;
        } 
        return result;
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    int x = -2147483648;
    // return value should be modified according to the implementation of Solution.solv()
    int result;

    result = solv.solv(x);
    
    cout << "Input:" << x << endl;
    cout << "result:" << result << endl;
    return 0;
}