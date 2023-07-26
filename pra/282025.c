#include<stdio.h>

int binary_search(int s[], int len, int key);

int main(void){
	int a[10], i, key;
	
	printf("输入10个数：");
	for(i = 0; i < 10; i++){
		scanf("%d", &a[i]);	
	}
	printf("输入查找的数：");
	scanf("%d", &key);
	printf("位置在a[%d]！\n", binary_search(a, 10, key));
	return 0;
}

int binary_search(int s[], int len, int key){
	int low, mid, high, count;

	count = 0;
	low = 0;
	high = len - 1;
	//mid = (low + high) / 2;//比len / 2好，len / 2会少比一个
	while(low <= high){
		mid = (low + high) / 2;//比len / 2好，len / 2会少比一个
		count++;
		if(s[mid] == key){
			printf("查找了%d次!\n", count);
			return mid;
		}else if(key > s[mid]){
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	if (low > high )
		printf("no\n");


}
