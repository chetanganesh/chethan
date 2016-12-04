#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
}*head1,*head2,*curr;
void inter_node();
void node_cr(int,struct node**);
int main(int argc,char*argv[])
{
   head1=head2=curr=NULL;
    int i,k=10;
  struct node *p,*q;
  for(i=1;i<=(atoi(argv[1]));i++)
       node_cr(i,&head1);
 for(i=1;i<=(atoi(argv[2]));i++,k++)
       node_cr(k,&head2);


printf("printing firstnode \n");
  for(p=head1;p!=NULL;p=p->link)
                                        
     printf("\n%d\n",p->data);
for(p=head1;p->data!=4;p=p->link);

  printf("curr=%d\n\n",curr->data);


curr->link=p;

printf("printing secondnode \n");
  for(p=head2;p!=NULL;p=p->link)                                 
     printf("\n%d\n",p->data);
 
 printf("\n\n\n\n");
inter_node();
  return 0;
}
void node_cr(int data,struct node **p)
{
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=data;
  temp->link=NULL;
  if(*p==NULL)
      curr=*p=temp;
  else
   {
         curr->link=temp;
        curr=temp;
   }
}

void inter_node()
{
   struct node *p1,*p2;
  int count1=1,count2=1,pos;
   p1=head1;
   p2=head2;
   
     while(p1!=NULL||p2!=NULL)
     {
          if(p1!=NULL)
           {
               p1=p1->link;
                count1++;
           }
          if(p2!=NULL)
           {
              p2=p2->link;
               count2++;
           }
     }
    
    if(count1>count2){p1=head1;p2=head2;
         pos=count1-count2;}
    else{p1=head2;p2=head1;
         pos=count2-count1;}
  count1=1;
  while(p1!=NULL&&p2!=NULL)
  {
         if(count1<=pos)
         {
            p1=p1->link;
            count1++;
        }
        else
        {
             if(p1->data==p2->data)
             {
                 printf("\nintersection point=%d\n",p1->data);
                     break;
             }
              p1=p1->link;
              p2=p2->link;
        }
  }
}

