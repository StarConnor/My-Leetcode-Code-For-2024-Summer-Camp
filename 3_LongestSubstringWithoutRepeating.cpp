#include<iostream>
#include<unordered_map>

using namespace std;

template class unordered_map<char, int>;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int ASCII_MAX = 255;
        int last[ASCII_MAX];
        int start = 0;

        fill(last, last+ASCII_MAX, -1);
        int max_len = 0;
        for (int i = 0; i < s.size(); i++){
            if (last[s[i]] >= start){
                max_len = max(i-start, max_len);
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        return max((int)s.size() - start, max_len);
    }
};

class Solution0 {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len=0;
        unordered_map<char, int> um;
        for(int i=0; i<s.size(); i++){
            int j = 0;
            for (j=i; j<s.size(); j++){
                if(um.count(s[j])){
                    break;
                }
                else{
                    um[s[j]] = j;
                }
            }
            if(max_len < j-i)
                max_len = j-i;
            if(j == s.size())
                break;
            i = um[s[j]];
            um.clear();
        }
        return max_len;
    }
};
int main(){
    string s = "abcadee";
    Solution sol;
    int result;
    result = sol.lengthOfLongestSubstring(s);
    cout<<"result:"<<result<<endl;
    return 0;
}