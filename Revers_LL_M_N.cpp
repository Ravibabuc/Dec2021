#include <iostream>
#include <vector>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};



ListNode *insert(ListNode* Head, vector<int>& A)
{
    int n =A.size();

    Head= new ListNode();
    Head->val=A[0];
    ListNode  *tmp =NULL;
    Head->next=tmp;

  //  cout<<" Head "<<Head<<endl;
  //  cout<<"Head data   "<<Head->val<<endl;
 //   cout<<" Head-> next "<<Head-> next<<endl;
    tmp= new ListNode();
    tmp->val=A[1];
    Head-> next= tmp;
    tmp->next=NULL;

   //  cout<<" Head "<<Head<<endl;
   // cout<<"Head data   "<<Head->val<<endl;
  //  cout<<" Head-> next "<<Head-> next<<endl;

   for(int i =2;i<n;i++)
    {

       ListNode* tmp1= new ListNode();
       tmp1->val=A[i];
       tmp1-> next= NULL;
       tmp->next=tmp1;
       tmp = tmp->next;
      // cout<<" Head-> next "<<Head-> next<<endl;
      // cout<<"Head data   "<<tmp->val<<endl;

    }
    return Head;
}

ListNode* reverse(ListNode* A, int B, int C)
{
    ListNode *curr1= A;
    ListNode *curr;
    ListNode *prev = NULL;
    ListNode *next = NULL;
    ListNode *join = NULL;

    ListNode *ptr1;
    ListNode *ptr2;
    
    int cnt=1;
    
    if(A == NULL || A ->next == NULL) 
        return A;
    ListNode * ptr0=NULL;
    while(curr1 != NULL)
    {
        
      //  cout<<" curr1 aa "<<curr1<<endl;
       // cout<<" curr2->valaa "<<curr1->val<<endl;
         if(cnt <B)
        {
            ptr0=curr1;
        }
        
        if(cnt ==B)
        {
           
            ptr1=curr1;
          //   cout<<" ptr1->valaa "<<ptr1->val<<endl;
        }
        if(cnt ==C)
        {
            ptr2=curr1->next;
        }
        curr1 = curr1->next;
        cnt ++;
    }
   // cout<<" ptr1 "<<ptr1<<endl;
   // cout<<" ptr1 "<<ptr1->val<<endl;


    curr =ptr1;
    while(curr != ptr2)
    {
       
      
        next =curr -> next;
        curr->next =prev;
        prev= curr;
        curr = next;
        
        //cout<<" curr "<<curr<<endl;
      //  cout<<" curr "<<curr->val<<endl;
    }
    join=prev;
    ListNode * Node1 = join;
   while(Node1 != NULL)
   {
        
      // cout<<" joinyy "<<Node1->next<<endl;
      // cout<<" joinyy "<<Node1->val<<endl;
     
       if(Node1->next ==NULL)
       {
           //cout<<" ptr2 nyy "<<ptr2->val<<endl;
        Node1 -> next = ptr2;
        break;
       }
        
       Node1= Node1->next;
   }
    if (ptr0 == NULL)
    {
       // cout<<"hello1"<<endl;
         ptr0=join;
         return ptr0;
    }
    else
    {
       // cout<<"hello2"<<endl;
        ptr0 -> next=join;
    }
     return A;
}




int main()
{
   //vector<int> A = {1, 2, 3, 4, 5, 6};
  // vector<int> A = {1, 2, 3, 4, 5, 6};
    vector <int> A ={97 , 63 , 89 , 34 , 82 , 95 , 4 , 70 , 14 , 41 , 38 , 83 , 49 , 32 , 68 , 56 , 99 , 52 , 33 , 54}; //{1, 2, 3, 4,5,6};
    int B =2;
    //list <int>  C;
// int C;
    ListNode* Head;
    Head=insert(Head, A);

   // C = removeNthFromEnd(A, B);
   // for (int i =0;i < C.size();i++)
       // cout<<C[i]<<endl;
    ListNode *curr =Head;
    cout<<"list started ----------"<<endl;
    while(curr != NULL )   
   {



       cout<<" Head->next "<<curr->next<<endl;
       cout<<"Head data   "<<curr->val<<endl;
       curr =curr->next;
    }
    cout<<"list end ----------"<<endl;
    int cnt=0;
    Head = reverse(Head, 13, 15);
    cout<<" cnt "<<cnt<<endl;
    cout<<"ans ----------------------  "<<endl;
    while(Head != NULL)   
    {


        cout<<" Head->next "<<Head->next<<endl;
       cout<<"Head data   "<<Head->val<<endl;
        Head =Head->next;
        cnt ++;
       // if(cnt == 10) break;
    }
    
    

    return 0;
}
