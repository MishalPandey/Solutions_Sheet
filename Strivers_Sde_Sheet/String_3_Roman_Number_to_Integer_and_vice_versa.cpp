//Solution 1---T.C{o(n^2)} , S.C{O(1)}



class Solution {
public:
    int romanToInt(string s) {

        map<string, int>m;
        m["I"] = 1, m["V"] = 5, m["X"] =10, m["L"] = 50, m["C"] = 100, m["D"] =500, m["M"] = 1000;
        m["IV"] = 4, m["IX"] = 9, m["XL"] =40, m["XC"] = 90, m["CD"] = 400, m["CM"] = 900;
        int n= s.size();

        int ans=0;
        for(int i=0; i<n; i++)
        {
            
            if(i+1<n)
            {
                string temp= "";
                temp = s.substr(i, 2);
                // cout<<temp<<endl;
                if(m.find(temp) != m.end())
                {
                    ans+= m[temp];
                    i++;
                }
                else{
                    string temp = "";
                    temp+=s[i];
                    ans+=m[temp];
                        
                    

                }

            }
            else 
            {
                string temp = "";
                temp+=s[i];
                ans+=m[temp];

            }
            
        }
        return ans;
        
    }
};
