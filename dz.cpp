//puzire
#include <iostream>
using namespace std;
#define N 10

void puzire(int (&arr)[N]){
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

}


//vybor
void vybor(int (&arr)[N]){
    for(int i = N-1; i > 0; i--){
        int mx = 0;
        for(int j = 0; j < i + 1; j ++){
            if(arr[j] > arr[mx]){
                mx = j;
            }
        }
        swap(arr[i], arr[mx]);
    }
}


//vstavka
void vstavka(int (&arr)[N]){
    for(int i = N-2; i >= 0; i--){
        int cur = arr[i];
        int j = i + 1;
        while(cur > arr[j] && j < N){
            arr[j-1] = arr[j];
            j++;
        }
        arr[j-1] = cur;
    }
}

//sliyanie
void sliv1(int (&arr)[N], int left, int mid, int right){
    int *t = new int [right - left+1];
    int i = 0;
    int i1 = left, i2 = mid + 1;
    while(i1 <= mid && i2 <= right){
        if(arr[i1] < arr[i2]){
            t[i] = arr[i1];
            i1++;
        }
        else{
            t[i] = arr[i2];
            i2++;
        }
        i++;
    }
    while(i1 <= mid){
        t[i] = arr[i1];
        i1++;
        i++;
    }
    while(i2 <= right){
        t[i] = arr[i2];
        i2++;
        i++;
    }
    for(int k = 0; k < right - left + 1; k++){
        arr[left + k] = t[k];
    }
}

void slivsort(int (&arr)[N], int left, int right){
    if(left >= right){
        return;
    }
    else{
        int mid = (left + right)/2;
        slivsort(arr, left, mid);
        slivsort(arr, mid+1, right);
        sliv1(arr, left, mid, right);
    }

}

int main(){
    int a[10] {10,9,8,6,5,4,3,2,1,-1};
    slivsort(a,0,N-1);
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
}

