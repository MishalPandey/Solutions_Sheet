// Solution 1 ---> T.C{ O(n*n)) }

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int max_val=INT_MIN;
        for(int i=0; i<n; i++)
        {
            for(int j=i+ 1; j<n; j++)
            {
                if(prices[j] - prices[i]> max_val)
                {
                    max_val = prices[j] - prices[i];
                }
                
            }

        }

        

        if(max_val>0)
        {
            return max_val;
        }
        else{
            return 0;
        }
    }
};

// Solution 2 ---> T.C{ O(n) }

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int max_val=0;
        int min_val=INT_MAX;

        for (int i=0; i<n; i++) 
        {
                min_val = min(min_val, prices[i]);
                max_val = max(max_val, prices[i] - min_val);
        }
    
    return max_val;
    }
};
