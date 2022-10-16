// Top down approach
class Solution {
public:
    int dp[301];
    int helper(int position, string s, unordered_set<string>& wordSet) {
        if(position == s.size()) return 1;
        if(dp[position] != -1) return dp[position];
        string temp;
        for(int i=position;i<s.size();i++) {
            temp += s[i];
            if(wordSet.find(temp) != wordSet.end()) {
                if(helper(i+1, s, wordSet)) return dp[position] = 1;
            }
        }
        return dp[position] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof dp);
        unordered_set<string> wordSet;
        for(string word:wordDict) {
            wordSet.insert(word);
        }
        return helper(0, s, wordSet);
    }
};
