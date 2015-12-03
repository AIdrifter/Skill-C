# GCC RULE
# -c : 只編譯不連結 :
也就是只產生副檔名為 .o 檔的 obj 檔而不將 obj 檔連結成執行檔在這個範例中，可以先把之前產生的 obj 檔和執行檔刪掉，輸入 $ gcc main.c op.c -c 指令，會發現只有 main.o 及 op.o 生成，接著再輸入 $ gcc main.o op.o -o test 就可以將兩個 obj 檔連結成執行檔。也就是說，最先前執行的 $ gcc main.c op.c -o test 其實是這兩條命令結合而成的。|

# -S : 只產生組合語言檔案 (.s) :
這個參數一般情況應該比較少用到，不過也是可以試試看會生出什麼東西。
-O0, O1, O2, O3 : 啟動編譯最佳化 :   O0 是不最佳化，O3 是最高等級的最佳化。這個東西可以配合上面的 -S 就能看出效果，測試以下兩個編譯命令，可以觀察出有無開最佳化編譯後的差異:
gcc op.c -o op.s -S
gcc op.c -o op.s2 -O3 -S

# -I : 指定 include path(.h) :
如果 header 放在其他資料夾的話可以使用此參數，這個東西和 VC project property 中的 Additional Include Directories 是類似的。

# -L : 指定 library path(.o) :
和 -I 類似，只是這裡指定的是 library 的路徑，和 VC  中的 Additional Library Directories 類似。
-Dname : 預定義 macro :   和 VC 的 Preprocessor Definitions 相同。這個範例可以使用 $ gcc main.c op.c -o -DTEST test ，會多印出 Program End 的文字。



# Parameter
-E -- 只進行前處理，不進行編譯，結果由 console 直接輸出
-C -- 進行前處理時保留註解
-S -- 產生組合語言程式碼 (.s)
-c -- 只編譯不進行連結 (產生 .o 檔)
-I -- 指定 INCLUDE PATH
-L -- 指定 LIBRARY PATH
-llibrary -- 指定要連結的函式庫
-Dname -- 定義 macro，同 #define
-Uname -- 解除 macro 定義，同 #undef

# Linking
-static -- 只使用靜態函式庫
-share -- 儘量使用共享函式庫
-shared-libgcc -- 指定連結共享的 libgcc
-static-libgcc -- 指定連結靜態的 libgcc
-nostartfiles -- 不使用 standard system startup files (常用於 cross-compiling 時)
-nodefaultlibs -- 不使用系統預設的標準函式庫
-nostdlib -- 不使用標準函式庫及 startup files
-nostdinc++ -- 不使用 c++ 標準的 #include 檔
-fPIC -- 產生 position-independent code，常用於共享函式庫的產生
-Wl,option -- 將 option 傳給 linker，如果有多個 option ，使用逗號(,)隔開。e.g.
$ gcc -shared -o myshared -Wl,--whole-archive -llib1 -llib2 -Wl,--no-whole-archive  a.o b.o c.o

# Debugging and profiling
-g -- 產生 debugging 時所需要的資訊及 symbol table
-p -- 產生 prof 所需要的資訊
-pg -- 產生 gprof 所需要的資訊

http://www.cmlab.csie.ntu.edu.tw/~daniel/linux/gcc.html
http://jayextmemo.blogspot.tw/2015/01/linux-gcc-makefile.html
