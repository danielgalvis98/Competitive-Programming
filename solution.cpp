#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
 
using namespace std;
 
typedef pair<int,int> ii;
typedef long long int ll;
 
#define oper min
const int K=20;
int st[K][1<<K];  // K such that 2^K>n
void st_init(vector<int> &a){
	int n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}

int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
 
 
#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
 
vector<int> constructSA(string& s){ // O(n logn)
	int n=s.size(),rank;
	vector<int> sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0);
		t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
    cout << "sa: ";
    for (int a: sa)
        cout << a << " ";
    cout << endl;
	return sa;
}
 
vector<int> computeLCP(string& s, vector<int>& sa){
	int n=s.size(),L=0;
	vector<int> lcp(n),plcp(n),phi(n);
	phi[sa[0]]=-1;
	fore(i,1,n)phi[sa[i]]=sa[i-1];
	fore(i,0,n){
		if(phi[i]<0){plcp[i]=0;continue;}
		while(s[i+L]!='$' && s[i+L]==s[phi[i]+L])L++;
		plcp[i]=L;
		L=max(L-1,0);
	}
	fore(i,0,n)lcp[i]=plcp[sa[i]];
    cout << "lcp: ";
    for(int a: lcp){
        cout << a << " ";
    }
    cout << endl;
	return lcp;
}
 
int n;
int w[500005];
ii difWord[500005];
ll answers[100005];
int wordLength[100005];
int ending [100005];
int cntEndings[15];
 
 
int main(){FIN;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
	cin >> n;
	string T="$";
	memset(w,-1,sizeof w);
	fore(i,0,n){
		string s;
		cin >> s;
		cntEndings[s[SZ(s)-1]-'0']++;
		ending[i]=s[SZ(s)-1]-'0';
		wordLength[i]=SZ(s);
		fore(j,0,s.size())w[j+SZ(T)]=i;
		T+=s;
		T+="_";
		T+="$";
	}
    fore(i,0,SZ(T))
        cout << i << " ";
    cout << endl; 
	fore(i,0,SZ(T))
        cout << T[i] << " "; 
    cout << endl;
	vector<int> SA=constructSA(T);
	vector<int> LCP=computeLCP(T,SA);
	st_init(LCP);
	
	int currentIndex=-1;
	fore(i,0,T.size()){
		if(i-1>=0 && w[SA[i]]!=w[SA[i-1]])currentIndex=i-1;	
		difWord[i].ff=currentIndex;
	}
	currentIndex=T.size();
	for(int i=T.size()-1;i>=0;i--){
		if(i+1<T.size() && w[SA[i]]!=w[SA[i+1]])currentIndex=i+1;	
		difWord[i].ss=currentIndex;
	}

    for(ii pairs: difWord)
        cout << pairs.first << " ";
    cout << endl;

    for(ii pairs: difWord)
        cout << pairs.second << " ";
    cout << endl;
		
	fore(i,0,T.size()){
		//cout << "here " <<i<<" "<<w[SA[i]]<< endl;
		if(w[SA[i]]!=-1){
			int leftWord=difWord[i].ff;
			int rightWord=difWord[i].ss;
			int minWait=max(st_query(leftWord+1,i+1),st_query(i+1,rightWord+1))+1;
			answers[w[SA[i]]]+=minWait;
		}
	}
	
	cout << fixed;
	cout << setprecision(10);
	
	fore(i,0,n){
		if(cntEndings[ending[i]]>1){
			cout << "Impossible\n";	
		}else{
			cout << answers[i]/((double)wordLength[i]) << "\n";
		}
	}
	
    return 0;
}