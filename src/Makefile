CC=gcc
CFLAGS=-ggdb

all: mr-add-key mr-add-value mr-reduce-add mr-reduce-max mr-reduce-min mr-reduce-concat

.PHONY: all

mr-add-key: mr-add-key.c
	$(CC) $< $(CFLAGS) -o $@

mr-add-value: mr-add-value.c
	$(CC) $< $(CFLAGS) -o $@

mr-reduce-add: mr-reduce-add.c
	$(CC) $< $(CFLAGS) -o $@

mr-reduce-max: mr-reduce-max.c
	$(CC) $< $(CFLAGS) -o $@

mr-reduce-min: mr-reduce-min.c
	$(CC) $< $(CFLAGS) -o $@

mr-reduce-concat: mr-reduce-concat.c
	$(CC) $< $(CFLAGS) -o $@

.PHONY: clean

clean:
	rm mr-add-value mr-reduce-add mr-reduce-max mr-reduce-min mr-reduce-concat mr-add-key
