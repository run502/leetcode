#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ڲ����ٶ���ռ�������ɾ����ʼ�ͽ�β���Ŀո񣬲����м�Ķ�������Ŀո�ϲ���һ��
//
void FormatString (char str[], int len) {
	int i = 1;          //ѭ������ 
	printf("%d\n",len);
	
	//���������Ȱ����ⳤ�ȿո����Ϊһ�����ȵĿո��ٶԿ�ͷ�ͽ�β�Ŀո���д��� 
	//
	while (str[i] != '\0') {                       //�ж��Ƿ񵽴��ַ���ĩβ 
		if (str[i] == ' ' && str[i-1] == ' ') {    //���������ո� 
			for (int j = i-1; j < len-1; j++) {    
				str[j] = str[j+1];                 //����Ԫ����ǰ�ƶ�һ��λ�� 
			}
			len--;                                 //�����С�� 1
			str[len] = '\0';                       //�����µ��ַ���������ʶ 
			i--;                                   //�����¸�Ԫ�ص��˵�ǰλ�ã����Լ� 1 
		}
		i++;
	}
	printf("%s\n",str);
	
	if (str[0] == ' ') {
		for (int k = 1; k < len; k++) {
			str[k-1] = str[k];
		}
		len--;           //�ַ������ȼ�1
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
