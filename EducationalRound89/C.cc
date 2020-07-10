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
{FIN;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        int table [n][m];
        fore(i,0,n){
            fore(j,0,m)
                cin >> table[i][j];
        }
        int zeroes [n+m-1];
        int ones [n+m-1];

        memset(zeroes, 0, sizeof zeroes);
        memset(ones, 0, sizeof ones);

        fore(i,0,n){
            fore(j,0,m){
                if (table[i][j] == 1)
                    ones[n+m]++;
                else
                    zeroes[n+m]++;
            }
        }
        int i = 0;
        int j = n+m-2;
        int totChanges = 0;
        while (i < j){
            totChanges += min(ones[i] + ones[j], zeroes[i] + zeroes[j]);
            i++;
            j = n+m-2-i;
        }
        cout << totChanges << "\n";
    }
    return 0;
}
