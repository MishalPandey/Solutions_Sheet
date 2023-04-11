//Solution 1 ----T.C{O(n)}  , S.C{O(1)}


class Solution {
public:
    int compareVersion(string version1, string version2) {

        int n = version1.size();
        int m = version2.size();
        //IMPOT POINT-All the given revisions in version1 and version2 can be stored in a 32-bit integer.
        int i=0, j=0;
        int flagi =0, flagj=0;
        while(i < n || j < m)
        {

                while(i<n && version1[i] !='.')
                {
                   
                    flagi = 10*flagi + (version1[i] - '0');
                    i++;
                }
                
                while(j<m && version2[j] !='.')
                {
                   
                    flagj = 10*flagj + (version2[j] - '0');
                    j++;
                }
                
                if(flagi >flagj)
                {
                    return 1;
                }
                else if(flagi <flagj) {
                    return -1;
                }

            i++;
            j++;
            flagi=0;
            flagj=0;
        
                    
            
        }




        return 0;

        
    }
};
