//Solution 1---T.C{O(N)} , S.C{O(1)}

class Solution {
public:
    int myAtoi(string s) {


        //triming front spaces
        int i=0;
        while(s[i]==' ')i++;
        
        //check if sigh present in string
        int sign=1;
        if(s[i]=='+' || s[i]=='-'){
            if(s[i]=='-') sign= -1;
            i++;
        }
        
        //initialize ans =0
        int ans=0;
        
        for(;i<s.size();i++){
            if(!isdigit(s[i])) return ans;
            int dig= (s[i]-'0')*sign;

            //IMPORTANTTTTTT---------------------------------------
			//very risky part (to handle overflows)
            if(sign== 1 && (ans> INT_MAX/10  || (ans==INT_MAX/10 && dig>(INT_MAX%10)))) return INT_MAX;
            if(sign== -1 && (ans< INT_MIN/10 || (ans==INT_MIN/10 && dig<(INT_MIN%10)))) return INT_MIN;
            // Value of INT_MAX is +2147483647.
            // Value of INT_MIN is -2147483648.    
            ans= (1LL*ans*10)+ dig;
        }
        return ans;

        
        
    }
};
