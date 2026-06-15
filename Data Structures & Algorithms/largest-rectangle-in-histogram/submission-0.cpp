class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int maxArea = 0;
        stack<pair<int , int>> stack; //pair : (index, height)

        for(int i =0; i<height.size(); i++){
            int start = i;
            while(!stack.empty() && stack.top().second > height[i]){
                pair<int , int> top = stack.top();
                int index = top.first;
                int height = top.second;
                maxArea = max(maxArea, height*(i-index));
                start = index;
                stack.pop();
            }
            stack.push({start, height[i]});
        }
        while(!stack.empty()) {
            int index = stack.top().first;
            int h = stack.top().second;
            maxArea = max(maxArea, h * ((int)height.size() - index));
            stack.pop();
        }
        return maxArea;
    }
};
