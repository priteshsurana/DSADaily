class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int noOfStrings = static_cast<int>(strs.size());
        int strLen = strs[0].size();
        int colDel=0;
        for(int i=0;i<strLen;i++){
            for(int j = 1;j<noOfStrings;j++){
                if(strs[j][i]<strs[j-1][i]){
                    colDel++;
                    break;
                }
            }
        }
        return colDel;
    }
};