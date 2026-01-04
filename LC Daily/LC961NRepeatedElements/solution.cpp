class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> history;
        for(int t:nums){
            if(history.count(t)) return t;
            history.insert(t);
        }
        return -1;
    }
};