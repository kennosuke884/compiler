#include <stdio.h>
#include <stdlib.h>

//how to compile : gcc hoge.c -o hoge
//how to run : ./hoge

// int argc, char **argv はコマンドライン引数
// コマンドライン引数とは、コンピュータのコマンド入力画面（コマンドライン）からプログラムを起動する際に指定する文字列
// argc:引数の個数　argv:引数の配列　**argv:引数配列のポインタ
int main(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, "引数の個数が正しくありません\n");
        return 1;
    }
    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");
    printf("  mov rax, %d\n", atoi(argv[1]));
    printf("  ret\n");
    return 0;
}