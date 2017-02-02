#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define COMPUTER 1
#define HUMAN 2
int heap(void);
int objects(void);
int firstplayer(void);
void hmturn(void);
void cpturn(void);
void termination(void);
void printa(void);
int heapnum,object;
int a[10];
bool end=true;

int main(void)
{
	int i,firstp,turn;
	turn = 1;
	srand((unsigned int)time(NULL));
		printf("Create %d heaps of size",heapnum = heap());
		for (i = 1; i <= heapnum; i++)
		{
			printf(" %d", object=objects());
			a[i-1] = object;// store heaps in an array
		}
		printf("\n");
		if ((firstp = firstplayer()) == COMPUTER)
		{
			printf("Player computer goes first\n");
			turn = 0;
		}
		else 
			printf("Player human goes first\n");
		while (turn <= 1000)
		{
			if ((turn % 2) == 0)//even turn,computer
			{
				cpturn();
				printa();
			}
			else			   //odd turn,human
			{
				hmturn();
				printa();
			}
			termination();
			if (end == false)
				break;
			turn++;
		}
		if ((turn % 2) == 0)
			printf("Player computer has won\n");
		else
			printf("Player human has won\n");

		return 0;
}
int heap(void)
{
	int i,j;
	j = 0;
	i = rand() % 9;
	if (i <= 2)
		j = 3;
	else if (i >= 6)
		j = 5;
	else j = 7;
	return j;
}
int objects(void)
{
	int i, j;
	i = rand() % 3;
	if (i == 0)
		j = 9;
	else if (i == 1)
		j = 11;
	else j = 13;
	return j;
}
int firstplayer(void)
{
	int i, j;
	i = rand() % 2;
	if (i == 0)
		j = COMPUTER;
	else j = HUMAN;
	return j;
}
void cpturn(void)
{
	int i, j, m;
	i = rand() % heapnum+1;//computer chooses heap
	while(a[i-1]==0)
		i = rand() % heapnum + 1;//valid heap
	m = rand() % a[i-1];
	j = m + 1;
	a[i-1]-=j;
	printf("Player computer takes %d objects from heap %d\n",j,i);
}
void printa(void)
{
	int i;
	for (i = 0; i < heapnum; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void hmturn(void)
{
	int i, j;
	printf("Player human enter the number of objects(Y) to take from what heap (X)- in order: Y X\n");
	while (scanf_s("%d %d", &i, &j) != 2||(a[j-1]<i))
	{
		while (getchar() != '\n')
			continue;
		printf("Player human that is an invalid move,try again\n");
		printf("Player human enter the number of objects(Y) to take from what heap (X)- in order: Y X\n");
	}
	a[j-1] -= i;
}
void termination(void)//check if game terminates
{
	int i;
	for (i = 0; i < heapnum; i++)
	{
		if (a[i] != 0)
		{
			end = true;
			break;
		}
		else
			end = false;
	}
}