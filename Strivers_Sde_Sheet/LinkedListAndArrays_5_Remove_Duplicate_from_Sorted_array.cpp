//Solution 1 ---T.C{O(n)}, S.C{O(n)}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        set<int>s;
        for(int i=0; i<n; i++)
        {
            s.insert(nums[i]);
        }
        int k= s.size();
        int i=0;
        for(auto it: s)
        {
            nums[i]= it;
            i++;
        }
        return k;
        
        
    }
};


//Solution 2----T.C{O(n)},  S.C{O(1)}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();

        int k=1;
        int curr_val= nums[0];
        int j=1;
        for(int i=1; i<n; i++)
        {
            if(curr_val!=nums[i])
            {
                nums[j]=nums[i];
                curr_val= nums[i];
                j++;
                k++;
            }
            

        }
        return k;
        
        
        
    }
};
