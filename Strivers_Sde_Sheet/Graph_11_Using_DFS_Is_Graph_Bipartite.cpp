//Solution 1 , T.C{O(V+E)}, S.C{O(V)} 
class Solution {
public:

// by two coloring statergy
    bool  Check_Bipartite_DFS(vector<vector<int >>& graph, int i, vector<int>&col, vector<bool>&vis)
    {

        
            vis[i] = true;

                    for(auto it: graph[i])
                    {
                        if(col[it]==col[i])
                        {
                            return false;

                        }

                        else if(!vis[it])
                        {
                            col[it] = !col[i];

                            if(Check_Bipartite_DFS(graph, it, col, vis)== false)
                            {
                                return false;
                            }

                            
                        }

                    }
                        
                    

        


        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        int m = graph[0].size();

        vector<int>col(n, -1);
        vector<bool>vis(n, 0);

        bool ans= true;

        for(int i=0; i< n; i++)
        {
            if(!vis[i])
            {
                col[i]=0;
                ans = ans & Check_Bipartite_DFS(graph, i, col, vis);

            }

            
        }

        return ans;
        
    }
};
