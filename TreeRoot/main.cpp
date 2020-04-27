#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;


using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;

int masLejano;
int maxLejura;

void lejano (int actNode, int acumLejura){
    visited[actNode] = 1;
    if (acumLejura > maxLejura){
        maxLejura = acumLejura;
        masLejano = actNode;
    }
    vector<int> node = nodes[actNode];
    fore(i,0, SZ(node)){
        int next = node[i];
        if (!visited[next])
            lejano(next, acumLejura+1);
    }
}

vector<int> bests;
int bestDist;

int getBests (int actNode, int actDist){
    visited[actNode] = 1;
    int depth = 0;
    vector<int> node = nodes[actNode];
    fore(i,0, SZ(node)){
        int next = node[i];
        if (!visited[next])
            depth = max(depth, getBests(next, actDist + 1));
    }

    if (depth == actDist){
        if (bestDist == actDist)
            bests.pb(actNode+1);
        else if (actDist > bestDist){
            bestDist = actDist;
            bests = {actNode+1};
        }
    }
    return depth + 1;
}

set<int> worsts;
void getWorsts(int actNode, int actDist){
    if (actDist == bestDist)
        worsts.insert(actNode+1);
    else if (actDist > bestDist){
        bestDist = actDist;
        worsts = {actNode+1};
    }
    visited[actNode] = 1;
    vector<int> node = nodes[actNode];
    fore(i,0, SZ(node)){
        int next = node[i];
        if (!visited[next])
            getWorsts(next, actDist + 1);
    }
}

int dfs(int actNode){
    visited[actNode] = 1;
    int depth = 0;

    vector<int> node = nodes[actNode];
    fore(i,0, SZ(node)){
        int next = node[i];
        if (!visited[next])
            depth = max(depth, dfs(next));
    }
    return 1 + depth;
}

int main()
{
    map<int, vector<int>> act;
    int N;
    while(cin >> N){
    masLejano = 0;
    maxLejura = -1;
    bestDist = -1;
    bests = {};
    worsts = {};
    nodes.resize(N);
    visited.resize(N);
    fore(i,0,N){
        visited[i] = 0;
        nodes[i] = {};
        int k;
        cin >> k;
        fore(j,0,k){
            int adj;
            cin >> adj;
            nodes[i].pb(adj-1);
        }
    }
    lejano(0,0);
    fill(visited.begin(), visited.end(),0);
    getBests(masLejano,0);
    sort(bests.begin(), bests.end());
    cout << "Best Roots :";
    fore(i,0,SZ(bests))
        cout << " " << bests[i];
    cout << "\nWorst Roots :";
    fill(visited.begin(), visited.end(), 0);
    bestDist = -1;
    getWorsts(bests[0]-1,0);
    for(auto it : worsts)
        cout << " " << it;
    cout << "\n";
    }
    return 0;
}
