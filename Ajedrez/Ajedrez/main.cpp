#include <iostream>

const int TAMAÑO  = 8;

int main(){
	char tablero[TAMAÑO][TAMAÑO];
	for (int i = 0; i < TAMAÑO; i++) {
		for (int j = 0; j < TAMAÑO; j++)
		{
			tablero[i][j] = '*';
		}
	}
	for (int i = -1, k = 8; i < TAMAÑO; i++,k--) {
		if (k == 8)
			std::cout << "  ";
		else
			std::cout << k + 1 << ' ';
		for (int j = 0; j < TAMAÑO; j++)
		{	
			if (i == -1)
				std::cout << j + 1 << ' ';
			else
				std::cout << tablero[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}