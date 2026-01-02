class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            int temp=digits[i]+carry;
            ans.push_back(temp%10);
            carry=temp/10;
        }
        if(carry==1) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};