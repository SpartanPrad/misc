#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void gen_random(char *s, const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    srand( time( NULL ) );
    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}

int main() {
	char *s;
	s=(char *)malloc(sizeof(char *)* 15);
	gen_random(s, 15);
	puts(s);
	return 0;
}
