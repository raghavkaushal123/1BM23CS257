#include <stdio.h>
void moveZeroes(int arr[] , int n){
    int indx = 0;
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            arr[indx++] = arr[i];
        }
    }
    while (index < n){
        arr[indx++] = 0;
    }
}
int main(){
    int arr[] = {0,2,3,0,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    moveZeroes(arr,n);
    for(int i=0; i<n; i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}
