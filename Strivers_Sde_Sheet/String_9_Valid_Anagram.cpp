//Solution 1----T.C{O(n)}, S.C{O(n)}
class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char>ss, st;
        int n= s.size();
        int m = t.size();

        for(int i=0; i<n; i++)
        {
            ss.insert(s[i]);
        }
        for(int i=0; i<m; i++)
        {
            st.insert(t[i]);
        }

        if(ss == st)
        {
            return true;
        }

        return false;
        
    }
};


//Solution 2---T.C{O(nlogn)}, S.C{O(1)}
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n= s.size();
        int m = t.size();
        if(n!= m) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i=0; i<n; i++)
        {
            if(s[i]!=t[i]) return false;
        }
        

        return true;
        
    }
};
