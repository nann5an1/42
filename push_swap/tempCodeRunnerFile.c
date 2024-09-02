void show_lst(t_struct_node* stacka, t_struct_node* stackb) 
// {
//     t_struct_node* original_stackA = stacka;
//     printf("\n\n");
//     printf("Stack A\t\t");
//     while (stacka != NULL)
//     {
//         printf("%d   ", stacka->data);
//         stacka = stacka->next;
//     }
//     printf("\nStack B\t\t");
//     while (stackb != NULL)
//     {
//         printf("%d   ", stackb->data);
//         stackb = stackb->next;
//     }
//     printf("\n\n");
//     t_struct_node* node = sort_ascend(original_stackA);
//     while(node)
//     {
//         printf("%d   ", node->data);
//         node = node->next;
//     }
//     printf("\n\n");
// }