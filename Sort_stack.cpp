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





int main()
{
   vector<int> A = {1, 2, 3, 4, 5};
   int B =2;
    vector <int> ans = solve(A);
    for(int i=0;i<ans.size();i++)
        std::cout << ans[i] << std::endl;

    return 0;
}

