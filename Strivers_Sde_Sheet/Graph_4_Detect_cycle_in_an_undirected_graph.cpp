//Solution 1, T.C{O(V+E)}, S.C{O(V)}
//Using DFS
class Solution {
  public:
    void dfs(int V, vector<int> adj[],  int &is_cycle, vector<bool>&vis, int vertex, int parent)
    {
        
        vis[vertex]= true;
        for(auto it: adj[vertex])
        {
            if(vis[it] && it == parent) continue;
            if(vis[it])
            {
                is_cycle=1;
                continue;
            }
            dfs(V, adj, is_cycle, vis, it, vertex);
            
        }
        
        
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> vis(V, 0);
        bool ans = false;
        
        for(int i=0; i< V; i++)
        {
            
            if(vis[i]== false)
            {
                int is_cycle = 0;
                dfs(V, adj, is_cycle, vis, i, -1);
                ans = ans | is_cycle;
            }
        }
        
        
        return ans;
    }
};
