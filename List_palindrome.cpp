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

ListNode* reverse(ListNode* Head)
{
    ListNode * prev =NULL;
    ListNode * next =NULL;

    ListNode *curr =Head;
    while(curr != NULL)
    {
            next =curr -> next;
            curr->next =prev;
            prev= curr;
            curr = next;
    }
    Head=prev;
    return Head;
}

int compare(ListNode *Node1, ListNode *Node2)
{
    int flag=-1;
   // cout<<"Node2->val "<<Node2->val<<endl;
   // cout<<"Node1->val "<<Node1->val<<endl;
    while((Node2 != NULL) && (Node1 != NULL) )
    {
       
        if(Node2->val==Node1->val)
        {
            flag=1;
            //cout<<"if "<<endl;
        }
        else 
        {
           // cout<<"else "<<endl;
            return 0;
        }
       // cout<<"Node2->val "<<Node2->val<<endl;
       // cout<<"Node1->val "<<Node1->val<<endl;
         Node2 =Node2->next;
        Node1 =Node1->next;
    }
   
    
    return 1;
}

int lPalin(ListNode* A) 
{
    
    ListNode *Head =A;
    ListNode *Slow =A;
    ListNode *Fast =A;
    ListNode *Node2;
    ListNode *Node1;
    ListNode *Prev;


 //   Slow = Slow->next;
   // Fast = Fast->next->next;
    
    while(Fast != NULL && Fast->next != NULL)
    {
        
       
        Fast = Fast->next->next;
        Prev =Slow;
        Slow = Slow->next;
       // cout<<"Fast "<<Fast<<endl;
     //  cout<<"Fast->val "<<Fast->val<<endl;

       // cout<<"Slow "<<Slow<<endl;
       // cout<<"Slow->val "<<Slow->val<<endl;
    }
   // cout<<"Slow "<<Slow->next<<endl;
   // cout<<"Slow val "<<Slow->val<<endl;
  //  cout<<"Prev "<<Prev->next<<endl;
   // cout<<"Prev->val "<<Prev->val<<endl;
   // Node1 =A;
   
    ListNode *midnode =NULL;
   
    if (Fast != NULL)
    {
        midnode = Slow;
        Slow = Slow->next;
    }
   
    Node2 =Slow;
    Prev->next =NULL;
   // cout<<"Fast "<<Node2->next<<endl;
  //  cout<<"Fast->val "<<Node2->val<<endl;
    Node2 =reverse(Node2);
    
    int x =compare(A, Node2);
    Node2 =reverse(Node2);
    if (midnode != NULL)
    {
        Prev->next = midnode;
        midnode->next = Node2;
    }
    else
        Prev->next = Node2;
  //  cout<<"x val   "<<x<<endl;
   return x;
}



int main()
{
    //vector<int> A = {1, 3, -1, -3, 5, 3, 6, 7};
    vector <int> A = {1, 2, 3,3,  2,1};
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

    int cnt=0;
    cnt = lPalin(Head);
    cout<<" cnt "<<cnt<<endl;
    cout<<"ans ----------------------  "<<endl;
    while(Head != NULL)   
    {


        cout<<" Head->next "<<Head->next<<endl;
       cout<<"Head data   "<<Head->val<<endl;
        Head =Head->next;
        
       // if(cnt == 20) break;
    }
    
    

    return 0;
}
