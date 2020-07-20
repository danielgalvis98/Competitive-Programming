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


class BagPacking 
{
private:
    /* data */
public:
    int minPay(vector<int> bag_sizes){
        int total_bags_size_i [101];
        memset(total_bags_size_i, 0, sizeof total_bags_size_i);
        for (int bag_size : bag_sizes)
            total_bags_size_i[bag_size]++;
        int max_bags = 0;
        for(int total_in_size : total_bags_size_i)
            max_bags = max(max_bags, total_in_size);
        return max_bags;
    }
};





int main(){
    vector<int> par = {3,1,3,2,4,3,3};

    BagPacking b;
    cout << b.minPay(par) << endl;
    return 0;
}
