#include <stdio.h>

const char colors[] = "Brgybmcw";

int main(int argc, char *argv[]){
	char text[4096];
	char c;
	int i;
	for(i = 0; ((c = getchar()) != EOF) && i < 4095; i++){
		text[i] = c;
	}
	
	text[i] = '\0';

	unsigned char colorText = 0;
	if(argc == 2){
		char colorer[6];
		colorer[0] = '\033';
		colorer[1] = '[';
		colorer[2] = '3';
		int i;
		for(i = 0 ; i < 8; i++){
			if(colors[i] == argv[1][0]){
				colorer[3] = '0' + i;
				colorText = 1;
			}
		}
		colorer[4] = 'm';
		colorer[5] = '\0';
		if(colorText){
			puts(colorer);
		}
	}
	puts(text);
	puts("\033[0m\n");
	
	return 0;
}
