#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define SZ(s) int(s.size())
#define ALL(s) s.begin(),s.end()
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

static int NUMB = 1048576;
int main()
{
    cout << "jojo";
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vi numbs(N);
        fore(i,0,N){
            cin>>numbs[i];
        }

        cout << "a\n";
        vi freqs(NUMB);
        cout << "d\n";
        freqs.assign(NUMB, 0);
        cout << "e\n";
        ll dp[1048576][22];
        cout << "f\n";
        ll ans=0;
        cout << "b\n";
        fore(i,0,N)
            freqs[numbs[i]]++;

        cout << "c\n";
        fore(i,0,NUMB)
            dp[i][0] = freqs[i];

        cout << "point is " << dp[29][0] << endl;
        fore(i,0,20){
            fore(mask,0,NUMB + 1){
                if (mask&(1<<i))
                    dp[mask][i+1] = dp [mask^(1<<i)][i];
                else {
                    dp[mask][i+1] = dp[mask][i];
                    if ((mask^(1<<i)) <= NUMB)
                        dp[mask][i+1] += dp [mask^(1<<i)][i];
                }

            }
        }

        fore(i,0,N){
            cout << "i: " << i << " is: " << dp[numbs[i]][20] << endl;
            ans += dp[numbs[i]][20];
        }
        cout << "ans is " << ans << "\n";


    }
    return 0;
}
