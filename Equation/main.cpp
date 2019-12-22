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

int main()
{
    int n;
    cin>>n;
    if (n%2 == 0 || n%3==0){
        if (n == 2)
            cout << "8 6\n";
        else if (n == 3)
            cout << "9 6\n";
        else
            cout << 2*n << " " << n << "\n";
    }
    else {
        if (n == 1)
            cout << "9 8\n";
        else
            cout << 2*n + n << " " << 2*n << "\n";
    }

    return 0;
}
