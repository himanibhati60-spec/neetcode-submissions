class Solution {
public:
    vector<int> minInterval(vector<vector<int>> & intervals, vector<int>& queries) {
        vector<int> res;
        for(int q: queries){
            int curr = -1;
            for(auto& interval : intervals){
                int l = interval[0], r = interval[1];
                if(l <= q && q <= r){
                    if(curr == -1 || (r-l+1) < curr){
                        curr = r-l+1;
                    }
                }
            }
            res.push_back(curr);
        }
        return res;
    }
};
