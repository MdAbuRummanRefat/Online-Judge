/* 10499 The Land of Justice Accepted C++ 0.044 2011-01-25 06:50:14 */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1&&n>=0){
		if(n==1){
			puts("0%");
			continue;
		}
		printf("%.0lf%%\n",n/4.0*100);
	}
	return 0;
}
/*

在公平國內每件東西的售價都是固定的。沒有人能夠買入一個東西後用2倍的價錢賣出去。但是這也產生了市場問題，大家都不做生意而跑去做製造了。所以過了不久之後，每個人都在製造東西，但卻沒有人在做生意。這使得人們沒有辦法得到日常所需，雖然這個國家在各方面都可以自給自足。

政府變的非常緊張了，他們找來了數學家們。數學家們提供了一個解決方案。他們建議賣東西時不以體積計價，而以表面積計價。

現在，政府要求程式設計師建立所需軟體來計算利潤。

你的任務就是計算賣一東西（固體的球體）的利潤。商人買來一個球體然後把它切割成相等的 n 等分出售。所有的切割一定都通過球體的軸心，如下圖一般：

Input

輸入含有多組測試資料。每組測試資料一列含有一正整數 n（0 < N < 231）。

若 n 為負數，代表輸入結束，請參考Sample Input。

Output

對每組測試資料輸出一列，輸出商人將一實體圓球切割成相等的 n 等分後，可以獲得的利潤。以百分比表示，四捨五入到整數位數。

Sample Input 

2
2
1
-1

Sample Output 

50%
50%
0% 
 
*/