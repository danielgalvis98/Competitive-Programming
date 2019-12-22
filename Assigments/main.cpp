#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, end=b;i<end;i++)
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
    int c;
    cin>>c;
    while (c--){
        int n;
        cin>>n;
        bool mat[n][n];
        int lim = pow(2,n);
        ll dp [lim];
        fore(i,0,n){
            fore(j,0,n){
                cin>>mat[i][j];
            }
        }

        dp[0]=1;
        fore(mask,1,lim)
            dp[mask]=0;

        fore(mask,0,lim){
           int i = __builtin_popcount(mask);
            if (dp[mask] == 0) continue;
            fore(j,0,n){
                int res = mask&(1<<j);
                if (res == 0){
                    int numb = mask|(1<<j);
                    dp[numb] += dp[mask]*mat[i][j];
                }
            }
        }
        cout << dp[lim-1]<<"\n";
    }
    return 0;
}
