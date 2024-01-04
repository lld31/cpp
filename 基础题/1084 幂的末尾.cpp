#include <stdio.h>
/*
 幂a^b的末3位数是多少？
*/
int main(){
	
	int a,b,t,s=1; 
	printf("请分别输入幂的底与指数（空格分开）："); 
	scanf("%d %d", &a,&b);
	
	//只与末尾三个数字相关直接取模即可%1000
	for(int i=1;i<=b;i++){
		s*=a;
		t=s%1000;
	}
	
	printf("幂%d^%d的末3位数是%d\n",a,b,t);
	
	return 0;
}
