#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i, a, b) for (int i = a, end = b; i < end; i++)
#define ALL(s) s.begin(), s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;

#define RB(x) (x < n ? r[x] : 0)
void csort(vector<int> &sa, vector<int> &r, int k)
{
    int n = sa.size();
    vector<int> f(max(255, n), 0), t(n);
    fore(i, 0, n) f[RB(i + k)]++;
    int sum = 0;
    fore(i, 0, max(255, n)) f[i] = (sum += f[i]) - f[i];
    fore(i, 0, n) t[f[RB(sa[i] + k)]++] = sa[i];
    sa = t;
}

vector<int> constructSA(string &s)
{ // O(n logn)
    int n = s.size(), rank;
    vector<int> sa(n), r(n), t(n);
    fore(i, 0, n) sa[i] = i, r[i] = s[i];
    for (int k = 1; k < n; k *= 2)
    {
        csort(sa, r, k);
        csort(sa, r, 0);
        t[sa[0]] = rank = 0;
        fore(i, 1, n)
        {
            if (r[sa[i]] != r[sa[i - 1]] || RB(sa[i] + k) != RB(sa[i - 1] + k))
                rank++;
            t[sa[i]] = rank;
        }
        r = t;
        if (r[sa[n - 1]] == n - 1)
            break;
    }
    return sa;
}

vector<int> computeLCP(string &s, vector<int> &sa)
{
    int n = s.size(), L = 0;
    vector<int> lcp(n), plcp(n), phi(n);
    phi[sa[0]] = -1;
    fore(i, 1, n) phi[sa[i]] = sa[i - 1];
    fore(i, 0, n)
    {
        if (phi[i] < 0)
        {
            plcp[i] = 0;
            continue;
        }
        while (s[i + L] == s[phi[i] + L])
            L++;
        plcp[i] = L;
        L = max(L - 1, 0);
    }
    fore(i, 0, n) lcp[i] = plcp[sa[i]];
    return lcp; // lcp[i]=LCP(sa[i-1],sa[i])
}

#define oper min

const int K = 20;

int st[K][1 << K]; // K such that 2^K>n
void st_init(vi &a)
{
    int n = SZ(a);
    fore(i, 0, n) st[0][i] = a[i];
    fore(k, 1, K) fore(i, 0, n - (1 << k) + 1)
        st[k][i] = oper(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
}
int st_query(int s, int e)
{
    int k = 31 - __builtin_clz(e - s);
    return oper(st[k][s], st[k][e - (1 << k)]);
}

vi word(500005, -1);
vi ending(15, 0);
vector<ii> proximity(500005);
vl checks (100005,0);
vector<string> words;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif

    string T = "$";

    int n;
    cin >> n;
    fore(i, 0, n)
    {
        string act;
        cin >> act;
        words.pb(act);
        fore(j, 0, SZ(act))
            word[SZ(T) + j] = i;
        ending[act[SZ(act) - 1] - '0']++;
        T += act;
    }

    vi sa = constructSA(T);
    vi lcp = computeLCP(T, sa);
    st_init(lcp);

    int curIndex = -1;
    fore(i, 0, SZ(sa))
    {
        if (i > 0 && word[sa[i]] != word[sa[i - 1]])
            curIndex = i - 1;
        proximity[i].fst = curIndex;
    }

    curIndex = SZ(sa);
    for (int i = SZ(sa) - 1; i >= 0; i--)
    {
        if (i < SZ(sa) - 1 && word[sa[i]] != word[sa[i + 1]])
            curIndex = i + 1;
        proximity[i].snd = curIndex;
    }
    fore(i,0,SZ(sa)){
        if (word[sa[i]] != -1){
            int left = proximity[i].fst;
            int right = proximity[i].snd;
            int sum = max(st_query(left+1, i+1), st_query(i+1, right + 1)) + 1;
            checks[word[sa[i]]] += sum;
        }
    }
    cout << fixed << setprecision(10);
    fore(i,0,n){
        string word = words[i];
        int size = SZ(word);
        if (ending[word[size - 1] - '0'] > 1) cout << "Impossible\n";
        else
            cout << checks[i] / (double)size << "\n";
    }
}
