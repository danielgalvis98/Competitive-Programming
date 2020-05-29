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
        //5freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    int n, m;
    cin >> n >> m;
    char ans [m];
    fore(i,0,n)
        cin >> ans[m-n+i];

    string cypher;
    cin >> cypher;
    for(int i = m-1; i >= n; i--){
        char actLetter = ans[i] - 'a';
        char cypheredAs = cypher[i] - 'a';
        fore(j,0,26){
            if ((actLetter + j) % 26 == cypheredAs){
                ans[i-n] = j+'a';
                break;
            }
        }
    }

    fore(i,0,m)
        cout << ans[i];
    cout << "\n";

    return 0;
}
