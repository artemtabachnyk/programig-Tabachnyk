/**
*	@file lab06.c Заповнити масив цілих чисел числами Фібоначчі
*	@author Tabachnyk Artem
*/
#include <stdio.h>
/**
*	Функція яка видає рандомне ціле число
*/
int random();             //  Вводимо функцію яка видає рандомне ціле число 
/**
*	Фунція за допомогою якої рандомне число ми прив'язуємо до системного часу
*/
int time();               //  Вводимо функції за допомогою яких рандомне число прив'яжемо до системного часу 
/**
*	Фунція за допомогою якої рандомне число ми прив'язуємо до системного часу
*/
int srand();               
/**
*	Фунція в якій буде виконуватися основна дія(Шукання чисел Фібоначчі)
*	@param Num рандомне число яке яке ми обмежуємо діапазоном від 10 до 20
*	@param arr Масив який складається з рандомної кількості елементів
*	@param xxx Змінна за допомогою якої ми шукаємо числа Фібоначчі
*	@param yyy Змінна за допомогою якої ми шукаємо числа Фібоначчі
*	@param zzz Змінна за допомогою якої ми шукаємо числа Фібоначчі
*	@param ccc Змінна за допомогою якої ми шукаємо числа Фібоначчі
*	@param iii Змінна за допомогою якої виводяться на екран всі елементи масива arr з рандомною кількістю елементів
*/ 
int findFibonachi(){      //Фунція в якій буде виконуватися основна дія(Шукання чисел Фібоначчі)-код ЛАБОРАТОРНОЇ РОБОТИ №6 
  srand (time(NULL));             // Генеруємо рандомне число яке прив'язано до системного часу 
    int Num = random() % 10 + 10 ;  // Так як ми прив'язуємо рандомне число до розміру масиву, для зручності програми, обмежуємо діапазон від 10 до 20
    int arr [Num] ;                 // Прив'язуємо раномне число до розміру масиву
    printf("Сгенероване число %d\n", Num );    // Для зручності виводимо сгенероване число на екран
    while (1)                                 //початок циклу
    {
        int xxx, yyy, zzz, ccc, iii;  //Вводимо змінні
        xxx = 0;     //Задаємо  початкові значення змінних
        yyy = 1;
        ccc = 0; 

            do 
            {                         // Початок виконання цикла
                arr[ccc] = xxx;       //Записуємо в 0 елемент масива число, а потім дії продовжуються
                ccc += 1;             //з кожним повторенням цикла елемент масива буде збільшуватися на 1 
                zzz = xxx + yyy;      //В цій дії буде обчислюватися кожен раз число Фібоначчі
                xxx = yyy;           //А в цих діях число записується для обчислення наступного числа Фібоначчі
                yyy = zzz;

           } while (xxx < 10000);   // Обмежуємо пошук чисел Фібоначчі до 10000

            for(iii=0;iii<Num;iii++) //Виводимо на екран масив arr з рандомним розміром
            {
                printf(" %d", arr[iii]); 
            }
            return 0;
    } 
}

/**
*	Головна фунція main, в якій записаний виклик функції, де знаходиться числа Фібоначчі
*/
void main()                        // Головна фунція main, в якій записаний виклик функції, де знаходиться числа Фібоначчі 
{
                      
    findFibonachi();
}

//int number (int xxx)        // Фунція в якій буде виконуватися основна дія(Шукати просте чи складене число)-код для ЛАБОРАТОРНОЇ РОБОТИ №5
//{
//        int aaa = 12, yyy = 0, iii = 1; // Об'явити змінні
//        if (aaa > 1) // програма працює якщо введені дані більше 1
//        {
//                //    do {
//                if (aaa % iii == 0) // якщо задане число ділиться на дільник без остачі
//                {
//                        yyy++; // то кількість дільників збільшити на 1
//                }
//                iii++;
                //  } while ( iii <= aaa );
//                while (iii <= aaa) {
//                        if (aaa % iii == 0) // якщо задане число ділиться на дільник без остачі
//                        {
//                                yyy++; // то кількість дільників збільшити на 1
//                        }
//                        iii++;
//                }
                //for (iii <= aaa; iii++) //цикл опрацювання дільників
//                {
//                        if (aaa % iii == 0) // якщо задане число ділиться на дільник без остачі
//                        {
//                                yyy++; // то кількість дільників збільшуємо на 1
//                        }
//                } //
//                if (aaa == 2) // якщо кількість дільників дорівнює 2
//                        printf("\nПросте"); // то вивести на екран, що воно просте
//                else // якщо ні то
//                        printf("\nСкладене"); // то вивесте на екран, що воно Складене
//        }
//        return 0;
//}
//int main()                 // Основна функція main
//{  
//    int xxx;               // Вводимо змінну ххх яке буде передаватися в функцію number для виконання задачі 
   
//    int ggg;                             
//    printf("Введіть число 1 або 2 ");    // Тут ми вибираємо спосіб роботи программи 
//    scanf("%d", &ggg);  
      
//    switch(ggg){                            // В залежності від обраного числа буде виконуватися певний спосіб роботи
//        case 1:                             // В 1 способі користувач самостійно обирає число 
//            printf("Вводить число ");  
//            scanf("%d", &xxx);  
//            number(xxx);  
//            break;  
//        case 2:                            // В 2 способі число генерується рандомно від 0 до 1000
//            srand (time(NULL));  
//            xxx = random()%1000;  
//            printf("Сгенерированное число %d\n", xxx);  
//            number(xxx);  
//            break;  
//        default :          // Якщо користувач неправильно ввів данні та не вибрав спосіб роботи программи то программа використає данні за замовчуванням
//            printf("Неправильно введені данні, ми використоємо данні за замовчуванням,число = 12");   
//            number(xxx);
//            break;  
//    }  
      
// return 0;  
  
//}
