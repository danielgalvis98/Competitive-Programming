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
    int n,m;
    cin >> n >> m;
    double probOcurrence [(1<<n)];
    memset(probOcurrence, 0, sizeof probOcurrence);
    probOcurrence[0]=1;
    fore(i,0,m){
        int a, b;
        cin >> a >> b;
        double p;
        cin >> p;
        a--;b--;

        fore(i,0,1<<n){
            if (!(i&(1<<a)) && !(i&(1<<b))){
                probOcurrence[i|(1<<b)] += probOcurrence[i]*p;
                probOcurrence[i] *= 1-p;
            }
        }
    }

    cout << fixed << setprecision(10);

    double probKilled [n];
    memset(probKilled, 0, sizeof probKilled);
    fore(i,0,1<<n){
        fore(j,0,n){
            if (i&(1<<j)) probKilled[j]+= probOcurrence[i];
        }
    }

    fore(i,0,n)
        cout << 1-probKilled[i] << "\n";
    return 0;
}
