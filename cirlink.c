#include<stdio.h>
#include<stdlib.h>
void node_cr(int);
void cir_del(int);
struct node
{
  int data;
  struct node *link;
}*head,*curr;
int main(int argc,char*argv[])
{
   head=curr=NULL;
    int i;
  struct node *p;
  for(i=1;i<=(atoi(argv[1]));i++)
       node_cr(i);
   curr->link=head;
    
   cir_del(atoi(argv[2]));
  p=head;
  do
  {
     printf("%d\n",p->data);
      p=p->link;
  }while(p!=head);
 
  return 0;
}
void node_cr(int data)
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=data;
  temp->link=NULL;
  if(head==NULL)
      curr=head=temp;
  else
   {
         curr->link=temp;
        curr=temp;
   }
}
void cir_del(int pos)
{
  struct node *p=head,*temp;
  int count=0;
  
  do
  {
        if(count<(pos-1))
        {
             p=p->link;
             count++;
       }
       else
       {
              count=1;
           p->link=p->link->link;
           p=p->link;
       }
     if(p->link==p){
        head=p;printf("p=%d\n",p->data);}

  }while(p->link!=p);  
} 
