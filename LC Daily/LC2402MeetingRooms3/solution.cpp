class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n, 0);
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> activemeet;
        for(int i=0;i<n;i++) available.push(i);
        sort(meetings.begin(), meetings.end());
        for(auto meet:meetings){
            while(!activemeet.empty() && activemeet.top().first<=meet[0]){
                available.push(activemeet.top().second);
                activemeet.pop();
            }
            if(!available.empty()){
                activemeet.push({meet[1], available.top()});
                rooms[available.top()]++;
                available.pop();

            }
            else{
                int roomNo = activemeet.top().second;
                long long diff = activemeet.top().first-meet[0];
                activemeet.pop();
                rooms[roomNo]++;
                activemeet.push({(long long)meet[1]+diff, roomNo});
            }
        }
        int result =0;
        for(int i=0;i<n;i++){
            if(rooms[i]>rooms[result]) result = i;
        }
        return result;

    }
};