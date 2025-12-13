class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        std::vector<int> validCouponIds;
        std::unordered_set<std::string> validBusiness = {"electronics", "grocery", "pharmacy", "restaurant"};
        int n = static_cast<signed int>(code.size());
        for(int i=0;i<n;i++){
            if(code[i].empty()) continue;
            bool checkAlphanum = true;
            for(char c:code[i]){
                if(isalnum(c) || c=='_'){
                    continue;
                }
                else{
                    checkAlphanum = false;
                }
            }
            if(checkAlphanum && isActive[i] && validBusiness.count(businessLine[i])!=0){
                validCouponIds.push_back(i);
            }
        }

        sort(validCouponIds.begin(), validCouponIds.end(), [&businessLine, &code](int id1, int id2){
            if(businessLine[id1]==businessLine[id2]) return code[id1]<code[id2];
            if(businessLine[id1]=="electronics" || businessLine[id2]=="electronics"){
                return businessLine[id1]=="electronics";
            }
            else if(businessLine[id1]=="grocery" || businessLine[id2]=="grocery"){
                return businessLine[id1]=="grocery";
            }
            else if(businessLine[id1]=="pharmacy" || businessLine[id2]=="pharmacy"){
                return businessLine[id1]=="pharmacy";
            }
            else{
                return businessLine[id1]=="restaurant";
            }
        });

        std::vector<string> validCoupon; //Output
        for(int id:validCouponIds){
            validCoupon.push_back(code[id]);
        }
        return validCoupon;
    }
};