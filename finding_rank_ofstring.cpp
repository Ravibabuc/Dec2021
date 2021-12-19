/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int factxx(int n)
{
    int fact1=1;
    for (int i =1;i<n;i++)
    {
        fact1 = (fact1 *i) ;
    }
    std::cout << fact1 << std::endl;
    return fact1;
}



ll fact(int n){
    ll f=1; 
    for(int i=2;i<=n;i++){
        f = (f*i)%1000003;
    }
    return f;
}
ll power(ll x,ll y,ll mod){
    ll res=1; 
    while(y){
        if(y&1) res = (res*x)%mod; 
        y>>=1; 
        x = (x*x)%mod;
    }
    return res;
}





int findRank(string A) {

    int n = A.size(); 
    ll mod = 1000003;
    ll ans = 1; // As we have to add 1 to get rank. 
    for (int i = 0; i < n; i++) { 
        ll less_than = 0; 
        for (int j = i + 1; j < n; j++) { 
            if ((int)A[i] > (int)A[j]) { 
                less_than += 1; 
            } 
        } 
        vector<int> freq(52, 0); 
        for (int j = i; j < n; j++) { 
            if(A[j]>='A' && A[j]<='Z')
                freq[A[j]-'A'] += 1;
            else
                freq[A[j] - 'a' + 26] += 1; 
        } 
        ll denominator = 1; 
        for (ll ele : freq) {
            denominator = (denominator*fact(ele))%mod; 
        }
        
        ll inverse = power(denominator,mod-2,mod); // inverse = (1/denominator)%mod
        
        ll permutation = (fact(n-i-1) * inverse) % mod;
        ll total_permutation = (less_than * permutation) % mod;
        
        ans = (ans + total_permutation)%mod; 
    } 
    return ans; 
}


 
int main()
{
    string A = "DTNGJPURFHYEW";

    int D= findRank(A);
    cout<<D<<endl;
    return 0;
}
