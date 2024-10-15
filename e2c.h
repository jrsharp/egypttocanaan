typedef struct {
	int	d;
	int	x;
	int	y;
} Click;

typedef struct QuestionCard {
	char number[4];
    char question[128];
	char value[64];
	char answer[128];
	char reference[64];
} QuestionCard;

typedef struct SpecialCard {
	char number[4];
	char event[128];
	char impact[64];
} SpecialCard;

typedef struct Player {
	char name[32];
	int color;
	int location;
} Player;
	

Image *img;

Image *background;
Image *textcol;

void load_questions(void);
void load_specials(void);