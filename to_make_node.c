
#include "header.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp -> next)
	{
		temp = temp -> next;
	}
	temp -> next = new;
}


t_list	*ft_lstnew(int number)
{
	t_list	*point;

	point = malloc (sizeof(t_list));
	if (!point)
		return (NULL);
	point -> number = number;
	point -> next = NULL ;
	return (point);
}


void	ft_lstddelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}
void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*s;

	if (!*lst || !lst)
		return ;
	temp = *lst;
	while (temp)
	{
		s = temp -> next;
		ft_lstddelone(temp);
		temp = s;
	}
	*lst = NULL;
}
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr -> next)
	{
		ptr = ptr -> next;
	}
	return (ptr);
}
unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	count;
	t_list			*str;

	count = 0;
	str = lst;
	if (!lst)
		return (00);
	while (str)
	{
		str = str -> next;
		count++;
	}
	return (count);
}

void	free_str(char **str, int len)
{
	int	i;	

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	count_len(char const *s, int *index, char c)
{
	int	count;

	count = 0;
	while (s[(*index)] == c && s[(*index)])
		*index += 1;
	while (s[(*index)] != c && s[(*index)])
	{
		count++;
		*index += 1;
	}
	return (count);
}

static void	fot_copy(char const *s, char **str, int numword, char c)
{
	int	i;
	int	x;
	int	j;
	int	f;

	i = 0;
	x = 0;
	while (i < numword)
	{
		j = 0;
		f = 0;
		while (s[x] == c)
			x++;
		while (s[x] != c && s[x])
		{
			str[i][j] = s[x];
			j++;
			x++;
			f = 1;
		}
		if (f)
			str[i][j] = '\0';
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		x;

	x = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (i < count_word(s, c))
	{
		str[i] = malloc((count_len(s, &x, c) + 1) * sizeof(char));
		if (!str || !str[i])
		{
			free_str(str, i);
			return (NULL);
		}
		i++;
	}
	str[i] = NULL;
	fot_copy(s, str, count_word(s, c), c);
	return (str);
}