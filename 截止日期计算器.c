#include<stdio.h>
#include<time.h>
char str1[8][12] = { "�Ԧء�", "(��o��)?", "(��գ� )��", "(�Ѧء�)", "O__O \"��", "(��3��)", "?_?", "=-=", };
char str2[8][12] = { "�Ԧء�", "^-^", ">_<", "(*��-��*)", "(�ޣ���)V", "^O^", "<(�����)>", "(�RO�Q)�~", };
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
	else e = 0;//�찡������֮ǰ�õ���e==0������ eֵ��ȷ�����ߺܴ�,�������������ѭ�� 
	for (y = nian1; y <= nian2; y++)
	{	//i++;
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) of = 1;
		else of = 0;
		if (y == nian2) h = 12 - yue2;//t=28+g-ri2;
		else h = 0;
		if (y == nian1) q = 1 - x - yue1;//qΪ��ȷ��������ʼ����·�  m �ļ�����ʼ��
		else q = 0;
		for (m = 1 - x - q; m <= 12 - h; m++)
		{
			switch (m)
			{
			case 1:case 3:case 5:case 7:case 8:case 10:case 12:g = 3; break;
			case 2:g = of; break;
			case 4:case 6:case 9:case 11:g = 2; break;
			}
			//if(y==nian2) flag=1;//����nian2��ʼ����nian2���������� 
			if (y == nian2&&m == yue2) {
				t = 28 + g - ri2;
				if (ri2>28 + g)
				{
					printf("\n��ֹ���ڵ�%d�·�û���������%s\n", yue2, str1[w]);
					system("pause");
				}
			}
			else t = 0;
			if (y == nian1&&m == yue1) {
				s = 1 - e - ri1;//sΪ��ȷ��������ʼ����ʼ�µ����� d �ļ�����ʼ�� 
				if (ri1>28 + g)
				{
					printf("\n��ʼ���ڵ�%d�·�û���������%s\n", yue1, str1[w]);
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
	printf("\n������ʼ�������ھ����ֹ���ڻ��� %d ��\n", n - 1);
	u = (n - 1) / 7; k = (n - 1) % 7;
	if (k == 0)
		printf("������%d��\n", u);
	else {
		printf("��%d����%d��\n", u, k);
		if (n - 1>364)
			printf("�����365��Ϊһ����㣬��%d����%d����%d��\n", (n - 1) / 365, (n - 1) % 365 / 7, (n - 1) % 365 % 7);
	}
	//else{if(r%7==0) printf("��%d����%d��",i-1,r/7);
	//else printf("��%d����%d����%d��",i-1,r/7,r%7);}

	if (n - 1 <= 100)printf("��ϧʱ�䣬���ͣ�����\n%s\n", str2[w]);
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
	//int flag=0,r=0;�Ȿ����Ϊ�˼����������������ڿ��������ȡ��������2016.12.24-2017.1.1����ʾһ��� 
	system("color A");
	w = run1();
	printf("����һ����ֹ����ʣ������������,����Լ��㹫Ԫ����һ��ʼ���ڵ���һ��ֹ������ʣ�������\n");
	printf("�����ʽΪ:�� �� ��(ע��֮���ÿո�Space���ֿ�)\n");
	printf("ȷ���밴�س�Enter��\n\n"); //printf("%s",str2[w]);//���� ���� 
	printf("������������ʼ����:");
	scanf("%d%d%d", &nian1, &yue1, &ri1);
	printf("�����������ֹ����:");
	scanf("%d%d%d", &nian2, &yue2, &ri2);
	//if(nian2>1000000) {printf("���̫���㲻������... ...%s\n",str1[w]);system("pause");}
	if (nian1>nian2 || nian1 == nian2&&yue1>yue2 || nian1 == nian2&&yue1 == yue2&&ri1>ri2)
	{
		printf("\n���벻�Ϸ�������\n"); system("pause");
	}
	if (yue1>12 || yue2>12 || ri1>31 || ri2>31)
	{
		printf("\n���벻�Ϸ�������\n"); system("pause");
	}
	if (nian1 <= 0 || nian2 <= 0 || yue1 <= 0 || yue2 <= 0 || ri1 <= 0 || ri2 <= 0)
	{
		printf("\n���벻�Ϸ�������\n"); system("pause");
	}
	if (nian2 - nian1 >= 10000)
	{
		int run2(int nian1, int yue1, int ri1, int nian2, int yue2, int ri2); system("pause");
	}
	else{

		if (nian1 == nian2) x = 1 - yue1;
		else x = 0;
		if ((yue1 == yue2) && (nian1 == nian2)) e = 1 - ri1;
		else e = 0;//�찡������֮ǰ�õ���e==0������ eֵ��ȷ�����ߺܴ�,�������������ѭ�� 

		for (y = nian1; y <= nian2; y++)
		{	//i++;
			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) of = 1;
			else of = 0;
			if (y == nian2) h = 12 - yue2;//t=28+g-ri2;
			else h = 0;
			if (y == nian1) q = 1 - x - yue1;//qΪ��ȷ��������ʼ����·�  m �ļ�����ʼ��
			else q = 0;
			for (m = 1 - x - q; m <= 12 - h; m++)
			{
				switch (m)
				{
				case 1:case 3:case 5:case 7:case 8:case 10:case 12:g = 3; break;
				case 2:g = of; break;
				case 4:case 6:case 9:case 11:g = 2; break;
				}
				//if(y==nian2) flag=1;//����nian2��ʼ����nian2���������� 
				if (y == nian2&&m == yue2) {
					t = 28 + g - ri2;
					if (ri2>28 + g)
					{
						printf("\n��ֹ���ڵ�%d�·�û���������%s\n", yue2, str1[w]);
						system("pause");
					}
				}
				else t = 0;
				if (y == nian1&&m == yue1) {
					s = 1 - e - ri1;//sΪ��ȷ��������ʼ����ʼ�µ����� d �ļ�����ʼ�� 
					if (ri1>28 + g)
					{
						printf("\n��ʼ���ڵ�%d�·�û���������%s\n", yue1, str1[w]);
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
		printf("\n������ʼ�������ھ����ֹ���ڻ��� %d ��\n", n - 1);
		u = (n - 1) / 7; k = (n - 1) % 7;
		if (k == 0)
			printf("������%d��\n", u);
		else {
			printf("��%d����%d��\n", u, k);
			if (n - 1>364)
				printf("�����365��Ϊһ����㣬��%d����%d����%d��\n", (n - 1) / 365, (n - 1) % 365 / 7, (n - 1) % 365 % 7);
		}
		//else{if(r%7==0) printf("��%d����%d��",i-1,r/7);
		//else printf("��%d����%d����%d��",i-1,r/7,r%7);}
	}
	if (n - 1 <= 100)printf("��ϧʱ�䣬���ͣ�����\n%s\n", str2[w]);
	system("pause");
}
