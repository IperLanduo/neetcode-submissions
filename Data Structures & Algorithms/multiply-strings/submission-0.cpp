class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";

        int m=num1.size(), n=num2.size();
        vector<int> ans(m+n,0);
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int sum=mul + ans[i+j+1];
                ans[i+j+1]=sum%10;
                ans[i+j] += sum/10;  // carry

            }
        }


        string res;
        int i=0;
        // 去掉前導零
        while(i<ans.size() && ans[i]==0) i++;
        for(;i<ans.size();i++) res += (ans[i]+'0');
        
        return res;

    }
};