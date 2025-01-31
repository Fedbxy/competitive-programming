#include <bits/stdc++.h>

using namespace std;

struct Person {
    string name;
    int age, height, blood;
};

bool cmp(const Person &l, const Person &r) {
    if (l.blood == r.blood) {
        if (l.age == r.age) {
            if (l.height == r.height) return l.name < r.name;
            return l.height > r.height;
        }
        return l.age < r.age;
    }   
    return l.blood > r.blood;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<Person> a(n);
    for (auto &e: a) {
        cin >> e.name >> e.age >> e.height;
        string c; cin >> c;
        if (c == "B") e.blood = 3;
        else if (c == "A") e.blood = 2;
        else if (c == "O") e.blood = 1;
        else e.blood = 0;
    }
    
    sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < n; ++i) cout << i + 1 << ". " << a[i].name << '\n';
    return 0;
}