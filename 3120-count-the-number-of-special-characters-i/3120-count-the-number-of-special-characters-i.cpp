class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> lower(26, 0);
        for(int i=0; i<n; i++){
            char ch = word[i];
            if(ch>='a' and ch<='z')
            lower[ch-'a']=1;
        }
        vector<int> upper(26, 0);
        for(int i=0; i<n; i++){
            char ch = word[i];
            if(ch>='A' and ch<='Z')
            upper[ch-'A']=1;
        }

        int ans=0;
        for(int i=0; i<26; i++){
            if(lower[i] and upper[i])
            ans++;
        }
        return ans;
    }
};