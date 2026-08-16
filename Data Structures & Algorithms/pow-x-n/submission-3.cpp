class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; 
        
        // 如果次方是負數，將 x 變成倒數，並把 N 轉為正數
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1.0;
        double current_product = x;
        
        while (N > 0) {
           
            if (N % 2 == 1) {
                ans *= current_product;
            }
            current_product *= current_product;
            N /= 2;
        }
        
        return ans;
    }
};