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
{FIN;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int M, N;
    cin >> M >> N;
    if (M < N)
        swap(M,N);
    int heights [M*N];
    fore(i,0,M*N)
        cin >> heights[i];
    sort(heights, heights + N*M, greater<>());
    ll maxSum = 0;
    fore(i,0,N){
        maxSum += 2*heights[i*i];
        maxSum += 2*heights[i*i + i];
    }

    fore(i,0,M-N){
        maxSum += 2*heights[N*N + i*N];
    }
    cout << maxSum << "\n";
    return 0;
}
