#pragma once

void Probability(int org, int cur, int sum, int* pProbability)
{
	if (cur == 1)
	{
		pProbability[sum - org]++;	//哈希思想，和减去最小下标等于数组中存的位置
	}
	else
	{
		for (int i = 1; i <= 6; i++)			//循环6次，每次都是从1个递归到6个
		{
			Probability(org, cur - 1, i + sum, pProbability);	//第2个骰子的6种情况,i+sum表示累加的和为多少点
		}
	}
}


void Probability(int n,int* pProbability)
{
	for (int i = 1; i <= 6; i++)		//第一个骰子的6种情况
	{ 
		Probability(n, n, i, pProbability);
	}
}


void PrintProbability(int n)
{
	if (n < 1)
		return;

	int maxsum = n * 6;
	int* pProbability = new int[maxsum - n + 1];

	for (int i = n; i < maxsum; ++i)	//初始化
	{
		pProbability[i - n] = 0;
	}

	Probability(n, pProbability);

	int total = pow((double)6, n);
	for (int i = n; i <= maxsum; i++)		//打印每个数出现的次数
	{
		double ratio = (double)pProbability[i - n] / total;
		printf("%d: %e\n", i, pProbability);
	}

	delete[] pProbability;
}


void Probability(int org, int cur, int sum, int* pa)
{
	if (cur == 1)
	{
		pa[sum - org]++;
	}
	else
	{
		for (int i = 1; i <= 6; i++)
		{
			Probability(org, cur - 1, i, pa);
		}
	}
}
void Probability(int n, int* pa)
{
	for (int i = 1; i <= 6; i++)
	{
		Probability(n, n, i, pa);
	}
}

void PrintProbability1(int n)
{
	int maxsum = 6 * n;
	int* pa = new int[maxsum - n + 1];

	for (int i = n; i < maxsum; i++)
	{
		pa[i - n] = 0;
	}

	Probability(n, pa);
	
}


void PrintProbability_NonR(int n)
{
	if (n < 1)
		return;

	int maxsum = 6 * n;
	int* pa[2];
	pa[0] = new int[maxsum + 1];
	pa[1] = new int[maxsum + 1];

	for (int i = 0; i < maxsum+1; i++)
	{
		pa[0][i] = 0;
		pa[1][i] = 0;
	}

	int flag = 0;
	for (int i = 1; i <= 6; i++)
	{
		pa[flag][i] = 1;
	}

	for (int k = 2; k < n; ++k)
	{
		for (int i = 0; i < k; ++i)
		{
			pa[1 - flag][i] = 0;
		}

		for (int i = k; i <= 6 * k; i++)
		{
			pa[1 - flag][i] = 0;
			for (int j = 1; j <= i&& j <= 6; ++j)
			{
				pa[1 - flag] += pa[flag][i - j];
			}
		}
		flag = 1 - flag;
	}
	int total = pow((double)6, n);
	for (int i = n; i <= maxsum; i++)		//打印每个数出现的次数
	{
		double ratio = (double)pa[flag][i] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] pa[0];
	delete[] pa[1];
}

void TestPrint()
{
	PrintProbability(7);
}