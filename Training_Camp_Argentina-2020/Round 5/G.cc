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

const int MAX_N = 1e5;

bool is_special [MAX_N + 5];

int disj_set [MAX_N + 5];

int n,k, joined_verts;

int update_idx(int i){
    //cout << i << " " << disj_set[i] << endl;
    return disj_set[i] == i ? i : disj_set[i] = update_idx(disj_set[i]);
}

struct edge{
    int u,v,w;
    void msp(){
        u = update_idx(u);
        v = update_idx(v);
        //cout << u << " " << v << endl;
        if (u != v){
            if (is_special[u])
                disj_set[v] = u;
            else
                disj_set[u] = v;
            if (is_special[u] && is_special[v]){
                joined_verts++;
                if (joined_verts == k-1){
                    fore(i,0,k)
                        cout << w << " ";
                    cout << "\n";
                    exit(0);
                }
            }
        }
    }
};

bool comp (edge i, edge j){
    return i.w < j.w;
}

edge edges[MAX_N+5];
int main()
{FIN;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int m;
    cin >> n >> m >> k;
    fore(i,0,k){
        int idx;
        cin >> idx;
        is_special[idx] = 1;
    }
    
    fore(i,0,n+1)
        disj_set[i] = i;
    fore(i,0,m)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges, edges + m, comp);
    joined_verts = 0;
    fore(i,0,m)
        edges[i].msp(); 
    return 0;
}
