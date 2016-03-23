#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int Global;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *Thread1(void *x){
    //pthread_mutex_lock(&lock);
    Global++;
    sleep(1);
    printf("thread 1 %d\n",Global);
    //pthread_mutex_unlock(&lock);
    return NULL;
}

void *Thread2(void *x){
    //pthread_mutex_lock(&lock);
    Global--;
    printf("thread 2 %d\n",Global);
    sleep(1);
    //pthread_mutex_unlock(&lock);
    return NULL;
}

int main(){
    printf("[PINKUS] check rtpm flow start  [%s] %s ........@%d \n",__func__,__FILE__,__LINE__);
    pthread_t t[2];
    pthread_create(&t[0], NULL , Thread1 , NULL);
    pthread_create(&t[1], NULL , Thread2 , NULL);
    //printf("before join 1 %d\n",Global);
    pthread_join(t[0], NULL);
    //printf("before join 2 %d\n",Global);
    pthread_join(t[1], NULL);
    printf("-------global final %d\n",Global);
}
