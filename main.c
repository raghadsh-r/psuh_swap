#include "header.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	size_t	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}
int	ft_isdigit(int str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

int chrak_if_is_number(char **ptr)
{
    int i;
    int j;

    i = 0;
    while(ptr[i])
    {
            j = 0;
            while(ptr[i][j])
            {
        	    if(!ft_isdigit(ptr[i][j]))
                    return 0;
                    j++;
            }
            i++;
    }
    return(1);
}

int cheak_duplicate(t_list *head)
{
    t_list *ptr;
    while(head)
    {
        ptr = head ->next;
        while (ptr)
        {
            if(head -> number == ptr -> number)
                return (0);
            ptr = ptr -> next;  
        }
        head = head -> next;
    }
    return (1);
}

double compute_disorder(t_list *head)
{
    double mistakes;
    double total_pairs;
    t_list *i;
    t_list *j;

    i = head;
    mistakes = 0;
    total_pairs = 0;
    while(i)
    {
        j = i -> next;
        while (j)
        {   
            total_pairs+=1;
            if(i->number > j ->number)
                mistakes+=1;
            j = j -> next;
        }
        i = i -> next;
    }
    return (mistakes / total_pairs);
}
int main(int argc, char **argv)
{
    char **ptr;
    int     i;
    int     j;
    t_list *point;
    int len;

    i  = 0;
    j = 0;
    if(argc == 1)
    {
        printf("no input\n");    
        return(0);
    }

    ptr = ft_split(argv[1],' ');
    if(!ptr)
        return(0);
    if(!chrak_if_is_number(ptr))
    {
        printf("Invalid input\n");
        free_str(ptr,count_word((char const *)ptr,' '));
        return(0);
    }
    t_list *head;
    head = NULL;
    while(ptr[i])
    {
        int z;
        point = ft_lstnew(ft_atoi(ptr[i]));
        if(!point)
        {
            printf("allocate fail\n");   
            ft_lstclear(&head);
            return 0;
        }
        ft_lstadd_back(&head,point);
        if(!head)
        {    
            printf("allocate fail\n");   
            ft_lstclear(&head);
            return 0;
        }
            i++;
    }
    len = ft_lstsize(head);
    free_str(ptr,len);
    if(!cheak_duplicate(head))
     {  
        printf("found duplicate\n");   
        ft_lstclear(&head);
        return (0);
     }
    t_list *curr = head;
    printf("%f\n",compute_disorder(head));
    while (curr)
    {
        printf("%i\n", curr->number);
        curr = curr->next;
    }
    ft_lstclear(&head);
}