#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int point1,point2,game1,game2,set1,set2;
} match;
int main()
{
    char * a=(char *)malloc(sizeof(char)*300);
    FILE *f=fopen("game.txt","r");
    fscanf(f,"%s",a);

    char c;
    match x;
    int i=0;
    c=a[i];

    x.point1=0;
    x.point2=0;
    x.game1=0;
    x.game2=0;
    x.set1=0;
    x.set2=0;
    while( x.set1<2 && x.set2<2 && (c=='A' || c=='B'))
    {

        if(x.game1>(x.game2+1) && x.game1>5)
        {
            x.set1++;
            x.game1=0;
            x.game2=0;

        }
        else
            if(x.game2>(x.game1+1) && x.game2>5)
            {
                x.set2++;
                x.game1=0;
                x.game2=0;
            }
            else
            {
                if(x.point1>3 && x.point1>(x.point2+1))
                {
                    x.point1=0;
                    x.point2=0;
                    x.game1++;

                }
                else
                    if(x.point2>3 && x.point2>(x.point1+1))
                    {
                    x.point1=0;
                    x.point2=0;
                    x.game2++;
                    }
                    else
                        if(c=='A')
                        {
                            x.point1++;

                        }
                        else
                        {
                            x.point2++;
                        }
            }
            i++;
            c=a[i];
    }
    if(x.set1>=2)
    {
        printf("Game ended, Playe 1 has won!!!");
    }
    else
        if(x.set2>1)
        {
            printf("Player 2 has won!!");
        }
        else
        {
            printf("game did not end score was %d vs %d",x.game1,x.game2);
        }
    return 0;
}
