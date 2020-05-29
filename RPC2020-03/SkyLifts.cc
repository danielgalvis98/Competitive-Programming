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
    int n;
    cin >> n;

    vector<ii> ys (100005,{0,0});

    fore(i,0,n){
        int x, y, a;
        cin >> x >> y >> a;
        if (--a) ys[y].snd++;
        else ys[y].fst++;
    }

    int ans = 0;
    fore(y,1, 100001){
        int original = ys[y].second;
        
        int actMin = min(ys[y].second, ys[y-1].first);
        ys[y].second = max(ys[y].second - actMin, 0);
        ys[y-1].first = max(ys[y-1].first - actMin, 0);
        ans += actMin;

        actMin = min(ys[y].second, ys[y-1].second);
        ys[y].second = max(ys[y].second - actMin, 0);
        ys[y-1].second = max(ys[y-1].second - actMin, 0);
        ans += actMin;
        
        actMin = min(ys[y].first, ys[y-1].first);
        ys[y].first = max(ys[y].first - actMin, 0);
        ys[y-1].first = max(ys[y-1].first - actMin, 0);
        ans += actMin;

        actMin = min(ys[y].first, ys[y-1].second);
        ys[y].first = max(ys[y].first - actMin, 0);
        ys[y-1].second = max(ys[y-1].second - actMin, 0);
        ans += actMin;




        ys[y].second = original;
    }

    cout << ans << "\n";

    return 0;
}
