//Solution 1, T.C{O(V+E)}, S.C{O(V)} 
//Using BFS
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	//Kahns algorithm
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> ans;
	   
	   vector<int> indegree(V, 0);
	   
	   for(int i=0; i<V; i++)
	   {
	       for(auto it: adj[i])
	       {
	           indegree[it]++;
	       }
	   }
	   
	   queue<int>q;
	   for(int i=0; i<V; i++)
	   {
	       if(indegree[i]==0)
	       {
	           q.push(i);
	       }
	   }
	   
	   while(q.size())
	   {
	       int ver = q.front();
	       q.pop();
	       ans.push_back(ver);
	       
	       for(auto it: adj[ver])
	       {
	           indegree[it]--;
	           
	           if(indegree[it]==0)
	           {
	               q.push(it);
	           }
	       }
	       
	   }
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   return ans;
	}
};

