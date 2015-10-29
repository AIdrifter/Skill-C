#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *ptr;
};

void put_data(struct node_t *node){
        printf("before\n");
        node->data=1;
        printf("after\n");
};

typedef struct node node_t;
int main(){
            //node *NODE;
            //NODE=malloc(sizeof(struct node_t));
            //if(NODE==NULL)
            //    printf("FKFKFKFKF\n");
            //else
            //    printf("FKFKFKFKF   ...\n");
            //node *NODE=malloc(sizeof(111));
            node_t NODE={6,NULL};
            printf("%d \n\n",NODE.data);
            put_data((node*)&NODE);
            printf("%d \n",NODE.data);
}


