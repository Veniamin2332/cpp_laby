#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;
using namespace chrono;

void puzire(int (*arr), int N){
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

}

void forwardstep(int (*arr), unsigned const beginidx, unsigned const endidx){
        for(int j = beginidx; j < endidx; j ++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

void backwardstep(int (*arr), unsigned const beginidx, unsigned const endidx){
    for(int j = endidx; j > beginidx; j --){
        if(arr[j] < arr[j-1]){
            swap(arr[j], arr[j-1]);
        }
    }
}


void shakersort(int (*arr), unsigned const beginidx, unsigned const endidx){
    unsigned a = beginidx, b = endidx;

    while(a < b){
        forwardstep(arr, a, b);
        backwardstep(arr,a,b);
        a ++;
        b --;
    } 
}


int combsort(int (*arr), int N){
    int cnt = 0;
    int step = N;
    bool swaped = true;
    while( swaped ){
        swaped = false;
        step = max(1, step/2);
        for(int i = 0; i + step < N; i ++){
            if(arr[i] > arr[i + step]){
                swap(arr[i], arr[i+step]);
                cnt++;
                swaped = true;
            }

        }
    }
    return cnt;
}

int shellsort1(int (*arr), int N){
    int d = N/2;
    int cnt = 0;
    while(d>0){
        for(int i = d; i < N; i++){
            int cur = arr[i];
            int j = i;
            while(j >= d && arr[j - d] > cur){
                arr[j] = arr[j-d];
                j -= d;
                cnt++;
            }
            arr[j] = cur;
        }
        d = d/2;
    }
    return cnt;
}

int shellsort2(int (*arr), int N){
    int k = 1;
    int cnt = 0;
    while((1<<k)-1 <= N){
        k++;
    }
    int d = (1<<k)-1;
    while(d>=1){
        for(int i = d; i < N; i++){
            int cur = arr[i];
            int j = i;
            while(j >= d && arr[j - d] > cur){
                arr[j] = arr[j-d];
                j -= d;
                cnt++;
            }
            arr[j] = cur;
        }
        k --;
        d = (1<<k) -1;
    }
    return cnt;
}

vector<int> fibbonachi(int n){
    vector<int> arr;
    int a = 1;
    int b = 1;
    while(b <= n){
        arr.push_back(b);
        int c = a + b;
        a = b;
        b = c;
    }
    return arr;
}


int shellsort3(int (*arr), int N){
    int cnt = 0;
    vector<int> shag = fibbonachi(N);
    for(int k = shag.size() - 1; k >= 0; k--){
        int d = shag[k];
        for(int i = d; i < N; i++){
            int cur = arr[i];
            int j = i;
            while(j >= d && arr[j - d] > cur){
                arr[j] = arr[j-d];
                j -= d;
                cnt ++;
            }
            arr[j] = cur;
        }
    }
    return cnt;
}


void vybor(int (*arr), int N){
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



void vstavka(int (*arr), int N){
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

int* r_massiv(int n){
    int* a = new int[n];
    for(int i = 0; i < n; i++){
        a[i] = rand()%100000;
    }
    return a;
}

int main(){
    ofstream fout("shellsort33.txt");
    high_resolution_clock::time_point start, end;
    for(int n = 500; n <= 100000; n += 500){
        int* b = r_massiv(n);
        int cnt;
        start = high_resolution_clock::now();
        // cnt = combsort(b, n);  Для расчески
        cnt = shellsort3(b,n);
        end = high_resolution_clock::now();
        auto time_span = duration_cast <microseconds> (end - start);
        // fout << n << " " << time_span.count() << " " << cnt << endl; Для расчески
        fout << n << " " << time_span.count() << " " << cnt << endl;
    }
}