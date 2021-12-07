#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <set>

using namespace std;

int max_value(int a , int b)
{
    return a> b  ? a: b;
}


int longestConsecutive1(const vector<int> &A) 
{
    set<int> map;
    set<int> ::  iterator itr;
    int n =A.size();
    
    if(n ==1) 
        return 1;
        
    int ans =INT_MIN;
    for (int i =0;i<n;i++)
    {
        map.insert(A[i]);
    }
    int val;
    itr = map.begin();
    val = *itr ;
    int ans1 =1;
    int flag=0;
    
            cout<<" val "<<val<<endl;
    itr++;
    for(;itr != map.end();itr++)
    {
        cout<<" map "<<*itr<<endl;
        
        if(val +1 == *itr)
        {
            val = *itr ;
            ans1 ++;
            flag=1;
        }
        else
        {
            ans = max_value(ans, ans1);
             val = *itr ;
             ans1 =1;
             flag=0;
        }
    }
    if(flag ==1)
        ans = max_value(ans, ans1);
    return ans;
}
 
 
 int longestConsecutive(const vector<int> &A) 
{
    unordered_set<int> map;
   // set<int> ::  iterator itr;
    int n =A.size();
    
    if(n ==1) 
        return 1;
        
    int ans =INT_MIN;
    for (int i =0;i<n;i++)
    {
        map.insert(A[i]);
    }

    
    
    for(int i =0;i<n;i++)
    {
       // cout<<" map "<<*itr<<endl;
        
           
        
        if(map.find(A[i]-1) == map.end())
        {
            int j = A[i];
            while(map.find(j) != map.end())
                j ++;
            ans = max_value(ans, j-A[i]);
        }
       
    }
   
    return ans;
}

int main() {
     
      vector<int> A = {97, 86, 67, 19, 107, 9, 8, 49, 23, 46, -4, 22, 72, 4, 57, 111, 20, 52, 99, 2, 113, 81, 7, 5, 21, 0, 47, 54, 76, 117, -2, 102, 34, 12, 103, 69, 36, 51, 105, -3, 33, 91, 37, 11, 48, 106, 109, 45, 58, 77, 104, 60, 75, 90, 3, 62, 16, 119, 85, 63, 87, 43, 74, 13, 95, 94, 56, 28, 55, 66, 92, 79, 27, 42, 70};
   // vector<int> A = {97, 86, 67, 19, 107, 9, 8, 49, 23, 46, -4, 22, 72, 4, 57, 111, 20, 52, 99, 2, 113, 81, 7, 5, 21, 0, 47, 54, 76, 117, -2, 102, 34, 12, 103, 69, 36, 51, 105, -3, 33, 91, 37, 11, 48, 106, 109, 45, 58, 77, 104, 60, 75, 90, 3, 62, 16, 119, 85, 63, 87, 43, 74, 13, 95, 94, 56, 28, 55, 66, 92, 79, 27, 42, 70};
    int c =longestConsecutive(A);
    
    cout <<" ans "<< c<<endl;
    return 0;
}
