/*
1. �������� T, �Է�
	1.1 ���������Է�
		: �ΰ����� 6��, ������ 7��. 0�� �ش���������. !0�� ������ ��

2. �������
	�� �� ���� = �ش������� ���� * ������ ���� ���� ��.
	2.1 �������� ������, 3case

3. 3case�� ���� ���ڿ����.
------------------------------------
���� ������ �����ϴ� �迭.
�Է¿� ���� 2���� Sum�� �ް�, ������� ����

����Է��� �޾ƾ��ϱ⿡ ������� �����ϴ� �迭. Tũ��.
-----------------------------------
���ѻ��� : �Է¹迭�� �����Ҵ����� �����迭ó�� �����ϱ�.
			�������� ������.

-------------
2�����迭ó�� ���� �Ͱ� �����Ҵ��� �ϰ� �ɶ���. 
[]�������� �ǹ̿� **�� �ǹ̸� �� �����غ��� ����.
*/

#include <stdio.h>

void fnSetRaceScore(int **pSrc, int nRow, int nCol, int nData);
void fnGetRaceScore(int **pSrc, int nRow, int nCol, int *pRes);
int fnCompareScore(int Score1, int Score2);
void fnPrintText(int nBattleNum, int nCase);

int main()
{
	int nData(0);

	int nBattleNum(0);
	int **pRace(nullptr);
	int *pResult(nullptr);

	int nRaceScore(0);
	int nHumanScore(0);
	int nEvilScore(0);

	//[2][7]
	pRace = new int*[2]{};
	for (int i = 0; i < 2; ++i)
	{
		pRace[i] = new int[7]{};
	}

	fnSetRaceScore(pRace, 0, 0, 1);
	fnSetRaceScore(pRace, 0, 1, 2);
	fnSetRaceScore(pRace, 0, 2, 3);
	fnSetRaceScore(pRace, 0, 3, 3);
	fnSetRaceScore(pRace, 0, 4, 4);
	fnSetRaceScore(pRace, 0, 5, 10);

	fnSetRaceScore(pRace, 1, 0, 1);
	fnSetRaceScore(pRace, 1, 1, 2);
	fnSetRaceScore(pRace, 1, 2, 2);
	fnSetRaceScore(pRace, 1, 3, 2);
	fnSetRaceScore(pRace, 1, 4, 3);
	fnSetRaceScore(pRace, 1, 5, 5);
	fnSetRaceScore(pRace, 1, 6, 10);

	//
	freopen("input.txt", "r", stdin);
	scanf("%d", &nBattleNum);
	pResult = new int[nBattleNum] {};

	for (int i = 0; i < nBattleNum; ++i)
	{
		nHumanScore = 0;
		nEvilScore = 0;
		for (int j = 0; j < 6; ++j)
		{
			scanf("%d", &nData);
			nRaceScore = 0;
			fnGetRaceScore(pRace, 0, j, &nRaceScore);
			nHumanScore += nData * nRaceScore;
		}

		for (int j = 0; j < 7; ++j)
		{
			scanf("%d", &nData);
			nRaceScore = 0;
			fnGetRaceScore(pRace, 1, j, &nRaceScore);
			nEvilScore += nData * nRaceScore;
		}

		pResult[i] = fnCompareScore(nHumanScore, nEvilScore);
	}
	

	//////////
	for (int i = 0; i < nBattleNum; ++i)
	{
		fnPrintText(i + 1, pResult[i]);
	}

	for (int i = 0; i < 2; ++i)
	{
		delete[] pRace[i];
		pRace[i] = nullptr;
	}
	delete[] * pRace;
	*pRace = nullptr;

	delete[]pResult;
	pResult = nullptr;


	return 0;
}

void fnSetRaceScore(int ** pSrc, int nRow, int nCol, int nData)
{
	pSrc[nRow][nCol] = nData;
}

void fnGetRaceScore(int ** pSrc, int nRow, int nCol, int * pRes)
{
	*pRes = pSrc[nRow][nCol];
}

int fnCompareScore(int Score1, int Score2)
{
	if (Score1 > Score2)
		return 1;
	else if (Score1 < Score2)
		return 2;
	else if (Score1 == Score2)
		return 3;
	else
	return 0;
}

void fnPrintText(int nBattleNum, int nCase)
{
	printf("Battle %d: ", nBattleNum);
	if (nCase == 1)//�̱�
	{
		printf("Good triumphs over Evil\n");
	}
	else if (nCase == 2)//��
	{
		printf("Evil eradicates all trace of Good\n");
	}
	else if (nCase == 3)//���
	{
		printf("No victor on this battle field\n");
	}
}
