class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(!M.size()) return 0;
        vector<bool> vis(M.size(), false);
        int cnt = 0;
        for(int i = 0; i < M.size(); i++){
            if(vis[i]) continue;
            
            cnt++;
            queue<int> que;
            que.push(i);
            vis[i] = true;
            
            while(!que.empty()){
                int u = que.front();
                que.pop();
                vis[u] = true;
                for(int v = 0; v < M[u].size(); v++){
                    if(!vis[v] && M[u][v]) que.push(v);
                }
            }
        }
        
        return cnt;
    }
};
