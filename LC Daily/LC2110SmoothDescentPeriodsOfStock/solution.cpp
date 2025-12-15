class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = static_cast<int>(prices.size());
        long long descentPeriod = n;
        int chainLength = 1;
        for(int i = 1;i<n;i++){
            if(prices[i]==prices[i-1]-1){
                descentPeriod+=chainLength;
                chainLength++;
            }
            else{
                //Reset chainLength
                chainLength = 1;
            }
        }
        return descentPeriod;
    }
};