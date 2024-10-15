
// board definition, start to finish...
//
// '*' is for special cards, 'E' = entrance, 'X' = exit,
// 'a' through 'k' mark the 'event' spaces defined below

char *board = "S.....*..a...b....*.c..*....*......d....*..e..fE..............g...h.X..i....*.......j...*.....*....*....k...*.....*....F";

char *board_events[] = {
	"Red Sea Experience",
	"Murmuring and Complaining",
	"Idol Worship",
	"Lack of Faith",
	"Miriam Dies",
	"For Complaining",
	"Encompassed Mount Seir Long Enough",
	"_for no apparent reason_",
	"Aaron Dies",
	"Poisonous Serpents",
	"Moses Dies"
};

char *board_event_impacts[] = {
	"Return 3",
	"Lose 1 turn",
	"Return 6",
	"Lose 1 turn",
	"Return 3",
	"Go Around Mount Seir",
	"Advance to Exit",
	"Go Around Mount Seir Again",
	"Return 3",
	"Lose One Turn",
	"Return 3"
};

