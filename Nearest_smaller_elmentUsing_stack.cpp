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


vector<int> prevSmaller1(vector<int> &A) 
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

vector<int> prevSmaller(vector<int> &A) 
{
    stack<int> St;
    int n =A.size();
    vector<int> B;
    B.resize(n);
    int j =0;
    B[0] =-1;
    //St.push(A[0]);
   cout<<"hello2 "<<endl;
    for (int i=1;i<n;i++)
    {
         cout<<"hello1 "<<endl;
        if(A[i-1] < A[i] )
        {
            cout<<"if "<<endl;
            j++;
            B[j] = A[i-1];
            St.push(A[i-1]);
        }
        else if(!St.empty() && St.top() < A[i] )
        {
            cout<<"else if "<<endl;
            j++;    
            B[j] = St.top();
             St.push(A[i-1]);
        }
        else
        {
             cout<<"else  "<<endl;
            while (!St.empty() && St.top() >= A[i] )
            {
                   St.pop();
            }
            
            if(!St.empty() &&  St.top () < A[i])
            {
                j++;    
                B[j] = St.top ();
                St.push(A[i]);
            }
            else
            {
                St.push(A[i]);
                j++;    
                B[j] = -1;
            }
        }
    }
    return B;
}

int main()
{
   vector<int> A ={8, 23, 22, 16, 22, 7, 7, 27, 35, 27, 32, 20, 5, 1, 35, 28, 20, 6, 16, 26, 48, 34};//  {7, 6, 5, 4, 3, 2, 1}; //{34, 35, 27, 42, 5, 28, 39, 20, 28}; //{4, 5, 2, 10, 8};
   
   //8, 23, 22, 16, 22, 7, 7, 27, 35, 27, 32, 20, 5, 1, 35, 28, 20, 6, 16, 26, 48, 34
   //-1 8 8 8 16 -1 -1 7 27 7 27 7 -1 -1 1 1 1 1 6 16 26 26
   //-1 8 8 8 16 -1 -1 7 27 7 27 7 -1 -1 1 1 1 1 6 16 26 26 
   //-1 8 8 8 16 -1 -1 7 27 -1 27 7 -1 -1 1 1 1 1 6 16 26 26 
   
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

