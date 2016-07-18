// CLRS-Excercise-5.1-2
#include <stdio.h>
#include <math.h>

int random(){
	srand(time(NULL));
	return rand()%2;
}
int randomGen(int start, int end){
	int p = ceil(log2(end)), r=0;
	l:
	r = 0;
	for(int i=1;i<p;i++){
		r = 2*r + random();
	}
	if(r>(end-start)){
		goto l;
	}
	return r+start;
}
int main(void) {
	// your code goes here
	printf("%d", randomGen(0, 7));
	return 0;
}
