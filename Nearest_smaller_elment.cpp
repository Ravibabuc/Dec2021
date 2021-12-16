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


vector<int> prevSmaller(vector<int> &A) 
{
    
    int n =A.size();
    vector<int> B;
    B.resize(n);
    B[0] =-1;
    int j =0;
    for (int i=1;i<n;i++)
    {
        if(A[i-1] < A[i] )
        {
            j++;
            B[j] = A[i-1];
        }
        else
        {
            if(B[j] >0 && B[j] < A[i]) {
            
                j++;    
                B[j] = B[j-1];
            }
            else {
                int x =j;
                int found =0;
                while (x)
                {
                    if(B[x] >0 && B[x] < A[i])
                    {
                        j++;
                        B[j] =B[x];
                        found=1;
                        break;
                    }
                    x --;
                }
                if(found ==0)
                {
                    j++;
                    B[j] =-1;
                }
            }
            
        }
    }
    return B;
}


int main()
{
   vector<int> A ={34, 35, 27, 42, 5, 28, 39, 20, 28}; //{4, 5, 2, 10, 8};
   
   //-1 34 -1 27 -1 5 28 5 20 
   //-1 34 -1 27 -1 5 28 -1 20 
   //int B =2;
   //string A="azxxzy";
    vector<int> ans = prevSmaller(A);
    for(int i =0;i<ans.size();i++)
        std::cout << ans[i]<< " ";
        cout<<endl;

    return 0;
}

