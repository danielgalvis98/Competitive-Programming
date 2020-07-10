#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int t;
    cin >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        if (a < b)
            swap(a,b);
        int dif = a - b;
        if (dif >= b){
            cout << b << "\n";
            continue;
        }
        ll ans = dif;
        a -= 2*dif;
        ans += 2l*(a / 3);
        if (a % 3 == 2)
            ans++;

        cout << ans << "\n";
    }

    return 0;
}
