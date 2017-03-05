#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node* next;
  int value;
} Node;

typedef struct list {
  Node* head;
} List;

Node* create_node(int value)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->next = NULL;
  node->value = value;
  return node;
}

void dump(List* list)
{
  if (!list || !list->head)
    return;

  printf("%d", list->head->value);
  Node* node =  list->head->next;
  while (node) {
    printf(", %d", node->value);
    node = node->next;
  }
  printf("\n");
}

// Refernece: https://www.ted.com/talks/linus_torvalds_the_mind_behind_linux
void remove_list_node_v1(List* list, Node* target)
{
    Node* prev = NULL;
    Node* current = list->head;

    // Walk the list
    while (current != target) {
      prev = current;
      current = current->next;
    }

    if(prev!=NULL)
      printf("prev is %d current is %d \n",prev->value,current->value);
    else
      printf("prev is NULL current is %d \n",current->value);
    // Remove the target by updating the head or the previous node.
    if (!prev)
    {
        printf("case 1 list->head->vaule %d  target->next->vaule %d \n",list->head->value, target->next->value);
        list->head = target->next;
    }
    else
    {
        printf("case 2 list->head->vaule %d  target->next->vaule %d \n",list->head->value, target->next->value);
        prev->next = target->next;
    }
}

void remove_list_node_v2(List* list, Node* target)
{

}


// conclustion:
//    *indirect <=> current
//     indirect <=> prev     <=> &((*indirect)->next)

void remove_list_node_v3(List* list, Node* target)
{
  // The "indirect" pointer points to the *address* of the thing we'll update.
  //      &list->head
  //  <=> &(list->head)
  Node** indirect = &list->head;

  // Walk the list, looking for the thing that points to the node we want to remove.
  //      &(*indirect)->next
  // <=>  &((*indirect)->next)
  while (*indirect != target)
    indirect = &(*indirect)->next;

  *indirect = target->next;
}

extern char *optarg;

void usage(char *argv0)
{
    fprintf(stderr,
            "Usage: %s [-c count] [-a] [-d]",
            argv0);
}
// Just for demo purpose. No free.
int main(int argc,char *argv[]) {
 //   char str[256];

 //   while(1)
 //   {
 //       gets(str);
 //       memcpy(argv,,)
 //       int c;
 //       while ((c = getopt(argc, argv, "c:ad")) != -1)
 //       {
 //                printf("[TRACE] %s %s %d %c \n",__func__,__FILE__,__LINE__,c);
 //             switch (c) {
 //                 case 'c':
 //                     printf("create node");
 //                     printf("input parameter is %s .....\n",optarg);
 //                     break;
 //                 case 'a':
 //                     printf("add node \n");
 //                     break;
 //                 case 'd':
 //                     printf("delete node \n");
 //                     break;
 //                 default:  // show usage
 //                     usage(argv[0]);
 //                     exit(1);
 //             }
 //       }
 //       printf("[TRACE] %s %s %d %c \n",__func__,__FILE__,__LINE__,c);
 //   }

  int i;
  List list;
  Node* node = list.head = create_node(1);
  dump(&list);
  for (i = 2; i <= 5; i++) {
    node->next = create_node(i);
    node = node->next;
    dump(&list);
  }

  Node* a = list.head;
  Node* c = list.head->next->next;
  remove_list_node_v3(&list, c);
  dump(&list);
  remove_list_node_v3(&list, a);
  dump(&list);



 return 0;
}
