#include <bits/stdc++.h>

using namespace std;

struct person {
    string name;
    int priority;
};

struct cmp {
    bool operator() (const person &l, const person &r) const {
        return l.priority < r.priority;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    priority_queue<person, vector<person>, cmp> pq;
    string cmd;
    while(cin>>cmd) {
        if(cmd == "New") {
            person p;
            cin>>p.name>>p.priority;
            pq.push(p);
        } else if(cmd == "Call") {
            cout<<pq.top().name<<'\n';
            pq.pop();
        } else {
            break;
        }
    }
    return 0;
}