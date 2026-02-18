class Solution {

    const bool checkHourValidity(const string hr){
        return hr[0]=='0' || hr[1]=='0';
    }
    const bool checkMinuteValidity(const string min){
        return min[0]=='0' || min[1]=='0' || min[2]=='0' || min[3]=='0';
    }
    const string hourVal(const string hr){
        int val = 0;
        if(hr[0]=='1') val+=8;
        if(hr[1]=='1') val+=4;
        if(hr[2]=='1') val+=2;
        if(hr[3]=='1') val+=1;
        return to_string(val);
    }

    const string minVal(const string hr){
        int val = 0;
        if(hr[0]=='1') val+=32;
        if(hr[1]=='1') val+=16;
        if(hr[2]=='1') val+=8;
        if(hr[3]=='1') val+=4;
        if(hr[4]=='1') val+=2;
        if(hr[5]=='1') val+=1;
        if(val<10) return to_string(0)+to_string(val);
        return to_string(val);
    }
public:
    void recurse(string h, string m,
             int hindex, int mindex,
             int unused,
             vector<string>& ans) {

        if (unused == 0) {
            if (checkHourValidity(h) && checkMinuteValidity(m)) {
                ans.push_back(hourVal(h) + ":" + minVal(m));
            }
            return;
        }

    // First handle hour LEDs completely
        if (hindex < 4) {
            // Turn on
            h[hindex] = '1';
            recurse(h, m, hindex + 1, mindex, unused - 1, ans);

            // Turn off
            h[hindex] = '0';
            recurse(h, m, hindex + 1, mindex, unused, ans);
        }
        else if (mindex < 6) {
            // Now handle minute LEDs

            // Turn on
            m[mindex] = '1';
            recurse(h, m, hindex, mindex + 1, unused - 1, ans);

            // Turn off
            m[mindex] = '0';
            recurse(h, m, hindex, mindex + 1, unused, ans);
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        if(turnedOn>=9) return ans;
        recurse("0000", "000000", 0, 0, turnedOn, ans);
        return ans;
    }
};