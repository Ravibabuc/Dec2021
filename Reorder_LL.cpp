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
    //vector <int> A = {1, 2, 3, 4, 5};
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

ListNode* removeNthFromEnd(ListNode* A, int B) 
{

    ListNode* tmp=A;
    ListNode* tmp1=A;
    ListNode* tmp2;

    int cnt=0;


    while(tmp1 != NULL)   
    {
        tmp1 =tmp1->next;
        cnt++;
    }    
    int step=0;
    int mov=cnt/2;

    //cout<<"step ="<<step<<endl;
    //cout<<"mov ="<<mov<<endl;
    //cout<<"cnt ="<<cnt<<endl;
    if(B < cnt)
    {
        while(tmp != NULL)   
        {
             step++;
             //  cout<<"step ="<<step<<endl;

           if(step==mov)
           {

             //  temp = first->next;
            //first->next = first->next->next;
            //free (temp);
            //return head;
            //cout<<" tmp xx "<<tmp<<endl;
            //cout<<" tmp->next xx "<<tmp->next<<endl;
            //cout<<"tmp data xx   "<<tmp->val<<endl;
             tmp2=tmp->next;
             tmp->next=tmp->next->next;
             delete tmp2;
           // cout<<" tmp "<<tmp<<endl;
            //cout<<" tmp->next "<<tmp->next<<endl;
            //cout<<"tmp data   "<<tmp->val<<endl;
            return A;
           }     


            //cout<<" tmp->next "<<tmp->next<<endl;
            //cout<<"tmp data   "<<tmp->val<<endl;
            tmp =tmp->next;

        }
    }
    else
    {
       // cout<<" tmp xx"<<tmp<<endl;
          // cout<<" tmp->next  x"<<tmp->next<<endl;
        //   cout<<"tmp data  xx "<<tmp->val<<endl;
             tmp2=tmp;
             tmp=tmp->next;
             //tmp->next = tmp->next->next;
             delete tmp2;
          // cout<<" tmp "<<tmp<<endl;
          // cout<<" tmp->next "<<tmp->next<<endl;
          // cout<<"tmp data   "<<tmp->val<<endl;
            return tmp;
    }
   // return A;
}


ListNode* reverseList(ListNode* A) 
{
    ListNode *curr = A;
    ListNode *prev = NULL;
    ListNode *next = NULL;
   
    while(curr != NULL)
    {
        next =curr -> next;
        curr->next =prev;
        prev= curr;
        curr = next;
    }
       
     return prev;

    
}
ListNode* newNode(int key)
{
    ListNode* temp = new ListNode;
    temp->val = key;
    temp->next = NULL;
    return temp;
}

ListNode* reorderList(ListNode* A) 
{
    ListNode *Slow=A;
    ListNode *Fast=A;
    ListNode *Head1=A;
    ListNode *Head2;
    
    while(Fast && Fast->next)
    {
        Fast= Fast->next->next;
        Slow= Slow->next;
    }
    
    Head2= Slow->next;
    Slow->next = NULL;
    Head2 = reverseList(Head2);
    ListNode *tmp1 ;
    ListNode *tmp2 ;
    
    ListNode *Head =new ListNode;
    Head->val = 0;
    Head->next = NULL;
    
    ListNode  *curr = Head;
    while(Head1 || Head2)
    {
        if(Head1)
        {
            curr->next = Head1;
            Head1 = Head1->next;
            curr  = curr -> next;
            
            
        }
        if(Head2)
        {
            curr->next = Head2;
            Head2 = Head2->next;
            curr  = curr -> next;
            
        }
    }
    return Head->next;
}

int main()
{
    //vector<int> A = {1, 3, -1, -3, 5, 3, 6, 7};
    vector <int> A = {1, 2, 3, 4, 5};
    int B =2;
    //list <int>  C;
// int C;
    ListNode* Head;
    Head=insert(Head, A);

   // C = removeNthFromEnd(A, B);
   // for (int i =0;i < C.size();i++)
       // cout<<C[i]<<endl;


   // while(Head != NULL)   
   // {



    //    cout<<" Head->next "<<Head->next<<endl;
     //  cout<<"Head data   "<<Head->val<<endl;
     //   Head =Head->next;
   // }

    Head = reorderList(Head);
    cout<<"ans ----------------------  "<<endl;
    while(Head != NULL)   
    {



        cout<<" Head->next "<<Head->next<<endl;
       cout<<"Head data   "<<Head->val<<endl;
        Head =Head->next;
    }
    
    

    return 0;
}
