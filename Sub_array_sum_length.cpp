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



int solve1vector<int> &A, int B) 
{
    
   // vector<int>Pre;
    
    int n =A.size();
 //   Pre.resize(n);
    int k =n;
    //Pre[0] =A[0];
 //   for(int i =1;i<n;i++)
   // {
    //    Pre[i]= Pre[i-1] +A[i];
    //    cout<<" Pre " <<Pre[i]<<endl;
   // }
    int sum =0;
    int start=0;
   //  cout<<"k "<<k<<endl;
    for (int i =0;i<n;i++)
    {
        sum += A[i];
        
        while(sum > B)
        {
            sum -= A[start];
            start++;
            k = min(k, i - start +1 );
          //  cout<<"i - start+1 "<<i - start+1<<endl;
            //cout<<"k "<<k<<endl;
            if (sum==0) break;
        }
          if (sum == 0) {
            k = -1;
            break;
        }
    }
    return k;
}

int solve(vector<int> &A, int B) 
{
    
   vector<int>Pre;
    
    int n =A.size();
    Pre.resize(n);
    int k =n;
   Pre[0] =A[0];
   for(int i =1;i<n;i++)
   {
        Pre[i]= Pre[i-1] +A[i];
       cout<<" Pre " <<Pre[i]<<endl;
    }
    int sum =0;
    int start=0;
   //  cout<<"k "<<k<<endl;
    
    return k;
}


int main()
{
  // vector<int> A ={2, 3, 1, 5, 4};
 // vector<int> B ={1, 3, 5, 4, 2};
   
   vector<int> A ={ 1, 2, 3, 4, 5};
   
   int B =10;
  int ans  = solve(A,B);
   
   //vector<int> ans = wave1(A);
    //int n =ans.size();
    //for(int i =0;i < n;i ++)
    //std::cout <<" ans " <<ans[i]<< std::endl;
    std::cout <<" ans " <<ans<< std::endl;


    return 0;
}

