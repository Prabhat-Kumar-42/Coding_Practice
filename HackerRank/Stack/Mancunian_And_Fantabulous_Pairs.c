#include<stdio.h>
#include<stdlib.h>
 
typedef long long llint;
#define gcx getchar_unlocked
#define pcx putchar_unlocked
 
llint stack[1000001], top = 0;
llint pops[1000001] = {0}, res[1000001] = {0};
 
void push(llint num)
{
	stack[top++] = num;
}
 
llint pop()
{
	llint z = stack[top-1];
	top--;
	return z;
}
 
llint stk_top()
{
	return stack[top-1];
}
 
int is_empty()
{
	return top == 0;
}
 
llint get_int()
{
	int c = gcx();
	llint num = 0;
	while(c >= '0' && c <= '9')
	{
		num = num*10 + c - '0';
		c = gcx();
	}
	return num;
}
 
void print(llint num)
{
	if(num == 0)
	{
		pcx('0'); pcx('\n'); return;
	}
 
	char str[30];
	int len = 0;
	while(num)
	{
		str[len++] = '0' + num % 10;
		num/=10;
	}
 
	while(len--)
	{
		pcx(str[len]);
	}
	pcx('\n');
}
 
int main()
{
	llint size = get_int();
	// scanf("%lld", &size);1
	llint arr[1000001];
	llint pairs = 0;
 
	for(llint i = 0; i < size; i++)
	{
		arr[i] = get_int();
		// scanf("%lld", &arr[i]);
		while( !is_empty() && arr[i] > arr[stk_top()])
		{
			llint a = i - stk_top();
			pairs = 1 + pops[stk_top()];
			if(res[a] < pairs)
			{
				res[a] = pairs;
			}
			pops[i] = 1 + pops[stk_top()] + pops[i];
			pop();
			pairs = 0;
		}
		push(i);
	}
 
	llint sum = 0;
	for(llint i = 0; i < size; i++)
	{
		sum = sum + res[i];
	}
	print(sum);
	return 0;
}