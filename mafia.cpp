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
    node parent;
    vector<node> childs;
}

int main(){
    int n, k;
    cin >> n >> k;
    return 0;
    node root;
    vector<node> nodes(n);
    root.idx=0;
    root.visited=false;
    nodes.pb(root);
    fore(i,0,n-1){
        node act;
        act.idx = i+1;
        act.visited=false;
        int idxParent
        cin >> idxParent;
        act.parent = nodes[idxParent-1];
        nodes[idxParent - 1].childs.pb(act);
    }
}