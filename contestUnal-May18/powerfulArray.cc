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

const int MAXN = 200005;

ll res;

int n,sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,id;};

int arr [MAXN];
qu qs[MAXN];
ll ans[MAXN]; // ans[i] = answer to ith query
int cnt [1000005];

bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}


void add(int i){
    int digit = arr[i];
    cnt[digit]++;
    res += digit * (2*cnt[digit] - 1);
}

void remove(int i){
    int digit = arr[i];
    res -= digit * (2*cnt[digit] - 1);
    cnt[digit]--;
}

ll get_ans(){
	return res;
}


void mos(){
    fore(i,0,nq)qs[i].id=i;
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    fore(i,0,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans();
    }
}



int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    cin >> n>> nq;

    fore(i,0,n)
        cin >> arr[i];

    fore(i,0,nq){
        cin >> qs[i].l;
        qs[i].l--;
        cin >> qs[i].r;
        //qs[i].r--;
    }

    fore(i,0,1000005)
        cnt[i] = 0;

    mos();

    fore(i,0,nq)
        cout << ans[i] << "\n";


    return 0;
}
