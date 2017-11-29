#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "gnome_sort.h"
#define N 10

using namespace std;

void test(int* sorted);

int main(){
    int* arr = new int(N);
    srand(time(NULL));
    for(int i=0; i<N; i++){
        arr[i] = rand()%100;
    }

    for(int i=0; i<N; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;

    gnome_sort(arr, N);

    for(int i=0; i<N; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;

    test(arr);
    return 0;
}

void test(int* sorted){
    bool res = true;

    for(int i=1; i<N; i++){
        if(sorted[i-1] > sorted[i]){
            res = false;
        }
    }
    assert(res);
}
