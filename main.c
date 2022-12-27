#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include<time.h>
#include <stdlib.h>
#define SIZE 15// 홀수

int map[SIZE][SIZE];
int map_[SIZE+2][SIZE+2];
int tmap[SIZE+2][SIZE+2];
int see = 3;
int mv = 0;


int st[9][32] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,1,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,0,1,0,1,0,0,0,1,1,0,0,1},
{0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,1,0,1},
{0,1,0,0,1,0,1,0,0,1,1,1,1,1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,1,0,1},
{0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,1,1,0,0,1},
{0,1,0,0,1,0,1,0,0,1,1,1,1,1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,1},
{0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1},
{0,1,1,1,1,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,1,1,1}
};

void st_create() {//시작화면
	for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 32; b++)
		{
			if (st[a][b] == 1)
			{
				printf("■");
			}
			else if (st[a][b] == 0)
			{
				printf("  ");
			}
		}
		printf("\n");
	}
}

void make_map()//랜덤 미로 생성
{
	int x=0, y = 0,rotate;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			map[j][i] = 1;
		}
	}
	map[x][y] = 0;
	srand(time(NULL));

	while (1) {

		for (int i = 0; i < 100000; i++) {

			rotate = rand() % 4 + 1;

			if (rotate == 1) {
				if (y == 0)
					continue;
				if (map[x][y - 2] == 1) {
					y--; map[x][y] = 0;
					y--; map[x][y] = 0;
				}
				else {
					y -= 2;
				}
			}

			if (rotate == 2) {
				if (x == SIZE - 1)
					continue;
				if (map[x + 2][y] == 1) {
					x++; map[x][y] = 0;
					x++; map[x][y] = 0;
				}
				else {
					x += 2;
				}
			}

			if (rotate == 3) {
				if (y == SIZE - 1)
					continue;
				if (map[x][y + 2] == 1) {
					y++; map[x][y] = 0;
					y++; map[x][y] = 0;
				}
				else {
					y += 2;
				}
			}

			if (rotate == 4) {
				if (x == 0)
					continue;
				if (map[x - 2][y] == 1) {
					x--; map[x][y] = 0;
					x--; map[x][y] = 0;
				}
				else {
					x -= 2;
				}
			}
		}
		if (map[SIZE - 1][SIZE - 1] == 0)
			break;
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			map_[i + 1][j + 1] = map[i][j];
		}
	}
	for (int i = 0; i < SIZE + 2; i++) {
		map_[0][i] = 1;
		map_[i][0] = 1;
		map_[SIZE + 1][i] = 1;
		map_[i][SIZE + 1] = 1;
	}

	int k = 0;
	srand(time(NULL));
	while (k != 5) {
		int a = rand() % SIZE + 1;
		int b = rand() % SIZE + 1;
		if (map_[a][b] == 0) {
			map_[a][b] = 6;
			k++;
		}
	}
	map_[SIZE][SIZE] = 4;
}




void show_map() //미로
{
	int a, b;

	for (a = 0; a < SIZE + 2; a++)
	{
		for (b = 0; b < SIZE + 2; b++)
		{
			if (tmap[a][b] == 1)
			{
				printf("■");
			}
			else if (tmap[a][b] == 0)
			{
				printf("  ");
			}
			else if (tmap[a][b] == 3) {
				printf("◎");
			}
			else if (tmap[a][b] == 4) {
				printf("★");
			}
			else if (tmap[a][b] == 5) {
				printf("□");
			}
			else if (tmap[a][b] == 6) {
				printf("♣");
			}

		}
		printf("\n");
	}
}
int main()
{
	st_create();
	printf("\n\n 시작하려면 엔터키를 누르세요.");
	while (1) {
		int k = _getch();
		if (k == 13)
			break;
	}

	system("cls");
	make_map();
	int ch_x = 1, ch_y = 1;
	int cmd = 0;

	clock_t start, finish;
	double duration;

	
	start = clock();


	while (1) {

		if (map_[ch_x][ch_y] == 4) {
			system("cls");
			break;
		}
		else if (map_[ch_x][ch_y] == 6) {
			see++;
		}
		map_[ch_x][ch_y] = 3;

		for (int i = 0; i < SIZE+2; i++) {
			for (int j = 0; j < SIZE+2; j++) {
				if (i == 0 || j == 0)
					tmap[i][j] = 1;
				else if (i == SIZE + 1 || j == SIZE + 1)
					tmap[i][j] = 1;
				else if (i == SIZE && j == SIZE)
					tmap[i][j] = 4;
				else {
					if (i < ch_x + see && i> ch_x - see) {
						if (j < ch_y + see && j > ch_y - see)
							tmap[i][j] = map_[i][j];
						else
							tmap[i][j] = 5;
					}
					else
						tmap[i][j] = 5;
				}
			}
		}

		
		system("cls");
		show_map();
	
		cmd = _getch();
		if (cmd == 77 && map_[ch_x][ch_y + 1] != 1) { //오
			map_[ch_x][ch_y] = 0;
			ch_y++;
			mv++;
		}
		else if (cmd == 72 && map_[ch_x - 1][ch_y] != 1) { //위
			map_[ch_x][ch_y] = 0;
			ch_x--;
			mv++;
		}
		else if (cmd == 75 && map_[ch_x][ch_y - 1] != 1) {//왼
			map_[ch_x][ch_y] = 0;
			ch_y--;
			mv++;
		}
		else if (cmd == 80 && map_[ch_x + 1][ch_y] != 1) { //아래
			map_[ch_x][ch_y] = 0;
			ch_x++;
			mv++;
		}

	}

	finish = clock();
	duration = (finish - start) / CLOCKS_PER_SEC;
	printf("\n\n\n");
	printf("   ■■■■■■■■■■\n");
	printf("   ■■■  성공! ■■■\n");
	printf("   ■■■■■■■■■■\n\n");
	Sleep(1000);
	printf("    %.0f 초 \n    %d번 이동\n\n", duration,mv);
	
	Sleep(1000);
}




