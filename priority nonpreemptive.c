#include<stdio.h>
int main()
{
       int i,j,k,n,in;
       printf("enter the no.of processors");
       scanf("%d",&n);
       float b[n],p[n],wt[n],ct,w,t,temp,m;
       for(i=0;i<n;i++)
       {
              printf("enter the burst time");
              scanf("%f",&b[i]);
              printf("enter the priority");
              scanf("%d",&p[i]);
       }
       for(i=0;i<n;i++)
       {
              for(j=0;j<n-1;j++)
              {
                     if(p[j]>p[j+1])
                     {
                            temp=p[j];
                            p[j]=p[j+1];
                            p[j+1]=temp;
                            temp=b[j];
                            b[j]=b[j+1];
                            b[j+1]=temp;
                     }
              }
       }
       ct=0;
       for(i=0;i<n;i++)
       {
            wt[i]=ct;
            ct=ct+b[i];
            p[i]=ct;
       }
       printf("pid\twaiting time\tturn around time\n");
       w=0;
       t=0;
       for(i=0;i<n;i++)
       {
              w+=wt[i];
              t+=p[i];
              printf("%d\t",i+1);
              printf("%f\t",wt[i]);
              printf("%f\n",p[i]);
       }
       w=w/n;
       t=t/n;
       printf("average waiting time is %f\n",w);
       printf("average turn around time is %f",t);
}
