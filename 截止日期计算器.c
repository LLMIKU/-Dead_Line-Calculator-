#include<stdio.h>
#include<time.h>
char str1[8][12] = { "≡ω≡", "(⊙o⊙)?", "(′д｀ )…", "(⊙ω⊙)", "O__O \"…", "(⊙3⊙)", "?_?", "=-=", };
char str2[8][12] = { "≡ω≡", "^-^", ">_<", "(*＾-＾*)", "(＾－＾)V", "^O^", "<(￣︶￣)>", "(≧O≦)嗷~", };
int run1()
{
	time_t time1;
	srand((unsigned int)time(&time1));
	int num = rand() % 8;
	return(num);
}

int run2(int nian1, int yue1, int ri1, int nian2, int yue2, int ri2)
{
	int y, m, d, of;
	int n = 0;
	int h, g, t;
	int x, e;
	int q, s;
	int u, k;
	int i = 0;
	int w;
	n = (nian2 - nian1) / 400 * (365 * 400 + 97);
	nian1 = nian1 + (nian2 - nian1) / 400 * 400;
	if (nian1 == nian2) x = 1 - yue1;
	else x = 0;
	if ((yue1 == yue2) && (nian1 == nian2)) e = 1 - ri1;
	else e = 0;//天啊，这里之前用的是e==0，导致 e值不确定或者很大,后面就陷入了死循环 
	for (y = nian1; y <= nian2; y++)
	{	//i++;
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) of = 1;
		else of = 0;
		if (y == nian2) h = 12 - yue2;//t=28+g-ri2;
		else h = 0;
		if (y == nian1) q = 1 - x - yue1;//q为了确定后面起始年的月份  m 的计算起始点
		else q = 0;
		for (m = 1 - x - q; m <= 12 - h; m++)
		{
			switch (m)
			{
			case 1:case 3:case 5:case 7:case 8:case 10:case 12:g = 3; break;
			case 2:g = of; break;
			case 4:case 6:case 9:case 11:g = 2; break;
			}
			//if(y==nian2) flag=1;//到了nian2开始计算nian2经过的天数 
			if (y == nian2&&m == yue2) {
				t = 28 + g - ri2;
				if (ri2>28 + g)
				{
					printf("\n截止日期的%d月份没有这个日期%s\n", yue2, str1[w]);
					system("pause");
				}
			}
			else t = 0;
			if (y == nian1&&m == yue1) {
				s = 1 - e - ri1;//s为了确定后面起始年起始月的日子 d 的计算起始点 
				if (ri1>28 + g)
				{
					printf("\n起始日期的%d月份没有这个日期%s\n", yue1, str1[w]);
					system("pause");
				}
			}
			else s = 0;
			for (d = 1 - e - s; d <= 28 + g - t; d++)
			{
				n++;
				//if(flag) r++;	
			}
		}
	}
	printf("\n包括起始日期在内距离截止日期还有 %d 天\n", n - 1);
	u = (n - 1) / 7; k = (n - 1) % 7;
	if (k == 0)
		printf("即整整%d周\n", u);
	else {
		printf("即%d周又%d天\n", u, k);
		if (n - 1>364)
			printf("如果按365天为一年计算，即%d年又%d周又%d天\n", (n - 1) / 365, (n - 1) % 365 / 7, (n - 1) % 365 % 7);
	}
	//else{if(r%7==0) printf("即%d年又%d周",i-1,r/7);
	//else printf("即%d年又%d周又%d天",i-1,r/7,r%7);}

	if (n - 1 <= 100)printf("珍惜时间，加油！！！\n%s\n", str2[w]);
	return(1);
}

void main()
{
	int y, m, d, of;
	int nian1, yue1, ri1;
	int nian2, yue2, ri2;
	int n = 0;
	int h, g, t;
	int x, e;
	int q, s;
	int u, k;
	int i = 0;
	int w;
	//int flag=0,r=0;这本来是为了计算年数，后来由于跨年问题而取消，比如2016.12.24-2017.1.1会显示一年多 
	system("color A");
	w = run1();
	printf("这是一个截止日期剩余天数计算器,你可以计算公元后任一起始日期到任一截止日期所剩余的天数\n");
	printf("输入格式为:年 月 日(注意之间用空格Space键分开)\n");
	printf("确认请按回车Enter键\n\n"); //printf("%s",str2[w]);//表情 测试 
	printf("现在请输入起始日期:");
	scanf("%d%d%d", &nian1, &yue1, &ri1);
	printf("现在请输入截止日期:");
	scanf("%d%d%d", &nian2, &yue2, &ri2);
	//if(nian2>1000000) {printf("年份太大算不过来啦... ...%s\n",str1[w]);system("pause");}
	if (nian1>nian2 || nian1 == nian2&&yue1>yue2 || nian1 == nian2&&yue1 == yue2&&ri1>ri2)
	{
		printf("\n输入不合法！！！\n"); system("pause");
	}
	if (yue1>12 || yue2>12 || ri1>31 || ri2>31)
	{
		printf("\n输入不合法！！！\n"); system("pause");
	}
	if (nian1 <= 0 || nian2 <= 0 || yue1 <= 0 || yue2 <= 0 || ri1 <= 0 || ri2 <= 0)
	{
		printf("\n输入不合法！！！\n"); system("pause");
	}
	if (nian2 - nian1 >= 10000)
	{
		int run2(int nian1, int yue1, int ri1, int nian2, int yue2, int ri2); system("pause");
	}
	else{

		if (nian1 == nian2) x = 1 - yue1;
		else x = 0;
		if ((yue1 == yue2) && (nian1 == nian2)) e = 1 - ri1;
		else e = 0;//天啊，这里之前用的是e==0，导致 e值不确定或者很大,后面就陷入了死循环 

		for (y = nian1; y <= nian2; y++)
		{	//i++;
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) of = 1;
			else of = 0;
			if (y == nian2) h = 12 - yue2;//t=28+g-ri2;
			else h = 0;
			if (y == nian1) q = 1 - x - yue1;//q为了确定后面起始年的月份  m 的计算起始点
			else q = 0;
			for (m = 1 - x - q; m <= 12 - h; m++)
			{
				switch (m)
				{
				case 1:case 3:case 5:case 7:case 8:case 10:case 12:g = 3; break;
				case 2:g = of; break;
				case 4:case 6:case 9:case 11:g = 2; break;
				}
				//if(y==nian2) flag=1;//到了nian2开始计算nian2经过的天数 
				if (y == nian2&&m == yue2) {
					t = 28 + g - ri2;
					if (ri2>28 + g)
					{
						printf("\n截止日期的%d月份没有这个日期%s\n", yue2, str1[w]);
						system("pause");
					}
				}
				else t = 0;
				if (y == nian1&&m == yue1) {
					s = 1 - e - ri1;//s为了确定后面起始年起始月的日子 d 的计算起始点 
					if (ri1>28 + g)
					{
						printf("\n起始日期的%d月份没有这个日期%s\n", yue1, str1[w]);
						system("pause");
					}
				}
				else s = 0;
				for (d = 1 - e - s; d <= 28 + g - t; d++)
				{
					n++;
					//if(flag) r++;	
				}
			}
		}
		printf("\n包括起始日期在内距离截止日期还有 %d 天\n", n - 1);
		u = (n - 1) / 7; k = (n - 1) % 7;
		if (k == 0)
			printf("即整整%d周\n", u);
		else {
			printf("即%d周又%d天\n", u, k);
			if (n - 1>364)
				printf("如果按365天为一年计算，即%d年又%d周又%d天\n", (n - 1) / 365, (n - 1) % 365 / 7, (n - 1) % 365 % 7);
		}
		//else{if(r%7==0) printf("即%d年又%d周",i-1,r/7);
		//else printf("即%d年又%d周又%d天",i-1,r/7,r%7);}
	}
	if (n - 1 <= 100)printf("珍惜时间，加油！！！\n%s\n", str2[w]);
	system("pause");
}
