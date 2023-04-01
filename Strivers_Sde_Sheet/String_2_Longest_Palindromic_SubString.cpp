// Solution 1 ---//T.C{O(n*n)} , S.C{O(1)}

class Solution {
public:
    int expandFromCentre(string s, int i, int j)
    {

            int n= s.size();
            int length=0;
            if(i==j) length=-1;
            while(i>=0 && j<n )
            {
                    if(s[i]!= s[j])
                    {
                        return length;
                    }
                    i--;
                    j++;
                    length+=2;
            }

            return length;
        
    }

    
    string longestPalindrome(string s) {

        int n = s.size();
        int idxs=0, idxe=0;
        for(int i=0; i<n; i++)
        {
            int length1 = expandFromCentre(s, i, i);// when one centre aba type palindrome
            int length2 = expandFromCentre(s, i, i+1);// when two centre abba type palindrome

            int ans_len = max(length1, length2);
            if(idxe - idxs + 1 < ans_len)
            {
                idxs = i - (ans_len -1 )/2;
                idxe = i + ans_len/2 ;       
            }
            
            
        }

        string ans_st;
        ans_st = s.substr(idxs, idxe - idxs + 1);

        return ans_st; 
        
    }
};
