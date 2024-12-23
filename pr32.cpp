#include<bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update> chad_set;
typedef tree<int, null_type, less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> chad_multiset;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll, ll>
#define ff first
#define float long double
#define int long long int
#define ss second
#define endl "\n"
#define V(T) vector<T>
#define all(x) x.begin(),x.end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
/*---------------------------------------------------------------------------------------------------------------------------*/
 
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> div(ll n){   vector<ll> v;   for(int i=1; i*i<=(n); i++){     if (n%i == 0){   v.pb(i);    if(n/i!=i) v.pb(n/i);  }   }   return v;   }
vector<ll> primediv(ll n){  vector<ll> v;   for(ll i=2;i*i<=(n);i++){   while(n%i==0){ n=n/i; v.pb(i); }  }   if(n>1) v.pb(n);    return v;   }
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
 
/*--------------------------------------------------------------------------------------------------------------------------*/

int solve(){
	vector<int> dig = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	set<int> s;

	do{
		for(int a = 1; a < 9; a++){
			for(int b = 1; b < 9; b++){
				int c = 9 - a - b;
				if(c < a || c < b){
					break;
				}
				int ind = 0;
				int aa = 0, bb = 0, cc = 0;
				for(int i = 1; i <= a; i++){
					aa = aa*10;
					aa += dig[ind++];
				}
				for(int i = 1; i <= b; i++){
					bb = bb*10;
					bb += dig[ind++];
				}
				for(int i = 1; i <= c; i++){
					cc = cc*10;
					cc += dig[ind++];
				}
				if(aa*bb == cc){
					s.insert(cc);
				}
			}
		}
	}while(next_permutation(dig.begin(), dig.end()));

	int ans = 0;
	for(auto it : s){
		ans += it;
	}

	cout << ans << endl;

    return 0;
}

/* ------------------------------------------------------------------------

chad_set A -> *A.find_by_order(x) gives index of x
A.order_of_key(x) gives no. of elems smaller than x
__builtin_clz(x): the number of zeros at the beginning of the number 
__builtin_ctz(x): the number of zeros at the end of the number
__builtin_popcountll(x): the number of ones in the number
__builtin_parity(x): the parity (even or odd) of the number of ones
__builtin_ffs(int) finds the index of the first (most right) set bit
 
-------------------------------------------------------------------------*/

int32_t main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int t;
    t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

