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
					printf("user�� %d �� %d�� �¸� �Ͽ����ϴ�.",user_count,com_count);
					printf("�̱� Ƚ�� %d : %d \n",user_win_count,com_win_count);
					break;
				}
				else if(com_count>=target)
				{
					printf("computer%d �� %d�� �¸� �Ͽ����ϴ�\n",user_count,com_count);
					printf("�̱� Ƚ�� %d : %d \n",user_win_count,com_win_count);
					break;
				}
				else if(i==29)
				{
					if(user_count>com_count)
					{
						printf("user�� %d �� %d�� �¸� �Ͽ����ϴ�.",user_count,com_count);
						printf("�̱� Ƚ�� %d : %d \n",user_win_count,com_win_count);
					}
					else if(user_count<com_count)
					{	
						printf("computer%d �� %d�� �¸� �Ͽ����ϴ�\n",user_count,com_count);
						printf("�̱� Ƚ�� %d : %d \n",user_win_count,com_win_count);
					}
					else
					{
						printf("user�� computer�� �����ϴ�.\n");
						printf("�̱� Ƚ�� %d : %d \n",user_win_count,com_win_count);
					}
				}
			}
		}


		printf("������ ����Ͻðڽ��ϱ�? (1:��� 2:����)");
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