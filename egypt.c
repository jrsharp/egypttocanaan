#include <u.h>
#include <libc.h>
#include <draw.h>
#include <event.h>
#include <stdio.h>
#include "e2c.h"

#define FBSZ 12000

char fb[FBSZ];
QuestionCard q_cards[100];
SpecialCard s_cards[25];
Player players[6];

// board definition, start to finish...
//
// '*' is for special cards, 'E' = entrance, 'X' = exit,
// 'a' through 'k' mark the 'event' spaces defined below

static char *board = "S.....*..a...b....*.c..*....*......d....*..e..fE..............g...h.X..i....*.......j...*.....*....*....k...*.....*....F";

void
load_questions() {
	print("loading questions...\n");
	int fd = open("question_cards.db", OREAD);
	long br = read(fd, fb, FBSZ);
	long si = 0;
	long bi = 0;
	short qi = 0;
	short findex = 0;
	short field = 0;
	while (bi < br) {
		if (fb[bi] == '\n') { // eol
			findex = si;
			while (findex < bi) {
				if (fb[findex] == ';' || (findex + 1 == bi)) { // field delim
					if (field == 0) {
						strncpy(q_cards[qi].number, fb+si, (findex - si));
					} else if (field == 1) {
						strncpy(q_cards[qi].question, fb+si, (findex - si));
					} else if (field == 2) {
						strncpy(q_cards[qi].value, fb+si, (findex - si));
					} else if (field == 3) {
						strncpy(q_cards[qi].answer, fb+si, (findex - si));
					} else if (field == 4) {
						strncpy(q_cards[qi].reference, fb+si, (findex + 1 - si));
					}
					si = findex + 1;
					field++;
				}
				findex++;
			}
			si = bi + 1;
			field = 0;
			qi++;
		}
		bi++;
	}
}

void
load_specials() {
	print("loading specials...\n");
	int fd = open("special_cards.db", OREAD);
	long br = read(fd, fb, FBSZ);
	long si = 0;
	long bi = 0;
	short qi = 0;
	short findex = 0;
	short field = 0;
	while (bi < br) {
		if (fb[bi] == '\n') { // eol
			findex = si;
			while (findex < bi) {
				if (fb[findex] == ';' || (findex + 1 == bi)) { // field delim
					if (field == 0) {
						strncpy(s_cards[qi].number, fb+si, (findex - si));
					} else if (field == 1) {
						strncpy(s_cards[qi].event, fb+si, (findex - si));
					} else if (field == 2) {
						strncpy(s_cards[qi].impact, fb+si, (findex + 1 - si));
					}
					si = findex + 1;
					field++;
				}
				findex++;
			}
			si = bi + 1;
			field = 0;
			qi++;
		}
		bi++;
	}
}

void print_question(QuestionCard *qc) {
	print("\nQ# %s: %s (%s)\n", qc->number, qc->question, qc->value);
}

void print_special(SpecialCard *sc) {
	print("\nE# %s: %s (%s)\n\n", sc->number, sc->event, sc->impact);
}

void print_board() {
	char bout[sizeof(board)] = {0};
	print(bout);
}


void
main(int argc, char **argv)
{
	int not_quit = 1;
	char inbuf[128];

	// seed:
	srand(time(0));

	// Load questions:
	load_questions();
	// Load specials:
	load_specials();

	//print_question(&q_cards[nrand(100)]);
	//print_special(&s_cards[nrand(25)]);

	if(initdraw(nil, nil, "Egypt To Canaan") < 0)
		sysfatal("initdraw failed: %r");

	int i = 0;
	while(not_quit) {
		QuestionCard *qc = &q_cards[nrand(100)];
		print("\nQ# %s: %s (%s)\n", qc->number, qc->question, qc->value);
		long br = read(0, inbuf, 64);
		inbuf[br] = 0; // n.t.
		print("Your answer: %s\n", inbuf);
		print("Correct answer: %s\n", qc->answer);
	}

	print("Welcome to Canaan.\n");
}
