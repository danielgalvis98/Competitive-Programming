#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for (int i = low, lim = n; i < lim; i++)

using namespace std;

typedef long long int ll;
typedef vector<int>  vi;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    fore (cas, 0, t){
        string line;
        cin >> line;
        char last = 'x';
        for (int i = 0; i < line.size(); i++){
            char &act = line[i];
            if (act == '?'){
                if (i == line.size() - 1){
                    if ('a' != last){
                        act = 'a';
                    } else {
                        act = 'b';
                    }
                } else {
                    if ('a' == last){
                        if (line[i+1] != 'b'){
                            act = 'b';
                        } else {
                            act = 'c';
                        }
                    } else if ('b' == last){
                        if (line[i+1] != 'c'){
                            act = 'c';
                        } else {
                            act = 'a';
                        }
                    } else {
                        if (line [i+1] != 'a'){
                            act = 'a';
                        } else {
                            act = 'b';
                        }
                    }
                }
            } else if (act == last){
                line = "-1";
                break;
            }
            last = act;
        }
        cout << line << "\n";
    }

}
