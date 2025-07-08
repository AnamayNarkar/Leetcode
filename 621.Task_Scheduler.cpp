#include<bits/stdc++.h>
using namesoace std;

class Solution {
private:
priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
queue<pair<int,char>>q;
unordered_map<char,int>map;

public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // ingest tasks

        for(char c: tasks){
            map[c]++;
        }

        for (auto& entry : map) {
            pq.push({entry.second, entry.first});
        }

        // process tasks

        int time = 0;

        while(!pq.empty() || !q.empty()){
            
            if(!pq.empty()){
                pair<int,char> currPair = pq.top();
                pq.pop();
                map[currPair.second]--;

                if(map[currPair.second]>0){ // if the current task wasn't the last of his name
                    q.push(make_pair(time+n,currPair.second));
                }
            }

            // empty the waitlist of the tasks whose time is up and push them into the heap
            while(!q.empty() && q.front().first <= time ){
                pq.push(make_pair(map[q.front().second],q.front().second));
                q.pop();
            }
            time++;
        }

        return time;

    }
};

