#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int c, n=1;

	do {
		if (argc < 2)
			fp = stdin;
		else
			fp = fopen(argv[n++], "r");
		c = getc(fp);
		while(c != EOF) {
			putc(c, stdout);
			c = getc(fp);
		}
		fclose(fp);
	} while (n < argc);
	return 0;
}
