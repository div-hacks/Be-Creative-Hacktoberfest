class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& g) {
     vector<int> adj[n]; vector<int> ans; int ctr=0;
        for(auto it:g)
        {
          int u=it[0]; int v=it[1];
            adj[v].push_back(u);
            ctr++;
        }
        vector<int> in(n);
          for(int i=0 ; i<n; i++)
        {
            for(auto j:adj[i])
                in[j]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop(); ans.push_back(node);
           for(auto it:adj[node])
           {
               in[it]--;
               if(in[it]==0) q.push(it);
           }
        } if(ans.size()==n) return ans;
        return {};
    }
};
