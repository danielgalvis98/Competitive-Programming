#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--){
        ll ans = 0;
        int initial = 0;
        cin >> initial;
        int rest = 0;
        while (initial != 0){
            initial += rest;
            rest = initial % 10;
            initial -= rest;
            ans += initial;
            initial /= 10;
        }
        ans += rest;
        cout << ans << "\n";
    }

    return 0;
}
