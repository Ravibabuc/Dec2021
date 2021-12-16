/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include<stack>

using namespace std;

stack<int> SortArray(stack<int> St)
{
    stack<int> tmpSt;
   
    
    while(!St.empty())
    {
        int tmp = St.top();
        St.pop();
        while(!tmpSt.empty() && tmpSt.top() < tmp)
        {
            St.push(tmpSt.top());
            tmpSt.pop();
        }
        
        tmpSt.push(tmp);
    }
    return tmpSt;
}

vector<int> solve(vector<int> &A) 
{
    int n =A.size(); 
    vector<int> B;
    stack<int> St;
    stack<int> tmpSt;
    B.resize(n);
    
    
    for(int i=0;i<n;i++)
    {
        St.push(A[i]);
    }
    
    tmpSt = SortArray( St);
    int i =0;
    while(!tmpSt.empty())
    {
        B[i] = tmpSt.top();
        tmpSt.pop();
        i++;
    }
    
    
    return B;
}



string solve1(string A) 
{
     stack<char> tmpSt;
    int n =A.size();
    char B[n];
    int i=0;
    while(A[i] != '\0')
    {
      //  cout<<"A[i] "<<A[i]<<endl;
        if (!tmpSt.empty() && tmpSt.top() == A[i])
        {
           // cout<<"if A[i] "<<A[i]<<endl;
            tmpSt.pop();
        }
        else
        {
            tmpSt.push(A[i]);
          // cout<<"else A[i] "<<A[i]<<endl;
        }
        i++;
       
    }
    
    int j =0;
     while(!tmpSt.empty())
        {
       //     cout<<"restore A[i] "<<tmpSt.top()<<endl;
            B[j] = tmpSt.top();
            tmpSt.pop();
         //   cout<<"j "<<j<<endl;
       //     cout<<"B[j "<<B[j]<<endl;
            j++;
            
        }
    B[j]='\0';
    
    int k=0;
    int p =j-1;
   //  cout<<"p "<<p<<endl;
    while(k<=p)
    {
         //cout<<"B[k "<<B[k]<<endl;
        char tmp = B[k];
        B[k] = B[p];
        B[p]=tmp;
        k++;
        p--;
    }
    return B;
}

int main()
{
  // vector<int> A = {1, 2, 3, 4, 5};
   //int B =2;
   string A="azxxzy";
    string ans = solve1(A);
        std::cout << " ans  " <<ans<< std::endl;

    return 0;
}

