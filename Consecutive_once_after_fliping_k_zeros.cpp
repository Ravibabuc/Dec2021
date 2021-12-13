/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int max_value(int a, int b)
{
    return a> b? a: b;
}


vector<int> maxone(vector<int> &A, int B) 
{
    int n =A.size();
    vector <int> ans;
    int cnt =0;
    int curcnt=0;
    int indx1=0, indx2=0;
    int Zcnt=0;
    int tcnt=0;
    int tzcnt=0;
    
    
    int start=0;
    int end=0;
    for( end=0;end <n; end ++)
    {
      

        if(A[end] == 0 )
        {
             Zcnt ++;
            
            
        }
        
     //     cout<<" A[end]  " <<A[end]<<endl;
       // cout<<" end " <<end<<endl;
        //cout<<" start " <<start<<endl;
         //cout<<" Zcnt " <<Zcnt<<endl;
           //       cout<<" curcnt " <<curcnt<<endl;

        while(Zcnt> B)
        {
            if(A[start] ==0)
            {
                Zcnt --;
               
            }
             start ++;
        }
        if (curcnt < (end- start +1))
        {
            indx1=start;
            indx2=end+1;
            curcnt=(end- start +1);
        }
    }
    
     ans.resize(indx2-indx1);
    for(int i =indx1, j=0;i<indx2;i++ , j++)
    {
        ans[j]= i;
    }
    return ans;
    
   
}



int main()
{
   vector<int> A ={1 ,1, 0, 1, 1, 0, 0, 1, 1, 1};// {1, 0, 0, 0, 0, 0, 1, 0, 1, 1};
   int B =1;
    vector <int> ans = maxone(A, B);
    for(int i=0;i<ans.size();i++)
        std::cout << ans[i] << std::endl;

    return 0;
}

