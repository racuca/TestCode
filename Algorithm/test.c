
#include <stdio.h>

void main()
{
	struct Player {
		char iName[6];
		int iHp;
		int iAtk;
		int iDef;
		int iLevel;
		int iExp;
		int iMoney;
	}player;

	strcpy(player.iName, "test");
	player.iHp = 250;
	player.iAtk = 15;
	player.iDef = 7;
	player.iLevel = 1;
	player.iExp = 0;
	player.iMoney = 500;


	printf("%s %d", player.iName, player.iMoney);

	getch();
}