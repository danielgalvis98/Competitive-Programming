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

bool checkValid(string str, int i, int j){
    if (j < i) return false;
    if (i == j) return str[i] == 'A';
    if (str[j] == 'B'){
        if (str[j-1] == 'A') return checkValid(str, i, j-2);
        return false;
    }
    if (str[i] == 'B') return checkValid(str, i+1, j-1);
    return false;
}

int main()
{FIN;
    int n;
    cin >> n;
    while (n--){
        string seq;
        cin >> seq;
        bool valid = checkValid(seq, 0, SZ(seq) - 1);
        if (valid){
            if (SZ(seq) == 1){
                if (seq == "A") cout << "SIMPLE\n";
                else cout << "MUTANT\n";
            }

            else if (seq[SZ(seq)-1] == 'B') cout << "FULLY-GROWN\n";
            else cout << "MUTAGENIC\n";
        } else
            cout << "MUTANT\n";
    }
    return 0;
}
