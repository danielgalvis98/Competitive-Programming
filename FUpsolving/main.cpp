#include <bits/stdc++.h>
#define db(x) cout<<#x<<" = "<<x<<"\n"
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;


vector<vector<int>> values;
vector<vector<char>> relations;
vector<vector<int>> comodin (10);
int n;


vector<vector<int>> solve(vector<vector<int>> &actState, int i, int j, vector<int> &rows, vector<int> &columns){

    if (actState[i][j] != 0){

        if (j == n-1){
            j = 0;
            if (i == n-1)
                return actState;
            i++;
        } else
            j++;
        return solve(actState,i,j,rows,columns);
    }


    for (int a = 1; a <= n; a++){
        if ((rows[i]&(1<<a)) != 0 || (columns[j]&(1<<a)) != 0)
            continue;

        if (i != 0){
            if (actState[i-1][j] != 0 && ((relations[2*i-1][j] == '^' && actState[i-1][j] > a) || (relations[2*i-1][j] == 'v' && actState[i-1][j] < a)))
                continue;
        }

        if (j != n-1){
            if (actState[i][j+1] != 0 && ((relations[2*i][j] == '>' && actState[i][j+1] > a) || (relations[2*i][j] == '<' && actState[i][j+1] < a))){
                continue;
            }
        }

        if (i != n-1)
            if (actState[i+1][j] != 0 && ((relations[2*i+1][j] == 'v' && actState[i+1][j] > a) || (relations[2*i+1][j] == '^' && actState[i+1][j] < a)))
                continue;


        if (j != 0)
            if (actState[i][j-1] != 0 && ((relations[2*i][j-1] == '<' && actState[i][j-1] > a) || (relations[2*i][j-1] == '>' && actState[i][j-1] < a)))
                continue;


        actState[i][j] = a;

        int newI = i;
        int newJ = j;
        if (j == n-1){
            newJ = 0;
            if (i == n-1)
                return actState;
            newI++;
        } else
            newJ++;

        rows[i] |= (1<<a);

        columns[j] |= (1<<a);

        vector<vector<int>> parAns = solve(actState, newI, newJ, rows, columns);

        if (parAns != comodin)
            return parAns;

        actState[i][j] = 0;
        rows[i] &= ~(1<<a);
        columns[j] &= ~(1<<a);
    }

    return comodin;

}


int main()
{FIN;
    cin >> n;

    values = vector<vector<int>> (n);
    relations = vector<vector<char>> (2*n - 1);
    vector<int> rrows (n);
    vector<int> ccols (n);
    for (int i = 0; i < n; i++){
        rrows[i] = 0;
        ccols[i] = 0;
    }

    for (int i = 0; i < 2*n-1; i++){
        if (i % 2 == 0)
            values[i/2] = vector<int> (n);
        relations[i] = vector<char> (n);
        string line;
        cin >> line;
        for (int j = 0; j < 2*n-1;j++){
            //cout << "j: "<< j << endl;
            char act = line[j];
            if (i%2 == 0){
                    //cout << "tro" << endl;
                if (j%2 == 0){
                        //cout << "con " << act << endl;
                    if (act == '-'){
                        values[i/2][j/2] = 0;

                    }
                    else{
                        //cout << "jotajotajotaota" << endl;
                        values [i/2][j/2] = act - '0';
                        //cout << "paso 1" << endl;
                        rrows[i/2] |= (1<<(act - '0'));
                       // cout << "paso 2" << endl;
                        ccols[j/2] |= (1<<(act - '0'));
                        //cout << "paso 3 " << endl;
                    }
                } else {
                    relations[i][j/2] = act;
                }
            } else if (j%2 == 0){
                relations[i][j/2] = act;
            }
        }
    }
    values = solve(values, 0, 0, rrows, ccols);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << values[i][j];
        }
        cout << "\n";
    }
    return 0;
}




