#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_GAMES 30


// 주사위2.c에 주어진 함수로 주사위1.c과 같은 결괏값을 출력해야합니다

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
		printf("목표 점수를 입력하시오 : ");
		scanf("%d", &target);
			
		srand((unsigned)time(NULL));
	
		for(i=0;i<30;i++)
		{
			printf("주사위를 던지려면 1을 누르십시요: ");
			scanf("%d",&game);
			if(game==1)
			{
				user[i]=rand()%6+1;
				com[i]=rand()%6+1;
				
				printf("%d번째 user_dice: %d\t ", i+1, user[i]);
				printf("%d번째 com_dice: %d\n", i+1, com[i]);
		
				game_count(i, user, com);
				result=game_result_print(i,target,MAX_NUM_GAMES);
				if(result==1) break;
			}
		}
		
		printf("게임을 계속하시겠습니까? (1:계속 2:중지)");
		scanf("%d",&game);
		if(game==2) break;
		else reset_parameter();
	}
	return 0;
}



