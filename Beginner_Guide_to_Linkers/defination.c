/* 這是一個未初始化的全局變量的定義 */
int x_global_uninit;
 
/* 這是一個初始化的全局變量的定義 */
int x_global_init = 1;
 
/* 這是一個未初始化的全局變量的定義，儘管該變量只能在當前 C文件中訪問 */
static int y_global_uninit;
 
/* 這是一個初始化的全局變量的定義，儘管該變量只能在當前 C文件中訪問 */
static int y_global_init = 2;
 
/* 這是一個存在於程序別處的某個全局變量的聲明 */
extern int z_global;
 
/* 這是一個存在於程序別處的某個函數的聲明（如果你願意，你可以在語句前加上 "extern"關鍵字，但沒有這個必要） */
int fn_a( int x, int y);
 
/* 這是一個函數的定義，但由於這個函數前加了 static限定，因此它只能在當前 C文件內使用 */
static int fn_b(int x)
{
    return x +1;
}
 
/* 這是一個函數的定義，函數參數可以認為是局部變量 */
int fn_c( int x_local)
{
    
/* 這是一個未初始化的局部變量的定義 */
    int y_local_uninit ;
    
/* 這是一個初始化的局部變量的定義 */
    int y_local_init = 3 ;
 
    
/* 以下代碼通過局部變量、全局變量和函數的名字來使用它們 */
    x_global_uninit = fn_a (x_local, x_global_init);
    y_local_uninit = fn_a (x_local, y_local_init);
    y_local_uninit += fn_b (z_global);
    return (x_global_uninit + y_local_uninit);
} 


