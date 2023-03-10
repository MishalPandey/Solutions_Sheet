// Solution 1 --T.C(O(N+ N)) , S.C(O(1))
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


//Solution 2 -- DUTCH NATIONAL FLAG ALGORITHM { T.C(O(N)) , S.C(O(1))  }
// Optimum Solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0; // pointing to (1st One), always so that we can swap it with zero when mid is pointing to zero. --->initially pointing 0th index
        int hi = nums.size() - 1;  // pointing to before index from (1st Two element)  always so that we can swap it with two when mid is pointing to two --->initially pointing last index
        int mid = 0; // It will move next index when it is pointing the value which has value equal to One.

        while (mid <= hi) { 
            switch (nums[mid]) { 

            // If the element is 0 
            case 0: 
                swap(nums[lo++], nums[mid++]); 
                break; 

            // If the element is 1 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[hi--]); 
                break; 
            }
        }
         
    }
};
