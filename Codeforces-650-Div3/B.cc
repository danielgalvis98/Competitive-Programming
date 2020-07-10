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
        int n;
        cin >> n;
        int totBadOdds = 0;
        int totBadEvens = 0;
        fore(i,0,n){
            int act;
            cin >> act;
            if ((i%2) && !(act%2))
                totBadEvens++;
            else if (!(i%2) && (act%2))
                totBadOdds++;
        }
        if (totBadEvens == totBadOdds)
            cout << totBadEvens << "\n";
        else
            cout << "-1\n";
    }

    return 0;
}
