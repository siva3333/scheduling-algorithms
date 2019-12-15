#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    printf("enter the no.of processes");
    scanf("%d",&n);
    int d[n],e[n];
    for(i=0;i<n;i++)
    {
        printf("enter the deadline");
        scanf("%d",&d[i]);
        printf("enter the execution time");
        scanf("%d",&e[i]);
    }
    int m,j,p[n],t;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(d[i]>d[j])
            {
                t=d[i];
                d[i]=d[j];
                d[j]=t;
                t=e[i];
                e[i]=e[j];
                e[j]=t;
            }
        }
    }
    int ct=0,in,temp[n],l,k,em=0,max=-1,r,td[n];
    for(i=0;i<n;i++)
    {
        temp[i]=e[i];
        if(d[i]>max)
        {
            max=d[i];
        }
        td[i]=d[i];
    }
    i=0;
    while(ct<50)
    {
        s:
            r=0;m=max;
            for(in=0;in<n;in++)
            {
                if(temp[in]>0)
                {
                    if(d[in]<=m)
                    {
                        m=d[in];
                        j=in;
                        r=1;
                    }
                }
            }
            if(r==0)
            {
                ct++;max++;
                for(k=0;k<n;k++)
                {
                    if(d[k]==ct)
                    {
                        temp[k]=e[k];
                        d[k]+=td[k];
                    }
                }
                goto s;
            }
            printf("%d\n",j);
       while(temp[j]>0)
       {
            temp[j]--;
            ct++;max++;
            for(k=0;k<n;k++)
            {
                if(d[k]==ct)
                {
                    temp[k]=e[k];
                    d[k]+=td[k];
                    printf("%d is preempted -%d  remained\n",j,temp[j]);
                    goto s;
                }
            }
       }
       printf("\n%d\t%d\n",temp[j],j);
       i++;
    }
printf("completion time is %d",ct);
}
