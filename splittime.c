#include <stdio.h>
#include <assert.h>

void split_time (long int tot_sec, int *h, int *m, int *s) {
	*h = 0;
	*m = 0;
	*s = 0;
	*h = (int)(tot_sec / 3600);
	tot_sec = tot_sec % 3600;
	*m = (int)(tot_sec / 60);
	tot_sec = tot_sec % 60;
	*s = tot_sec;
}

int main () {
	int h = 0;
	int m = 0;
	int s = 0;
	split_time((long int)3661, &h, &m, &s);
	assert(h == 1 && m == 1 && s == 1 && "split_time(3661, ...) call failed.");
	split_time((long int)60, &h, &m, &s);
	assert(h == 0 && m == 1 && s == 0 && "split_time(60, ...) call failed.");
	split_time((long int)136, &h, &m, &s);
	assert(h == 0 && m == 2 && s == 16 && "split_time(136, ...) call failed.");
	split_time((long int)86401, &h, &m, &s);
	assert(h == 24 && m == 0 && s == 1 && "split_time(86401, ...) call failed.");
	return 0;
}
