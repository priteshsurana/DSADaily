class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple = std::accumulate(apple.begin(), apple.end(),0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        int boxes = 0;
        if(totalApple==0) return 0;
        for(int i:capacity){
            totalApple-=i;
            boxes+=1;
            if(totalApple<=0) return boxes;
        }
        return boxes;
    }
};