#include <stdio.h>
#define MAX 50

int main()
{
    int a[MAX][MAX]={{0,0}} ;
    int i,j,k,n,h,l,ht,lt,total=0,flag=0 ;
    scanf("%d",&n) ;
    h = 1 ;
    ht= n ;
    l = n ;
    lt= 1 ;
    k = n*n ;
    while (total < k )
    {

       if( flag == 0)
       {
           for(i= h,j=l; i<= ht ; i++)
           {
           ++ total ;
           a[i][j] = total ;
           }

            -- l ;

            for(i = l,j=ht; i>=lt ; i--)
            {
             ++ total ;
              a[j][i] = total ;
            }
             -- ht ;
             flag = 1 ;
        }
        else
        {
            for(i=ht,j=lt; i>= h ; i--)
            {
                           ++ total ;
                           a[i][j] = total ;
            }
            ++ lt ;

            for(i=lt,j=h ; i<= l ; i++)
            {
                         ++ total ;
                         a[j][i] = total ;
            }
            ++ h ;
            flag = 0 ;
        }
    }

   for(i=1 ; i<= n; i++)
   {
           for(j=1 ; j<= n; j++)
             printf("%d ",a[i][j]);
           printf("\n");
   }

    return 0 ;
}
