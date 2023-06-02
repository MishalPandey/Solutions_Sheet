bool Cycle_det_dir_graph(int V, vector<int> adj[], vector<int>&visited, vector<int>&dfsvisited, int x)
  {
      
      visited[x]= true;
      dfsvisited[x] = true;
      int ans= false;
      
      for(auto it: adj[x])
      {
          if(visited[it] && dfsvisited[it])
          {
              return true;
          }
          else if(!visited[it]){
              ans = ans | Cycle_det_dir_graph(V, adj, visited, dfsvisited, it);
              
          }
          
      }
      dfsvisited[x] = false;
      
      return ans;
  }
  
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        
        vector<int>visited(V, 0);
        vector<int>dfsvisited(V, 0);
        bool ans= false;
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                 ans= ans| Cycle_det_dir_graph(V, adj, visited, dfsvisited, i);
            }
            
        }
        
        
        return ans;
    }
