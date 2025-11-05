#include "finalibft/libft.h"
#include <stdio.h>

// A simple function to print the content of a list node
void	print_content(void *content)
{
	ft_putendl_fd((char *)content, 1);
}

// A simple function to delete the content of a list node
void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	char	*sentence = "This is a test sentence for libft.";
	char	**words;
	t_list	*list;
	int		i;

	ft_putendl_fd("--- Testing ft_split and linked list functions ---", 1);
	ft_putendl_fd("Original sentence:", 1);
	ft_putendl_fd(sentence, 1);

	// Split the sentence into words
	words = ft_split(sentence, ' ');
	if (!words)
		return (1);

	// Create a linked list from the words
	list = NULL;
	i = 0;
	while (words[i])
	{
		t_list *new_node = ft_lstnew(ft_strdup(words[i]));
		if (!new_node)
		{
			ft_lstclear(&list, del_content);
			return (1);
		}
		ft_lstadd_back(&list, new_node);
		i++;
	}

	// Print the content of the list
	ft_putendl_fd("\nWords stored in the linked list:", 1);
	ft_lstiter(list, print_content);

	// Clean up
	ft_lstclear(&list, del_content);
	i = 0;
	while(words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);

	ft_putendl_fd("\n--- Test complete ---", 1);

	return (0);
}
