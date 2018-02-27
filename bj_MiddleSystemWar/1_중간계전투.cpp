/*
1. 전투개수 T, 입력
	1.1 전투정보입력
		: 인간팀은 6개, 적팀은 7개. 0은 해당종족없음. !0은 종족의 수

2. 전투계산
	각 팀 점수 = 해당종족의 점수 * 종족의 수를 더한 값.
	2.1 양진형의 점수비교, 3case

3. 3case에 따라 문자열출력.
------------------------------------
종족 점수를 저장하는 배열.
입력에 따라 2개의 Sum을 받고, 결과값을 저장

모든입력을 받아야하기에 결과값을 저장하는 배열. T크기.
-----------------------------------
제한사항 : 입력배열을 동적할당으로 이차배열처럼 구현하기.
			전역변수 사용금지.

-------------
2차원배열처럼 쓰고 싶게 동적할당을 하게 될때는. 
[]연산자의 의미와 **의 의미를 잘 생각해보고 쓰자.
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
	if (nCase == 1)//이김
	{
		printf("Good triumphs over Evil\n");
	}
	else if (nCase == 2)//짐
	{
		printf("Evil eradicates all trace of Good\n");
	}
	else if (nCase == 3)//비김
	{
		printf("No victor on this battle field\n");
	}
}
