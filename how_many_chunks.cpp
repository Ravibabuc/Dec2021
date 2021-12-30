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

//struct Data
//{
 //   int Task;
  //  int Priority;
//}

vector<int> wave(vector<int> &A) 
{
    int n =A.size();
    sort(A.begin(), A.end());

    
    for(int i =0;i<n-1;i+=2)
    {
        int temp= A[i];
        //cout <<"A[i] "<<A[i]<<endl;
        //cout <<"A[i+1] "<<A[i+1]<<endl;
        A[i] = A[i+1] ;
        A[i+1]= temp;
    }
   // cout<<"hello"<<endl;
    return A;
}
void swap(int *a, int *b)
{
    int temp= *a;
    *a = *b;
    *b = temp;
}

int wave1(vector<int> &A) 
{
    int n =A.size();
   // sort(A.begin(), A.end());
    int cnt =0;
    int max1 =0;
    
    for (int i = 0; i < n; i++)
    {
       
        //cout <<"A[i] "<<A[i]<<endl;
        //cout <<"A[i+1] "<<A[i+1]<<endl;
        max1 = max(max1, A[i]);
        if(i == max1)
            cnt++;
        
    }
   // cout<<"hello"<<endl;
    return cnt;
}



int main()
{
  // vector<int> A ={2, 3, 1, 5, 4};
 // vector<int> B ={1, 3, 5, 4, 2};
   
   vector<int> A ={ 1, 2, 3, 4 ,0};
   
   
  int ans  = wave1(A);;
   
   //vector<int> ans = wave1(A);
    //int n =ans.size();
    //for(int i =0;i < n;i ++)
    //std::cout <<" ans " <<ans[i]<< std::endl;
    std::cout <<" ans " <<ans<< std::endl;


    return 0;
}

