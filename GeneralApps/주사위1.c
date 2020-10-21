#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

	int target;
	int i,user_num,com_num;
	int user[30]={0};
	int com[30]={0};
	int user_count=0, com_count=0, user_win_count=0, com_win_count=0;
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
				
				printf("user_dice: %d ",user[i]);
				printf("com_dice: %d\n",com[i]);
		

				if(user[i]>com[i]){
					user_count+=user[i];
					user_win_count++;
				}
				else if(com[i]>user[i])
				{	
					com_count+=com[i];
					com_win_count++;
				}
				printf("user_count: %d ", user_count);
				printf("com_count: %d\n", com_count);

				if(user_count>=target)
				{ 
					printf("user가 %d 대 %d로 승리 하였습니다.",user_count,com_count);
					printf("이긴 횟수 %d : %d \n",user_win_count,com_win_count);
					break;
				}
				else if(com_count>=target)
				{
					printf("computer%d 대 %d로 승리 하였습니다\n",user_count,com_count);
					printf("이긴 횟수 %d : %d \n",user_win_count,com_win_count);
					break;
				}
				else if(i==29)
				{
					if(user_count>com_count)
					{
						printf("user가 %d 대 %d로 승리 하였습니다.",user_count,com_count);
						printf("이긴 횟수 %d : %d \n",user_win_count,com_win_count);
					}
					else if(user_count<com_count)
					{	
						printf("computer%d 대 %d로 승리 하였습니다\n",user_count,com_count);
						printf("이긴 횟수 %d : %d \n",user_win_count,com_win_count);
					}
					else
					{
						printf("user와 computer가 비겼습니다.\n");
						printf("이긴 횟수 %d : %d \n",user_win_count,com_win_count);
					}
				}
			}
		}


		printf("게임을 계속하시겠습니까? (1:계속 2:중지)");
		scanf("%d",&game);
		if(game==2) break;
		else
		{
			user_count=com_count=0;
			user_win_count=com_win_count=0;
		}
	}
	return 0;
}