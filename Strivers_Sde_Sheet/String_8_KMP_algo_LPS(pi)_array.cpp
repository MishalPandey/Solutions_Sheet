//Knuth-Morris-Pratt KMP String Matching Algorithm
//for problems like --- String_7_Find_the_Index_of_the_First_Occurrence_in_a_String.cpp

//link --- algorithm---(https://youtu.be/V5-7GzOfADQ)

//Solution 1 --T.C{O(n+m)}, S.C{O(n)}



class Solution {
    
public:
    int strStr(string haystack, string needle) {  

        int ss = needle.size();
        int ls = haystack.size();

        if(ss > ls) return -1;

        //longest prefix suffix
        int len=0;
        int lps[ss];
        lps[0]=0;

        int i=1;
        while(i < ss)
        {
                if(needle[i]== needle[len])
                {
                    len++;
                    lps[i]=len;
                    i++;
                }
                else
                {
                        // This is tricky. Consider the example.
                        // AAACAAAA and i = 7. The idea is similar
                        // to search step.
                        if (len != 0) {
                            len = lps[len - 1];
            
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


        i = 0; // index for haystack[]
        int j = 0; // index for needle[]
        while ((ls - i) >= (ss - j)) {
                if (needle[j] == haystack[i]) {
                    j++;
                    i++;
                }

                if (j == ss) {
                    printf("Found pattern at index %d ", i - j);
                    j = lps[j - 1];
                    return i - ss;
                }

                // mismatch after j matches
                else if (i < ls && needle[j] != haystack[i]) {
                    // Do not match lps[0..lps[j-1]] characters,
                    // they will match anyway
                    if (j != 0)
                        j = lps[j - 1];
                    else
                        i = i + 1;
                }
        }



        

        

        return -1;
        
    }
    
    
};
