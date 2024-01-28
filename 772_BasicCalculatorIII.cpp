/**
 * Implement a basic calculator to calculate simple expression string
 * The expression string only contains non-negative integer, '+', '-', '*', '/'
 * '(', ')', ' '. The devision should be truncated towards zero.
 * 
 * Example:
 * "1 + 1" = 2
 * " 6-4 / 2" = 4
 * "2*(5+5*2)/3+(6/2+8)" = 21
 * 
 * Constraint:
 * all intermediate results should range from -214783648 to 214783648.
 */
#include<iostream>
#include<vector>

using namespace std;

/**
*/
class Solution {
public:
    int solv(string s){
        //stopr: operator stack
        vector<char> stopr;
        //stpost: suffix expression stack
        vector<char> stpost;
        //stcalc: calculator stack
        vector<int> stcalc;
        int length = s.size();
        int num = 0;
        // this "for" cycle and the next "for" cycle together give the suffix expression
        for (int i = 0; i < length; i ++){
            if (s[i] >= '0' && s[i] <= '9'){
                stpost.push_back('#');
                do{
                    stpost.push_back(s[i]);
                    i ++;
                }while (i < length && s[i] >= '0' && s[i] <= '9');
                //there is a "i++" in the "for" expression, redundant
                i --;
                stpost.push_back('#');
            } else if (s[i] == ' '){
                continue;
            //"(" means that any operator after it has higher priority over before
            } else if (stopr.empty() || stopr.back() == '('){
                stopr.push_back(s[i]);
            } else if (s[i] == ')'){
                char e;
                while ((e = stopr.back()) != '('){
                    stopr.pop_back();
                    stpost.push_back(e);
                }
                // pop_back '('
                stopr.pop_back();
            } else {
                char e = stopr.back();
                switch (s[i]){
                    case '-':
                    case '+':
                        stopr.pop_back();
                        stpost.push_back(e);
                        stopr.push_back(s[i]);
                        break;
                    case '/':
                    case '*':
                        if (e == '+' || e == '-'){
                            stopr.push_back(s[i]);
                        } else {
                            stopr.pop_back();
                            stpost.push_back(e);
                            stopr.push_back(s[i]);
                        }
                        break;
                    case '(':
                        stopr.push_back(s[i]);
                }
            }
        }
        //this "for" cycle clean the remain operator in the stopr stack
        for (size_t i = 0; i < stopr.size(); i ++){
            stpost.push_back(stopr.back());
            stopr.pop_back();
        }
        //this "for" cycle calculate the result based on the suffix expression
        for (size_t i = 0; i < stpost.size(); i ++){
            if (stpost[i] == '#'){
                num = 0;
                i ++; 
                do {
                    num = 10 * num  + stpost[i] - '0';
                    i ++;
                } while (stpost[i] != '#');
                stcalc.push_back(num);
            } else {
                int num1 = stcalc.back();
                stcalc.pop_back();
                int num2 = stcalc.back();
                stcalc.pop_back();
                switch (stpost[i]){
                    case '+':
                        stcalc.push_back(num2 + num1);
                        break;
                    case '-':
                        stcalc.push_back(num2 - num1);
                        break;
                    case '*':
                        stcalc.push_back(num2 * num1);
                        break;
                    case '/':
                        stcalc.push_back(num2 / num1);
                        break;
                }
            }
        }
        return stcalc.back();
    }
};

/**
 * Here is the main function to execute the solving class.
*/
int main(){
    Solution solv;
    string s = "2 * (3/(4-2)-1)";
    int result;

    result = solv.solv(s);
    
    cout << "Input:" << s << endl;
    cout << "result:" << result << endl;
    return 0;
}