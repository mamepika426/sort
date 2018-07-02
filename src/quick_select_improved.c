#include <stdio.h>

// フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
 A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
 ただし、Aの中身は書き換えてしまう。
 */
int quick_select(int A[], int n, int k){
    int i, j, l, pivot;
    l = n;
    // 先頭の要素をピボットとする
    pivot = A[0];
    for(i =  j = 0; i < l; i++){
        if(A[i] < pivot){
            int z = A[j];
            A[j] = A[i];
            A[i] = z;
            j++;
        }
        if (A[i] > pivot){
            l--;
            int z = A[l];
            A[l] = A[i];
            A[i] = z;
            i--;
        }
    }
    
    if(k < j) return quick_select(A,j,k);
    else if(l <= k) return quick_select(A+l, n-l, k-l);
    else return pivot;
}

int main(){
    int i;
    A[0] = 0;
    A[1] = 3; //原始元
    for(i=2;i<N;i++){
        A[i] = (long long int) A[i-1] * A[1] % N;
    }
    
    // すべての要素が同じ場合でも計算が早く終わるか確認する
    
    for(i=0;i<N;i++){
        if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
        //    printf("%d th element is %d\n", i, quick_select(A, N, i));
    }
}


/*
 int main(){
 int i;
 A[0] = 0;
 A[1] = 3; //原始元
 for(i=2;i<N;i++){
 A[i] = 2;
 }
 
 // すべての要素が同じ場合でも計算が早く終わるか確認する
 
 for(i=0;i<N;i++){
 if(quick_select(A, N, i) == 2) printf("ERROR %d %d\n", i, quick_select(A, N, i));
 //    printf("%d th element is %d\n", i, quick_select(A, N, i));
 }
 }
 */
