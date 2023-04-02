#include "Header.h"


int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		perror("2 bin files required!");
		exit(EXIT_FAILURE);
	}
	else
	{
		build(argv[1], argv[2]);
	}
}