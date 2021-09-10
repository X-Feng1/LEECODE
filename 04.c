//寻找两个正序数组的中位数
//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
//请你找出并返回这两个正序数组的 中位数 。


#include<stdio.h>



//利用指针进行数据读取
double findmediansortedarrays(int l1[], int size1, int l2[], int size2)
{
	int* ret1 = (int*)malloc(sizeof(int) * (size1 + size2));
	int* p1 = &(l1[size1 - 1]) + 1;
	int* p2 = &(l2[size2 - 1]) + 1;
	int ret = 0;
	int k = 0;
	int i = 0;
	double a = 0.0;
	while (1)
	{
		if (l1 == p1 || l2 == p2)
			break;
		else
		{
			if (*(l1) < *(l2))
			{
				ret1[k] = *(l1);
				l1++;
				k++;
			}
			else if(*(l1)>*(l2))
			{
				ret1[k] = *(l2);
				l2++;
				k++;
			}
			else
			{
				ret1[k] = *(l1);
				k++;
				ret1[k] = *(l2);
				l1++;
				l2++;
				k++;
			}
		}
	}

	if ((size1 + size2 - k) > 0)
	{
		if (l1 == p1)
		{
			for (i = 0; i < (size1 + size2 - k); i++)
			{
				ret1[k + i] = *(l2);
				l2++;
			}
		}
		else if (l2 == p2)
		{
			for (i = 0; i < (size1 + size2 - k); i++)
			{
				ret1[k + i] = *(l1);
				l1++;
			}
		}
	}
		if (((size1 + size2) % 2) == 1)
	{
		i = (size1 + size2) / 2;
		a = ret1[i] / 1.0;
		return a;
	}
	else
	{
		i = (size1 + size2) / 2;
		int a1 = (ret1[i] + ret1[i- 1]);
		a = a1/ 2.0;
		return a;
	}
}


//
//double findmediansortedarrays(int l1[], int size1, int l2[], int size2)
//{
//	int* ret1 = (int*)malloc(sizeof(int) * (size1 + size2));
//	int ret = 0;
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	int s1 = 0;
//	int f = 0;
//	double a = 0.0;
//	i = 0;
//	while (1)
//	{
//		if (i >= size1 || j >= size2)
//		{
//			break;
//		}
//		else
//		{
//			if (l1[i] < l2[j])
//			{
//				ret1[k] = l1[i];
//				i++;
//				k++;
//			}
//			else if (l1[i] > l2[j])
//			{
//				ret1[k] = l2[j];
//				j++;
//				k++;
//			}
//			else
//			{
//				ret1[k] = l1[i];
//				k++;
//				ret1[k] = l2[j];
//				k++;
//				j++;
//				i++;
//			}
//		}
//
//	}
//	s1 = (size1 + size2)-k;
//	if (s1 > 0)
//	{
//		if (i >= size1)
//		{
//			for (f = 0; f < s1; f++)
//			{
//				ret1[s + f] = l2[j + f];
//			}
//		}
//		else if (j >= size2)
//		{
//			for (f = 0; f < s1; f++)
//			{
//				ret1[s + f] = l1[j + f];
//			}
//		}
//	}
//	if (((size1 + size2) % 2) == 1)
//	{
//		i = (size1 + size2) / 2;
//		a = ret1[i] / 1.0;
//		return a;
//	}
//	else
//	{
//		i = (size1 + size2) / 2;
//		int a1 = (ret1[i] + ret1[i- 1]);
//		a = a1/ 2.0;
//		return a;
//	}
//
//	
//}
//

int main()
{
	int l1[] = { 3 };
	int l2[] = { -2,-1 };
	int sz1 = sizeof(l1) / sizeof(l1[0]);
	int sz2 = sizeof(l2) / sizeof(l2[0]);
	double ret = findmediansortedarrays(l1, sz1, l2, sz2);
	printf("%lf\n", ret);
	return 0;
}