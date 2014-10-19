#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

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

void filldictionarywith (Dictionary *d, const char *s, size_t s_length) {
	for (int i = 0; i < s_length; i++) {
		for (int j = 0; j < d->length; j++) {
			Tuple *t = d->tuples[j];
			if (t->character == toupper(s[i])) {
				t->numberofoccurrences += 1;
				break;
			}
		}
	}
}

bool equal_Tuple (const Tuple *t1, const Tuple *t2) {
	return t1->character == t2->character && t1->numberofoccurrences == t2->numberofoccurrences;
}

bool equal_Dictionary (const Dictionary *d1, const Dictionary *d2) {
	int length = d1->length;
	bool equal = true;
	for (int i = 0; i < length; i++) {
		Tuple *t1 = d1->tuples[i];
		Tuple *t2 = d2->tuples[i];
		if (!equal_Tuple(t1, t2)) {
			equal = false;
		}
	}
	return equal;
}

int main () {
	Dictionary *d1 = initdictionary();
	Dictionary *d2 = initdictionary();
	char *s1 = "bfoofaroo";
	char *s2 = "foobarfoo";
	filldictionarywith(d1, s1, strlen(s1));
	filldictionarywith(d2, s2, strlen(s2));
	assert(equal_Dictionary(d1, d2));
	delete_Dictionary(d2);
	delete_Dictionary(d1);
	return 0;
}
