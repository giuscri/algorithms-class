#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
	int character;
	int numberofoccurrences;
} Tuple;

typedef struct {
	Tuple **tuples;
	int length;
} Dictionary;

Dictionary *initdictionary () {
	Dictionary *out = (Dictionary*)calloc(1, sizeof(Dictionary));
	out->length = 25;
	out->tuples = (Tuple**)calloc(25, sizeof(Tuple*));
	for (int i = 0; i < out->length; i++) {
		out->tuples[i] = (Tuple*)calloc(1, sizeof(Tuple));
		out->tuples[i]->character = 'A' + i;
		out->tuples[i]->numberofoccurrences = 0;
	}
	return out;
}

void delete_Tuple (Tuple *t) {
	free(t);
}

void delete_Dictionary (Dictionary *d) {
	for (int i = 0; i < d->length; i++) {
		delete_Tuple(d->tuples[i]);
	}
	free(d->tuples);
	free(d);
}

void print_Dictionary (const Dictionary *d) {
	printf("[\n");
	for (int i = 0; i < d->length; i++) {
		Tuple *t = d->tuples[i];
		printf("\t(%c,%d)\n", t->character, t->numberofoccurrences);
	}
	printf("\n]");
}

void printasistogram_Dictionary (const Dictionary *d) {
	for (int i = 0; i < d->length; i++) {
		Tuple *t = d->tuples[i];
		int numberofoccurrences = t->numberofoccurrences;
		if (numberofoccurrences < 1) {
			continue;
		}
		printf("%c: ", t->character);
		for (int j = 0; j < t->numberofoccurrences; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int main () {
	Dictionary *d = initdictionary();
	printf("Type in a string and I'll make the graph: ");
	char *buffer = NULL;
	size_t buffer_length = 0;
	size_t charactersread = 0;
	charactersread = getline(&buffer, &buffer_length, stdin);
	if (charactersread < 1) {
		printf("uhm... Did you type anything?!\n");
		return 1;
	}
	for (int i = 0; buffer[i] != '\0'; i++) {
		for (int j = 0; j < d->length; j++) {
			Tuple *t = d->tuples[j];
			if (t->character == toupper(buffer[i])) {
				t->numberofoccurrences += 1;
				break;
			}
		}
	}
	printasistogram_Dictionary(d);
	delete_Dictionary(d);
	return 0;
}
