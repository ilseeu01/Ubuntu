#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	
	FILE *fp;
	int c;
	int chars = 0, lines = 0, words = 0;
	int inword = 0;

	if (argc < 2)
		fp = stdin;
	else
		fp = fopen(argv[1], "r");
	
	while((c = getc(fp)) != EOF) {
		chars++;
		if (c == '\n')
			lines++;
		if (isspace(c))
			inword = 0;
		else if (inword == 0) {
			inword = 1;
			words++;
		}
		
	}
	printf("Lines, Words, Characters\n");
	printf(" %3d %3d %3d\n", lines, words, chars);
	return 0;
}
