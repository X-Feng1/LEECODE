//����֮��
//����һ���������� nums ��һ������Ŀ��ֵ target��
//�����ڸ��������ҳ���ΪĿ��ֵtarget��������������
//���������ǵ������±ꡣ
//����nums = [3,2,4],target = 6

#include<stdio.h>
int* Two_Sum(int nums[], int target, int numsSize, int* returnSize)
{
	int* a = (int*)malloc(sizeof(int) * 2);
	int begin = 0;
	int i = 0;
	while (1)
	{
		for (i = begin + 1; i < numsSize; i++)
		{
			if (target == nums[begin] + nums[i])
			{
				a[0] = begin;
				a[1] = i;
				*returnSize = 2;
				return a;
			}
		}
		begin++;
	}
}


int main()
{
	int nums[] = { 2,7,11,5 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int target = 9;
	int returnSize = 2;
	int i = 0;
	int* p = Two_Sum(nums, target,sz,&returnSize);
	for (i = 0; i < 2; i++)
	{
		printf("%d ", *(p + i));
	}
	return 0;
}