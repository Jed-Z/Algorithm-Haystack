/*
Author: Jed Zhang
Date: 20171215
Time: 19:26
Note: QuickSort in pure C. See also: http://developer.51cto.com/art/201403/430986.htm
*/
#include <stdio.h>
void qsort(int [], int);
void swap(int *, int *);
int main(void)
{
	int n;
	scanf("%d", &n);
	int test[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &test[i]);
	}
	qsort(test, n);	//���ú���
	for(int i = 0; i < n; i++) {
		printf("%d ", test[i]);
	}
}
void qsort(int test[], int n)
{
	if(n < 2) return;	//ע�����������������
	int i = 0, j = n-1;	//iҪ����Ϊ0������1������Ҫ�õ��ں�
	int key = test[0];
	while(i != j) {
		while(test[j] >= key && i != j)	//ע���е��ں�
			j--;
		while(test[i] <= key && i != j)	//ͬ��
			i++;
		swap(&test[i], &test[j]);
	}
	swap(&test[0], &test[i]);
	qsort(test, i);
	qsort(&test[i+1], n-i-1);
}
void swap(int *x, int *y)
{
	int hold = *x;
	*x = *y;
	*y = hold;
}
