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
#define MAXN   100001 
  
// stores smallest prime factor for every number 
int spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

bool primeFactors(int n)  
{
    int totDivisors = 0;
    bool divBy2 = false; 
    bool toReturn = 0;
    int orN = n;
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {
        totDivisors++;
        divBy2 = true; 
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {
            totDivisors++;
            toReturn = true;   
        }  
    }
    if (n > 2)
        totDivisors++;
    toReturn |= ((orN != n) && (n > 2) && (n%2 != 0));
    toReturn &= ( (totDivisors != 2) || !divBy2);
    return toReturn;
}  

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1){
            cout << "FastestFinger\n";
            continue;
        }
        if (n == 2){
            cout << "Ashishgup\n";
            continue;
        }
        if(n%2 != 0){
            cout << "Ashishgup\n";
            continue;
        }
        if(primeFactors(n)){
            cout << "Ashishgup\n";
        } else {
            cout << "FastestFinger\n";
        }


    }
    

    return 0;
}