#include <stdio.h>
int main()
{
	int xxx = 4232, aaa, ddd, eee, fff, ccc; //вводимо змінну
	fff = xxx % 10; //Відділяємо саму останню цифру числа
	eee = xxx / 10 % 10; //Відділяємо другу цифру числа
	ddd = xxx / 100 % 10; //Відділяємо 3 цифру числа
	aaa = xxx / 1000; //Відділяємо 4 цифру числа
	ccc = fff + eee + ddd + aaa; //Додаємо усі цифри числа
	printf("%d", ccc); //Виводимо результат на екран
	return 0;
}
