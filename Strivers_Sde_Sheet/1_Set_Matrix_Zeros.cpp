// Solution 1
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // O(2*m*n) T.C and O(m+n) S.C solution of (73. Set Matrix Zeroes) Question
        int m = matrix.size();
        int n = matrix[0].size();
        
        set<int>si, sj;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0){
                    si.insert(i);
                    sj.insert(j);

                }
            }
        
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(si.find(i)!=si.end() || sj.find(j)!=sj.end()){
                    matrix[i][j]=0;
                }
            }
        
        }

        
    }
};


//Solution 2

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // O(2*m*n) T.C and O(m + n) S.C without stl solution of (73. Set Matrix Zeroes) Question
        int m = matrix.size();
        int n = matrix[0].size();

        
        vector<int>vc(n, 1), vr(m, 1);

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0){
                    
                         vr[i]=0;
                         vc[j]=0;
                    
                   
                }
            }
        
        }

        

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(vr[i]==0 || vc[j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        
        }


        
    }
};


// Solution 3 --Optimum
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // O(2*m*n) T.C and O(1) S.C solution of (73. Set Matrix Zeroes) Question
        int m = matrix.size();
        int n = matrix[0].size();

        int col0=1, row0=1;
        

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0){
                    if(i==0)
                    {
                        row0=0;
                    }
                    else if(j==0)
                    {
                        col0=0;
                    }
                    else{
                         matrix[i][0]=0;
                         matrix[0][j]=0;
                    }
                   
                }
            }
        
        }

        //traversing in the the reverse direction and
        //checking if the row or col has 0 or not
        //and setting values of matrix accordingly.

        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(i==0 && row0==0)
                {
                   matrix[0][j]=0; 

                }
                else if(j==0 &&col0==0){
                     matrix[i][0]=0;
                }
                else if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        
        }

        
    }
};
