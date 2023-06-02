//Solution 1, T.C{O(V+E)}, S.C{O(V)} --LUV SIR
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


//Solution 2, T.C{O(V+E)}, S.C{O(V)} -- SUMIT SIR
//Using BFS

class Solution {
  public:
    void bfs(int V, vector<int> adj[],  int &is_cycle, vector<bool>&vis, int vertex)
    {
        
        queue<int>q;
        q.push(vertex);
        while(q.size())
        {
            int top = q.front();
            q.pop();
            
            if(vis[top])
            {
                is_cycle = 1;
                continue;
            }
            vis[top]= true;
            
            for(auto it: adj[top])
            {
                if(vis[it]) continue; 
                q.push(it);
            }
            
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
                bfs(V, adj, is_cycle, vis, i);
                ans = ans | is_cycle;
            }
        }
        
        
        return ans;
    }
};
