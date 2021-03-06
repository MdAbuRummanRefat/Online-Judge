/* 9053498 369 Combinations Accepted C++ 0.024 2011-07-16 11:30:04 */
#include<stdio.h>
static int prime[30];
static int count;
static int factor[101][30]={0};
void initial(){
	int i,j,gap;
	prime[0]=2;
	prime[1]=3;
	count=2;
	for(i=5,gap=2;i<=100;i+=gap,gap=6-gap){
		for(j=0;j<count&&i%prime[j]!=0;j++);
		if(j>=count)
			prime[count++]=i;
	}
}
void get_factor(){
	int i,j,temp;
	factor[2][0]=1;
	for(i=3;i<=100;i++){
		for(j=0;factor[i-1][j]!=0;j++)
			factor[i][j]=factor[i-1][j];

		for(temp=i,j=0;temp>1;j++)
			while(temp%prime[j]==0){
				temp/=prime[j];
				factor[i][j]++;
			}
	}
}
int main(){
	initial();
	get_factor();
	int n,m;
	while(scanf("%d%d",&n,&m)==2&&n!=0&&m!=0){
		unsigned long long result=1;
		int t[30]={0};
		int i;

		for(i=0;factor[n][i]!=0;i++)
			t[i]+=factor[n][i];
		for(i=0;factor[n-m][i]!=0;i++)
			t[i]-=factor[n-m][i];
		for(i=0;factor[m][i]!=0;i++)
			t[i]-=factor[m][i];

		for(i=0;i<30;i++)
			while(t[i]>0){
				result*=prime[i];
				t[i]--;
			}
		printf("%d things taken %d at a time is %llu exactly.\n",n,m,result); // 槓 原始方法會在運算中溢位
	}
	return 0;
}
/*

Computing the exact number of ways that N things can be taken M at a time can be a great challenge when N and/or M become very large. Challenges are the stuff of contests. Therefore, you are to make just such a computation given the following:
 
GIVEN: 

Compute the EXACT value of: 

You may assume that the final value of C will fit in a 32-bit Pascal LongInt or a C long.
 
For the record, the exact value of 100! is: 

     93,326,215,443,944,152,681,699,238,856,266,700,490,715,968,264,381,621,
        468,592,963,895,217,599,993,229,915,608,941,463,976,156,518,286,253,
        697,920,827,223,758,251,185,210,916,864,000,000,000,000,000,000,000,000 

Input and Output
 
The input to this program will be one or more lines each containing zero or more leading spaces, a value for N, one or more spaces, and a value for M. The last line of the input file will contain a dummy N, M pair with both values equal to zero. Your program should terminate when this line is read.
 
The output from this program should be in the form: 

N things taken M at a time is C exactly. 

Sample Input 

     100  6
      20  5
      18  6
       0  0 

Sample Output 

100 things taken 6 at a time is 1192052400 exactly.
20 things taken 5 at a time is 15504 exactly.
18 things taken 6 at a time is 18564 exactly.

*/