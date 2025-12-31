class Solution {
public:
    unordered_map<string, unordered_set<char>> allowedBases;
    bool backtrack(vector<vector<char>>& Layer){

        if(Layer.size()==1) return true;
        vector<vector<char>> baseLayer(Layer.size() - 1);
        for(int i=0; i<Layer.size()-1; i++){
            vector<char> temp;
            for(char first:Layer[i]){
                for(char second:Layer[i+1]){
                    string t;
                    t.push_back(first);
                    t.push_back(second);
                    if(allowedBases.count(t)!=0){
                        for(char c:allowedBases[t]){
                            temp.push_back(c);
                        }
                    }
                }
            }
            baseLayer[i]=temp;
        }
        if(baseLayer.size()!=0 && backtrack(baseLayer)) return true;
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<char>> baseLayer;
        for(string s:allowed){
            string key;
            key.push_back(s[0]);
            key.push_back(s[1]);
            allowedBases[key].insert(s[2]);
        }
        for(char c:bottom){
            vector<char> temp{c};
            baseLayer.push_back(temp);
        }
        return backtrack(baseLayer);

    }
};