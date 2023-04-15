//Knuth-Morris-Pratt KMP String Matching Algorithm
//for problems like --- String_7_Find_the_Index_of_the_First_Occurrence_in_a_String.cpp

//link --- algorithm---(https://youtu.be/V5-7GzOfADQ)

//Solution 1 --T.C{O(n+m)}, S.C{O(n)}

//code when revise strings



class Solution {
    
public:
    int strStr(string haystack, string needle) {  

                int ss = needle.size();
                int ls = haystack.size();

                if(ss > ls) return -1;

                //longest prefix suffix
                int lps[ss];
                lps[0]=0;

                int len = 0;

                int i=1;
                while(i<ss)
                {
                        if(needle[i]== needle[len])
                        {
                            len++;
                            lps[i] = len;
                            i++;

                        }
                        else //needle[i] != needle[len]
                        {
                                if(len !=0)
                                {
                                    //imp Note**********************************************
                                    len = lps[len - 1];
                                    
                                     //len= 0; wrong becz {needle ="aabaaac" } 
                                                                    0101210----wrong
                                                                    0101220-----right
                                       //simillarly for 
                                                        // {needle = "AAACAAAA" } 
                                                                      01201231----wrong
                                                                      01201233-----right
                                                            
                                }
                                else
                                {
                                    lps[i] =0;
                                    i++;
                                }

                        }
                }

                int j=0;
                i=0;
                while(i + (ss- j) <= ls)
                {
                        if(haystack[i]==needle[j])
                        {
                            i++;
                            j++;

                        }
                        else
                        {
                                if(j==0)
                                {
                                    i++;
                                }
                                else 
                                {   
                                    j =lps[j-1];
                                }


                        }

                        if(j==ss)
                        {

                            return (i-j);
                            //j = lps[j - 1]; 
                        }

                }

        return -1;

        
    }
    
    
};
