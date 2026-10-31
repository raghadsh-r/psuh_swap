#ifndef HEADER_H
# define HEADER_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
typedef struct s_list
{
    int         number;
	struct s_list	*next;
}	t_list;
t_list	*ft_lstnew(int number);
void	ft_lstddelone(t_list *lst);
void	ft_lstclear(t_list **lst);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
#endif