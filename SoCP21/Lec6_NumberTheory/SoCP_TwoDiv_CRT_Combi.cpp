#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define per(i,a,b) for(int i = (a); i > (b); i--)
#define repl(i,a,b) for(ll i = (a); i < (b); i++)
#define perl(i,a,b) for(ll i = (a); i > (b); i--)

const ll MOD = 1000000007;

const int N = 1e7;

long long fact[N], invfact[N];

//Fast modular exponentiation, needed by the function below
long long fast_exp(long long base, long long exp, long long mod) {
    long long res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}

//Precomputes factorials and their inverses (modulo mod) from 0 to n
void binom(int n, long long mod){

    fact[0] = 1;

    for(int i = 1; i <= n; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }

    invfact[n] = fast_exp(fact[n], mod-2, mod);

    for(int i = n-1; i >= 0; i--){
        invfact[i] = ((i+1)*invfact[i+1])%mod;
    }

}

//Returns the value of nCr
long long nCr(int n, int r, long long mod){

    long long ret = (((fact[n]*invfact[r])%mod)*invfact[n-r])%mod;
    return ret;
    
}

vector<int> sieve(N+1);

void precompute(){

    for(int i = 2; i <= N; i++){

        if(sieve[i]) continue;

        sieve[i] = i;
        for(int j = 2*i; j <= N; j += i){
            if(!sieve[j]) sieve[j] = i;
        }

    }

}

void solve(){

    int n; cin >> n;
    vector<int> arr(n), line1(n), line2(n);
    rep(i, 0, n) cin >> arr[i];

    int power, p;

    for(int i = 0; i < n; i++){

        p = sieve[arr[i]]; power = 1;

        while(arr[i]%p == 0){
            arr[i] /= p; power *= p;
        } 

        if(arr[i] == 1){
            line1[i] = -1; line2[i] = -1;
        }

        else {
            line1[i] = power; line2[i] = arr[i];
        }

    }

    for(int i = 0; i < n; i++) cout << line1[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; i++) cout << line2[i] << " ";
    cout << "\n";

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();
    solve();

    return 0;
}