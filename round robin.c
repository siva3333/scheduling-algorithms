#include<stdio.h>
#define max 10
int rear=0,front=0;
int q[max];
void insert(int);
int del();
int main ()
{
    int i,j,k,n,tq,v,s,c,x,in;
    printf("enter the no.of processors");
    scanf("%d",&n);
    printf("enter the time quantum");
    scanf("%d",&tq);
    float a[n],b[n],wt[n],ta[n],min,w,t,temp,ct,tb[n],z;
    for(i=0;i<n;i++)
    {
        printf("enter the arrival time");
        scanf("%f",&a[i]);
        printf("enter the burst time");
        scanf("%f",&b[i]);
    }
    min=a[0];
    for(i=0;i<n;i++)
    {
        tb[i]=b[i];
        if(a[i]<min)
        {
            min=a[i];
        }

    }
    ct=min;
    for(i=0;i<n;i++)
    {
        if(a[i]==ct)
        {
            insert(i);
        }
    }
    c=0;
    while(c<n)
    {
        x:
        v=del();
        if(v==-1)
        {
            i=0;
            while((a[i]<ct)&&b[i]>=0)
            {
                i++;
            }
            ct=a[i];
            insert(i);
            goto x;
        }
        for(s=0;s<tq;s++)
        {
            if(b[v]==0)
            {
                break;
            }
            b[v]--;
            ct++;
                for(i=0;i<n;i++)
                {
                   if(a[i]==ct)
                   {
                      insert(i);
                   }
                }
        }
        if(b[v]==0)
        {
            c++;
            ta[v]=ct-a[v];
        }
        else
        {
            insert(v);
        }
    }
    for(i=0;i<n;i++)
    {
        wt[i]=ta[i]-tb[i];
    }
    printf("pid\twaiting time\tturn around time\n");
       w=0;
       t=0;
       for(i=0;i<n;i++)
       {
              w+=wt[i];
              t+=ta[i];
              printf("%d\t",i+1);
              printf("%f\t",wt[i]);
              printf("%f\n",ta[i]);
       }
       w=w/n;
       t=t/n;
       printf("average waiting time is %f\n",w);
       printf("average turn around time is %f",t);
       return 0;
}
void insert(int e)
{
    q[rear++]=e;
}
int del()
{
       int n,i;
       if((front==0)&&(rear==0))
       {
           return -1;
       }
       else
       {
            n=q[front];
              for(i=front;i<=rear;i++)
              {
                     q[i]=q[i+1];
              }
              rear--;
       return n;
       }
}
