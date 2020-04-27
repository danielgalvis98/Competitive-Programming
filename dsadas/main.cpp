#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct node{
    int idx;
    bool visited;
    int parent, depth;
    vi childs;
};

bool forSort (node a, node b){
    return a.depth > b.depth;
}


int main(){
    int n, k;
    cin >> n >> k;
    node root;
    vector<node> nodes(n);
    root.idx=0;
    root.visited=false;
    root.depth=0;
    root.parent = -1;
    nodes[0] = root;
    fore(i,0,n-1){
        nodes[i+1].idx = i+1;
        nodes[i+1].visited=false;
        int idxParent;
        cin >> idxParent;
        nodes[i+1].parent = idxParent-1;
        nodes[i+1].depth=0;
        nodes[idxParent - 1].childs.pb(i+1);
    }

    stack<node> forDfs;
    forDfs.push(nodes[0]);
    nodes[0].visited = true;
    while (!forDfs.empty()){
        node act = forDfs.top();
        forDfs.pop();
        fore(i,0,act.childs.size()){
            if (!nodes[act.childs[i]].visited){
                nodes[act.childs[i]].visited = true;
                nodes[act.childs[i]].depth = act.depth + 1;
                forDfs.push(nodes[act.childs[i]]);
            }
        }
    }
    vector<node> nodes2 = nodes;
    sort(ALL(nodes2), forSort);


    fore(i,0,SZ(nodes))
        nodes[i].visited=false;

    vi depths;
    fore(i,0,SZ(nodes2)){
        node act = nodes2[i];
        if (!nodes[act.idx].visited){
            int depth = 1;
            nodes[act.idx].visited = true;
            while (act.parent != -1 && !nodes[act.parent].visited){
                nodes[act.parent].visited = true;
                act = nodes[act.parent];
                depth++;
            }
            depths.pb(depth);
        }
    }
    sort(ALL(depths));
    int ans = 0;

    fore(i,0,min(k, SZ(depths)))
        ans += depths[depths.size() -1 - i];
    cout << ans << "\n";
    return 0;
}
