//����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�

#include<stdio.h>

int LengthOfLongestSubstring(char s[])
{
	int begin = 0;
	int count = 1;
	int count2 = 1;
	
	int i = 1;
	int j = 0;

	if (s[0] == '\0')
	{
		return 0;
	}
	while (s[i]!='\0')
	{
		int mark = 0;
		char ret = s[i];
		for (j=0; j< count; j++)//��֮ǰ�Ĳ����ظ��ַ��в����Ƿ����ظ�
		{
			if (s[begin+j] == ret)
			{
				begin = begin+j+1;
				count = count-j;
				mark = 1;//��־���ظ�
				break;
			}
		}
		i++;
		if (mark<1)
		{
			count++;
		}
		if (count > count2)
		{
			count2 = count;
		}
	}
	return count2;
}


int main()
{
	char s[] = "dvdf";
	int length = LengthOfLongestSubstring(s);
	printf("����Ϊ%d\n", length);
	return 0;
}