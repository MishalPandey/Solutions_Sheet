//Solution 1---(Recursive)---- T.C{O(n*n)}, S.C{O(n)}

class Solution {
public:

    string countAndSay(int n) {

        if(n==1) return "1";
        
        string smallans = countAndSay(n - 1);

        int x = smallans.size();
        string ans="";
        int i = 0;
        while(i < x)
        {

                int ct =1;
                string temp ="";
                while(i + 1 < x && smallans[i] == smallans[i+1])
                {
                        if(ct==1)  temp+= smallans[i];
                        ct++;
                        i++;
                }

                if(ct==1)   ans+= to_string(1)+ smallans[i];
                else    ans+= to_string(ct)+ temp;
                
                i++;

            
        }

        return ans;
        
    }
};

//Solution 2 (iterative) T.C{O(n*n)}, S.C{O(1)}




class Solution {
public:

    string countAndSay(int n) {

        string main_ans="1";
        n--;
        while(n--)
        {

                int x = main_ans.size();
                int i = 0;
                string ans="";
                while(i < x)
                {

                        int ct =1;
                        string temp ="";
                        while(i + 1 < x && main_ans[i] == main_ans[i+1])
                        {
                                if(ct==1)  temp+= main_ans[i];
                                ct++;
                                i++;
                        }

                        if(ct==1)   ans+= to_string(1)+ main_ans[i];
                        else    ans+= to_string(ct)+ temp;

                        i++;

                    
                }

                main_ans = ans;

                
        }

        return main_ans;
        
    }
};
