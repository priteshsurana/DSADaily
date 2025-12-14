class Solution {
public:
    const int mod = 1'000'000'007;
    int n=0;
    int numberOfWays(string corridor) {
        n = static_cast<int>(corridor.size());
        int previousSIndex = -1;
        long ans = 1;
        int countS=0;

        for(int i=0;i<n;i++){
            if(corridor[i]=='S'){
                if(countS%2==1){
                    previousSIndex = i;
                }
                else if(countS>1){
                    long temp = i-previousSIndex;
                    ans = i>previousSIndex+1?(ans*(temp%mod))%mod:ans;
                }
                countS++;
            }
        }
        return (countS%2==1 || countS==0)?0:ans;

    }
};