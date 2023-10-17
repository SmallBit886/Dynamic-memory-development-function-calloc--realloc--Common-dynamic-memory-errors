#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//2.2 calloc --- void* calloc (size_t num, size_t size);
//与函数 malloc 的区别只在于 calloc 会在返回地址之前把申请的空间的每个字节初始化为全0
//int main()
//{
//	//malloc(10*sizeof(int))
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));//0 0 0 0 0 0 0 0 0 0
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//2.3 realloc --- void* realloc (void* ptr, size_t size);
//realloc 函数就可以做到对动态开辟内存大小的调整。
//int main()
//{
//	int* p = (int*)malloc(20);
//	int i = 0;
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 5; i++)
//		{
//			printf("%d ", *(p + i));//0 1 2 3 4
//		}
//		printf("%p\n",p);//00000207857D0840
//
//	}
//
//	//假设我们开辟的20字节不能满足我们的使用了
//	//希望能够有40字节的空间可以使用
//	//可以使用realloc来调整动态开辟的空间
//	//
//	//realloc使用的注意事项：
//	//1.如果p指向的空间之后有足够的内存空间可以追加，则直接追加，后返回p
//	//2.如果p指向的空间之后没有足够的内存空间可以追加，则realloc函数会重新找一个新的内存区域
//	//开一块满足需求的空间，并且把原先内存的数据拷贝回来，释放旧的内存空间，返回新开辟的内存空间地址
//	//3.得用一个新的变量来接收realloc函数返回值
//	//p = realloc(p, INT_MAX);//失败后返回NULL
//
//	int* ptr=realloc(p, INT_MAX);
//	if (ptr != NULL)
//	{
//		p = ptr;//防止失败返回空指针，覆盖旧内存地址的指针
//	}
//
//	for (i = 5; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));//0 1 2 3 4 5 6 7 8 9
//	}
//	printf("%p\n", p);//0000020785A15070
//	
//	free(p);
//	p = NULL;
//	return 0;
//}
// 
//realloc也可以替代malloc
//int main()
//{
//	int* p = (int*)realloc(NULL, 40);//开辟40字节的空间
//}

//3. 常见的动态内存错误
//3.1 对NULL指针的解引用操作
// 
//void test()
//{
//	int* p = (int*)malloc(INT_MAX / 4);
//	*p = 20;//如果p的值是NULL，就会有问题
//	free(p);
//}
// 
//在使用的时候一定要进行判断

//3.2 对动态开辟空间的越界访问
//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//当i是10的时候越界访问
//	}
//	free(p);
//	p = NULL;
//}

//3.3 对非动态开辟内存使用free释放
//void test()
//{
//	int a = 10;//栈空间上内存
//	int* p = &a;
//	free(p);//释放堆空间上的内存
//}

//3.4 使用free释放一块动态开辟内存的一部分
//void test()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//p不再指向动态内存的起始位置
//}

//3.5 对同一块动态内存多次释放
//void test()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);//重复释放
//}

//3.6 动态开辟内存忘记释放（内存泄漏）
//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test();
//	while (1);//疯狂开辟空间
//}

