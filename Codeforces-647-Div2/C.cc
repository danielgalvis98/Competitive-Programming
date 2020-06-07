#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,end=b;i<end;i++)
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
        ll n;
        cin >> n;
        ll theLog = (ll)log2(n);
        ll ans = (theLog+1)*(theLog+2) / 2;
        fore(i,1,theLog)
            ans += i + 2*(i-1);

        ll dif = n - (ll) (pow(2l, theLog));
        ans += (ll)(ceil(dif/2.0)) + 2 * (dif/2l);
        cout << ans << "\n";
    }


    return 0;
}
