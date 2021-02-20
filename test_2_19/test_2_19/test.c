#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//strtok

//int main(void)
//{
//	char arr[] = "192.168.31.121";
//	char* p = ".";
//
//	char arr1[] = "123@234.@2345";
//	char* p1 = "@.";
//	char buf[100] = { 0 };
//	strcpy(buf, arr);
//	
//	char* ret = NULL;
//	char* ret1 = NULL;
//	for (ret1 = strtok(arr1, p1); ret1 != NULL; ret1 = strtok(NULL, p1))
//	{
//		printf("%s\n", ret1);
//	}
//	return 0;
//}

//strerror

#include<errno.h>
 
//int main(void)
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("open file success\n");
//	}
//	return 0;
//}

#include<ctype.h>
//int main(void)
//{
//	//char ch ='2';
//
//	////int ret = islower(ch);
//	//int ret = isdigit(ch);
//	//printf("%d\n", ret);
//
//	//char ch = tolower('Q');
//	/*char ch = toupper('q');
//	putchar(ch);*/
//
//	char arr[] = "I Am A Student";
//	int i=0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//	return 0;
//}

//momcpy   不重叠的内存拷贝
//mommove  内存重叠的拷贝
#include<assert.h>
struct s
{
	char name[20];
	int age;
};

void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;

	while (num--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return ret;
}
void* my_memmove1(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;

	//右边内容拷贝到左边，则从前往后拷贝
	if (dest < src)
	{
		while (num--)
		{
			*(char*)dest = *(char*)src; 
			++(char*)dest;
			++(char*)src;
		}
	}
	else//左边内容拷贝到右边，则从后往前拷贝
	{
		/*(char*)dest += (num-1);
		(char*)src += (num-1);
		while (num--)
		{
			
			*(char*)dest = *(char*)src;
			--(char*)dest;
			--(char*)src;
		}*/

		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
	
	
}
void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	if (dest<src || dest>(char*)src + num)
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}

	}
	return ret;
}
//
//int main(void)
//{
//	//int arr1[] = { 1,2,3,4,5 };
//	//int arr2[5] = { 0 };
//	//struct s arr3[] = { {"张三",20},{"李四",30} };
//	//struct s arr4[3] = { 0 };
//	///*memcpy(arr2, arr1, sizeof(arr1));
//	//memcpy(arr4, arr3, sizeof(arr3));*/
//	//my_memcpy(arr4, arr3, sizeof(arr3));
//
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	my_memmove(arr, arr+2, 20);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//memcmp
//memset   修改单位是字节
int main(void)
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,5,4,3 };
	int ret = memcmp(arr1, arr2, 9);
	//printf("%d\n", ret);

	char arr[10] = "";
	memset(arr,'#',10);
	return 0;
}