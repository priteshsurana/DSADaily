class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int maxN = 0;
        int ans=0;
        for(int n:nums) maxN = max(maxN, n);
        unordered_map<int, int> counter;
        for(int n:nums) maxN = counter[n]+=1;
        unordered_map<int, unordered_set<int>> factors;
        for(auto t = counter.begin(); t!=counter.end();t++){
            int n = t->first;
            factors[n].insert(1);
            int last = n;
            int curr = 2;
            while(curr<last){
                if(n%curr==0){
                    factors[n].insert(curr);
                    factors[n].insert(n/curr);
                }
                last = n/curr;
                curr++;
            }
            factors[n].insert(n);
        }
        for(auto t = factors.begin(); t!=factors.end();t++){
            if(t->second.size()==4){
                int tempSum = accumulate(t->second.begin(), t->second.end(), 0);
                //cout<<tempSum<<endl;
                ans +=(tempSum*counter[t->first]);
            }
        }

        return ans;
    }
};