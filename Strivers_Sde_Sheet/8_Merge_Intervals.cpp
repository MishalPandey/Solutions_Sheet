// Solution 1 T.C{O(n.logn + n)} S.C{O(n)}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector < vector < int >> merged;

        if(intervals.size()==0)
        {
            return merged;
        }
        vector<int>tmp = intervals[0];

        for (int i = 0; i < n; i++) {
            if (tmp[1]>=intervals[i][0]) 
            {

                tmp[1]= max(tmp[1], intervals[i][1]);

            }
            
            else
            {
                merged.push_back(tmp);
                tmp = intervals[i]; 
                
            }
        }
        merged.push_back(tmp);

        return merged;
    }

        
    
};
