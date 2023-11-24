#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	int id;
	char name[20];
	char color[20];
	double amount[9]; 			// rent lot but empty, 1, 2, 3, 4, hotel, mortgage, house cost, hotel cost (house cost * 5) 
	int houseCount;				// will be used only if players owns already the property
	int hotelCount;				// will be used only if players owns already the property
	int mortgage;				// will be used only if players owns already the property and value is 1 - under mortgage, 0 - not in mortgage 
} TitleDeed;

typedef struct {
	char cardType[20];
	char cardDescription[100];
} Card, Cards[16];

// Used to store Title Deeds in a linkled list 
typedef struct prop {
	TitleDeed lot;
	struct prop *next;
} Prop, *PropLList, *SortedPropLList;

// Used to store Title Deeds in an array list 
typedef struct {
	TitleDeed *lot;
	int count;
	int max;
} PropAList, SortedPropAList;

//
typedef struct {
	int id;
	SortedPropLList owned;		// initially empty but insertSorted when adding ownership to a title deed based on id
	int moneyCount[7];			// 2pcs-$500, 2pcs-$100, 2pcs-$50, 6pcs-$20, 5pcs-$10, 5pcs-$5, 5pcs-$1
	double totalMoney;			// $1500
	int position;				// current position in board starts at 0
} Player;

typedef struct {
	PropLList ownedBank;		// the collection of title deeds not yet owned by a player
	int boardLot[40];			// compromises the lot area
	int moneyCount[7];			// 30pcs-$500, 30pcs-$100, 30pcs-$50, 30pcs-$20, 30pcs-$10, 30pcs-$5, 30pcs-$1
	double totalMoney;			// $20580
	Player players[8];			// players of the game
	int playerCount;			// current count of players
	int houseCount;				// 32 houses
	int hotelCount;				// 12 hotels
	Cards chance;				// chance cards
	int currChanceTop;			// initially starts at 0 then moves once the player lands a chance lot
	Cards communityChest;		// commmunity chest cards
	int currCommunityChestTop;	// initially starts at 0 then moves once the player lands a community chest lot
	int dice[2];				// will contain the dice values (0 for the dice 1 and 1 for dice 2)
} GameBoard;

//	> 0 special(-1 community chest, -2 chance, -3 free parking, -4 income tax, -5 jail, -6 electric company, -7 water works, -8 road 1, -9 road 2, -10 road 3, -11 road 4, -12)
//  0 owned by bank, id of the player if lot is owned by a player
//  initial value of board lot 0, *0, -1, *0, -4, -8, !0, -2, !0, !0, -5, *0, -6, *0, *0, -9, !0, -1, !0, !0, -3, *0, -2, *0, *0, -10, !0, !0, -7, !0, -12, *0, *0, -1, *0, -11, -2, !0, -4, !0

// must implement
void initGameBoard(GameBoard *board);
bool addPlayer(GameBoard *board, int player_id);

// place the other function prototypes needed

int main(int argc, char *argv[]) {
	
	GameBoard* board;
	
	int i;
	
	for(i = 0 ; i < 3; i++){
		addPlayer(board, i);
	}
	
	return 0;
}

void initGameBoard(GameBoard *board){
	
	FILE *fp = fopen("titledeed.cis", "r");
	PropLList ownedbybank;
	
	while(ownedbybank != NULL){
		fread(ownedbybank, sizeof(Prop), 1, fp);
		board->ownedBank->lot.hotelCount = 0;
		board->ownedBank->lot.houseCount = 0;
		board->ownedBank->lot.mortgage = 0;
		ownedbybank = ownedbybank->next;	
	}
	board->moneyCount[0] = 500;
	board->moneyCount[1] = 100;
	board->moneyCount[2] = 50;
	board->moneyCount[3] = 20;
	board->moneyCount[4] = 10;
	board->moneyCount[5] = 5;
	board->moneyCount[6] = 1;
	board->totalMoney = 20580;
	board->playerCount = 0;
	board->houseCount = 0;
	
}

bool addPlayer(GameBoard *board, int player_id){
	
	int count = board->playerCount;
	
	board->players[count].id = player_id;
	
	board->players[count].moneyCount[0] = 500;
	board->players[count].moneyCount[1] = 100;
	board->players[count].moneyCount[2] = 50;
	board->players[count].moneyCount[3] = 20;
	board->players[count].moneyCount[4] = 10;
	board->players[count].moneyCount[5] = 5;
	board->players[count].moneyCount[6] = 1;
	board->players[count].totalMoney = 1500.00;
	board->players[count].position = 0;
	
	board->playerCount++;
	
	return true;
}

