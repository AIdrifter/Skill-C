// 1. 使用巨集避免重複宣告或定義
#ifndef __FOO_H__
#define __FOO_H__

// 2. 將全域變數的宣告集中放到 .h 應該用extern
// .c 才是實體
extern int ShareCount;
typedef enum{add=0,sub,mul} operation_type;

int chose_operation(operation_type operation);
int call_operation(int a ,int b);
#endif
