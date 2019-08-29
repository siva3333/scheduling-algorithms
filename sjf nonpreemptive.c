#include<stdio.h>
int main()
{
       int n,i,j,k,l,x;
       printf("enter the no.of processes");
       scanf("%d",&n);
       float a[n],b[n],wt[n],min,tb,t,ta[n],w,ws,ts,y,m;
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
             if(a[i]<min)
             {
                    min=a[i];
             }
      }
      x=min;
       for(i=0;i<n;i++)
       {
              for(j=i+1;j<n;j++)
              {
                     if((a[j]<=x)&&(b[j]<b[i]))
                     {
                            t=a[i];
                            a[i]=a[j];
                            a[j]=t;
                            t=b[i];
                            b[i]=b[j];
                            b[j]=t;
                     }
              }
               y=0;
              if(a[i]>x)
              {
                     y=a[i]-x;
              }
              x+=y;
              wt[i]=x-a[i];
              x+=b[i];
       }
       for(i=0;i<n;i++)
       {
              ta[i]=wt[i]+b[i];
       }
       printf("pid\twaiting time\tturn around time\n");
       ws=0;ts=0;
       for(i=0;i<n;i++)
       {
              ws=ws+wt[i];
              ts=ts+ta[i];
              printf("%d\t",i);
              printf("%f\t",wt[i]);
              printf("%f\n",ta[i]);
       }
       w=ws/n;
       t=ts/n;
       printf("average waiting time is %f\n",w);
       printf("average turn around time is %f",t);
}
