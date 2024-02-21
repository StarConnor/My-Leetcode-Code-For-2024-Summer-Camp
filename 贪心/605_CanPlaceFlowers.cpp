/**
 * You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
 * 
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: true
 * Example 2:
 * 
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: false
 *  
 * 
 * Constraints:
 * 
 * 1 <= flowerbed.length <= 2 * 104
 * flowerbed[i] is 0 or 1.
 * There are no two adjacent flowers in flowerbed.
 * 0 <= n <= flowerbed.length
 */
#include<iostream>
#include<vector>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    bool solv(vector<int>& flowerbed, int n){
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);
        for (auto i = next(flowerbed.begin()); i < flowerbed.end() && n; ++ i){
            if (!*i && !*(i - 1) && (i + 1) < flowerbed.end() && !*(i + 1)){
                n --;
                *i = 1;
            }
        }
        if (n)
            return false;
        return true;
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    vector<int> flowerbed = {0,0,1,0,0};
    int n = 1;
    // return value should be modified according to the implementation of Solution.solv()
    bool result;

    result = solv.solv(flowerbed, n);
    
    cout << "Input:[";
    for (auto i = flowerbed.begin(); i < flowerbed.end(); ++i)
        cout << *i << ", ";
    cout << "\nn:" << n << endl;
    cout << "Result:" << result << endl;
    return 0;
}