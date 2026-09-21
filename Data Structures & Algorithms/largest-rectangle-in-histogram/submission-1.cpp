class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int area=0;
        int maxArea=0;
        int n=heights.size();
        
        for(int i=0;i<n;i++){
            while(!s.empty()&&heights[i]<heights[s.top()]){
                int top_high=heights[s.top()];
                s.pop();
                if(s.empty()){
                    area=i*top_high;
                }

                else area=(i-s.top()-1)*top_high;
                maxArea=max(maxArea, area);
            }
            s.push(i);

        } 
        while(!s.empty()){
            int top_high=heights[s.top()];
            s.pop();
            if(s.empty()){
                area=n*top_high;
            }
            else area=(n-s.top()-1)*top_high;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
