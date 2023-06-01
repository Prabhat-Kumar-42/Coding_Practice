
char stack[100001];

char top(char* str, long long int size)
{
    return str[size-1];
}

void push(char* str, long long int* size, char ch)
{
    str[*size] = ch;
    (*size)++;
    str[*size] = '\0';
}

char pop(char* str, long long int* size)
{
    char ch = str[*size - 1];
    (*size)--;
    str[*size] = '\0';
    return ch;
}

int isEmpty(long long int size)
{
    return size == 0;
}

int main()
{
    long long int test_case;
    scanf("%lld", &test_case);
    
    while(test_case--)
    {
        long long int stack_size = 0;
        
        char str[100001], *ptr;
        scanf(" %s", str);
        
        //printf("%s\n", str);
        int flag = 1;
        ptr = str;
        
        while(*ptr)
        {
            if(*ptr == '(' || *ptr == '{' || *ptr == '[')
            {
                //printf("pushed = %c stack_size = %d\n", *ptr, stack_size);
                push(stack, &stack_size, *ptr);
            }
            else
            {
                if((top(stack, stack_size) == '(' && *ptr == ')') || (top(stack, stack_size) == '[' && *ptr == ']')
                    || (top(stack, stack_size) == '{' && *ptr == '}'))
                {
                    //printf("popped = %c stack_size = %d\n", *ptr, stack_size);
                    pop(stack, &stack_size);
                }
                else
                {
                    //printf("*pt = %c stack_top = %c\n", *ptr, top(stack, stack_size));
                    flag = 0;
                    break;
                }
            }
            ptr++;
        }
        
        //printf("%d\n", flag);
        int z = isEmpty(stack_size);
        //printf("z = %d stack_size = %lld ", z, stack_size);
        if(flag && z)
        {
            printf("balanced\n");
        }
        else
        {
            printf("not balanced\n");
        }
    }
    
    return 0;
}