class Solution {
public:
    int findMaxArea(vector<int>& hist){
        stack<int> st;
        vector<int> prev(hist.size(), -1);
        vector<int> next(hist.size(), hist.size());
        int maxArea=0;
        for(int i=0;i<hist.size();i++){
            while(!st.empty() && hist[st.top()]>=hist[i]){
                next[st.top()]=i;
                st.pop();
            }
            if(!st.empty()) prev[i] = st.top();
            st.push(i);
        }
        for(int i=0;i<hist.size();i++){
            maxArea = max(maxArea, (next[i]-prev[i]-1)*hist[i]);
        }
        
        return maxArea;


    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<int> currHist(matrix[0].size(), 0);
        for(int i=0; i<matrix.size(); i++){
            for(int j =0; j<matrix[0].size();j++){
                if(matrix[i][j]=='0') currHist[j]=0;
                else currHist[j]++;
            }
            ans = max(ans, findMaxArea(currHist));
        }
        return ans;
    }
};