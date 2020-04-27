#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        bool hasPair = n%2!=0;
        bool hasOdd = false;
        for (int i = 0; i < n; i++){
            int act;
            cin >> act;
            hasOdd |= act % 2 != 0;
            hasPair |= act % 2 == 0;
        }
        if (hasOdd && hasPair)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
