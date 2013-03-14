#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char *line = NULL;
	size_t length = 0;
	char *value = NULL;

	if(argc > 1) {
		value = argv[1];
	} else {
		value = malloc(sizeof(char)*2);
		value[0]='1';
		value[1]='\0';
	}

	while( (length = getline(&line, &length, stdin)) != -1 ) {
		line[length-1] = 0;
		fprintf(stdout, "%s\t%s\n", line,value);
	}

	free(line);

	return 0;
}
