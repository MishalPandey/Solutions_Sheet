// Solution1 
// Kadane’s Algorithm of Maximum sum of Subarray
// Kadane’s Algorithm is not valid for when all elements of array is negative
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        int flag =1, ans=INT_MIN;
        for(int i=0; i<n; i++)
        { 
            if(nums[i]>0){
                flag=0;
            }
            ans= max(ans, nums[i]);

        }
        if(flag)
        {
            return ans;
        }
        

        // Kadane’s Algorithm
        int maxsum=0, currsum=0;
        for(int i=0; i<n; i++)
        {
            currsum= currsum + nums[i];
            if(currsum> maxsum)
            {
                maxsum= currsum;
            }
            if(currsum<0){
                currsum=0;
                
            }

        }
        return maxsum;
        
    }
};
