#include <stdio.h>
#include <stdlib.h>
enum choicec {rock1, rock2, rock3, scissors1, scissors2, paper};




int main(){
    printf("%d %d %d %d %d %d \n ",rock1, rock2, rock3, scissors1, scissors2, paper);
    char Alpha=scissors1;
    switch(Alpha)
    {
        case rock1:
        case rock2:  // rock1: error: duplicate case value
        case rock3:
            printf("There are rocks\n");
            break;

        // switch need integer type!!
        // case scissors1 || scissors1   # uplicate case value
        case  scissors1:
        case  scissors2:
            printf("There is scissors\n");
            break;

        default:
            printf("go fucking yourself\n");
    }
    printf("Alpha =  %d \n",Alpha);

}
