// Knuth-Morris-Pratt(KMP) String Matching Algorithm
#include<stdio.h>
#include<string.h>

#define max_size 100

int match(char*, char*);

int main(){
	char str[max_size], pat[max_size];
	printf("Enter the string: ");
	scanf("%s", &str);
	printf("Enter pattern: ");
	scanf("%s", &pat);
	
	int pos = match(&str[0], &pat[0]);
	
	if(pos != -1){
		printf("String is matched at: %d\n", pos);
		printf("%s\n", str);
		int i;
		for(i = 0; i < pos; i++){
			printf(" ");
		}
		printf("%s \n", pat);
	}else{
		printf("String is not matched");
	}
	return 0;
}

int match(char* str, char* pat){
	int n, m;
	n = strlen(str);
	m = strlen(pat);
	int i, j;
	// Generate Pi table
	for(i = 0; i < n; i++){
		// 
	}
	
	return -1;
}