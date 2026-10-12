#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int l, r;
    bool operator<(const Interval& other) const {
        if (l != other.l) return l < other.l;
        return r < other.r;
    }
};

bool conflicts(const Interval& a, const Interval& b) {
    return max(a.l, b.l) <= min(a.r, b.r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    set<Interval> intervals;
    
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            
            Interval new_interval = {l, r};
            
            // Find all intervals that conflict with the new interval
            vector<Interval> to_delete;
            
            // Since intervals are sorted by start time, we can iterate through all intervals
            // and check for conflicts
            for (auto it = intervals.begin(); it != intervals.end(); ) {
                if (conflicts(*it, new_interval)) {
                    to_delete.push_back(*it);
                    it = intervals.erase(it);
                } else {
                    it++;
                }
            }
            
            // Add the new interval to the set
            intervals.insert(new_interval);
            
            cout << to_delete.size() << "\n";
            
        } else if (op == 'B') {
            cout << intervals.size() << "\n";
        }
    }
    
    return 0;
}