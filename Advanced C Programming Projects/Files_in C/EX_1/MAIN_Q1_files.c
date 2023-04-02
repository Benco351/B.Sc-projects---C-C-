#include "Header.h"


int main(int argc, char* argv[]) 
{
	if (argc < 3)
	{
		perror("you forgot 1 variable");
		exit(EXIT_FAILURE);
	}
	int x = atoi(argv[2]);
	char* token = strtok(argv[1], ".");
	token = strtok(NULL, ".");
	if (strcmp(token, "bin") == 0)
	{
		strcat(argv[1], ".bin");
		build(argv[1], x);
	}
	else
	{
		printf("Worng file , only bin file!");
		exit(EXIT_FAILURE);
	}
}