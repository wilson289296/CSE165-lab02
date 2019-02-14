#include "board.h"

Board::Board(){
	//initializing empty board
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			slots[i][j] = 0;
		}
	}
}

void Board::setelement(int x, int y, bool iscircle){
	if(iscircle){
		slots[x - 1][y - 1] = 1;
	} else {
		slots[x - 1][y - 1] = -1;
	}
}

bool Board::ispopulated(int x, int y){
	if(slots[x - 1][y - 1] == 1 || slots[x - 1][y - 1] == -1){
		return true;
	} else {
		return false;
	}
}


int Board::checkresults(){
	//first, check if anyone has won
	//horizontal win cases
	if (slots[0][0] == slots[1][0] && slots[1][0] == slots[2][0]){
		if (slots[0][0] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	if (slots[0][1] == slots[1][1] && slots[1][1] == slots[2][1]){
		if (slots[0][1] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	if (slots[0][2] == slots[1][2] && slots[1][2] == slots[2][2]){
		if (slots[0][2] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	
	//vertical win cases
	if (slots[0][0] == slots[0][1] && slots[0][1] == slots[0][2]){
		if (slots[0][0] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	if (slots[1][0] == slots[1][1] && slots[1][1] == slots[1][2]){
		if (slots[1][0] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	if (slots[2][0] == slots[2][1] && slots[2][1] == slots[2][2]){
		if (slots[2][0] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	
	//diagonal win cases
	if (slots[0][0] == slots[1][1] && slots[1][1] == slots[2][2]){
		if (slots[0][0] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	if (slots[2][0] == slots[1][1] && slots[1][1] == slots[0][2]){
		if (slots[2][0] == 1){
			return 1; //circle wins
		} else {
			return 2; //cross wins
		}
	}
	
	//check if entire board is populated
	bool boardfull = true;
	for(int i = 1; i < 4; i++){
		for(int j = 1; j < 4; j++){
			if(!ispopulated(i, j)){ //if theres an empty spot
				boardfull = false;  //then throw not full flag
			}
		}
	}
	if (boardfull){
		return 3; //report tie
	} else {
		return 0; //report game still happening
	}
}

void Board::clearboard(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			slots[i][j] = 0;
		}
	}
}