#include <iostream>
#include <time.h>
#include <stdlib.h>
bool fun_isp(int n);

void fun_massin(int* a, int* size,int id) {
	for (int i = 0; i < *size; i++) {
		if (id == 1) {
			a[i] = rand() % 20 - 9;
		}
		if (id == 0) {
			a[i] = rand()%25 +1;
		}
		if (id == 2) {
			std::cin >> a[i];
		}
	}

}


void fun_massout(int* a, int* size) {
	std::cout << "\n" << "Vuhodnoi massiv = " << "\n";
	for (int i = 0; i < *size; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
}

void fun_masswork_1(int* a, int* size) {
	int ind = 0;
	for (int i = 0; i < *size; i++) {
		if (fun_isp(a[i])==false) {
			a[i] = 0;
		}
	}
	do {
	for (int i = 0; i < *size; i++) {
		if (a[i] == 0) {
			a[i] = a[i + 1];
			a[i + 1] = 0;
			ind++;
		}
		else {
			ind = 0;
		}
	}
	*size = *size - 1;
	
	
	} while (ind != 0);
	
	
}


bool fun_isp(int n) {
	if (n == 1) // 1 - не простое число
		return false;
	// перебираем возможные делители от 2 до sqrt(n)
	for (int d = 2; d*d <= n; d++) {
		// если разделилось нацело, то составное
		if (n%d == 0)
			return false;
	}
	// если нет нетривиальных делителей, то простое
	return true;
}

void fun_masswork_2(int* a, int* size) {
	int ind = 0;
	int t = 0;
	
	do {
		for (int i = 0; i < *size; i++) {
			if (*(a+i) > *(a+i+1)) {
				t = *(a + i);
				*(a + i) = *(a + i + 1);
				*(a + i + 1 )= t;
				ind++;
			}
		}
		if (ind >= *size *2) {
			ind = 0;
		}
	} while (ind != 0 );
	
}

int fun_masswork_3(int* a, int* b, int* size, int* size_2) {
	int ind = 0;
	if (*size != *size_2) {
		return 0;
	}
	for (int i = 0; i < *size; i++) {
		if (a[i] == b[i] || a[i]== -b[i] || -a[i]==b[i]) {
			ind++;
		}
	}
	if (ind == *size) {
		return 1;
	}
	else {
		return 0;
	}
}

void fun_massin_dv(int a[100][100], int *size, int* size_2) {
	for (int i = 0; i < *size; i++) {
		for (int j = 0; j < *size_2; j++) {
			a[i][j] = rand()%2;
		}
	}
}
void fun_massout_dv(int a[100][100], int *size, int* size_2) {
	std::cout << "\n" << "Vuhodnoi massiv = " << "\n";
	for (int i = 0; i < *size; i++) {
		for (int j = 0; j < *size_2; j++) {
			std::cout << " " << a[i][j];
		}
		std::cout << "\n";
	}
}


void fun_masswork_4(int* x_1, int* x_2, int* y_1, int* y_2, int a[100][100], int* size, int* size_2) {
	int ind = 0;
	int ind_2 = 0;
	int id = 0;
	int ind_3 = 0;
	int id_2 = 0;
	do {
		for (int i = 0; i < *size; i++) {
			if (a[id][id_2] == 0) {
				*x_1 = id;
				*y_1 = id_2;

				for (int j = id_2; j < *size_2; j++) {
					if (a[id][j] == 0) {
						ind_2++;
					}
					else {
						*y_2 = j - 1;
						break;
					}
				}
				if (ind_3 < ind_2) {
					ind_3 = ind_2;
				}
				id++;

			}
			else {
				id_2++;
			}
			if (id_2 >= *size) {
				id_2 = 0;
				id++;
			}
			
		}
		if (id >= *size) {
			ind = 0;
		}
	} while (ind != 0);
}

int main() {
	srand(time(NULL));
	int a[100] = { 0 };
	int size = 0;
	int flag_menu = 0;
	int b[100] = { 0 };
	int size_2 = 0;
	int c[100][100] = { 0 };
	int x_1 = 0;
	int x_2 = 0;
	int y_1 = 0;
	int y_2 = 0;
	


	do {
		std::cout << "\n" << "Vvedite nomer zadani9 1-8 , 0 -vuhod" << "\n";
		std::cin >> flag_menu;

		if (flag_menu == 1) {
			std::cout << "\n" << "Zadaca nomer 1" << "\n";
			std::cout << "\n" << "Vvedite razmer massiva : ";
			std::cin >> size;
			fun_massin(&a[0], &size,0);
			fun_massout(&a[0], &size);
			fun_masswork_1(&a[0], &size);
			size++;
			fun_massout(&a[0], &size);

		}
		if (flag_menu == 2) {
			std::cout << "\n" << "Zadaca nomer 2" << "\n";
			std::cout << "\n" << "Vvedite razmer massiva : ";
			std::cin >> size;
			fun_massin(&a[0], &size, 1);
			fun_massout(&a[0], &size);
			fun_masswork_2(&a[0], &size);
			fun_massout(&a[0], &size);


		}

		if (flag_menu == 3) {
			std::cout << "\n" << "Zadaca nomer 3" << "\n";
			std::cout << "\n" << "Vvedite razmer massiva : ";
			std::cin >> size;
			std::cout << "\n" << "vvedite elementu massiva ";
			fun_massin(&a[0], &size, 2);
			std::cout << "\n" << "Vvedite razmer vtorogo massiva : ";
			std::cin >> size_2;
			std::cout << "\n" << "vvedite elementu massiva ";
			fun_massin(&b[0], &size_2, 2);

			fun_massout(&a[0], &size);
			fun_massout(&b[0], &size_2);
			int otvet= fun_masswork_3(&a[0],&b[0],&size,&size_2);
			if (otvet == 0) {
				std::cout << "\n" << "otvet : NET";
			}
			else {
				std::cout << "\n" << "otvet : DA";
			}
			


		}


		if (flag_menu == 4) {
			std::cout << "\n" << "Zadaca nomer 4" << "\n";
			std::cout << "\n" << "Vvedite razmer strok massiva : ";
			std::cin >> size;
			std::cout << "\n" << "Vvedite razmer stolbcov massiva : ";
			std::cin >> size_2;
			fun_massin_dv(c , &size, &size_2);

			fun_massout_dv(c , &size, &size_2);
			fun_masswork_4(&x_1, &x_2, &y_1, &y_2, c, &size, &size_2);

			std::cout << "\n" << "Kordinatu po x : " << x_1+1 << " " << x_2+1 << " \n" << "po y :" << y_1+1 << " " << y_2+1 << " \n";

		}



		if (flag_menu == 5) {
			std::cout << "\n" << "Zadaca nomer 5" << "\n";
			std::cout << "Vvedite 4islo = ";
			std::cin >> size;
			int flag = 0;
			for (int i = 0; i < sizeof(size); i++) {
				uint8_t byte = *((uint8_t*)&size + i);
				int bits[8];
				for (int j = 0; j < 8; j++) {
					bits[j] = byte % 2;
					byte /= 2;
				}
				for (int j = 7; j >= 0; j--) {
					printf("%d", bits[j]);
					if (i == 0 && bits[j] != 0) {
						flag = 1;
					}
				}
				printf(" ");
			}
			
			if (flag == 1) {
				printf(" \n Por9dok bait na atoi platforme = LE ");
			}
			else {
				printf(" \n Por9dok bait na atoi platforme = BE ");
			}
		}

		if (flag_menu == 6) {
			std::cout << "\n" << "Zadaca nomer 6" << "\n";
			std::cout << "Vvedite 4islo = ";
			std::cin >> size;
			int flag = 0;
			int flag_2 = 0;
			for (int i = 0; i < sizeof(size); i++) {
				uint8_t byte = *((uint8_t*)&size + i);
				int bits[8];
				for (int j = 0; j < 8; j++) {
					bits[j] = byte % 2;
					byte /= 2;
				}
				for (int j = 7; j >= 0; j--) {
					printf("%d", bits[j]);
					if (size < 0 && i>0 && bits[j] == 1) {
						flag++;
					}
					
				}
				if (flag == 8) {
					flag_2 = 1;
					flag = 0;
				}
				else {
					flag = 0;
				}
				printf(" ");
			}
			if (flag_2 == 1) {
				printf("\n Por9dok kodirofki na etoi sisteme = INVERSI9 N+1 ");

			}
			else {
				printf("\n Por9dok kodirofki na etoi sisteme = INVERSI9 N ");
			}






		}

	} while (flag_menu != 0);





}