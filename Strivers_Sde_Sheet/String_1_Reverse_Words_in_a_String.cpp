// Solution 1 T.C{O(n)} , S.C{O(n)}

class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();
        vector<string> vs;
        string temp="";
        for(int i=0; i < n; i++)
        {
            if(s[i]==' ')
            {
                if(temp.size()>0)
                {
                    vs.push_back(temp);
                }
                temp="";
                
            }
            else{
                temp += s[i];

            }
           
        }
        if(temp!= "")
        {
            vs.push_back(temp);
        }
        int m = vs.size();

        for(int i=0; i< m/2; i++)
        {
            swap(vs[i], vs[m-1-i]);

        }
        s="";
        for(int i=0; i<m-1; i++)
        {
            s+= vs[i]+" ";

        }
        s+= vs[m-1];
        

        return s;
        
    }
};


//Solution 2---optimum T.C{O(n)} , S.C{O(1)}

//jitni space delete kar rhe utani hi le rahe

class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();
        string temp="";
        int i = n-1;
        string s1="";
        while(n--)
        {
            if(s[i]==' ')
            {
                if(temp.size()>0)
                {
                    if(s1=="") s1= s1 + temp;
                    else s1= s1 + " " + temp;
                    i= s.size() -1;
                }
                temp="";
                
                
            }
            else{
                temp = s[i] + temp;

            }
            s.pop_back();
            i--;
           
        }
        if(temp!= "")
        {
            if(s1=="") s1= s1 + temp;
             else s1= s1 + " " + temp;
        }
        s.pop_back();
        
        return s1;
        
    }
};


