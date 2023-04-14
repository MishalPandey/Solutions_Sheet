//Rabin-Karp String Matching Algorithm
//for problems like --- String_7_Find_the_Index_of_the_First_Occurrence_in_a_String.cpp
//link------approach------   (https://youtu.be/qQ8vS2btsxI)

//Solution--- T.C{O(n + m)},  S.C{O(1)} 
// worst T.C {O(n*m)} ---jab hash function bekaar ho bahut jada 

class Solution {
    
public:
    int strStr(string haystack, string needle) {

        

        int ss = needle.size();
        int ls = haystack.size();

        if(ss > ls) return -1;
        

        //Hash function --yeh jitna tagra utane kam string check operation honge
        int prime = 119;
        int BASE = 1000000;
        int val =0;
        for(int i=0; i <ss ; i++)
        {
            val = (val + ((needle[i] - 'a' + 1)*1LL*prime)%BASE ) % BASE;

        }


        int ans_val = 0;
        for(int i=0; i < ss; i++)
        {
            ans_val = (ans_val + ((haystack[i] - 'a' + 1)*1LL*prime)%BASE ) % BASE;

        }
        

        int j=0;
        for(int i=ss-1; i <= ls; i++)
        {
            if(i==ss-1 || i==ls || ans_val == val)
            {
               
                if(needle == haystack.substr(j, ss))
                {
                    return j;
                }
                else if( i!= ss-1 && ans_val == val)
                {
                    ans_val = (ans_val - ((haystack[j] - 'a' + 1)*1LL*prime)%BASE ) % BASE;
                    j++;
                    ans_val = (ans_val + ((haystack[i] - 'a' + 1)*1LL*prime)%BASE ) % BASE;

                }
                
                
            }
            else {
                ans_val = (ans_val - ((haystack[j] - 'a' + 1)*1LL*prime)%BASE ) % BASE;
                j++;
                ans_val = (ans_val + ((haystack[i] - 'a' + 1)*1LL*prime)%BASE ) % BASE;
            }
            

        }

        return -1;






        
    }
    
    
};
