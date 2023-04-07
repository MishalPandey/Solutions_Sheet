//Solution 1-----T.C{O(N)}  , S.C{O(1)}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        int j=0;
        string ans="";
        if(strs.size()==1)
        {
            return strs[0];
        }
        for(int i=0; i<n; i++)
        {
            if( (i+1< n ) && ((strs[i]=="") ||(strs[i+1]=="") ||j > strs[i].size()-1 || j > strs[i+1].size()-1 || (strs[i][j]!=strs[i+1][j]) ) )
            {
                break;
            }

            if(i==n-1)
            {
                if(strs[i]!="") ans+=strs[i][j];
                j++;
                i=-1;

            }
            
        }


        return ans;
        
    }
};
