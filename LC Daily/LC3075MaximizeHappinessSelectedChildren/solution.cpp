class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        int decrementCounter = 0;
        long long totalSum = 0;
        for(int i=0; i<k;i++){
            happiness[i]-=decrementCounter;
            if(happiness[i]>0){
                totalSum+=happiness[i];
                decrementCounter++;
            }
            else{break;}
        }
        return totalSum;
    }
};