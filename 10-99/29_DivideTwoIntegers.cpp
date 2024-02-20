
/**
 * Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

 * The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = 3.33333.. which is truncated to 3.
 * Example 2:
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 *  
 * 
 * Constraints:
 * 
 * -231 <= dividend, divisor <= 231 - 1
 * divisor != 0
 */
#include<iostream>
#include<vector>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    int solv(int dividend, int divisor){
        long long a = dividend >= 0 ? dividend : -(long long)dividend;
        long long b = divisor >= 0 ? divisor : -(long long)divisor;
        long long result = 0;
        while(a >= b){
            long long c = b;
            for (int i = 0; a >= c; ++i, c <<= 1){
                a -= c;
                result += 1 << i;
            }
        }
        if ((dividend ^ divisor) >> 31){
            return -result;
        } else {
            if (result > 0x7fffffff)
                return 0x7fffffff;
            else 
                return result;
        }
    }
};
class Solution0 {
public:
    int solv(int dividend, int divisor){
        int result = 0;
        int addition = 0;
        int neg = 0;
        if (dividend & 0x80000000 && divisor & 0x80000000 || !(dividend & 0x80000000) && !(divisor & 0x80000000)){
            neg = 1;
        }
        long tdividend = dividend > 0 ? dividend : -dividend;
        long tdivisor = divisor > 0 ? divisor : -divisor;
        while (addition < tdividend){
            addition += tdivisor;
            result ++;
        }
        if (addition > tdividend)
            result --;
        if (!neg)
            result = -result;
        return result;
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    int dividend = 0, divisor = 1;
    // return value should be modified according to the implementation of Solution.solv()
    int result;

    result = solv.solv(dividend, divisor);
    
    cout << "Input:" << dividend << "\t" << divisor << endl;
    cout << "result:" << result << endl;
    return 0;
}