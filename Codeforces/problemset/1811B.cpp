// #include <bits/stdc++.h>

// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);cin.tie(0);
//     int testcase;cin>>testcase;
//     while(testcase--){
//         int n;cin>>n;
//         int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;

        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);

        if (dx == 0 && dy == 0) {
            cout << 0 << endl;
            continue;
        }

        int layer1 = max(x1, max(y1, max(n - x1 + 1, n - y1 + 1)));
        int layer2 = max(x2, max(y2, max(n - x2 + 1, n - y2 + 1)));

        if (layer1 != layer2) {
            cout << dx + dy << endl;
            continue;
        }

        int cycle = 2 * (n - 2 * (layer1 - 1));
        int pos1 = ((x1 - 1) + (y1 - 1)) % cycle;
        int pos2 = ((x2 - 1) + (y2 - 1)) % cycle;

        int dist = abs(pos2 - pos1);
        dist = min(dist, cycle - dist);

        cout << dx + dy + dist / 2 << endl;
    }

    return 0;
}
