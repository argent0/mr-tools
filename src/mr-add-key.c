#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char *line = NULL;
	size_t length = 0;
	char *key = NULL;

	if(argc > 1) {
		key = argv[1];
	} else {
		key = malloc(sizeof(char)*2);
		key[0]='1';
		key[1]='\0';
	}

	while( (length = getline(&line, &length, stdin)) != -1 ) {
		line[length-1] = 0;
		fprintf(stdout, "%s\t%s\n", key,line);
	}

	free(line);

	return 0;
}
