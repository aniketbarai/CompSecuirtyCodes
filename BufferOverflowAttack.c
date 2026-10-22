#include<stdio.h>

int main(){

    int n;
    printf("Enter size of buffer: ");
    scanf("%d",&n);

    char buffer[n];
    
    int count;
    printf("Enter num of charcter: ");
    scanf("%d",&count);

    if(count > n){
        printf("BufferOverflow !!!");
        return 0;
    } else {
        printf("Enter Buffer Content: ");
        for(int i = 0; i < count; i++){
            scanf(" %c", &buffer[i]);
        }
    }
    printf("Buffer Content: ");
    for (int i = 0; i < count; i++)
    {
        printf(" %c", buffer[i]);
    }
    
    return 0;
}
