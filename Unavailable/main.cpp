#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{FIN;
    int t;
    cin >> t;
    while (t--){
        int a,b,c,r;
        cin>>a>>b>>c>>r;
        if (a > b)
            swap(a,b);
        ll limR = c + r;
        ll limL = c - r;

        if (limL <= a && limR >= b){
            cout <<"0\n";
            continue;
        }

        if (limR < a || limL > b){
            cout << (b - a) << "\n";
            continue;
        }

        ll ans = 0;

        if (limR < b)
            ans += (b - limR);

        if (limL > a)
            ans += (limL - a);

        cout << ans << "\n";

    }
    return 0;
}
