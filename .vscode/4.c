#include <stdio.h>
int main()
{
    char AAA[80];
    int i,j,word=0,num=0;
    printf("please input: ");
    gets(AAA);
    for (i = 0; (j=AAA[i])!='\0' ; i++)
    {
        if (j==' ')
        {
            word=0;}
        else if (word==0)
        {
            /* code */
            word=1;
            num = num +1;
        }
        
        
    }
    
    printf("%d words\n",num);



    return(0);
}
