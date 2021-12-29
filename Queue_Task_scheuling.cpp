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
//};

int solve(vector<int> &A, vector<int> &B)
{
    //Data Node;
    int n =A.size();
   
   // int Order=1;
    int clk=0;
    queue<int> Que;
    
    
    for(int i =0;i<n;i++)
    {
      // Node.Task=A[i];
       // Node.Priority=B[i];
        Que.push(A[i]);
    }
    int i=0;
    while(!Que.empty())
    {
        //cout<<"Que "<<Que.front()<<endl;
      //  cout<<"Que "<<Que.front().Priority<<endl;
        if(Que.front() == B[i])
        {
            Que.pop();
            i ++;
            
        }
        else
        {
            Que.push(Que.front());
            Que.pop();
        }
        clk++;
    }
    
    return clk;
}



int main()
{
  // vector<int> A ={2, 3, 1, 5, 4};
 // vector<int> B ={1, 3, 5, 4, 2};
   
   vector<int> A ={6, 7, 1, 2, 4, 5, 8, 3 };
   vector<int> B ={3, 7, 2, 5, 1, 8, 4, 6};
   
   int ans;
   int n =A.size();
   ans = solve(A, B);

    std::cout <<" ans " <<ans<< std::endl;


    return 0;
}

