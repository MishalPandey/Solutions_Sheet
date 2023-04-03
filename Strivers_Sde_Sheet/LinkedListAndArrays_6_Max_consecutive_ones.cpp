//Solution 1----T.C[O(n)},  S.C{O(1)}

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size();
        int ans_max =0;
        int temp_max =0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==1)
                temp_max++;
            else
                temp_max=0;
            if(ans_max < temp_max)
                ans_max = temp_max;
            

        }

        return ans_max;
    }
};
