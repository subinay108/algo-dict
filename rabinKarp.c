// Rabin Carp String Matching Algorithm
#include<stdio.h>
#include<string.h>
#include<math.h>

#define max_size 100
#define char_count 26 // no of possible characters
#define mod 1000000007

int match(char*, char*);
long long calculateHashCode(char*, int);
long long calculateRollingHash(int, char, char, long long, long long);
int isStringEqual(char*, char*, int);

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
	
	long long pattern_hash = calculateHashCode(pat, m);
	
	long long lead_power = pow(char_count, m - 1);

	int i, j;
	long long hc;
	char substring[m];
	for(i = 0; i < n - m + 1; i++){
		strncpy(substring, str + i, m);
		if(i == 0){	
			hc = calculateHashCode(substring, m);
		}else{
			hc = calculateRollingHash(m, str[i - 1], str[i + m - 1], hc, lead_power);
		}
		if(hc == pattern_hash){
			if(isStringEqual(pat, substring, m)){
				return i;
			}
		}
	}
	return -1;
}

int isStringEqual(char* a, char* b, int size){
	int i;
	int flag = 1;
	for(i = 0; i < size; i++){
		if(a[i] != b[i]){
			flag = 0;
			break;
		}
	}
	
	return flag;
}

// Rabin Fingerprint Hash Function
long long calculateRollingHash(int n,char first, char next, long long hc, long long p){
	int i;
	p = (first - 65) * p;
	hc = ((hc - p) * char_count + (next - 65)) % mod;
	return hc;
}

long long calculateHashCode(char* s, int n){
	int i;
	long long h = 0;
	for(i = 0; i < n; i++){
		h = (h * char_count + s[i] - 65) % mod;
	}
	return h;
}