//Solution 1, T.C{O(V+E)}, S.C{O(V)}
class Solution {
  public:
    void bfs(int V, vector<int> adj[],  vector<int> &ans, vector<bool>&vis)
    {
        
        queue<int>q;
        q.push(0);
        while(q.size())
        {
            int top = q.front();
            q.pop();
            if(vis[top]) continue;
            vis[top]= true;
            ans.push_back(top);
            for(auto it: adj[top])
            {
                q.push(it);
            }
            
        }
        
        
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<bool> vis(V, 0);
        
        bfs(V, adj, ans, vis);
        
        
        return ans;
    }
};
