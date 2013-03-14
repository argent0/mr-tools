#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000

int main(int argc, char **argv) {
	char *line = NULL;
	size_t length = 0;
	char *value = NULL;
	char *key = NULL;
	char *prevkey;
	char *accumulator = NULL;
	size_t acclen = MAX_VALUE_LENGTH;
	char *separator=",";
	int flag=0;

	prevkey = malloc(sizeof(char)*MAX_KEY_LENGTH);
	if (prevkey == NULL) {
		fprintf(stderr, "Out of memory.\n");
		return EXIT_FAILURE;
	}
	bzero(prevkey, MAX_KEY_LENGTH);

	accumulator = malloc(sizeof(char)*MAX_VALUE_LENGTH);

	if (accumulator == NULL) {
		fprintf(stderr, "Out of memory.\n");
		return EXIT_FAILURE;
	}
	bzero(accumulator, MAX_VALUE_LENGTH);

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
			fprintf(stdout, "%s\t%s\n", prevkey,accumulator);
			bzero(accumulator, acclen);
			flag=0;
		}

		value = line+strlen(key)+1;
		
		if ( strlen(value)+strlen(accumulator) > acclen-2) {
			acclen += acclen + strlen(value);
			accumulator = realloc(accumulator, acclen*sizeof(char));
			if (accumulator == NULL) {
				free(line);
				fprintf(stderr,"Out of memory");
				return EXIT_FAILURE;
			}
		}

		if(flag!=0) {
			accumulator = strcat(accumulator, separator);
		}

		flag=1;

		accumulator = strncat(accumulator, value, strlen(value)-1);
		prevkey = strncpy( prevkey, key, MAX_KEY_LENGTH);
	}
			
	fprintf(stdout, "%s\t%s\n", prevkey,accumulator);

	free(line);
	free(prevkey);
	free(accumulator);

	return 0;
}