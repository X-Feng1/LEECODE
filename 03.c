//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

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
		for (j=0; j< count; j++)//在之前的不含重复字符中查找是否与重复
		{
			if (s[begin+j] == ret)
			{
				begin = begin+j+1;
				count = count-j;
				mark = 1;//标志有重复
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
	printf("长度为%d\n", length);
	return 0;
}