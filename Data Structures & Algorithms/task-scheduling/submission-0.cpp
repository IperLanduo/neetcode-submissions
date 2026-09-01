class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        priority_queue<int>q;
        for(int i=0;i<tasks.size();i++){
            v[tasks[i]-'A']++;
        }
        
        for(int i=0;i<26;i++){
            if(v[i]>0)q.push(v[i]);
        }

        queue<pair<int,int>> wait_q;
        
        int time=0;//模擬時間
        
        while(!q.empty()||!wait_q.empty()){
            time++;
            
            if(!q.empty()){
                int count = q.top()-1;
                q.pop();
                if(count>0){
                    wait_q.push({count, time + n});
                }
            }
            if(!wait_q.empty()&&wait_q.front().second==time){
                q.push(wait_q.front().first);
                wait_q.pop();
            }
        }
        return time;

    }
};
