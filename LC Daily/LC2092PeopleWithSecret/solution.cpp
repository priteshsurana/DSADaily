class Solution {
public:
    void processNodes(int index, unordered_set<int>& visited, unordered_map<int, vector<int>>& personPairs, unordered_set<int>& secretPerson){
        visited.insert(index);
        secretPerson.insert(index);
        if(personPairs.count(index)>0){
            for(auto v:personPairs[index]){
                secretPerson.insert(v);
                if(visited.count(v)==0) processNodes(v, visited, personPairs, secretPerson);
            }
        }

    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        std::set<int> time;
        std::unordered_set<int> secretPerson;
        secretPerson.insert(0);
        secretPerson.insert(firstPerson);
        
        unordered_map<int, unordered_map<int, vector<int>>> sameTimeNodes;
        unordered_map<int, unordered_set<int>> personAtThatTime;
        for(auto v:meetings){
            sameTimeNodes[v[2]][v[1]].push_back(v[0]);
            sameTimeNodes[v[2]][v[0]].push_back(v[1]);
            time.insert(v[2]);
            personAtThatTime[v[2]].insert(v[0]);
            personAtThatTime[v[2]].insert(v[1]);
        }

        for(auto t:time){
            unordered_set<int> visited;
            for(auto i:personAtThatTime[t]){
                if(visited.count(i)==0 && sameTimeNodes[t].count(i)>0 && secretPerson.count(i)>0){
                    processNodes(i, visited, sameTimeNodes[t], secretPerson);
                }
            }
        }

        return std::vector<int>(secretPerson.begin(), secretPerson.end());

    }
};