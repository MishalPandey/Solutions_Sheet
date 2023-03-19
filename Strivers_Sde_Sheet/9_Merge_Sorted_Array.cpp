//Solution 1----> T.C{O(n*m)} S.C{O(1)}
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=n;
        while(k--)
        {
            nums1.pop_back();
        }
        
        if(n==0){
            return;
        }
        int i=0;
        while(i<m)
        {
           if(nums1[i]>nums2[0])
           {
               swap(nums1[i], nums2[0]);
               for(int j=0; j<n-1; j++)
                {
                    if(nums2[j]> nums2[j+1])
                    {
                        swap(nums2[j], nums2[j+1]);
                    }
                    
                }
           }
           i++;
           
           
       }
       for(int i=0; i<n; i++)
       {
           nums1.push_back(nums2[i]);
       }
        
    }
};
