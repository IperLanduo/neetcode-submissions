class CountSquares {
public:
    vector<vector<int>>v;
    int freq[1001][1001]={0};

    CountSquares() {
       
    }
    
    void add(vector<int> point) {
        v.push_back(point);
        freq[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int ans=0;
        int px=point[0];
        int py=point[1];

        for(const auto&p:v){
            int qx=p[0];
            int qy=p[1];

            if(qx==px||qy==py)continue;
            if(abs(qx-px)!=abs(qy-py))continue;

            int x1 = qx;
            int x2 = px;
            int y1 = qy;
            int y2 = py;
            ans+=freq[x1][y2]*freq[x2][y1];

        }

        return ans;

    }
}; 
