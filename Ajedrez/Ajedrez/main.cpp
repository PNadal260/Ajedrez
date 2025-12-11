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
		for (int i = 0; i < TAMAÑO; i++) {
			for (int j = 0; j < TAMAÑO; j++)
			{	
				std::cout << tablero[i][j] << " ";
			}
			std::cout << std::endl;
		}
		return 0;
	}