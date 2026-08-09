class KthLargest {
private:
    int m_k;
    vector<int>m_nums;
public:
    KthLargest(int k, vector<int>& nums) {
        m_k=k;
        m_nums=nums;
    }
    
    int add(int val) {
        m_nums.push_back(val);
        sort(m_nums.rbegin(),m_nums.rend());
        return m_nums[m_k-1];
    }
};
//5 3 3 2 1 

