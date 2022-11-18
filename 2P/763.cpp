class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int size = 0;
        vector<int> lastIndices(26, 0);
        for(int i=0;i<s.length();i++) {
            lastIndices[s[i]-'a'] = i;
        }
        for(int i=0;i<s.length();i++) {
            cout<<"here we come with i "<<i<<" and "<<lastIndices[s[i]-'a']<<endl;
                if(i == lastIndices[s[i]-'a']) {
                cout<<"here we come with i "<<i<<" and "<<lastIndices[s[i]-'a']<<endl;
                ans.push_back(size);
                size = 0;
            }
            size++;
        }
        return ans;
    }
};
