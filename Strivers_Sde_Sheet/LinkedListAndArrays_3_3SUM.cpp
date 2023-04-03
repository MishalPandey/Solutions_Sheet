//Solution 1--- T.C{O(n*n/2)},  S.C{O(n)}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n= nums.size();
        set<vector<int>>sv;
        for(int i=0; i < n; i++)
        {
                    int tar= nums[i]* -1;
                    int x1= 0, x2= n-1;
                    while(x2 > x1)
                    {
                                if(x1!=i && x2!=i && nums[x1]+ nums[x2]< tar)
                                {
                                    x1++;
                                }
                                else if(x1!=i && x2!=i && nums[x1]+ nums[x2]> tar)
                                {
                                    x2--;
                                }
                                else if(x1!=i && x2!=i && nums[x1]+ nums[x2]== tar)
                                {
                                    vector<int>v;
                                    v.push_back(nums[x1]);
                                    v.push_back(nums[x2]);
                                    v.push_back(nums[i]);
                                    sort(v.begin(), v.end());
                                    sv.insert(v);
                                    // did mistate  becz of this point below
                                    int pre_x1_val=nums[x1]; 
                                    while(x1<n && pre_x1_val==nums[x1])
                                    {
                                        x1++;
                                    }
                                    int pre_x2_val=nums[x2]; 
                                    while(x2>=0 &&pre_x2_val==nums[x2])
                                    {
                                        x2--;
                                    }

                                    
                                }
                                else{
                                    if(x1==i)
                                    {
                                        x1++;
                                    }
                                    else{
                                        x2--;
                                    }
                                }



                    }


        }
        vector<vector<int>>ans;
        for(auto it: sv)
        {
            ans.push_back(it);

        }

        return ans;


        
    }
};




//Solution 2--- T.C{O(n*n/2)}, S.C{O(1)}


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n= nums.size();
        vector<vector<int>>ans;
        int i=0;
        while(i<n-2)
        {
                    int tar= nums[i]* -1;
                    int x1= i + 1, x2= n-1;
                    while(x2 > x1)
                    {
                                if(x1!=i && x2!=i && nums[x1]+ nums[x2]< tar)
                                {
                                    x1++;
                                }
                                else if(x1!=i && x2!=i && nums[x1]+ nums[x2]> tar)
                                {
                                    x2--;
                                }
                                else if(x1!=i && x2!=i && nums[x1]+ nums[x2]== tar)
                                {
                                    vector<int>v;
                                    v.push_back(nums[x1]);
                                    v.push_back(nums[x2]);
                                    v.push_back(nums[i]);
                                    sort(v.begin(), v.end());
                                    ans.push_back(v);
                                    // did mistate  becz of this point below
                                    int pre_x1_val=nums[x1]; 
                                    while(x1<n && pre_x1_val==nums[x1])
                                    {
                                        x1++;
                                    }
                                    int pre_x2_val=nums[x2]; 
                                    while(x2>=0 && pre_x2_val==nums[x2])
                                    {
                                        x2--;
                                    }

                                    
                                }
                                else{
                                    if(x1==i)
                                    {
                                        x1++;
                                    }
                                    else{
                                        x2--;
                                    }
                                }



                    }
                    int prev_i_val= nums[i];
                    while(i < n-2 && prev_i_val==nums[i])
                    {
                        i++;
                    }


        }
        

        return ans;


        
    }
};
