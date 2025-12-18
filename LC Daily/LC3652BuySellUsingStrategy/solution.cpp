class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long total=0;
        for(int i=0;i<prices.size();i++){
            total+=(prices[i]*strategy[i]);
        }
        long long maxi=total;
        long long temptotal =total;
        cout<<temptotal<<endl;
        for(int i=k/2;i<k;i++){
            temptotal-=(prices[i-k/2]*strategy[i-k/2]);
            temptotal-=(prices[i]*strategy[i]);
            temptotal+=prices[i];            
        }
        cout<<temptotal<<endl;
        maxi=max(maxi, temptotal);
        for(int i=k;i<prices.size();i++){
            temptotal-=(prices[i]*strategy[i]);
            temptotal+=prices[i]; 
            temptotal+=(prices[i-k]*strategy[i-k]);
            temptotal-=(prices[i-k/2]);
            maxi=max(maxi, temptotal);
        }
        return maxi;
    }
};