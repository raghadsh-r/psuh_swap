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
int main(int argc, char **argv)
{
    char **ptr;
    int     i;
    int     j;
    t_list *point;

    i  = 0;
    j = 0;
    if(argc == 1)
        return(0);
    ptr = ft_split(argv[1],' ');
    if(!ptr)
        return(0);
    if(!chrak_if_is_number(ptr))
        return(0);
    t_list *head;
    head = NULL;
    while(ptr[i])
    {
        int z;
        point = ft_lstnew(ft_atoi(ptr[i]));
        if(!point)
        {
            ft_lstclear(&head);
            return 0;
        }
        ft_lstadd_back(&head,point);
        if(!head)
        {   
            ft_lstclear(&head);
            return 0;
        }
            i++;
    }
    free_str(ptr,ft_lstsize(head));
    if(!cheak_duplicate(head))
        return (0);
    t_list *curr = head; 
    while (curr)
    {
        printf("%i\n", curr->number);
        curr = curr->next;
    }
    ft_lstclear(&head);
}