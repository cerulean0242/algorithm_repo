#include <iostream>
#include <utility>

const int N = 1e6 + 10;
int n;
int arr[N];

void quick_sort(int left, int right, int arr[]){
    
    if(left >= right) return;
    
    int x = arr[left + right >> 1], i = left - 1, j = right + 1;
    while (i < j){
        do i++; while(arr[i] < x);
        do j--; while(arr[j] > x);
        
        if(i < j) std::swap(arr[i],arr[j]);
    }
    
    quick_sort(left, j, arr);
    quick_sort(j + 1, right, arr);
    
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    
    quick_sort(0, n - 1, arr);
    
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}
