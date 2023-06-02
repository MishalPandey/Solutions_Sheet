//Solution 1 
//Using BFS(Kahns algorithm)

class Solution {
public:
   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;   
        vector<int> graph[n];
        for(auto x : prerequisites){
            vector<int> data = x;
            int a =data[0];
            int b = data[1];
            graph[a].push_back(b);
            
        }

        bool ans= false;
        
                vector<int> ordering;

                vector<int>indegree(n+1, 0);
                for (int i = 0; i < n; ++i)
                {
                    for(auto child: graph[i])
                            indegree[child]++;
                }

                queue<int>q;

                for (int i = 0; i < n; ++i)
                {
                    if(indegree[i]== 0){
                            q.push(i);
                    }
                }

                int ct=0;
                while(q.size())
                {
                        int ver = q.front();
                        q.pop();

                        ordering.push_back(ver);
                        ct++;

                        for(auto child : graph[ver])
                        {
                            indegree[child]--;

                            if(indegree[child]==0)
                                q.push(child);
                        }
                }

                if(ct== n)
                {
                        ans = true;
                }
                


            
        return ans;

        
        
    }
};
