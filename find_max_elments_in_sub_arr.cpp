/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

int maxavl(int a , int b)
{
    return a > b ? a: b;
}
vector<int> slidingMaximum1(const vector<int> &A, int B) 
{
    int n = A.size();
    vector<int> C;
    C.resize(n-B+1);
    int max=INT_MIN;
    int q=0;
    for(int i =0;i<n-B+1;i++)
    {
         max = A[i];
        for (int j =1;j< B;j++)
        {
           
           
                max =maxavl(max , A[j+i]);
           
           
           //    max =maxavl(max , A[j+1]);
           
           
        }
         C[q]= max;
        q++;
        
    }
    return C;
}

vector<int> slidingMaximum(const vector<int> &A, int B) 
{
    int n = A.size();
    vector<int> C;
    C.resize(n-B+1);
    int max=INT_MIN;
    deque<int> Qi;
    
    int q=0;
    int i;
    for( i =0;i<B;++i)
    {
         
        while ((!Qi.empty()) && A[i] >= A[Qi.back()])
        {
           
           Qi.pop_back();
           
        }
        Qi.push_back(i);

    }
    
    
    
    
    
   // while(! Qi.empty() )
    //{
      // cout<<" Q.front "<<A[Qi.front()]<<endl;
       //Qi.pop_front();
       
    //}
    
     for(;i<n;++i)
    {
       //  cout<<" Q.front "<<A[Qi.front()]<<endl;
         C[q]=A[Qi.front()];
         q++;
        while ((!Qi.empty()) && Qi.front() <= i-B)
        {
           
           Qi.pop_front();
           
        }
         
        while ((!Qi.empty()) && A[i] >= A[Qi.back()])
        {
           
           Qi.pop_back();
           
        }
        Qi.push_back(i);

    }
    C[q]=A[Qi.front()];
     //cout<<" Q.front "<<A[Qi.front()]<<endl;
    
    
    // while(! Qi.empty() )
    //{
      // cout<<" Q.front "<<A[Qi.front()]<<endl;
       //Qi.pop_front();
       
    //}
    
    return C;
}

 
int main()
{
    //vector<int> A = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> A = {7, 4, 3, 1, 5};
    int B =3;
 vector<int> C;
// int C;
    C = slidingMaximum(A, B);
    for (int i =0;i < C.size();i++)
        cout<<C[i]<<endl;
    return 0;
}
