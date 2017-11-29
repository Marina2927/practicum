#include "gnome_sort.h"

void gnome_sort(int* arr, int n){
    int i = 0, j = 1, temp;

    while(i<n){
        if(i == 0 || arr[i-1]<=arr[i]) i++;
        else{
            temp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = temp;
            i--;
        }
    }
}
