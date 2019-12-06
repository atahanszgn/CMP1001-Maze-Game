#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;
const int mrow = 12;
const int mcolumn = 24;
bool lvl1bspawn = false,lvl2bspawn = false;
bool restart = false;
bool b3active = false,b4active = false;
bool Level1Finished = false,Level2Finished = false;
char decision;
char movementinput;
char W = 219 , Player = 155 , Bonus1 = 250 , Bonus2 = '#' , Bonus3 = '?' , Bonus4 = '@';
int randomx,randomy;
int autoinput;
int highscore;
int option = 0;
int lvl1count = 0,lvl2count = 0;
int playcount = 1;
int result1 = 0;
int lvl1x = 1,lvl1y = 1;
int beflvl1x = 1,beflvl1y = 1;
int lvl2x = 1,lvl2y = 2;
int beflvl2x = 1,beflvl2y = 2;
int score = 0;
int sclvl1,sclvl2;
int timer = 20;
int scorex = 26;
int scorey = 0,timery = 1, resulty = 2, bon3y = 3, bon4y = 4, lvlendy = 5;

//--Pointers--
int *plvl2x = &lvl2x;
int *plvl2y = &lvl2y;
int *pplvl2x = &beflvl2x;
int *pplvl2y = &beflvl2y;
int *plvl1x = &lvl1x;
int *plvl1y = &lvl1y;
int *pplvl1x = &beflvl1x;
int *pplvl1y = &beflvl1y;

char Level1[mrow][mcolumn] // First Maze

{ { W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W },
{ W,Player,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,W },
{ W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,0,W },
{ W,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,W },
{ W,0,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W },
{ W,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,W },
{ W,W,W,W,W,W,W,W,W,W,W,0,W,W,W,W,W,0,W,W,W,W,0,W },
{ W,W,W,0,0,0,0,W,W,W,W,0,W,W,W,W,W,0,0,0,0,0,0,W },
{ W,W,W,'F',W,W,0,0,0,0,0,0,0,0,0,0,0,0,W,W,W,W,W,W },
{ W,W,W,W,W,W,W,W,0,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W },
{ W,W,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,W,W,W,W },
{ W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W }};

char Level2[mrow][mcolumn] // Second Maze
{ { W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W },
{ W,Player,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,W,W,W },
{ W,W,W,W,0,W,W,W,W,W,W,0,W,W,W,W,W,W,W,W,0,W,W,W },
{ W,W,0,0,0,0,0,0,0,0,W,0,W,W,0,0,0,W,W,W,0,W,W,W },
{ W,W,0,W,0,W,W,W,W,0,W,0,W,W,0,W,0,W,W,W,0,W,W,W },
{ W,W,0,W,0,W,W,W,W,0,W,0,W,0,0,0,0,0,W,W,0,W,0,W },
{ W,W,0,0,0,W,0,0,0,0,0,0,0,0,W,W,W,0,W,W,W,W,0,W },
{ W,W,W,W,0,W,0,W,0,W,W,0,W,0,0,0,W,0,0,0,0,0,0,W },
{ W,0,0,0,0,W,0,0,0,W,W,0,W,W,W,0,W,W,W,0,W,W,W,W },
{ W,W,W,W,0,W,W,W,0,0,0,0,0,0,W,0,W,W,W,0,0,0,'F',W },
{ W,W,W,W,0,0,0,0,0,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W },
{ W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W }};

void pposition(int x, int y)
{
	COORD player;
	player.X = x;
	player.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),player);
} 

void BonusSpawner()
{
	if (Level1Finished == false)
	{
		srand(time(0));
		while (lvl1count < 5)
		{
			 randomx = rand() % mcolumn;
			 randomy = rand() % mrow;
			if (Level1[randomy][randomx] != W && Level1[randomy][randomx] != 'F' && Level1[randomy][randomx] != Bonus1  && Level1[randomy][randomx] != Bonus2 && Level1[randomy][randomx] != Bonus3 && Level1[randomy][randomx] != Bonus4 && Level1[randomy][randomx] != Player)
			{
				Level1[randomy][randomx] = Bonus1;
				lvl1count++;
			}
		}

		lvl1count = 0;

		while (lvl1count < 2)
		{
			 randomx = rand() % mcolumn;
			 randomy = rand() % mrow;
			if (Level1[randomy][randomx] != W && Level1[randomy][randomx] != 'F' && Level1[randomy][randomx] != Bonus1   && Level1[randomy][randomx] != Bonus2 && Level1[randomy][randomx] != Bonus3 && Level1[randomy][randomx] != Bonus4 && Level1[randomy][randomx] != Player)
			{
				Level1[randomy][randomx] = Bonus2;
				lvl1count++;
			}
		}

		lvl1count = 0;

		while (lvl1count < 1)
		{
			 randomx = rand() % mcolumn;
			 randomy = rand() % mrow;
			if (Level1[randomy][randomx] != W && Level1[randomy][randomx] != 'F' && Level1[randomy][randomx] != Bonus1  && Level1[randomy][randomx] != Bonus2 && Level1[randomy][randomx] != Bonus3 && Level1[randomy][randomx] != Bonus4 && Level1[randomy][randomx] != Player)
			{
				Level1[randomy][randomx] = Bonus3;
				lvl1count++;
			}
		}
		
		lvl1count = 0;
		
		while (lvl1count < 1)
		{
			 randomx = rand() % mcolumn;
			 randomy = rand() % mrow;
			if (Level1[randomy][randomx] != W && Level1[randomy][randomx] != 'F' && Level1[randomy][randomx] != Bonus1   && Level1[randomy][randomx] != Bonus2 && Level1[randomy][randomx] != Bonus3 && Level1[randomy][randomx] != Bonus4 && Level1[randomy][randomx] != Player)
			{
				Level1[randomy][randomx] = Bonus4;
				lvl1count++;
			}
		}

		lvl1count = 0;

	}
	else if (Level2Finished == false)
	{
		while (lvl2count < 5)
		{
			 randomx = rand() % mcolumn;
			 randomy = rand() % mrow;
			if (Level2[randomy][randomx] != W && Level2[randomy][randomx] != 'F' && Level2[randomy][randomx] != Bonus1  && Level2[randomy][randomx] != Bonus2 && Level2[randomy][randomx] != Bonus3 && Level2[randomy][randomx] != Bonus4 && Level2[randomy][randomx] != Player)
			{
				Level2[randomy][randomx] = Bonus1;
				lvl2count++;
			}
		}

		lvl2count = 0;

		while (lvl2count < 2)
		{
			 randomx = rand() % mcolumn;
			 randomy = rand() % mrow;
			if (Level2[randomy][randomx] != W && Level2[randomy][randomx] != 'F' && Level2[randomy][randomx] != Bonus1  && Level2[randomy][randomx] != Bonus2 && Level2[randomy][randomx] != Bonus3 && Level2[randomy][randomx] != Bonus4 && Level2[randomy][randomx] != Player)
			{
				Level2[randomy][randomx] = Bonus2;
				lvl2count++;
			}
		}

		lvl2count = 0;

		 while (lvl2count < 1)
		{
			  randomx = rand() % mcolumn;
			  randomy = rand() % mrow;
			if (Level2[randomy][randomx] != W && Level2[randomy][randomx] != 'F' && Level2[randomy][randomx] != Bonus1  && Level2[randomy][randomx] != Bonus2 && Level2[randomy][randomx] != Bonus3 && Level2[randomy][randomx] != Bonus4 && Level2[randomy][randomx] != Player)
			{
				Level2[randomy][randomx] = Bonus3;
				lvl2count++;
			}
		}

		lvl2count = 0;
		
		while (lvl2count < 1)
		{
			 randomx = rand() % mcolumn;
			 randomy = rand() % mrow;
			if (Level2[randomy][randomx] != W && Level2[randomy][randomx] != 'F' && Level2[randomy][randomx] != Bonus1  && Level2[randomy][randomx] != Bonus2 && Level2[randomy][randomx] != Bonus3 && Level2[randomy][randomx] != Bonus4 && Level2[randomy][randomx] != Player)
			{
				Level2[randomy][randomx] = Bonus4;
				lvl2count++;
			}
		}

		lvl2count = 0;

	}
	

}

void HighscoreFunc()
{   
	if ((playcount) == 1) {
		result1 = sclvl1 + sclvl2;

		cout << "Total Score = " << result1 << endl;
		highscore = result1;
		cout << "Highest Score = " << highscore << endl;
		cout << "Do you want to restart the game ? (type y or n) = ";
			cin >> decision;
	}
	else if ((playcount) > 1)
	{
		result1 = sclvl1 + sclvl2;
		cout << "Total Score = " << result1 << endl;
		if (result1 > highscore)
		{
		 highscore = result1;
		}
		cout << "Highest Score = " << highscore << endl;
		cout << "Do you want to restart the game ? (type y or n) = ";
		cin >> decision;
	}
}

void LevelMaker()
{   
	if (Level1Finished == false)
	{
		for (int a = 0; a < mrow; a++)
		{
			for (int b = 0; b < mcolumn; b++)
			{
				cout << Level1[a][b];
			}
			cout << endl;
		}
	}
	else if (Level2Finished == false)
	{ 
		for (int a = 0; a < mrow; a++)
		{
			for (int b = 0; b < mcolumn; b++)
			{
				cout << Level2[a][b];
			}
			cout << endl;
		}
	}
}



void MCarGameplay()
{
	if (Level1Finished == false) {
		while (Level1Finished == false) {

			//For fixing the score writer bug
			if ((score) == 0 || (score) == -50 || (score) == 50 || (score) == 100 || (score) == 150)
			{
				pposition(scorex, scorey);
				cout << "Score = " << "    ";
			}


			pposition(scorex, scorey);
			cout << "Score = " << score;
			pposition(scorex, timery);
			cout << "Time: *" << timer << " seconds*";
			pposition(beflvl1x, beflvl1y);
			cout << ' ';
			pposition(lvl1x, lvl1y);
			cout << Player;
			movementinput = _getch();
			*pplvl1x = *plvl1x;
			*pplvl1y = *plvl1y;

			if (movementinput == 'w') {
				*plvl1y -= 1;
				if (b4active == true)
				{
					Sleep(180);
				}
			}
			else if (movementinput == 's')
			{
				*plvl1y += 1;
				if (b4active == true)
				{
					Sleep(180);
				}
			}
			else if (movementinput == 'a')
			{
				*plvl1x -= 1;
				if (b4active == true)
				{
					Sleep(180);
				}
			}
			else if (movementinput == 'd')
			{
				*plvl1x += 1;
				if (b4active == true)
				{
					Sleep(180);
				}
			}

			if (b3active == false) {
				if (Level1[lvl1y][lvl1x] == W)
				{
					*plvl1x = *pplvl1x;
					*plvl1y = *pplvl1y;
				}
			}
			else if (Level1[lvl1y][lvl1x] == W)
			{
				if (movementinput == 'w' && Level1[lvl1y - 1][lvl1x] != W && lvl1x != 23 && lvl1y != 11 && lvl1x != 0 && lvl1y != 0)
				{
					(*plvl1y) -= 1;
					(score) -= 50;
				}
				else if (movementinput == 's' && Level1[lvl1y + 1][lvl1x] != W && lvl1x != 23 && lvl1y != 11 && lvl1x != 0 && lvl1y != 0)
				{
					(*plvl1y) += 1;
					(score) -= 50;
				}
				else if (movementinput == 'a' && Level1[lvl1y][lvl1x - 1] != W && lvl1x != 23 && lvl1y != 11 && lvl1x != 0 && lvl1y != 0)
				{
					(*plvl1x) -= 1;
					(score) -= 50;
				}
				else if (movementinput == 'd' && Level1[lvl1y][lvl1x + 1] != W && lvl1x != 23 && lvl1y != 11 && lvl1x != 0 && lvl1y != 0)
				{
					(*plvl1x) += 1;
					(score) -= 50;
				}
				else
				{
					*plvl1x = *pplvl1x;
					*plvl1y = *pplvl1y;

				}
			}

			if (Level1[lvl1y][lvl1x] == Bonus1)
			{
				(score) += 100;
				Level1[lvl1y][lvl1x] = 0;
			}

			if (Level1[lvl1y][lvl1x] == Bonus2)
			{
				(score) -= 100;
				Level1[lvl1y][lvl1x] = 0;
			}

			if (Level1[lvl1y][lvl1x] == Bonus3)
			{
				b3active = true;
				pposition(scorex, bon3y);
				cout << "Wallhack activated!";
				Level1[lvl1y][lvl1x] = 0;
				Player = char(189);
			}

			if (Level1[lvl1y][lvl1x] == Bonus4)
			{

				b4active = true;
				pposition(scorex, bon4y);
				cout << "Car speed decreased!";
				(score) += 100;
				Level1[lvl1y][lvl1x] = 0;
				Player = char(254);

			}

			if (b3active == true && b4active == true)
			{
				Player = char(1);
			}

			if (Level1[lvl1y][lvl1x] == 'F')
			{

				Level1Finished = true;

			}
		}
	}
 else if (Level2Finished == false)
 {
	 while (Level2Finished == false) {

		 //For fixing the score writer bug
		 if ((score) == 0 || (score) == -50 || (score) == 50 || (score) == 100 || (score) == 150)
		 {
			 pposition(scorex, scorey);
			 cout << "Score = " << "    ";
		 }

		 pposition(scorex, scorey);
		 cout << "Score = " << score;
		 pposition(scorex, timery);
		 cout << "Time: *" << timer << " seconds*";
		 pposition(beflvl2x, beflvl2y);
		 cout << ' ';
		 pposition(lvl2x, lvl2y);
		 cout << Player;
		 movementinput = _getch();
		 *pplvl2x = *plvl2x;
		 *pplvl2y = *plvl2y;

		 if (movementinput == 'w') {
			 *plvl2y -= 1;
			 if (b4active == true)
			 {
				 Sleep(180);
			 }
		 }
		 else if (movementinput == 's')
		 {
			 *plvl2y += 1;
			 if (b4active == true)
			 {
				 Sleep(180);
			 }
		 }
		 else if (movementinput == 'a')
		 {
			 *plvl2x -= 1;
			 if (b4active == true)
			 {
				 Sleep(180);
			 }
		 }
		 else if (movementinput == 'd')
		 {
			 *plvl2x += 1;
			 if (b4active == true)
			 {
				 Sleep(180);
			 }
		 }

		 if (b3active == false) {
			 if (Level2[lvl2y][lvl2x] == W)
			 {
				 *plvl2x = *pplvl2x;
				 *plvl2y = *pplvl2y;
			 }
		 }
		 else if (Level2[lvl2y][lvl2x] == W)
		 {
			 if (movementinput == 'w' && Level2[lvl2y - 1][lvl2x] != W && lvl2x != 23 && lvl2y != 11)
			 {
				 (*plvl2y) -= 1;
				 (score) -= 50;
			 }
			 else if (movementinput == 's' && Level2[lvl2y + 1][lvl2x] != W && lvl2x != 23 && lvl2y != 11)
			 {
				 (*plvl2y) += 1;
				 (score) -= 50;
			 }
			 else if (movementinput == 'a' && Level2[lvl2y][lvl2x - 1] != W && lvl2x != 23 && lvl2y != 11)
			 {
				 (*plvl2x) -= 1;
				 (score) -= 50;
			 }
			 else if (movementinput == 'd' && Level2[lvl2y][lvl2x + 1] != W && lvl2x != 23 && lvl2y != 11)
			 {
				 (*plvl2x) += 1;
				 (score) -= 50;
			 }
			 else
			 {
				 *plvl2x = *pplvl2x;
				 *plvl2y = *pplvl2y;

			 }
		 }

		 if (Level2[lvl2y][lvl2x] == Bonus1)
		 {
			 (score) += 100;
			 Level2[lvl2y][lvl2x] = 0;
		 }
		 if (Level2[lvl2y][lvl2x] == Bonus2)
		 {
			 (score) -= 100;
			 Level2[lvl2y][lvl2x] = 0;
		 }

		 if (Level2[lvl2y][lvl2x] == Bonus3)
		 {
			 b3active = true;
			 pposition(scorex, bon3y);
			 cout << "Wallhack activated!";
			 Level2[lvl2y][lvl2x] = 0;
			 Player = char(189);

		 }

		 if (Level2[lvl2y][lvl2x] == Bonus4)
		 {
			 b4active = true;
			 pposition(scorex, bon4y);
			 cout << "Car speed decreased!";
			 (score) += 100;
			 Level2[lvl2y][lvl2x] = 0;
			 Player = char(254);
		 }

		 if (b3active == true && b4active == true)
		 {
			 Player = char(1);
		 }

		 if (Level2[lvl2y][lvl2x] == 'F')
		 {

			 Level2Finished = true;

		 }
	 }
	}
}

void ACarGameplay()
{
	srand(time(NULL));
	if (Level1Finished == false) {
		while (Level1Finished == false) {
			
			//For fixing the score writer bug
			if ((score) == 0 || (score) == -50 || (score) == 50 || (score) == 100 || (score) == 150)
			{
				pposition(scorex, scorey);
				cout << "Score = " << "    ";
			}

			pposition(scorex, scorey);
			cout << "Score = " << score;
			pposition(scorex, timery);
			cout << "Time: *" << timer << " seconds*";
			pposition(beflvl1x, beflvl1y);
			cout << ' ';
			pposition(lvl1x, lvl1y);
			cout << Player;
			*pplvl1x = *plvl1x;
			*pplvl1y = *plvl1y;	

			autoinput = (rand() % 4) + 1;

			if (autoinput == 1) {
				
					*plvl1y -= 1;
					Sleep(5);

				if (b4active == true)
				{
					Sleep(20);
				}
			}
			else if (autoinput == 2)
			{
					*plvl1y += 1;
					Sleep(5);
		
				if (b4active == true)
				{
					Sleep(20);
				}
			}
			else if (autoinput == 3)
			{
					*plvl1x -= 1;
					Sleep(5);

				if (b4active == true)
				{
					Sleep(20);
				}
			}
			else if (autoinput == 4)
			{   
					*plvl1x += 1;
					Sleep(5);
			
				if (b4active == true)
				{
					Sleep(20);
				}
			}

			if (b3active == false) {
				if (Level1[lvl1y][lvl1x] == W)
				{
					*plvl1x = *pplvl1x;
					*plvl1y = *pplvl1y;
				}
			}
			else if (Level1[lvl1y][lvl1x] == W)
			{
				if (autoinput == 1 && Level1[lvl1y - 1][lvl1x] != W && lvl1x != 23 && lvl1y != 11 && lvl1x != 0 && lvl1y != 0)
				{
					(*plvl1y) -= 1;
					(score) -= 50;
				}
				else if (autoinput == 2 && Level1[lvl1y + 1][lvl1x] != W && lvl1x != 23 && lvl1y != 11 && lvl1x != 0 && lvl1y != 0)
				{
					(*plvl1y) += 1;
					(score) -= 50;
				}
				else if (autoinput == 3 && Level1[lvl1y][lvl1x - 1] != W && lvl1x != 23 && lvl1y != 11 && lvl1x != 0 && lvl1y != 0)
				{
					(*plvl1x) -= 1;
					(score) -= 50;
				}
				else if (autoinput == 4 && Level1[lvl1y][lvl1x + 1] != W && lvl1x != 23 && lvl1y != 11 && lvl1x != 0 && lvl1y != 0)
				{
					(*plvl1x) += 1;
					(score) -= 50;
				}
				else
				{
					*plvl1x = *pplvl1x;
					*plvl1y = *pplvl1y;

				}
			}

			if (Level1[lvl1y][lvl1x] == Bonus1)
			{
				(score) += 100;
				Level1[lvl1y][lvl1x] = 0;
			}

			if (Level1[lvl1y][lvl1x] == Bonus2)
			{
				(score) -= 100;
				Level1[lvl1y][lvl1x] = 0;
			}

			if (Level1[lvl1y][lvl1x] == Bonus3)
			{
				b3active = true;
				pposition(scorex, bon3y);
				cout << "Wallhack activated!";
				Level1[lvl1y][lvl1x] = 0;
				Player = char(189);
			}

			if (Level1[lvl1y][lvl1x] == Bonus4)
			{

				b4active = true;
				pposition(scorex, bon4y);
				cout << "Car speed decreased!";
				(score) += 100;
				Level1[lvl1y][lvl1x] = 0;
				Player = char(254);

			}

			if (b3active == true && b4active == true)
			{
				Player = char(1);
			}

			if (Level1[lvl1y][lvl1x] == 'F')
			{

				Level1Finished = true;

			}
		}
	}
	else if (Level2Finished == false)
	{
		while (Level2Finished == false) {

			//For fixing the score writer bug
			if ((score) == 0 || (score) == -50 || (score) == 50 || (score) == 100 || (score) == 150)
			{
				pposition(scorex, scorey);
				cout << "Score = " << "    ";
			}

			pposition(scorex, scorey);
			cout << "Score = " << score;
			pposition(scorex, timery);
			cout << "Time: *" << timer << " seconds*";
			pposition(beflvl2x, beflvl2y);
			cout << ' ';
			pposition(lvl2x, lvl2y);
			cout << Player;
			*pplvl2x = *plvl2x;
			*pplvl2y = *plvl2y;
			autoinput = (rand() % 4) + 1;

			if (autoinput == 1) {
				*plvl2y -= 1;
				Sleep(5);
				if (b4active == true)
				{
					Sleep(20);
				}
			}
			else if (autoinput == 2)
			{
				*plvl2y += 1;
				Sleep(5);
				if (b4active == true)
				{
					Sleep(20);
				}
			}
			else if (autoinput == 3)
			{
				*plvl2x -= 1;
				Sleep(5);
				if (b4active == true)
				{
					Sleep(20);
				}
			}
			else if (autoinput == 4)
			{
				*plvl2x += 1;
				Sleep(5);
				if (b4active == true)
				{
					Sleep(20);
				}
			}

			if (b3active == false) {
				if (Level2[lvl2y][lvl2x] == W)
				{
					*plvl2x = *pplvl2x;
					*plvl2y = *pplvl2y;
				}
			}
			else if (Level2[lvl2y][lvl2x] == W)
			{
				if (autoinput == 1 && Level2[lvl2y - 1][lvl2x] != W && lvl2x != 23 && lvl2y != 11)
				{
					(*plvl2y) -= 1;
					(score) -= 50;
				}
				else if (autoinput == 2 && Level2[lvl2y + 1][lvl2x] != W && lvl2x != 23 && lvl2y != 11)
				{
					(*plvl2y) += 1;
					(score) -= 50;
				}
				else if (autoinput == 3 && Level2[lvl2y][lvl2x - 1] != W && lvl2x != 23 && lvl2y != 11)
				{
					(*plvl2x) -= 1;
					(score) -= 50;
				}
				else if (autoinput == 4 && Level2[lvl2y][lvl2x + 1] != W && lvl2x != 23 && lvl2y != 11)
				{
					(*plvl2x) += 1;
					(score) -= 50;
				}
				else
				{
					*plvl2x = *pplvl2x;
					*plvl2y = *pplvl2y;

				}
			}

			if (Level2[lvl2y][lvl2x] == Bonus1)
			{
				(score) += 100;
				Level2[lvl2y][lvl2x] = 0;
			}
			if (Level2[lvl2y][lvl2x] == Bonus2)
			{
				(score) -= 100;
				Level2[lvl2y][lvl2x] = 0;
			}

			if (Level2[lvl2y][lvl2x] == Bonus3)
			{
				b3active = true;
				pposition(scorex, bon3y);
				cout << "Wallhack activated!";
				Level2[lvl2y][lvl2x] = 0;
				Player = char(189);

			}

			if (Level2[lvl2y][lvl2x] == Bonus4)
			{
				b4active = true;
				pposition(scorex, bon4y);
				cout << "Car speed decreased!";
				(score) += 100;
				Level2[lvl2y][lvl2x] = 0;
				Player = char(254);
			}

			if (b3active == true && b4active == true)
			{
				Player = char(1);
			}

			if (Level2[lvl2y][lvl2x] == 'F')
			{

				Level2Finished = true;

			}
		}
	}
}


int main() {
	

	do {
		Level1Finished = false;
		Level2Finished = false;
		restart = false;
		sclvl1 = 0;
		sclvl2 = 0;
		lvl1count = 0;
		lvl2count = 0;
		*plvl1x = 1;
		*plvl1y = 1;
		*pplvl1x = 1;
		*pplvl1y = 1;
		*plvl2x = 1;
		*plvl2y = 1;
		*pplvl2x = 1;
		*pplvl2y = 1;

		cout << "Welcome to Maze of Infinity!" << endl << endl;
		cout << "There are 2 different controller options for this game."<< endl;
		cout << "Please select your option." << endl;
		cout << "1-Player   2-CPU" << endl;
		cout << "Option : ";
		cin >> option;
		system("CLS");

		Player = 155;
		BonusSpawner();
		LevelMaker();
		double timer1 = clock();
		
			if (option == 1) {
				MCarGameplay();
			}
			else if (option == 2)
			{
				ACarGameplay();
			}
		

		b3active = false;
		b4active = false;

		if (Level1Finished == true)
			{
			if ((clock() - timer1) / 1000 >= timer){
			
				pposition(scorex, resulty);
				cout << "Game Over!" << endl;
				pposition(scorex, timery);
				cout << "Time elapsed = " << ((clock() - timer1)) / 1000;
				sclvl1 = 0;
				score = 0;
				pposition(scorex, lvlendy);
				system("pause");
				system("CLS");
				HighscoreFunc();
				playcount++;
			}
			else {
				pposition(scorex, resulty);
				cout << "Level 1 Completed!" << endl;
				pposition(scorex, timery);
				cout << "Time elapsed = " << ((clock() - timer1)) / 1000;
				sclvl1 = score;
				score = 0;
				pposition(scorex, lvlendy);
				system("pause");
				system("CLS");

				Player = 155;
		        BonusSpawner();
				LevelMaker();
				double timer2 = clock();
			
					if (option == 1) {
						MCarGameplay();
					}
					else if (option == 2)
					{
						ACarGameplay();
					}
				

				b3active = false;
				b4active = false;

				if (Level2Finished == true)
				{
					if ((clock() - timer2) / 1000 >= timer) {

						pposition(scorex, resulty);
						cout << "Game Over!" << endl;
						pposition(scorex, timery);
						cout << "Time elapsed = " << ((clock() - timer2)) / 1000;
						sclvl2 = 0;
						score = 0;

					}
					else {

						pposition(scorex, resulty);
						cout << "Level 2 Completed" << endl;
						pposition(scorex, timery);
						cout << "Time elapsed = " << ((clock() - timer2)) / 1000;
						sclvl2 = score;
						score = 0;

					}
				}

				pposition(scorex, lvlendy);
				system("pause");
				system("CLS");
				HighscoreFunc();
				playcount++;

			}
	  }
		
		if (decision == 'y')
		{
			restart = true;
		}
		system("CLS");
		
	} while (restart == true);
	return 0;
}


