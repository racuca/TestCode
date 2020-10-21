#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_GAMES 30


// �ֻ���2.c�� �־��� �Լ��� �ֻ���1.c�� ���� �ᱣ���� ����ؾ��մϴ�

int user_count, com_count, user_win_count, com_win_count;
void game_count(int x, int *y, int *z);
void reset_parameter(void);
int game_result_print(int x,int y,int z);

int main(void)
{

	int target;
	int i,result;
	int user[MAX_NUM_GAMES]={0};
	int com[MAX_NUM_GAMES]={0};
	int game;
	

	while(1)
	{
		printf("��ǥ ������ �Է��Ͻÿ� : ");
		scanf("%d", &target);
			
		srand((unsigned)time(NULL));
	
		for(i=0;i<30;i++)
		{
			printf("�ֻ����� �������� 1�� �����ʽÿ�: ");
			scanf("%d",&game);
			if(game==1)
			{
				user[i]=rand()%6+1;
				com[i]=rand()%6+1;
				
				printf("%d��° user_dice: %d\t ", i+1, user[i]);
				printf("%d��° com_dice: %d\n", i+1, com[i]);
		
				game_count(i, user, com);
				result=game_result_print(i,target,MAX_NUM_GAMES);
				if(result==1) break;
			}
		}
		
		printf("������ ����Ͻðڽ��ϱ�? (1:��� 2:����)");
		scanf("%d",&game);
		if(game==2) break;
		else reset_parameter();
	}
	return 0;
}



