#define __USE_MINGW_ANSI_STDIO 0
#include <stdio.h>

int main(){
    int n;scanf("%d",&n);
    for(int q=1;q<=n;q++){
        int v;printf("%d",&v);
        int l=(n-1)/4,m=(n-1)%4;
        if(m==0){
            for(int i=1;i<=l;i++){
                printf(".");
            }
            for(int i=1;i<=1;i++){
                printf("#");
            }
            for(int i=1;i<=l;i++){
                printf(".");
            }
            for(int i=1;i<=1;i++){
                printf("#");
            }
            for(int i=1;i<=l;i++){
                printf(".");
            }
        }else if(m==2){
            for(int i=1;i<=l;i++){
                printf(".");
            }
            for(int i=1;i<=2;i++){
                printf("#");
            }
            for(int i=1;i<=l;i++){
                printf(".");
            }
            for(int i=1;i<=2;i++){
                printf("#");
            }
            for(int i=1;i<=l;i++){
                printf(".");
            }
        }
    }
    return 0;
}