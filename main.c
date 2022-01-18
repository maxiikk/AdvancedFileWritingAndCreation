#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int *k;
	int i =0;
	int g;
	FILE *p1;
	char ans[100];
	char openorcreate[100];
	printf("Do you want to create or open an existing file to write to it? Use create/open as an asnwer \n");
	gets(openorcreate);
	while (strcmp(tolower(openorcreate),"open") != 0 && strcmp(tolower(openorcreate),"create") != 0){
		printf("Only create/open is accepted! \n");
		scanf(" %s", ans);
	}
	if (strcmp(tolower(openorcreate),"open") == 0){
		printf("Which file to open? Type the name with the extension of the file!\n");
		scanf(" %99s", ans);
		p1 = fopen (ans, "r+");
		if (p1 == NULL){
			while (p1 == NULL){
				printf("Cant open the file, try again! Type the name with the extension of the file!\n");
				scanf(" %99s", ans);
			}
		}
	}
	else if (strcmp(tolower(openorcreate),"create") == 0){
		printf("How will you name the file?\n");
		scanf(" %95s", ans);
		while (1){
			if (ans[i] == '\0'){
				break;
			}
			i++;
		}
		strcat(ans, ".txt");
		p1 = fopen(ans, "w+");
		if (p1 == NULL){
			printf("Cannot create the file!\n");
			return 1;
		}
	}
	printf("Great, now, what do you want to write to it? Give me a string with a maximum of 99 letters length\n");
	scanf(" %[^\n]", ans);
	char ans2[6];
	if (strcmp(tolower(openorcreate),"open") == 0){
		printf("Write it to the end of the file or at the start? Use end/start as an answer\n");
		scanf(" %5s", ans2);
		while (strcmp(tolower(ans2),"end") != 0 && strcmp(tolower(ans2),"start") != 0){
			printf("Use end/start as an answer\n");
			scanf(" %5s", ans2);
		}
		if (strcmp(tolower(ans2),"end") == 0){
			fseek(p1, 0, SEEK_END);
		}
		else if (strcmp(tolower(ans2),"start") == 0){
			fseek(p1, 0, SEEK_SET);
		}
	}
	
	printf("Writing <%s> to the file\n", ans);
	fputs(ans, p1);
	
	
	fclose(p1);
	return 0;
}