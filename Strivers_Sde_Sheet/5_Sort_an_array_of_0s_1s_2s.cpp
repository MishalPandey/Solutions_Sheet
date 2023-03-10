// Solution 1
class Solution {
public:
    void sortColors(vector<int>& nums) {

          int n= nums.size();
          int count_0=0, count_1=0, count_2=0;

          for(int i=0; i<n; i++)
          {
                if(nums[i]==0){
                    count_0++;
                }
                else if(nums[i]==1){
                    count_1++;
                }
                else{
                    count_2++;
                }
          }
          for(int i=0; i<n; i++)
          {
                if(count_0>0){
                    nums[i]=0;
                    count_0--;
                }
                else if(count_1>0){
                    nums[i]=1;
                    count_1--;
                }
                else{
                    nums[i]=2;

                }
          }


        
    }
};
