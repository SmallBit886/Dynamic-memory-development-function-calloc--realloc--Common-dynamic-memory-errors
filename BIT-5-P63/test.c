#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//2.2 calloc --- void* calloc (size_t num, size_t size);
//�뺯�� malloc ������ֻ���� calloc ���ڷ��ص�ַ֮ǰ������Ŀռ��ÿ���ֽڳ�ʼ��Ϊȫ0
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
//realloc �����Ϳ��������Զ�̬�����ڴ��С�ĵ�����
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
//	//�������ǿ��ٵ�20�ֽڲ����������ǵ�ʹ����
//	//ϣ���ܹ���40�ֽڵĿռ����ʹ��
//	//����ʹ��realloc��������̬���ٵĿռ�
//	//
//	//reallocʹ�õ�ע�����
//	//1.���pָ��Ŀռ�֮�����㹻���ڴ�ռ����׷�ӣ���ֱ��׷�ӣ��󷵻�p
//	//2.���pָ��Ŀռ�֮��û���㹻���ڴ�ռ����׷�ӣ���realloc������������һ���µ��ڴ�����
//	//��һ����������Ŀռ䣬���Ұ�ԭ���ڴ�����ݿ����������ͷžɵ��ڴ�ռ䣬�����¿��ٵ��ڴ�ռ��ַ
//	//3.����һ���µı���������realloc��������ֵ
//	//p = realloc(p, INT_MAX);//ʧ�ܺ󷵻�NULL
//
//	int* ptr=realloc(p, INT_MAX);
//	if (ptr != NULL)
//	{
//		p = ptr;//��ֹʧ�ܷ��ؿ�ָ�룬���Ǿ��ڴ��ַ��ָ��
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
//reallocҲ�������malloc
//int main()
//{
//	int* p = (int*)realloc(NULL, 40);//����40�ֽڵĿռ�
//}

//3. �����Ķ�̬�ڴ����
//3.1 ��NULLָ��Ľ����ò���
// 
//void test()
//{
//	int* p = (int*)malloc(INT_MAX / 4);
//	*p = 20;//���p��ֵ��NULL���ͻ�������
//	free(p);
//}
// 
//��ʹ�õ�ʱ��һ��Ҫ�����ж�

//3.2 �Զ�̬���ٿռ��Խ�����
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
//		*(p + i) = i;//��i��10��ʱ��Խ�����
//	}
//	free(p);
//	p = NULL;
//}

//3.3 �ԷǶ�̬�����ڴ�ʹ��free�ͷ�
//void test()
//{
//	int a = 10;//ջ�ռ����ڴ�
//	int* p = &a;
//	free(p);//�ͷŶѿռ��ϵ��ڴ�
//}

//3.4 ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����
//void test()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//p����ָ��̬�ڴ����ʼλ��
//}

//3.5 ��ͬһ�鶯̬�ڴ����ͷ�
//void test()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);//�ظ��ͷ�
//}

//3.6 ��̬�����ڴ������ͷţ��ڴ�й©��
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
//	while (1);//��񿪱ٿռ�
//}

