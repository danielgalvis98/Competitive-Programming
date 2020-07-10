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
        int n, m;
        cin >> n >> m;
        set <int> takenRows;
        set <int> takenCols;
        fore(i,0,n){
            fore(j,0,m){
                int act;
                cin >> act;
                if (act){
                    takenRows.insert(i);
                    takenCols.insert(j);
                }
            }
        }
        n -= SZ(takenRows);
        m -= SZ(takenCols);

        int movs = min(n,m);
        if (movs % 2 == 0)
            cout << "Vivek\n";
        else 
            cout << "Ashish\n";
    }

    return 0;
}
