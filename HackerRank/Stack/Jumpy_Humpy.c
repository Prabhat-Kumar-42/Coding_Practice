    #include <stdio.h>
    #include <stdlib.h>
     
    typedef long long llint;
    #define gcx getchar_unlocked
    #define pcx putchar_unlocked
     
    llint stack[1000001], top = 0;
    llint res[1000001];
     
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
     
    llint process(llint* arr, llint size)
    {
    	llint max = arr[size-1];
    	res[size-1] = arr[size-1];
    	for ( llint i = size - 1; i >= 0; i--)
    	{
    		while(arr[stk_top()] < arr[i] && !is_empty())
    		{
    			pop();
    		}
    		if (arr[i] < arr[stk_top()] && !is_empty())
    		{
    			if(!res[stk_top()])
    			{
    				res[i] = arr[i]^arr[stk_top()];
    			}
    			else
    			{
    				res[i] = arr[i]^res[stk_top()];
    			}
    			if(res[i] > max)
    			{
    				max = res[i];
    			}
    		}
    		push(i);
    	}
    	return max;
    }
     
    int main()
    {
        llint size = get_int();
        llint arr[1000001];
        llint x = 0;
     
        for(llint i = 0; i < size; i++)
        {
            arr[i] = get_int();
        }
     
        print(process(arr, size));
        return 0;
    }