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
        freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
 
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        map<ii, int> lastVisited;
        ii actPos = {0,0};
        string path;
        cin >> path;
        int minStr = 1e9;
        ii toPrint;
 
        lastVisited[actPos] = -1;
        fore(i, 0, n){
            char walk = path[i];
            if (walk == 'L') actPos.first--;
            else if (walk == 'R') actPos.first++;
            else if (walk == 'U') actPos.second++;
            else if (walk == 'D') actPos.second--;
 
            if (lastVisited.count(actPos)){
                int pathLength = i - lastVisited[actPos];
                minStr = min (minStr, pathLength);
                if (minStr == pathLength) toPrint = {lastVisited[actPos] + 2, i+1};
            }
            lastVisited[actPos] = i;
        }
        if (minStr == 1e9) cout << "-1\n";
        else cout << toPrint.first << " " << toPrint.second << "\n";
    }
 
    return 0;
}