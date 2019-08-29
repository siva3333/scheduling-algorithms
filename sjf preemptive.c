#include<stdio.h>
int main()
{
       int i,j,k,n,c,s,si;
       printf("enter the no.of processors");
       scanf("%d",&n);
       float wt[n],a[n],b[n],ta[n],temp,min,w,t,ct,tb[n],max;
       int id[n];
       for(i=0;i<n;i++)
       {
              printf("enter the arrival time");
              scanf("%f",&a[i]);
              printf("enter the burst time");
              scanf("%f",&b[i]);
              id[i]=i;
       }
       min=a[0];
       max=b[0];
       for(i=0;i<n;i++)
       {
           if(a[i]<min)
           {
               min=a[i];
           }
           if(b[i]>max)
           {
               max=b[i];
           }
              for(j=i+1;j<n;j++)
              {
                     if(a[j]<a[i])
                     {
                            temp=a[j];
                            a[j]=a[i];
                            a[i]=temp;
                            temp=b[j];
                            b[j]=b[i];
                            b[i]=temp;
                     }
              }
       }
       for(i=0;i<n;i++)
       {
           tb[i]=b[i];
       }
       c=n;ct=min;s=0;
       while(c>0)
       {
           min=max;
              for(i=n-1;i>=0;i--)
              {
                     if((b[i]<=min)&&(a[i]<=ct)&&(b[i]>0))
                     {
                            min=b[i];
                            s=i;
                     }
              }
               ct++;
              b[s]--;
              if(b[s]<=0)
              {
                  ta[s]=ct-a[s];
                     c--;
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
