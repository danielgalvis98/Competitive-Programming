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

    int n, p;
    cin >> n >> p;
    string line;
    cin >> line;
    int ans [n];
    fore(i,0,n){
        if (line[i] == '1')
            ans[i] = 1;
        else if (line [i] == '0')
            ans[i] = 0;
        else
            ans [i] = -1;
    }
    bool possible = false;
    fore(i,0,n-p){
        int newIdx = i+p;
        if (ans[i] == ans[newIdx]){
            if (ans[i] == -1){
                ans[i] = 1;
                ans[newIdx] = 0;
                possible = true;
            }
        } else {
            possible = true;
            if (ans[i] == 1)
                ans[newIdx] = 0;
            else if(ans[i] == 0)
                ans[newIdx] = 1;
            else
                ans[i] = 1 - ans[newIdx];
        }
    }

    fore(i,n-p,p){
        if (line [i] == '0')
            ans[i] = 0;
        else
            ans [i] = 1;
    }
    if (possible)
        for(int act : ans) cout << act;
    else
        cout << "No";
    cout << "\n";

    return 0;
}
