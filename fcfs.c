#include<stdio.h>
int main()
{
       int n,i,j,k,c;
       printf("enter the no.of processes");
       scanf("%d",&n);
       float a[n],b[n],wt[n],x,y,w,t,temp;
              printf("do you have arrival time");
              printf("1.yes\n2.no\n");
              scanf("%d",&c);
              switch(c)
              {
              case 1:
                     for(i=0;i<n;i++)
                     {
                     printf("enter the arrival time");
                     scanf("%f",&a[i]);
                     printf("enter the burst time");
                     scanf("%f",&b[i]);
                     }
                     break;
              case 2:
                     for(i=0;i<n;i++)
                     {
                     a[i]=0;
                     printf("enter the burst time");
                     scanf("%f",&b[i]);
                     }
              }
       for(i=0;i<n;i++)
       {
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
       x=0;
       for(i=0;i<n;i++)
       {
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
              a[i]=wt[i]+b[i];
       }
       printf("pid\twaiting time\tturn around time\n");
       w=0;
       t=0;
       for(i=0;i<n;i++)
       {
              w+=wt[i];
              t+=a[i];
              printf("%d\t",i+1);
              printf("%f\t",wt[i]);
              printf("%f\n",a[i]);
       }
       w=w/n;
       t=t/n;
       printf("average waiting time is %f\n",w);
       printf("average turn around time is %f",t);
}
