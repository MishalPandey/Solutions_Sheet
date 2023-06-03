//Solution 1, T.C{O(V+E)}, S.C{O(V)}


class Solution {
public:
    bool  Check_Bipartite_BFS(vector<vector<int >>& graph, int i, vector<int>&vis)
    {

        queue<pair<int, int>>q;
        q.push({i, -1});

        int level = 0;

        while(q.size())
        {
            int x = q.size();
            while(x--)
            {
                    pair<int, int> top = q.front();
                    q.pop();

                    if(vis[top.first]!=-1)
                    {
                        if(vis[top.first] != top.second)
                        {
                            return false;

                        }

                    }
                    else{
                        vis[top.first]= level;
                    }

                    for(auto it: graph[top.first])
                    {
                        if(vis[it]==-1)
                        {
                            q.push({it, level+1});

                        }
                        
                    }

            }
            level++;


        }


        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        int m = graph[0].size();

        vector<int>vis(n, -1);

        bool ans= true;

        for(int i=0; i< n; i++)
        {
            if(vis[i] ==-1)
            {
                
                ans = ans & Check_Bipartite_BFS(graph, i, vis);

            }

            
        }

        return ans;
        
    }
};
