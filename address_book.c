#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char *name;
	char *phonenumber;
} Entry;

typedef struct {
	Entry **entries;
	size_t length;
} AddressBook;

Entry *create_Entry (const char *name, const char *phonenumber) {
	Entry *out = calloc(1, sizeof(Entry));
	out->name = calloc(strlen(name) +1, sizeof(char));
	strncpy(out->name, name, strlen(name));
	out->name[strlen(name)] = '\0';
	out->phonenumber = calloc(strlen(phonenumber) +1, sizeof(char));
	strncpy(out->phonenumber, phonenumber, strlen(phonenumber));
	return out;
}

AddressBook *create_AddressBook () {
	AddressBook *out = calloc(1, sizeof(AddressBook));
	out->length = 0;
	return out;
}

void print_Entry (const Entry *e) {
	printf("%s: %s", e->name, e->phonenumber);
}

void print_AddressBook (const AddressBook *ab) {
	size_t ab_length = ab->length;
	printf("\n");
	for (int i = 0; i < ab_length; i++) {
		printf("+ ");
		print_Entry(ab->entries[i]);
		printf("\n");
	}
	printf("\n");
}

void delete_Entry (Entry *e) {
	free(e->name);
	free(e->phonenumber);
	free(e);
}

void delete_AddressBook (AddressBook *ab) {
	for (int i = 0; i < ab->length; i++) {
		delete_Entry(ab->entries[i]);
	}
	free(ab->entries);
	free(ab);
}

void insertentryintoaddressbook (Entry *e, AddressBook **ab) {
	AddressBook *tmp = calloc(1, sizeof(AddressBook));
	size_t ab_length = (*ab)->length;
	tmp->length = ab_length + 1;
	tmp->entries = calloc(tmp->length, sizeof(Entry*));
	for (int i = 0; i < ab_length; i++) {
		tmp->entries[i] = create_Entry((*ab)->entries[i]->name, (*ab)->entries[i]->phonenumber);
	}
	delete_AddressBook(*ab);
	*ab = tmp;
	(*ab)->entries[(*ab)->length - 1] = e;
}

int main () {
	AddressBook *ab = create_AddressBook();
	for (;;) {
		printf("[-] Want to read the address book, add an entry or quit? [p/a/q] : ");
		int answer = getchar();
		for (int c; (c=getchar()) != '\n';)
			;
		if (answer == 'p' || answer == 'P') {
			if (ab->length > 0) {
				print_AddressBook(ab);
			}
			else {
				printf("[!] Address book is empty!\n");
			}
		}
		else if (answer == 'a' || answer == 'A') {
			Entry *e = NULL;
			char *line = NULL;
			char *name = NULL;
			char *phonenumber = NULL;
			size_t line_size = 0;
			size_t howmany_Char = 0;
			printf("Type in the name of your entry: ");
			howmany_Char = getline(&line, &line_size, stdin);
			if (howmany_Char > 2) {
				name = calloc(howmany_Char, sizeof(char));
				strncpy(name, line, howmany_Char);
				name[howmany_Char -1] = '\0';
			}
			printf("Type in its phone number: ");
			howmany_Char = getline(&line, &line_size, stdin);
			if (howmany_Char > 2) {
				phonenumber = calloc(howmany_Char, sizeof(char));
				strncpy(phonenumber, line, howmany_Char);
				phonenumber[howmany_Char -1] = '\0';
			}
			e = create_Entry(name, phonenumber);
			insertentryintoaddressbook(e, &ab);
			free(name);
			free(phonenumber);
			free(line);
		}
		else if (answer == 'q' || answer == 'Q') {
			printf("[+] uh?! ..nice to met ya!\n");
			break;
		}
		else {
			printf("[!] NOT getting you... Retry please!\n");
		}
	}
	delete_AddressBook(ab);
	return 0;
}
