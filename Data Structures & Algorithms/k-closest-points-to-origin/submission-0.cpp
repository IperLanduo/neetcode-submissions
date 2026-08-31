class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> q;
        vector<vector<int>> ans;
        for(int i=0;i<points.size();i++){
            pair<int,int> tmp;
            int dis = points[i][0]* points[i][0]+ points[i][1]* points[i][1];
            tmp={dis,i};
            q.push(tmp);
            if(q.size()>k){
                q.pop();
            }
        }

        while(!q.empty()){
            int idx = q.top().second;
            ans.push_back({points[idx][0], points[idx][1]});
            q.pop(); 
        }
        return  ans;
    }
};
