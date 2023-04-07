//Solution 1---T.C{O(N*n)}, S.C{O(n)}

class Solution {
public:
    int strStr(string haystack, string needle) {

        int ans= -1;

        int s_h = haystack.size();
        int s_n = needle.size();

        for(int i=0; i<s_h; i++)
        {
            if(i+ s_n -1 < s_h)
            {
                string temp = haystack.substr(i, s_n);
                if(temp == needle)
                {
                    ans= i;
                    break;
                }

            }
        }

    return ans;


        
    }
};



//Solutiom 2-- optimum ---T.C{O(N*n)}, S.C{O(1)}


class Solution {
public:
    int strStr(string haystack, string needle) {

        int ans= -1;

        int s_h = haystack.size();
        int s_n = needle.size();
        int i=0;
        while(i < s_h)
        {
                if(i+ s_n - 1 < s_h)
                {
                        int t_ans = i;
                        int j=0;
                        int size=0;
                        while(i < s_h && j < s_n && haystack[i]==needle[j])
                        {
                            size++;
                            i++;
                            j++;
                        }
                        if(size == s_n)
                        {
                            ans= t_ans;
                            break;
                        }
                        else 
                        {
                            i = t_ans;
                            i++;
                        }

                }

                else
                {
                    break;
                }
        }

    return ans;


        
    }
};
