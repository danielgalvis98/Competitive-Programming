#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define pb push_back
#define SZ(s) (int)(s.size())
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1e9;

int n;
vector<vector<int>> nodes;
vector<int> ans;

void bfs(vector<int> start, vector<int> end){

    queue<int> q;
    vector<int> d(n, INF);
    for (auto n: start){
        q.push(n);
        d[n]=0;
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (auto n: nodes[v]){
            if (d[n]==1e9){
                d[n] = d[v] + 1;
                q.push(n);
            }
        }
    }

    for (auto n: end)
        if (d[n] != 1e9)
            ans[n] = d[n];

}

int main()
{FIN;
    cin >> n;
    nodes = vector<vi>(n);
    ans = vi(n, -1);
    vi evens;
    vi odds;
    int idx=0;
    for (int i = 0; i < n; i++){
        int num;
        cin>>num;
        if (num%2==0)
            evens.pb(idx);
        else
            odds.pb(idx);

        if (idx + num < n)
            nodes[idx+num].pb(idx);
        if (idx-num >= 0)
            nodes[idx-num].pb(idx);

        idx++;
    }
    bfs(evens, odds);
    bfs(odds,evens);

    for (auto it: ans)
        cout << it << " ";

    cout << "\n";

    return 0;
}
