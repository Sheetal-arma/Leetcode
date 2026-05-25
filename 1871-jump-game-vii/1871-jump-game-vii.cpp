class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1]=='1')
        return false;

        queue<int> q;
        vector<int> visited(n, 0);
        q.push(0);
        visited[0] = 1;

        int prev=0+minJump;

        while(!q.empty()){
            int idx = q.front();
            q.pop();

            if(idx==n-1)
            return true;

            int mini = max(prev, idx+minJump);
            int maxi = idx+maxJump;

            for(int i=mini; i<=min(maxi, n-1); i++){
                if(s[i]=='0' and visited[i]==0){
                    visited[i] = 1;
                    q.push(i);
                }               
            }
            prev = idx+maxJump+1;
        }
        return false;
    }
};