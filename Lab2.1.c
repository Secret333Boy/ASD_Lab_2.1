#include <stdio.h>

int main () {//							 0    1  2    3    4  5  6    7  8  9
	float MATRIX_WITH_DATA[7][10] = {	{5  , 5, 4  , 3  , 3, 3, 2.4, 1, 1, 1   /*0*/}, 
										{5  , 5, 5  , 4  , 4, 4, 1  , 1, 1, 1	/*1*/}, 
										{3.1, 3, 2  , 1  , 1, 1, 1  , 1, 1, 1	/*2*/},
										{5  , 5, 4.5, 4.2, 4, 4, 1  , 1, 1, 0.3	/*3*/},
										{5  , 5, 5  , 4.3, 4, 4, 1.8, 1, 1, 0.2	/*4*/},
										{5  , 5, 5  , 4  , 4, 4, 2  , 1, 1, 0	/*5*/},
										{5  , 5, 5  , 4  , 4, 4, 1  , 1, 1, 1	/*6*/}	};
	float NUBMER_TO_FIND = 0;
	printf("Enter real number: ");
	scanf("%f", &NUBMER_TO_FIND);// Дізнаємося, яке число треба шукати

	int ARRAY_LENGTH = sizeof(MATRIX_WITH_DATA[0]) / sizeof(MATRIX_WITH_DATA[0][0]); //Довжина рядка

	int i = 0, j = -1;
	for (i; i < 7; i++) {// Проходимо по всіх рядках
		int L = 0, R = ARRAY_LENGTH - 1;
		while (L < R) {
			int MIDDLE_INDEX = (L + R) / 2;
			float middle = MATRIX_WITH_DATA[i][MIDDLE_INDEX];// Знаходимо середину

			if (NUBMER_TO_FIND < middle) {
				L = MIDDLE_INDEX + 1; // Розглядаємо масив з середини (не включно) до кінця
			} else {
				R = MIDDLE_INDEX; // Розглядаємо масив з початку до середини включно
			}
		}

		if (R == L && MATRIX_WITH_DATA[i][R] == NUBMER_TO_FIND && MATRIX_WITH_DATA[i][L] == NUBMER_TO_FIND) {
			j = L;
		}

		if (j != -1) {// Знайшли елемент, отримали координату Y => закінчуємо пошук, фіксуємо X (номер рядка)
			break;
		}
	}

	if (j != -1) {// Знайшли => виводимо результати
		printf("X: %d; Y: %d\n", i, j);
	} else {// Не знайшли => виводимо повідомлення про помилку
		printf("There is no such number in the matrix!\n");
	}

	system("pause");
	return 0;
}