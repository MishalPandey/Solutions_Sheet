// code when Revise String ------USED KMP Algorithm concept longest prefix sum


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





//Solution 2 -----T.C{O(n)},  S.C{O(n)} --------------USING KMP algorithm, String_8_KMP algo / LPS(pi) array question




// C++ program for getting minimum character to be
// added at front to make string palindrome
#include <bits/stdc++.h>
using namespace std;
 
// returns vector lps for given string str
vector<int> computeLPSArray(string str)
{
    int M = str.length();
    vector<int> lps(M);
 
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (str[i] != str[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
 
// Method returns minimum character to be added at
// front to make string palindrome
int getMinCharToAddedToMakeStringPalin(string str)
{
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
 
    // Get concatenation of string, special character
    // and reverse string
    string concat = str + "$" + revStr;
 
    //  Get LPS array of this concatenated string
    vector<int> lps = computeLPSArray(concat);
 
    // By subtracting last entry of lps vector from
    // string length, we will get our result
    return (str.length() - lps.back());
}
 
// Driver program to test above functions
int main()
{
    string str = "AACECAAAA";
    cout << getMinCharToAddedToMakeStringPalin(str);
    return 0;
}

