#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int n;
int father[200005];
int main(){FIN;
    int n;
    cin >> n;
    fore(i,1,n){
        cin >> father[i+1];
    }

    vector <int> path;
    int act = n;
    while (act != 1){
        path.push_back(act);
        act = father[act];
    }
    path.push_back(1);
    for (int i = path.size() -1 ; i >= 0; i--)
        cout << path[i]<< " ";
    cout << "\n";
    return 0;
}
