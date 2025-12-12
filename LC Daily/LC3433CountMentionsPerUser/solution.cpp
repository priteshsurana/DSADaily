class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        //sort events based on timestamp. Prioritize OFFLINE event over MESSAGE if timestamp is equal
        sort(events.begin(), events.end(),
            [](const vector<string>& a, const vector<string>& b) {
                int ta = stoi(a[1]);
                int tb = stoi(b[1]);
                if (ta != tb)
                    return ta < tb;
                // OFFLINE FIRST
                if (a[0] != b[0])
                    return a[0] == "OFFLINE";
                // final stable tie-breaker (just to satisfy strict weak ordering)
                return a[2] < b[2];
            }
        );

        vector<bool> isonline(numberOfUsers, true); //Actively keep track of which events are online
        vector<int> mentionCount(numberOfUsers, 0); //Output
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> offlineUsers;

        int trackAll = 0; //For mentionstring ALL keep a track of count and add at the end of processing

        for (auto& v : events) {
            string type = v[0];
            int time = stoi(v[1]);
            if (type == "MESSAGE") {
                while (!offlineUsers.empty() &&
                       offlineUsers.top().first + 60 <= time)
                {
                    isonline[offlineUsers.top().second] = true;
                    offlineUsers.pop();
                }
                // ALL
                if (v[2] == "ALL") {
                    trackAll++;
                }
                // HERE
                else if (v[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (isonline[i]) mentionCount[i]++;
                    }
                }
                // LIST like "id1 id4 id9"
                else {
                    stringstream ss(v[2]);
                    string token;

                    while (ss >> token) {
                        int num = stoi(token.substr(2));
                        mentionCount[num]++;
                    }
                }
            }
            else { // OFFLINE
                //Any user that has part offline time +60 is Online again
                while (!offlineUsers.empty() &&
                       offlineUsers.top().first + 60 <= time)
                {
                    isonline[offlineUsers.top().second] = true;
                    offlineUsers.pop();
                }

                int uid = stoi(v[2]);
                offlineUsers.push({ time, uid });
                isonline[uid] = false;
            }
        }

        //Add ALL tracking count to all users.
        for (int &c : mentionCount) {
            c += trackAll;
        }

        return mentionCount;
    }
};
