#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <set>

using namespace std;

int max_value(int a , int b)
{
    return a> b  ? a: b;
}



 
int solve(int A, string B) 
{
    int n =B.size();
    if (n % A != 0)
        return -1;
    
    int freq[26]= {0};
    int ans =-1;
    
    for(int i =0;i<n;i++)
    {
        freq[B[i] -'a'] ++;
    }
    for(int i =0;i< n;i++)
    {
        if(freq[i] > 0)
        {
            if(freq[i] % A==0)
            {
                //cout<<"fre "<<freq[i]<<endl;
                ans=1;
                continue;
            }
            else
                return -1;
        }
    }
    return ans;
}

int main() {
     
      int A = 2;
      string B ="abcabca";
      int c =solve(A, B);
    
    cout <<" ans "<< c<<endl;
    return 0;
}
