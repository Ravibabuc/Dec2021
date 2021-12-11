/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;





int Fact1(int B)
{
    int M=1000000006;
  
  
   //cout <<" mod "<< 6227020800 % M <<endl;
    
    long   ans = 1;
    for (int i =1;i<=B;i++)
    {
        ans = (ans % M  * i % M ) % M;
        //std::cout <<" Factor "<<ans <<std::endl;
    }
    return  ans;
}

long Fact(int B)
{
    int M=1000000006;
    if(B <=1) return 1;
    
    return ( (B  ) * Fact(B-1 )) % M;
}


long power_val(long x, int n)
{
    int mod=1000000007;
    
     //cout<<" hello 3"<<endl;
    if (n == 0) return 1;
    if (n == 1) return x;

    if (x ==0) return 0;
    
       cout<<" n11 ="<<n<<endl;    
    if( n % 2 ==0 )
    {
            //    cout<<" n12 ="<<n<<endl;    
        cout<<" x ="<<x<<endl;    

        
              return  (power_val((x *x )% mod , n /2  )) % mod ;
        
    }
    else
    {
       //  cout<<" n13 ="<<n<<endl;    
        cout<<" x13 ="<<x<<endl; 
        return (x * power_val((x  )  % mod  , n -1 )) % mod ;
        
    }
}

int exponentMod(int A, int B, int C)
{
    // Base cases
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;
 
    // If B is even
    long y;
    if (B % 2 == 0) {
        y = exponentMod(A, B / 2, C);
        y = (y * y) % C;
    }
 
    // If B is odd
    else {
        y = A % C;
        y = (y * exponentMod(A, B - 1, C) % C) % C;
    }
 
    return (int)((y + C) % C);
}


int solve(int A, int B) {
    

   
     int Factval= Fact(B);
     
 
    //std::cout <<" Factor "<<Factval <<std::endl;
    
    int C=1000000007;
    
    long y =power_val(A, Factval);
    return y;

}

int main()
{
    int A= 2;
    int B =27;
    int M=1000000007;
    long C =solve(A, B);
    std::cout <<"ans =" <<C << std::endl;
    
    long ans = power_val(2 , 120);
   std::cout <<"ans2 =" <<ans << std::endl;
   
    int ans3 = exponentMod(2 , 120, M);
   std::cout <<"ans3 =" <<ans3 << std::endl;

    return 0;
}
