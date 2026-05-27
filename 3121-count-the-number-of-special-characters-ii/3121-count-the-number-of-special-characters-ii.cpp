class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        for(int i=0; i<n; i++){
            char ch = word[i];            
            if(ch>='a' and ch<='z'){
                int islower = lower[ch-'a'];
                int isupper = upper[ch-'a'];
                if(isupper==0)
                lower[ch-'a']=1;
                else
                upper[ch-'a'] = -1;
            }
            else if(ch>='A' and ch<='Z'){
                int islower = lower[ch-'A'];
                int isupper = upper[ch-'A'];
                if(islower==1 and isupper!=-1)
                upper[ch-'A'] = 1;
                else
                upper[ch-'A'] = -1;
            }
        }
        int ans=0;
        for(int i=0; i<26; i++){
            if(lower[i]==1 and upper[i]==1)
            ans++;
        }
        return ans;
    }
};