/**
 * There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
 * 
 * You are giving candies to these children subjected to the following requirements:
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * Return the minimum number of candies you need to have to distribute the candies to the children.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: ratings = [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
 * Example 2:
 * 
 * Input: ratings = [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
 * The third child gets 1 candy because it satisfies the above two conditions.
 *  
 * 
 * Constraints:
 * 
 * n == ratings.length
 * 1 <= n <= 2 * 104
 * 0 <= ratings[i] <= 2 * 104
 */
#include<iostream>
#include<vector>

using namespace std;

/**
 * Here is the solution class to be implemented.
*/
class Solution {
public:
    int solv(vector<int>& ratings){
        int result = ratings.size();
        vector<int> candies(result); 
        for (int i = 1; i < result; ++ i){
            if (ratings[i] > ratings[i - 1]){
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = result - 1; i > 0; -- i){
            if (ratings[i] < ratings[i - 1] && candies[i] >= candies[i - 1]){
                candies[i - 1] = candies[i] + 1;
            }
        }
        for (int i = 0; i < ratings.size(); i ++)
            result += candies[i];
        return result;
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    vector<int> ratings = {1,6,10,8,7,3,2} ;
    // return value should be modified according to the implementation of Solution.solv()
    int result;

    result = solv.solv(ratings);
    
    cout << "Input:\n[";
    for (auto i = ratings.begin(); i < ratings.end(); ++i)
        cout << *i << ", ";
    cout << "]\nResult:" << result << endl;
    return 0;
}