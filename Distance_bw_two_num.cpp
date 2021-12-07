#include <iostream>
#include<vector>
#include<set>
#include <bits/stdc++.h>


using namespace std;

int min_value(int a, int b)
{
    return a < b ? a:b;
}


int solve1(vector<int> &A) {

    
    
    int n =A.size();
    int sum=0;
    int left=0;
    int right=0;
    unordered_set<int> sumSet;
    int ans =INT_MAX;
    int found=-1;
    for (int i =0;i<n;i++)
    {
       for(int j =0;j<n;j++)
       {
           if(A[i] == A[j] && i != j){
            ans = min_value(ans, abs(i-j));
            found=1;
           }
            
       }
        
    }
    if(found == -1)
        return -1;
    else return ans;
}


int solve(vector<int> &A) {

    int n =A.size();
    int sum=0;
    map<int, int> Map;
    int ans =INT_MAX;
    int preindex;
    for (int i =0;i<n;i++)
    {
       
           if(Map.find(A[i]) != Map.end()){
               
            preindex = Map[A[i]]   ;
            ans = min_value(ans, abs(i-preindex));
           }
           
        Map[A[i]] = i;           
        
    }
    return  (ans == INT_MAX ? -1 : ans);;
}

int main()
{
    
    vector<int> A = {7, 1, 3, 4, 1, 7};
   cout<<"ans = "<<solve(A) <<endl;
   
   return 0;
}
