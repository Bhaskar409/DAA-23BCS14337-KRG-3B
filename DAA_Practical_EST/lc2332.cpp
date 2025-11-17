#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int latestTimeCatchBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        
        unordered_set<int> passSet(passengers.begin(), passengers.end());

        int j = 0;                     
        int n = passengers.size();
        int lastCount = 0;            
        int lastPassengerTime = -1;    
        
        for (int bus : buses) {
            int count = 0;
            while (j < n && passengers[j] <= bus && count < capacity) {
                lastPassengerTime = passengers[j];
                j++;
                count++;
            }
            lastCount = count;
        }

       
        int candidate;
        
        if (lastCount < capacity) {
            // Case A: last bus not full
            candidate = buses.back();
        } else {
            // Case B: last bus full
            candidate = lastPassengerTime - 1;
        }

       
        while (passSet.count(candidate)) {
            candidate--;
        }

        return candidate;
    }
};
