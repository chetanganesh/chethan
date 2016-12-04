#include<stdio.h>
#include<stdlib.h>
int palldrom(char *);
int recpal(char*);
int main()
{
   char s[]="kabak";
   int res;

 // res= palldrom(s);
   
recpal(s);
/*if(res==1)
         printf("pallendrom\n");
   else
        printf("not pallendrom\n");*/
   return 0;
}
int palldrom(char *s)
{
     int i,j;
    for(i=0;s[i];i++);
     j=i-1;
      for(i=0;i<j;i++,j--)
      {
                 if(s[i]!=s[j])
                     return 0;
      }
       
      return 1;
}       
int recpal(char *s)
{
 static int i=0,j=0;
    if(s[j]=='\0')   
       return 1;
    
     j++;
   recpal(s);
     j--;

   if(s[i]!=s[j])
   {
       printf("not pallendrom\n");
         exit(0);
   }
   else if(i>j)
   {
         printf("pallendrom\n");
         exit(0);
   }
      i++;
}        
  
      
