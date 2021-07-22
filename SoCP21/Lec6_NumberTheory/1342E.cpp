#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 200009;

int fact[N];

int mul(int x,int y)
{
    return (1ll*x*y) % MOD;
}

int bexp(int x,int y)
{
    int z=1;
    while(y>0)
    {
        if (y%2==1)
            z = mul(z,x);
        x = mul(x,x);
        y /= 2;
    }
    return z;
}

int inv(int x)
{
    return bexp(x,MOD-2);
}

int comb(int n,int r)
{
    return mul(fact[n],inv(mul(fact[r],fact[n-r])));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin>>n>>k;
    if (k >= n)
    {
        cout<<0;
        return 0;
    }
    
    int c= n-k;
    fact[0] = 1;
    
    for(int i =1;i<=n;i++)
    {
        fact[i] = mul(fact[i-1],i);
    }
    int ans = 0;
    
    for(int i=0; i<=c; i++)
    {
        if (i%2==0)
            ans = (ans + mul(comb(c,i),bexp(c-i,n)))%MOD;
        else
            ans = (ans + MOD - mul(comb(c,i),bexp(c-i,n)))%MOD;
        
    }
    
    ans = mul(ans,comb(n,c));
    if (k>0)
        ans = mul(ans,2);
        
    cout<<ans;
    return 0;
}