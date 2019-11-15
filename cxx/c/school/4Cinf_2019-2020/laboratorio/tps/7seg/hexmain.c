#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NDIM 16

//funzione per stampare un carattere partendo da coordinate determinate
void draw(char num[9][5], int x0, int y0);
//funzione wrapper di draw che prende dal parametro le singole cifre e le stampia
void print7Seg(char nums[NDIM][9][5], char n[]);

void main(int argv, char** argc){
	if (argv == 1) printf("Please supply at least 1 parameter.\n");
	else {
		//array 3dimensionale coi numeri
		char numbers[NDIM][9][5] =
		{
			{//0
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '}
			},
			{//1
				{' ', ' ', ' ', ' ', ' '},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', ' '},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', ' '}
			},
			{//2
				{' ', '#', '#', '#', ' '},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{' ', '#', '#', '#', ' '}
			},
			{//3
				{' ', '#', '#', '#', ' '},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '}
			},
			{//4
				{' ', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', ' '}
			},
			{//5
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{' ', '#', '#', '#', ' '},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '}
			},
			{//6
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '}
			},
			{//7
				{' ', '#', '#', '#', ' '},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', ' '},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', ' '}
			},
			{//8
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '}
			},
			{//9
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '}
			},
			{//A
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', ' '}
			},
			{//B
				{' ', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '}
			},
			{//C
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{' ', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{' ', '#', '#', '#', ' '}
			},
			{//D
				{' ', ' ', ' ', ' ', ' '},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{'#', ' ', ' ', ' ', '#'},
				{' ', '#', '#', '#', ' '}
			},
			{//E
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{' ', '#', '#', '#', ' '}
			},
			{//F
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{' ', '#', '#', '#', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{'#', ' ', ' ', ' ', ' '},
				{' ', ' ', ' ', ' ', ' '}
			}
		};
		//clear terminale
		printf("\e[2J");
		//stampare numero passato come parametro
		print7Seg(numbers, argc[1]);
	}
}

void print7Seg(char nums[NDIM][9][5], char n[]) {
	printf("length of string %ld.\n", strlen(n));
	for (int i = 0; i < strlen(n); i++) {
		printf("Printing %c as %d", n[i], (int)strtol(&n[i],NULL,16));
//		draw(nums[ (int)strtol(&n[i],NULL,16) ], 1 + (i * 10), 1);
	}
}

void draw(char num[9][5], int x0, int y0 ){
	for (int i = 0; i < 9; i++) {             //loop righe numero
		for (int j = 0; j < 5; j++) {         //loop colonne numero
			printf("\e[%i;%iH", i+y0, j+x0);  //vai a coordinate (i,j) con offset x0 e y0
			printf("%c", num[i][j]);          //stampa il carattere dal numero
		} 
	}
}
