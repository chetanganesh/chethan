#include<stdio.h>
#include<stdlib.h>
void node_cr(int);
void node_at_par_pos(int ,int );
void node_del_at_parpos(int );
void node_atevery_parpos(int );
void node_add_atevery_parpos(int,int);
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
//node_at_par_pos(3,10);
//node_del_at_parpos(5); 
//node_atevery_parpos(atoi(argv[2])); 
node_add_atevery_parpos(atoi(argv[2]),atoi(argv[3]));

  for(p=head;p!=NULL;p=p->link)
     printf("%d\n",p->data);
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
// ADDITION OF NODE AT PARTICUAL POSITION
void node_at_par_pos(int pos,int data)
{
   struct node *p=head,*temp;
    int count=1;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
 
  while(p!=NULL)
  {
         if(count<(pos-1))
         {
              p=p->link;
              count++;
         }
         else
         {
            temp->link=p->link;
            p->link=temp;
              break;
        }
  }
}
// DELETION OF NODE AT PARTICULAR POSITION
void node_del_at_parpos(int pos)
{
   struct node *p=head,*temp;
    int count=1;
    while(p->link!=NULL)
     {
            if(count<(pos-1))
             {
                 p=p->link;
                 count++;
             } 
             else
             {
                  temp=p->link;
                  p->link=p->link->link;
                
                   free(temp);
                     break;
             }
     }
}
// DELETION OF NODE AT EVERY PARTICULAR POSITION
void node_atevery_parpos(int pos)
{
   struct node *p=head,*temp;
   int count=1;
    
   while(p->link!=NULL)
    {
           if(count<(pos-1))
           {
               p=p->link;
              count++;
           }
	   else
	  {
 		count=1;
              temp=p->link;
              p->link=p->link->link;
		  if(p->link!=NULL)		
                        p=p->link;
                   free(temp);
          }
    }
}
     
// ADDITION OF NODE AT EVERY PARTICULAR POSITION
void node_add_atevery_parpos(int data,int pos)
{
   struct node *p=head,*temp;
   int count=1;
  while(p!=NULL)
    {
           if(count<(pos-1))
           {
               p=p->link;
              count++;
           }
	   else
	  {
 		count=1; 
              temp=(struct node*)malloc(sizeof(struct node));
              temp->data=data;
              temp->link=NULL;
              temp->link=p->link;
             p->link=temp;
		  		
                        p=temp->link;
             
                   
          }
   }
}
