/* *************************
* FileName: HanoiTower.c
* Author: Jed Zhang
* Site: https://www.jedbit.com
* Date: 2017.10.31
* Description: ��ŵ������ļ򵥵ݹ�ʵ�֡�
**************************/
#include <stdio.h>
void move(int x, char orig, char targ, char trans);
long stepNum(int y);
int main(void)
{
	int n, steps;
	scanf("%d", &n);
	steps = stepNum(n);
	if(steps == 0)
		printf("ERROR!");
	else
		printf("Require %ld step(s)!\nPress ENTER to continue.\n", stepNum(n));
	getchar();
	getchar();

	//��ʼ�������
	move(n, 'A', 'C', 'B');
	printf("\nThe end, my friend!\n");
	return 0;
}

//���������������ݹ飩
long stepNum(int y)
{
	if(y == 1)
		return 1;
	else if(y >1)
		return 2*stepNum(y-1) + 1;
	else return 0;
}

void move(int x, char orig, char targ, char trans)
{
	static long i = 0;
	if(1 == x) {
		printf("STEP %d : %c -> %c\n", ++i, orig, targ);
	} else {
		move(x-1, orig, trans, targ);
		printf("STEP %d : %c -> %c\n", ++i, orig, targ);
		move(x-1, trans, targ, orig);
	}

}
