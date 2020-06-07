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

    int T;
    cin >> T;
    while (T--){
        ll a, b;
        cin >> a >> b;
        ll maxNumb = max(a,b);
        ll minNumb = min(a,b);
        if (maxNumb % minNumb != 0){
            cout << "-1\n";
            continue;
        }
        ll division = maxNumb / minNumb;
        if (ceil(log2(division)) != floor(log2(division))){
            cout << "-1\n";
            continue;
        }

        ll pow = (ll)log2(division);
        int ans = 0;
        ans += pow / 3;
        pow%=3;
        ans += pow / 2;
        pow%=2;
        ans += pow;
        cout << ans << "\n";
    }

    return 0;
}
