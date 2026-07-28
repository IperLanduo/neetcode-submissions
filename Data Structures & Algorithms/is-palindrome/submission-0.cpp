class Solution {
public:
    bool isPalindrome(string s) {
        int p1=0;
        int p2=s.size()-1;
        
        while(p1<p2){
            while (p1 < p2 && !isalnum(s[p1])) p1++;
            while (p1 < p2 && !isalnum(s[p2])) p2--;
            
            if(toupper(s[p1])!=toupper(s[p2]))return false;
            p1++;
            p2--;

        }
        return true;

    }
};
