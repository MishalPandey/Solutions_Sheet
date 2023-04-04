
//Solution 1 -----//T.C{O(3*n)} , S.C{O(2*n)}
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int ans = 0;
        int prefix_max [n];
        int suffix_max [n];

        prefix_max[0] = height[0];
        suffix_max[n-1] = height[n-1];
        for(int i=1; i<n; i++)
        {
            prefix_max[i] = max(prefix_max[i-1], height[i]);
        }
        for(int i=n-2; i>=0; i--)
        {
            suffix_max[i] = max(suffix_max[i+1], height[i]);
        }

        for(int i=0; i < n ; i++)
        {
            ans+=(min(prefix_max[i], suffix_max[i]) - height[i]);

        }

        return ans;
        
    }
};


//Solution2 ---optimum ------//T.C{O(n)} , S.C{O(1)}
//Two pointer (imp)
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int ans = 0;
        int left_max= height[0];
        int right_max= height[n-1];

        int left=0, right = n-1;

        while( left < right)
        {
            if(height[left] <= height[right])// yeh gurrenty deraha ki ko bara value aage hai
            {
                if(left_max > height[left])
                {
                    ans+= ( left_max - height[left] );
                }
                else{
                    left_max= height[left];
                }
                left++;
            }
            else
            {
                if(right_max > height[right])
                {
                    ans+= ( right_max - height[right] );
                }
                else{
                    right_max= height[right];
                }
                right--;

            }

        }

        return ans;
        
    }
};
