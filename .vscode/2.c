#include <stdio.h>
/* 降序冒泡排序练习 */
int main()
{   int i,j,k,a[5];
    
    for ( i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n");
    for ( j = 0; j < 4; j++)
    {
        for ( i = 0; i < 4-j; i++)
        {
            if (a[i]<a[i+1])
            {
                k = a[i];
                a[i] = a[i+1];
                a[i+1] = k;

            }
            
        }
        
    }

    for ( i = 0; i < 5; i++)
    {
        printf("%d ",a[i]);
    }
    


    return(0);
}