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


const int MAX_SLOTS = 1e5 + 5;

int st[4*MAX_SLOTS];

void insert(int s, int e, int k, ii slot){
    if (s+1 == e){
        st[k] = slot.fst;
        return;
    }

    int mid = (s + e) / 2;
    if (slot.snd < mid)
        insert(s, mid, k*2, slot);
    else
        insert(mid, e, k*2 + 1, slot);
    st[k] = max(st[2*k], st[2*k + 1]);
}

int find(int s, int e, int k, int thickness){
    if (s + 1 == e)
        return s;
    int mid = (s + e) / 2;
    if (thickness <= st[2*k])
        return find(s,mid,2*k,thickness);
    
    return find(mid, e, 2*k+1, thickness);
}

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    int s;
    cin >> s;
    vector<pair<int, ii>> slots (s);
    fore(i,0,s){
        int a, b;
        cin >> a >> b;
        slots[i] = {b, {a, i}};
    }

    sort(slots.begin(), slots.end());

    int c;
    cin >> c;
    vector<ii> coins (c);
    fore(i,0,c){
        int u, v;
        cin >> u >> v;
        coins[i] = {v, u};
    }

    sort(coins.begin(), coins.end());

    int actSlot = 0;
    ll ans = 0;
    for (int i = 0; i < c; i++){
        int wCoin = coins[i].fst;
        while (actSlot < s && slots[actSlot].fst <= wCoin)
            insert(0, s, 1, slots[actSlot++].snd);
        ans += find(0,s,1,coins[i].snd) + 1;
    }

    cout << ans << "\n";

    return 0;
}