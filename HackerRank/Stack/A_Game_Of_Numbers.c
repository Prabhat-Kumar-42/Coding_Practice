#include <stdio.h>
#include <stdlib.h>
 
typedef long long llint;
#define gcx getchar_unlocked
#define pcx putchar_unlocked
 
llint stack[1000001], top = 0;
llint next_greater[1000001], next_smaller[1000001];
 
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
	if(num == -1)
	{
		pcx('-'); pcx('1'); pcx(' '); return;
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
	pcx(' ');
}
 
int main()
{
   llint arr[1000001];
   llint size;// = get_int();
   scanf("%lld", &size);
 
   for(llint i = 0; i < size; i++)
   {
      // arr[i] = get_int();
      scanf("%lld", &arr[i]);  
      while ( !is_empty() && arr[stk_top()] < arr[i])
      {
         next_greater[stk_top()] = i;
         pop();
      }
      push(i);
   }
 
   while (!is_empty())
   {
      next_greater[stk_top()] = -1;
      pop();
   }
 
   for(llint i = size-1; i >= 0; i--)
   {
      while ( !is_empty() && arr[stk_top()] >= arr[i])
      {
         if(next_smaller[stk_top()] == 0)
         {
            next_smaller[stk_top()] = -1; 
         }
         pop();
      }
      if(!is_empty() && arr[stk_top()] < arr[i])
      {
         next_smaller[i] = stk_top();
      }
      push(i);
   }
 
   while (!is_empty())
   {
      next_smaller[stk_top()] = -1;
      pop();
   }
   
   for(llint i = 0; i < size; i++)
   {
      if(next_greater[i] == -1)
      {
         printf("-1 ");
      }
      else if( next_smaller[next_greater[i]] == -1)
      {
         printf("-1 ");
      }
      else
      {
         printf("%lld ", arr[next_smaller[next_greater[i]]]);
      }
   }
   return 0;
}