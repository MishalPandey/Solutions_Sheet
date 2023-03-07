//Solution 1 (Upper bound only works for sorted Array/Vec/Set...)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {


            int n= nums.size();
            int flag=1;

            for(int i=0; i<n-1; i++)
            {
                if(nums[i]<nums[i+1])
                {
                    flag=0;
                }
            }


            if(flag)
            {
                reverse(nums.begin(), nums.end());

            }
            else{

                    for(int i=n-1; i>=1; i--)
                    {
                            if(nums[i]>nums[i-1])
                            {
                                sort(nums.begin()+ i, nums.end());
                                
                                auto it=  upper_bound(nums.begin()+ i, nums.end(), nums[i-1]);
                                int x = it - nums.begin();
                                swap(nums[i-1], nums[x]);
                                break;
                                
                            }
                    }



            }

        
    }
};
