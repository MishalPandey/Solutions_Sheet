//Solution 1, T.C{O(V+E)}, S.C{O(V)}
void dfs(int V, vector<int> &adj[],  vector<int> & ans, int x, vector<bool>&vis)
    {
        
        ans.push_back(x);
        vis[x]= true;
        for(auto it: adj[x])
        {
            if(vis[it]) continue;
            dfs(V, adj, ans, it, vis);
            
        }
        
        
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<bool> vis(V, 0);
        
        if(V>0)
        {
            dfs(V, adj, ans, 0, vis);
        
        }
        
        
        return ans;
        
        
    }
