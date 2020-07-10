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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int posNextOcupped[n];
        int last = k + n + 1;
        for(int i = n-1; i >= 0; i--){
            posNextOcupped[i]=last;
            if (s[i]=='1')
                last=i;
        }
        int canPut = 0;
        int before = -(k+1);
        fore(i,0,n){
            if (s[i] == '1')
                before = i;
            else if (i - before >= k+1 && posNextOcupped[i] - i >= k+1){
                canPut++;
                before=i;
            }

        }
        cout << canPut << "\n";
    }

    return 0;
}
