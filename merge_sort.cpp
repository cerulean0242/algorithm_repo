#include <iostream>

const int N = 1e6 + 10;
int n;
int arr[N];
int temp[N];

void merge_sort(int left, int right){
    
    if(left >= right) return;
    int mid = left + right >> 1;
    merge_sort(left, mid),merge_sort(mid + 1, right);
    
    int k = 0, i = left, j = mid + 1;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];
    
    for(int i = left, j = 0; i <= right;i++, j++) arr[i] = temp[j];
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    
    merge_sort(0, n - 1);
    
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    } 
    
}
