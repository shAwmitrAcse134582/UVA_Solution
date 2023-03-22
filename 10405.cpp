#include<stdio.h>
#include<string.h>
#define SIZE 1024
 
static char x[SIZE], y[SIZE];
static int lcs[SIZE][SIZE];
 
int maxval(int a, int b){
    return a > b ? a : b;
}
 
int main(){
    register int i, j;
 
    while(gets(x) && gets(y)){
 
        int xlen = strlen(x);
        int ylen = strlen(y);
        for(i = 1; i <= xlen; ++i){
            for(j = 1; j <= ylen; ++j){
                if(x[i-1] == y[j-1])
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else
                    lcs[i][j] = maxval(lcs[i-1][j], lcs[i][j-1]);
            }
        }

        printf("%d\n", lcs[xlen][ylen] );
 
    }
    return 0;
}