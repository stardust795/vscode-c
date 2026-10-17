#include <stdio.h>
int max2(int a,int b)
{
    if (a>=b)
    {
        return(a);
    }
    else 
    return(b);
}

int max4(int a,int b,int c,int d)
{   
    int j;
    j = max2(a,b);
    j = max2(j,c);
    j = max2(j,d);
    return(j);
}

int main()
{   int max2(int a,int b);
    int a,b,c,d,max;
    printf("input:");
    scanf("%d,%d,%d,%d",&a,&b,&c,&d);
    max = max4(a,b,c,d);
    printf("max is %d",max);

    return(0);
}

