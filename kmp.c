// Knuth Morris Pratt(KMP) String Matching Algorithm
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
	int n = strlen(str);
	int m = strlen(pat);
	
	// generate pi table
	int pi[m + 1];
	int i, q = 0;
	pi[1] = 0;
	for(i = 2; i <= m; i++){
		while(i <= m && pat[0 + q] == pat[i - 1]){
			q++;		
			pi[i] = q;
			i++;
		}
		q = 0;
		pi[i] = q;
	}
	
	// print pi table
	printf("PI Table:\n");
	for(i = 1; i <= m; i++){
		printf("%3d ", i);
	}
	printf("\n");
	for(i = 1; i <= m; i++){
		printf("%3c ", pat[i - 1]);
	}
	printf("\n");
	for(i = 1; i <= m; i++){
		printf("%3d ", pi[i]);
	}
	printf("\n");
	
	// searching for match
	q = 0;
	for(i = 0; i < n; i++){
		while(q > 0 && str[i] != pat[q]){
			q = pi[q];
		}
		if(str[i] == pat[q]){
			q++;
		}
		if(q == m){
			return (i - m + 1);
		}
	}
	
	return -1;
}
