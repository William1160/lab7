#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void bubble(int arr[], int current, int size);
void selection(int arr[],int size, int start);

int main(){
    int array1[] = {97,16,45,63,13,22,7,58,72};
    int array2[] = {90,80,70,60,50,40,30,20,10};
    int array3[] = {97,16,45,63,13,22,7,58,72};
    int array4[] = {90,80,70,60,50,40,30,20,10};
    size_t size = sizeof(array1) / sizeof(array1[0]);
    bubble(array1, 0, size);
    bubble(array2, 0, size);
    size = sizeof(array2) / sizeof(array2[0]);
    selection(array3, size, 0);
    selection(array4, size, 0);
    return 0;
}

void bubble(int arr[], int current, int size){
    static int swaps[100];
    static int flag = 0;
    if(flag = 0){
        for(int i = 0; i <100; ++i){
            swaps[i] = 0;
        }
    }
    static int total = 0;
    if((current + 1) == size){
        flag = 0;
        for(int i = 0; i < (size-1); ++i){
            if(arr[i] <= arr[i+1]){

            }
            else{
                flag = 1;
            }
        }
        if(flag == 1){
            bubble(arr, 0, size);
        }
        else{
            for(int i = 0; i < size; ++i){
                printf("%d ", arr[i]);
            }
            puts(" ");
            total = 0;
            for(int j = 0; j < size; ++j){
                for(int i = 0; i < 100; ++i){
                    if( i == arr[j] ){
                        total = total + swaps[i];
                        printf("%d: %d\n", i,swaps[i]);
                    }
                }
            }
            printf("total swaps: %d\n", total/2);
            for(int i = 0; i <100; ++i){
                swaps[i] = 0;
            }
            flag = 0;
            total = 0;
            return;
        }
        return;
    }
    int temp = arr[current];
    if(arr[current] <= arr[current + 1]){
        bubble(arr, (current + 1), size);
        return;
    }
    else{
        ++swaps[arr[current]];
        ++swaps[arr[current+1]];
        arr[current] = arr[current + 1];
        arr[current + 1] = temp;
        bubble(arr, current + 1, size);
        return;
    }
    return;
}

void selection(int arr[],int size, int start){
    static int swaps[100];
    static int flag = 0;
    if(flag = 0){
        for(int i = 0; i <100; ++i){
            swaps[i] = 0;
        }
    }
    if(start+1 == size){
        for(int i = 0; i < size; ++i){
            printf("%d ", arr[i]);
        }
        puts(" ");
        int total = 0;
        for(int j = 0; j < size; ++j){
            for(int i = 0; i < 100; ++i){
                if( i == arr[j] ){
                    total = total + swaps[i];
                    printf("%d: %d\n", i,swaps[i]);
                }
            }
        }
        printf("total swaps: %d\n", total/2);
        return;
    }
    int min = arr[start];
    int place = -1;
    for(int i = start; i < size; ++i){
        if(arr[i] < min){
            min = arr[i];
            place = i;
        }
    }
    if(place < size && place > -1){
        ++swaps[min];
        ++swaps[arr[start]];
        arr[place] = arr[start];
        arr[start]= min;
    }
    selection(arr,size,start+1);
}