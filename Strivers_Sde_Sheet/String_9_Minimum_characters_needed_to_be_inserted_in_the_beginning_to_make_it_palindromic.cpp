//Solution 1---T.C{O(n^2)}, S.C{O(1)}

int palin_max(string s)
{
        int n = s.size();
        int i=0, j= n-1;
        int ans=0;
        int flag =0;
        int prev=n-1;
        while(i<j)
        {
              if(s[i]!=s[j] )
              {
                    if(flag==1)
                    {
                          j = prev-1;
                    }
                    else
                    {
                          j--;
                    }
                    ans++;
                    i=0;
                    flag=0;

              }
              else{
                    if(flag==0)
                    {
                          prev = j;

                    }
                    i++;
                    j--;
                    flag=1;

          }

          if(i>=j && flag)
          {
                return ans;

          }
        }

        return n -1;
}


int minCharsforPalindrome(string str) {
	
	int n= str.size();
	if(n==1)
		return 0;
	
	int ans= palin_max(str);
	
	
	return ans;

   
	
	
}

