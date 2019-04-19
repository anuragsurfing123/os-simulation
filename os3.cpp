//SJF Scheduling Programm
#include <stdio.h>
#include <stdlib.h>
int main() 
{
 int i,j,a[20],b[20],p[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},temp,tat[20],wat[20],n,min,k=1,btime=0,ta=0,sum=0;
  

float avgwat=0,avgtat=0,tsum=0,wsum=0;
  
printf("***************OPERATING SYSTEM PROJECT************************\n");

 start:                                          //for start process again
  
  /*take Input through User*/
 printf("enter the number of Processes:\n");
 scanf("%d",&n); 
 
 printf("enter arrival time\n");
 for(i=0;i<n;i++)
 {  
    scanf("%d",&a[i]); 
    
  if(a[i]==0)                                  //loop works when arrival time is zero
    {
    	printf("Arrival time will not be zero(As per Test Cases) enter Arrival time Again\n");
    	printf("--------------------------------------------------------------------------\n\n\n");
    	goto start;
    	
	}
 }
 printf("enter burst time\n");
 for(i=0;i<n;i++)
 {
    scanf("%d",&b[i]); 
 }
 
 
 
 
 //Sorting According to Arrival Time
 
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
//for calculate waiting time
wat[0]=0;
for(i=1;i<n;i++)
{
sum=sum+b[i-1];
wat[i]=sum-a[i];
sum=sum+2;
wsum=wsum+wat[i];
}
 
avgwat=(wsum/n);
//for calculate Turn Arround Time
for(i=0;i<n;i++)
{
ta=ta+b[i];
tat[i]=ta-a[i];
ta=ta+2;
tsum=tsum+tat[i];
}
avgtat=(tsum/n);
 
 
 
//Output 
 
 printf("------------------------\n");
 printf("RESULT:-\n");
 printf("************************\n");

printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(i=0;i<n;i++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],b[i],a[i],wat[i],tat[i]);
}
printf("\n\n---------------------------------------------------------------------\n");
printf("\n\nAVERAGE WAITING TIME : %f",avgwat);
printf("\nAVERAGE TURN AROUND TIME : %f",avgtat);
return 0;
}
