#define __USE_MINGW_ANSI_STDIO 0
#include <stdio.h>

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char ID[13];scanf("%s",&ID);
        int total=0;
        for(int i=1;i<=12;i++){
            total+=((int)ID[i-1]-48)*(14-i);
        }
        if((int)ID[12]-48==((11-(total%11))%10)){
            printf("Y\n");
        }else{
            printf("N\n");
        }
    }
    return 0;
}