#include<stdio.h>
#include<stdlib.h>

void swap(int arr[],int i,int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
//sort for every node
void heapify(int tree[],int n,int i){
	if( i >= n){
		return ;
	}
	int c1 = 2*i +1;
        int c2 = 2*i + 2;
	int max = i;
	if(c1 < n && tree[c1]>tree[max] ){
		max = c1;
	}
	if(c2 < n && tree[c2] > tree[max]){
		max = c2;
	}
// change 
	if(max != i){
		swap(tree,max,i);
		heapify(tree,n,max);
	}
}
void build_heap(int tree[],int n){
	int last_node = n -1;
        int parent = (last_node - 1)/2;
	for(int i = parent ; i>=0;i--){
		heapify(tree,n,i);
	}
}
void heapSort(int tree[],int n){
	build_heap(tree,n);
	int i=0;
	for(i=n-1;i>=0;i--){
		swap(tree,i,0);
		heapify(tree,i,0);
	}
}
int main(){
	int tree[] = {4,10,3,5,1,2};
	heapSort(tree,6);
	for(int i= 0 ;i<6;i++){
		printf("%d ",tree[i]);
	}
	printf("\n");
	return 0;
}
