#include <stdio.h>
#include <stdlib.h>

//how to compile : gcc hoge.c -o hoge
//how to run : ./hoge

// int argc, char **argv はコマンドライン引数
// コマンドライン引数とは、コンピュータのコマンド入力画面（コマンドライン）からプログラムを起動する際に指定する文字列
// argc:引数の個数　argv:引数の配列　**argv:引数配列へのポインタ
int main(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, "引数の個数が正しくありません\n");
        return 1;
    }

    char *p = argv[1];

    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");
    printf("  mov rax, %ld\n", strtol(p, &p, 10)); //strtol():文字列を整数型の数値に変換する関数 文字列pを10を基数にして変換。
    //変換が成功したら、変換終了位置へのアドレスが&pへ格納
    
    while(*p){
        if(*p == '+'){
            p++;
            printf("    add rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        if(*p == '-'){
            p++;
            printf("    sub rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        fprintf(stderr, "予期しない文字です: '%c'\n", *p);
        return 1;
    }

    printf("    ret\n");
    return 0;
}