#include "minirt.h"


int main(int argc, char **argv)
{
	t_list_minirt *head = NULL;
	if (argc != 2)
		ft_terminate_with_error("Trop d'argument passe en parametre", NULL, NULL, NULL);
	head = ft_parsing(argv[1]);
	if (!ft_check_for_mandatory(&head))
		ft_terminate_with_error("Les elements obligatoires ne sont pas presents.",NULL,&head, &ft_del_node_lstminirt);
	if (ft_check_for_duplicate(&head))
		ft_terminate_with_error("Presence de doublons.",NULL,&head, &ft_del_node_lstminirt);
	ft_raytracing(head);
	ft_lstclear_minirt(&head, &ft_del_node_lstminirt);
	printf("FICHIER VALIDE\n");
	return (0);
}
