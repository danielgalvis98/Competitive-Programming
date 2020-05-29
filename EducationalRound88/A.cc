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
        int n, m, k;
        cin >> n >> m >> k;
        int cardsPerPlayer = n/k;
        int totPoints = min(m, cardsPerPlayer);
        m -= totPoints;
        int otherMax = ceil(m/double(k-1));
        int ans = totPoints - otherMax;
        cout << ans << "\n";
    }

    return 0;
}
