#include <stdio.h>
int main()
{
	int aaa = 12, yyy = 0, iii = 1; // Об'явити змінні
	if (aaa > 1) // програма працює якщо введені дані більше 1
	{
		//    do {
		if (aaa % iii == 0) // якщо задане число ділиться на дільник без остачі
		{
			yyy++; // то кількість дільників збільшити на 1
		}
		iii++;
		//    } while ( iii <= aaa );
		while (iii <= aaa) {
			if (aaa % iii == 0) // якщо задане число ділиться на дільник без остачі
			{
				yyy++; // то кількість дільників збільшити на 1
			}
			iii++;
		}
		//for (iii <= aaa; iii++) //цикл опрацювання дільників
		{
			if (aaa % iii == 0) // якщо задане число ділиться на дільник без остачі
			{
				yyy++; // то кількість дільників збільшуємо на 1
			}
		} //
		if (aaa == 2) // якщо кількість дільників дорівнює 2
			printf("Просте"); // то вивести на екран, що воно просте
		else // якщо ні то
			printf("Складене"); // то вивесте на екран, що воно Складене
	}
	return 0;
}
