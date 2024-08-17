#include<stdio.h>
#include<stdlib.h>
void main()
{
int n,r,i,j,c=0,flag=0,k=0,exec;
printf("Enter number of process:");
scanf("%d",&n);
int a[n],vis[n];
printf("Enter number of resources:");
scanf("%d",&r);
int alloc[n][r],max[n][r],need[n][r],avail[r];
printf("Enter available allocations:");
for(i=0;i<r;i++)
{
scanf("%d",&avail[i]);
}
for(i=0;i<n;i++)
{
vis[i]=0;
printf("Enter maximum allocations for P%d:",i);
for(j=0;j<r;j++)
scanf("%d",&max[i][j]);
printf("Enter allocations for P%d:",i);
for(j=0;j<r;j++)
scanf("%d",&alloc[i][j]);
for(j=0;j<r;j++)
need[i][j]=max[i][j]-alloc[i][j];
}
printf("Process \tAllocation\tMaximum         Need\n");
for(i=0;i<n;i++)
{
printf("P%d\t\t",i);
for(j=0;j<r;j++)
printf("%d ",alloc[i][j]);
printf("\t\t");
for(j=0;j<r;j++)
printf("%d ",max[i][j]);
printf("\t\t"); 
for(j=0;j<r;j++)
printf("%d ",need[i][j]);
printf("\n");
}
while(c<n)
{
flag=0;
for(i=0;i<n;i++)
{
exec=0;
for(j=0;j<r;j++)
{
if(need[i][j]<=avail[j])
exec++;
}
if(exec==r&&vis[i]==0)
{
for(j=0;j<r;j++)
avail[j]+=alloc[i][j];
flag=1;
c++;
a[k++]=i;
vis[i]=1;
}
}
}
if(flag==0)
{
printf("No safe sequence");
exit(0);
}
printf("Safe sequence is:\n");
printf("< ");
for(i=0;i<n;i++)
printf("P%d ",a[i]);
printf(">");
printf("\n");
}
