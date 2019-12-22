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
    int n, m;
    cin >> n >> m;
    map<int,int> a;
    map<int,int>b;
    fore(i,0,n){
        int numb;
        cin>>numb;
        a[numb]++;
    }
    fore(i,0,n){
        int numb;
        cin>>numb;
        b[numb]++;
    }



    return 0;
}
