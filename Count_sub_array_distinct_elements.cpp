/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>

using namespace std;

int max_value(int a, int b)
{
    return a> b? a: b;
}


int solve1(vector<int> &A) 
{
        int n =A.size();
        int cnt =n;
        unordered_set <int> Map;
        int l =0; 
        int r =n-1;
        int found= 0;
        int left =1;
        int right=0;
        
       while(l < r)
       {
           found= 0;
           int i =l;
           while(i<=r)
           {
              // cout<<"A[i] "<<A[i]<<endl;
              // cout<<"i "<<i<<endl;
                if(Map.find(A[i] )!= Map.end())
                {
                                     
                    found=1;
                    break;
                }
                else
                {
                    Map.insert(A[i]);
                
                 
                }
                i++;
           }
           if(found ==0)
           {    cnt ++;
            
           }
            
           if (left ==1)
           {
            l++;
           }
            //cout<<" l "<<l<<endl;
            //cout<<" r "<<r<<endl;
           if (right ==0 && l== r)
           {
               right =1;
               left =0;
               l=0;
           }
            
            if(right ==1)
                r --;
           Map.clear();
       }
    return cnt;
}


long int SubArraySum(int arr[], int n)
{
    long int result = 0,temp=0;
 
    // Pick starting point
    for (int i=0; i <n; i++)
    {
        // Pick ending point
        temp=0;
        for (int j=i; j<n; j++)
        {
            // sum subarray between current
            // starting and ending points
            cout<<"arr[j] "<<arr[j]<<"  ";
            temp+=arr[j];
            result += temp ;
                      //  cout<<"temp "<<temp<<"  ";
                        //cout<<"result "<<result<<"  ";

        }
        cout<<endl;
    }
    return result ;
}

int solve(vector<int> &A) 
{
    int n =A.size();
    
    int cnt =0;
  
    
    int start=0;
    int end=0;
    int l =0; 
    int r =0;
    int found= 0;
    int sum=0;
    unordered_set <int> Map;
    for(int i =0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {  
                    found =0;
                    for(int k=i;k<=j;k++)
                    {
                          if(Map.find(A[k] )!= Map.end())
                           {
                             
                              found=1;
                              break;
                           }
                           else
                           {
                              Map.insert(A[k]);
                           }
                   
                    }
                    Map.clear();
                    if(found ==0)
                    {
                        cnt ++;
                    }
        }
        
        
    }
    
         // cout<<"sum "<<sum<<endl;

    return cnt;
    
   
}




int sumoflength(vector<int> &A)
{
    int n=A.size();
    // For maintaining distinct elements.
    unordered_set<int> s;
  
    // Initialize ending point and result
    int j = 0, ans = 0;
  
    // Fix starting point
    for (int i=0; i<n; i++)
    {
        // Find ending point for current subarray with
        // distinct elements.
        
        cout<<" j xx "<<j<<endl;
        cout<<" i xx "<<i<<endl;
        while (j < n && s.find(A[j]) == s.end())
        {
            cout<<" j yy "<<j<<endl;
            cout<<" A[j] yy "<<A[j]<<endl;
            s.insert(A[j]);
            j++;
        }
  
        // Calculating and adding all possible length
        // subarrays in arr[i..j]
     //   ans += ((j - i) * (j - i + 1))/2;
     
        cout<<" j "<<j<<endl;
        cout<<" i "<<i<<endl;
        
        ans += (j - i) ;
  
        // Remove arr[i] as we pick new stating point
        // from next
        s.erase(A[i]);
    }
  
    return ans;
}


int main()
{
   vector<int> A ={2, 1, 2};
   int ans = sumoflength(A);
   
  // int B[] ={1, 2, 3};
     // int sum = SubArraySum(B, 3);

       std::cout << ans<< std::endl;
          //      std::cout << sum<< std::endl;


    return 0;
}

