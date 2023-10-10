#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0 ; i <n; i++)
    {
        cin >> arr[i];
    }
    sort (arr, arr+n) ;
    for (int j = 0 ; j < m ; j++)
    {
        int c,cnt=0; //customer // count
        cin >> c;

        for (int i = 0 ; (i < n) && (c > arr[i]) ; i++)
        {
            c -= arr[i];
            cnt++;

            cout << cnt; if (i < m-1) cout << '\n';
        }
    }
}

// 5 1
// 5 1 4 3 2
// 5