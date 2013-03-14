#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100

int main(int argc, char **argv) {
	char *line = NULL;
	size_t length = 0;
	char *value = NULL;
	char *key = NULL;
	char *prevkey;
	int accumulator = 0;

	prevkey = malloc(sizeof(char)*MAX_KEY_LENGTH);
	bzero(prevkey, MAX_KEY_LENGTH);

	if (prevkey == NULL) {
		fprintf(stderr, "Out of memory.\n");
		return EXIT_FAILURE;
	}

	while( (length = getline(&line, &length, stdin)) != -1 ) {
		//Separate key from value
		key = strtok(line, "\t");
		length = strlen(key);

		if (length > MAX_KEY_LENGTH) {
			free(line);
			fprintf(stderr,"Key is too long");
			return EXIT_FAILURE;
		}

		if ((strcmp(key, prevkey) != 0) && (strlen(prevkey)>0)) {
			fprintf(stdout, "%s\t%d\n", prevkey,accumulator);
			accumulator = 0;
		}

		value = line+strlen(key)+1;
		
		accumulator += atoi(value);
		prevkey = strncpy( prevkey, key, MAX_KEY_LENGTH);
	}
			
	fprintf(stdout, "%s\t%d\n", prevkey,accumulator);

	free(line);

	return 0;
}
