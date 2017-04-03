#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//在不开辟额外空间的情况下删除开始和结尾处的空格，并将中间的多个连续的空格合并成一个
//
void FormatString (char str[], int len) {
	int i = 1;          //循环计数 
	printf("%d\n",len);
	
	//处理方法：先把任意长度空格均变为一个长度的空格，再对开头和结尾的空格进行处理 
	//
	while (str[i] != '\0') {                       //判断是否到达字符串末尾 
		if (str[i] == ' ' && str[i-1] == ' ') {    //连续两个空格 
			for (int j = i-1; j < len-1; j++) {    
				str[j] = str[j+1];                 //数组元素向前移动一个位置 
			}
			len--;                                 //数组大小减 1
			str[len] = '\0';                       //设置新的字符串结束标识 
			i--;                                   //由于下个元素到了当前位置，所以减 1 
		}
		i++;
	}
	printf("%s\n",str);
	
	if (str[0] == ' ') {
		for (int k = 1; k < len; k++) {
			str[k-1] = str[k];
		}
		len--;           //字符串长度减1
		str[len] = '\0';
	}
	
	if (str[len-1] == ' ') {
		str[len-1] = '\0';
	}
	
	printf("%s",str);	
	printf("%d",strlen(str));
}

int main () {
	char str[] = "  I am        Goson a ! ";
	FormatString(str, strlen(str));
	return 0;
}
