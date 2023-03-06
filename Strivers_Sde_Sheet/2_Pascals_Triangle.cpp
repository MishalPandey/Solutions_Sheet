// Solution 1 (Revise Recursion for this question)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {

          if(numRows==1){
              vector<vector<int>>ans={{1}};
              return ans;
          }
          // else if(numRows==2){
          //     vector<vector<int>>ans={{1}, {1, 1}};
          //     return ans;
          // }

          vector<vector<int>>chhota_numRows_ka_sol = generate(numRows - 1);

          vector<int>lastrow = chhota_numRows_ka_sol[chhota_numRows_ka_sol.size()-1];

          vector<int>newrow(lastrow.size()+1, 0);

          newrow[0]=1;
          newrow[lastrow.size()]=1;

              for(int i=1; i<lastrow.size(); i++)
              {
                  newrow[i]= lastrow[i-1]+ lastrow[i];
              }
              vector<vector<int>>ans;
              ans= chhota_numRows_ka_sol;
              ans.push_back(newrow);


          return ans;
        
        
    }
};
