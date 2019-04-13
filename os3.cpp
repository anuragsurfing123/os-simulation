#include <stdio.h>
int main() 
{
 int i,j,a[10],b[10],p[10]={1,2,3,4,5,6,7,8,9,10},temp,tat[10],wat[10],n,min,k=1,btime=0,ta=0,sum=0;
  

float avgwat=0,avgtat=0,tsum=0,wsum=0;
  
  
  
  
  
 printf("enter the number of Processes:\n");
 scanf("%d",&n); 
 
 printf("enter arrival time\n");
 for(i=0;i<n;i++)
 {
    scanf("%d",&a[i]); 
 }
 printf("enter burst time\n");
 for(i=0;i<n;i++)
 {
    scanf("%d",&b[i]); 
 }
 
 
 
 
 /*Sorting According to Arrival Time*/
 
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i]<a[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=a[j];
a[j]=a[i];
a[i]=temp;
temp=b[j];
b[j]=b[i];
b[i]=temp;
}
}
}
 
/*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/
 
for(j=0;j<n;j++)
{
btime=btime+b[j];
min=b[k];
for(i=k;i<n;i++)
{
if (btime>=a[i] && b[i]<min)
{
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=a[k];
a[k]=a[i];
a[i]=temp;
temp=b[k];
b[k]=b[i];
b[i]=temp;
}
}
k++;
}
wat[0]=0;
for(i=1;i<n;i++)
{
sum=sum+b[i-1];
wat[i]=sum-a[i];
wsum=wsum+wat[i];
}
 
avgwat=(wsum/n);
for(i=0;i<n;i++)
{
ta=ta+b[i];
tat[i]=ta-a[i];
tsum=tsum+tat[i];
}
avgtat=(tsum/n);
 
 
 
 
 
 
 printf("************************");
printf("\n RESULT:-");
printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(i=0;i<n;i++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],b[i],a[i],wat[i],tat[i]);
}
 
printf("\n\nAVERAGE WAITING TIME : %f",avgwat);
printf("\nAVERAGE TURN AROUND TIME : %f",avgtat);
return 0;
}
