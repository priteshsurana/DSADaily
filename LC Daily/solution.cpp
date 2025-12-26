class Solution {
public:
    int bestClosingTime(string customers) {
        int n =customers.size();
        vector<int> yPrefix(n+1,0);
        for(int i=n-1; i>=0; i--){
            yPrefix[i]=yPrefix[i+1]+(customers[i]=='Y'?1:0);
            
        }
        int mini=INT_MAX;
        int ans=0;
        int  NCount=0;
        for(int i=0; i<n;i++){
            if(yPrefix[i]+NCount<mini){
                mini=yPrefix[i]+NCount;
                ans=i;
            }
            NCount+=(customers[i]=='N'?1:0);
        }
        if( yPrefix[n]+NCount<mini) ans=n;
        //ans=min(ans, NCount+yPrefix[n]);
        return ans;
    }
};