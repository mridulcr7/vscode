#include<stdio.h>
#include<math.h>
 
int main(){
  int a[100];
  for(int i=0;i<100;i++)
  a[i]=1;
  int j=1;
  for(int i=0;i<99;i++)
  {
    while(a[j%100]==0)
    {
       j++;
    }
    a[j%100]=0;
    j++;
    while(a[j%100]==0)
    {
      j++;
    }
    j++;
  }
  for(int i=0;i<100;i++)
  if(a[i]==1)
  printf("%d",i+1);
  return 0;
}