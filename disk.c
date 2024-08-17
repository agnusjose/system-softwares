#include<stdio.h>
#include<stdlib.h>
void main()
{
int ch,max,hd,n,i,seektime,distance;
do
{
printf("Enter Choice: 1.FCFS 2. Scan 3.CScan 4.Exit");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("Enter head position:");
scanf("%d",&hd);
printf("Enter number of requests:");
scanf("%d",&n);
int req[n];
req[0]=hd;
printf("Enter disk requests:");
for(i=1;i<=n;i++)
scanf("%d",&req[i]);
seektime=0;
for(i=0;i<n;i++)
{
distance=(req[i]>req[i+1])?req[i]-req[i+1]:req[i+1]-req[i];
seektime=seektime+distance;
printf("Disk movement from %d to %d is : %d\n",req[i],req[i+1],distance);
}
printf("Total seektime:%d\n",seektime);
break;
}
case 2:
{
int temp,q1[20],q2[20],q[50],t1=0,t2=0,j;
printf("enter maximum range:");
scanf("%d",&max);
printf("Enter head position:");
scanf("%d",&hd);
printf("Enter number of requests:");
scanf("%d",&n);
printf("Enter disk requests:");
for(i=0;i<n;i++)
{
scanf("%d",&temp);
if(temp>hd)
{
q1[t1]=temp;
t1++;
}
else
{
q2[t2]=temp;
t2++;
}
}
for(i=0;i<t1;i++)
{
for(j=i+1;j<t1;j++)
{
if(q1[i]>q1[j])
{
temp=q1[i];
q1[i]=q1[j];
q1[j]=temp;
}
}
}
for(i=0;i<t2;i++)
{
for(j=i+1;j<t2;j++)
{
if(q2[i]<q2[j])
{
temp=q2[i];
q2[i]=q2[j];
q2[j]=temp;
}
}
}
q[0]=hd;
for(i=0,j=1;i<t1;i++,j++)
q[j]=q1[i];
q[j]=max;
for(i=0,j=t1+2;i<t2;i++,j++)
q[j]=q2[i];
q[j]=0;
seektime=0;
for(i=0;i<=n+1;i++)
{
distance=abs(q[i]-q[i+1]);
seektime=seektime+distance;
printf("Disk movement from %d to %d is : %d\n",q[i],q[i+1],distance);
}
printf("Total seektime:%d\n",seektime);
break;
}
case 3:
{
int temp,q1[20],q2[20],q[50],t1=0,t2=0,j;
printf("enter maximum range:");
scanf("%d",&max);
printf("Enter head position:");
scanf("%d",&hd);
printf("Enter number of requests:");
scanf("%d",&n);
printf("Enter disk requests:");
for(i=0;i<n;i++)
{
scanf("%d",&temp);
if(temp>hd)
{
q1[t1]=temp;
t1++;
}
else
{
q2[t2]=temp;
t2++;
}
}
for(i=0;i<t1;i++)
{
for(j=i+1;j<t1;j++)
{
if(q1[i]>q1[j])
{
temp=q1[i];
q1[i]=q1[j];
q1[j]=temp;
}
}
}
for(i=0;i<t2;i++)
{
for(j=i+1;j<t2;j++)
{
if(q2[i]>q2[j])
{
temp=q2[i];
q2[i]=q2[j];
q2[j]=temp;
}
}
}
q[0]=hd;
for(i=0,j=1;i<t1;i++,j++)
q[j]=q1[i];
q[j]=max;
q[j+1]=0;
for(i=0,j=t1+3;i<t2;i++,j++)
q[j]=q2[i];
seektime=0;
for(i=0;i<=n+1;i++)
{
distance=abs(q[i]-q[i+1]);
seektime=seektime+distance;
printf("Disk movement from %d to %d is : %d\n",q[i],q[i+1],distance);
}
printf("Total seektime:%d\n",seektime);
break;
}
}
}while(ch!=4);
}
