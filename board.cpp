#include "board.h"
#include <iostream>
using namespace std;

Board::Board(){
	//initializing empty board
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			slots[i][j] = 0;
		}
	}
	ended = false;
	started = false;
	over = false;
}

void Board::setelement(int x, int y, bool iscircle){
	if(iscircle){
		slots[x][y] = 1;
		circleturn = false;
	} else {
		slots[x][y] = -1;
		circleturn = true;
	}
}

int Board::getelement(int x, int y){
	return slots[x][y];
}

bool Board::ispopulated(int x, int y){
	//cout << "checking if populated...\n";
	if(slots[x][y] == 1 || slots[x][y] == -1){
		return true;
	} else {
		return false;
	}
}


int Board::checkresults(){
	//first, check if anyone has won
	//1-3 horizontal
	//4-6 vertical
	//7-8 diagonal
	if (slots[0][0] != 0 && slots[0][0] == slots[1][0] && slots[1][0] == slots[2][0]){
		if (slots[0][0] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	if (slots[0][1] != 0 && slots[0][1] == slots[1][1] && slots[1][1] == slots[2][1]){
		if (slots[0][1] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	if (slots[0][2] != 0 && slots[0][2] == slots[1][2] && slots[1][2] == slots[2][2]){
		if (slots[0][2] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	} 
	
	
	if (slots[0][0] != 0 && slots[0][0] == slots[0][1] && slots[0][1] == slots[0][2]){
		if (slots[0][0] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	if (slots[1][0] != 0 && slots[1][0] == slots[1][1] && slots[1][1] == slots[1][2]){
		if (slots[1][0] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	if (slots[2][0] != 0 && slots[2][0] == slots[2][1] && slots[2][1] == slots[2][2]){
		if (slots[2][0] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	
	
	if (slots[0][0] != 0 && slots[0][0] == slots[1][1] && slots[1][1] == slots[2][2]){
		if (slots[0][0] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	if (slots[2][0] != 0 && slots[2][0] == slots[1][1] && slots[1][1] == slots[0][2]){
		if (slots[2][0] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	
	//check if entire board is populated
	bool boardfull = true;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(slots[i][j] == 0){ //if theres an empty spot
				boardfull = false;  //then throw not full flag
				//cout << "board is not full\n";
			}
		}
	}
	
	if (boardfull){
		//cout << "board is full\n";
		return 3; //report tie
	}
	return 0; //report game still happening
}

void Board::clearboard(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			slots[i][j] = 0;
		}
	}
	ended = false;
	over = false;
	started = false;
	issingleplayer = false;
	circleturn = false;
}

void Board::inputtosector(float &x, float &y){
	if(x > -1 && x < -0.333){
		x = 0;
	} else if(x > -0.333 && x < 0.333){
		x = 1;
	} else if(x > 0.333 && x < 1){
		x = 2;
	}
	if(y < 1 && y > 0.333){
		y = 0;
	} else if(y < 0.333 && y > -0.333){
		y = 1;
	} else if(y < -0.333 && y > -1){
		y = 2;
	}
}











