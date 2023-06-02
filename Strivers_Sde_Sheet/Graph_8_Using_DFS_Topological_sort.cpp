class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	//Kahns algorithm
	void topo_sorting(int V, vector<int> adj[], vector<bool> &visited, int x, stack<int>&st )
	{
    	   visited[x] =true;
    	    
    	   for(auto it: adj[x])
           {
               if(!visited[it])
               {
                   topo_sorting(V, adj, visited, it, st);
                   
               }
               
              
           }
           st.push(x);
     
	    
	}
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   
	   vector<bool> visited(V, 0);
	   stack<int>st;
	   
	   for(int i=0; i<V; i++)
	   {
	       if(!visited[i])
	       {
	           topo_sorting(V, adj, visited, i, st);
	       }
	   }
	   
	   
	       
	   
	   
	   vector<int> ans;
	   while(st.size())
	   {
	       ans.push_back(st.top());
	       st.pop();
	   }
	   
	   
	   
	   
	   
	   
	   
	   
	   return ans;
	}
};
