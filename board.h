#ifndef BOARD_H
#define BOARD_H

class Board{
	private:
		int slots[3][3];
		//index is [x][y]
		//diagram:
		//  00 | 10 | 20  :  1 | 2 | 3
 		//  01 | 11 | 21  :  4 | 5 | 6
		//  02 | 12 | 22  :  7 | 8 | 9
		//0 indicates empty element
		//1 indicates circle
		//-1 indicates cross
	public:
		Board();
		void setelement(int x, int y, bool iscircle);
		//doesn't check whether spot is empty before setting
		int getelement(int x, int y);
		bool ispopulated(int x, int y);
		//true = that spot is populated
		//false = that spot is empty
		int checkresults();
		//if 0, game still happening
		//if 1, circle wins
		//if 2, cross wins
		//if 3, tie
		void clearboard();
		//unconditionally clears board
		void inputtosector(float &x, float &y);
		
		bool ended;
		bool over;
		bool started;
		bool issingleplayer;
		bool circleturn;
		//first turn is always circle
};

#endif