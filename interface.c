/*************************************************
Copyright (C), 2019-2019, DREACYOU
File name:	interface.c
Author:		DREACYOU
Version:	0.0.1.0
Date:		2019.6.11
Description: 界面设计 
Others: 
Function List: 

History: 

*************************************************/
#include "datastruct.h"
#include "packet.h"


/*************************************************
Function: showMonsterList
Description: list怪物列表 
Calls: 
Called By: 

Input: void
Output: 
Return: 返回0
Others: 
*************************************************/
extern SpiritAttribute	Monster[];
int showMonsterList(void)
{
	int i;
	printf("================怪物列表================\n");
	for(i = 0; i < 3; i++)
	{
		printf("--------%.8s\t--------\n",Monster[i].Name);
		printf("\t生命值:\t%d\n",Monster[i].HP);
		printf("\t魔力值:\t%d\n",Monster[i].MP);
		printf("\t力量:\t%d\n",Monster[i].ATK);
		printf("\t魔法:\t%d\n",Monster[i].MATK);
		printf("\t物防:\t%d\n",Monster[i].DEF);
		printf("\t魔防:\t%d\n",Monster[i].MDEF);
		printf("------------------------\n");
	}
	printf("========================================\n\n");
	return 0; 
}

/*************************************************
Function: showAttritube
Description: list人物属性 
Calls: 
Called By: 

Input: TheOne protagonist,int language
Output: 
Return: 返回0
Others: 
*************************************************/
int showAttritube(TheOne protagonist,int language)
{
	if(language)//中文 
	{
		printf("================人物属性================\n");
		printf("\t名字：\t%s\n",protagonist.Name);
		printf("\t性别：\t%s\n",protagonist.sex?"男":"女");
		printf("\t生命值:\t%d\n",protagonist.HP);
		printf("\t魔力值:\t%d\n",protagonist.MP);
		printf("\t力量:\t%d\n",protagonist.ATK);
		printf("\t魔法:\t%d\n",protagonist.MATK);
		printf("\t物防:\t%d\n",protagonist.DEF);
		printf("\t魔防:\t%d\n",protagonist.MDEF);
		printf("\t装备:\t%.2x\n",protagonist.equipment);
		printf("========================================\n\n");
	}
	else	//英文 
	{
		printf("================Attribute================\n");
		printf("\tName：\t%s\n",protagonist.Name);
		printf("\tSex：\t%s\n",protagonist.sex?"man":"female");
		printf("\tHP:\t%d\n",protagonist.HP);
		printf("\tMP:\t%d\n",protagonist.MP);
		printf("\tATK:\t%d\n",protagonist.ATK);
		printf("\tMATK:\t%d\n",protagonist.MATK);
		printf("\tDEF:\t%d\n",protagonist.DEF);
		printf("\tMDEF:\t%d\n",protagonist.MDEF);
		printf("========================================\n\n");
	}
	return 0; 
}

/*************************************************
Function: battleResult
Description: 显示战斗结果 
Calls: 
Called By: 

Input: int ret,const char* monstername
Output: 
Return: 返回0
Others: 
*************************************************/
int battleResult(int ret,const char* monstername)
{
	if(ret)	//杀死怪物
	{
		printf("恭喜你杀死了%s！\n",monstername);
	}
	else	//被杀死
	{
		printf("你被%s杀死了！\n",monstername);
	}
	return 0;
}

/*************************************************
Function: dropResult
Description: 显示掉落物品 
Calls: 
Called By: 

Input: int itemid
Output: 
Return: 返回0
Others: 
*************************************************/
extern Items dropItem[];
int dropResult(int itemid)
{
	printf("恭喜你获得了%s！\n",dropItem[itemid].Name);
	return 0;
};

/*************************************************
Function: showPacket
Description: 显示包裹物品信息 
Calls: 
Called By: 

Input: struct PacketLink *L
Output: 
Return: 返回0
Others: 
*************************************************/
int showPacket(struct PacketLink *L)
{
	int i;
	struct PacketLinkNode *p = L->head->next;
	printf("================包裹信息================\n");
	if(listEmpty(L) == true)printf("packet is empty.\n");
	else
	{
		for(i = 0; i < L->link_len; i++)
		{
			//printf("%p\n",p);
			printf("PacketItem[%d] Name:%s\t",i,p->Name);
			printf("Have:%d\n",p->num);
			p=p->next;
		}
	}
	printf("========================================\n\n");

	return 0;
}

char miloffsetname[8][8]={
	{"武器"},
	{"防具"},
	{"首饰"},
	{"戒指"},
	{"戒指"},
	{"手镯"},
	{"手镯"},
	{"坐骑"},
}; 
extern Items military[MILIIDMAX];
int showMilitary(void)
{
	int i;
	printf("================装备信息================\n");
	
	for(i = 0; i < MILIIDMAX; i++)
	{
		//if(military[i].Name[0] != 0)
			printf("\t%s:\t%s\n",miloffsetname[i],military[i].Name);
	}
	printf("========================================\n\n");
	return 0;
}

int showMainMenu(void)
{
	printf("================主菜单==================\n");
	printf("\t1.查看人物属性\n");
	printf("\t2.查看怪物列表\n");
	printf("\t3.查看装备清单\n");
	printf("\t4.查看包裹清单\n");
	printf("\t5.去打怪\n");
	printf("\t6.存档和读档\n");
	printf("\t7.退出游戏\n");
	printf("========================================\n\n");		
} 

int  showEixt(void)
{
	
	
	return 0;
}
