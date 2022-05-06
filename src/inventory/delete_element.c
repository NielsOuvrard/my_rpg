/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** delete_element
*/

#include "my.h"
#include "rpg_header.h"

void delete_element_inv(int position)
{
    struct_inventory **inv = &all_infos()->inventory;
    struct_inventory *node = *inv;
    if (!node)
        return;
    struct_inventory *tmp = (node)->next;
    if (position == 0) {
        use_elem(node);
        (*inv) = (*inv) ->next;
        return;
    }
    for (int i = 0; i < position - 1; i++) {
        node = node->next;
        tmp = tmp->next;
    }
    use_elem(node);
    node->next = tmp->next;
    all_infos()->inventory_move -= 1;
    free(tmp);
}

void use_elem(struct_inventory *node)
{
    if (node->object == BANANA)
        increase_health_and_stamina(2, 1);
    if (node->object == APPLE)
        increase_health_and_stamina(1, 2);
}

void increase_health_and_stamina(int health, int stamina)
{
    if (all_infos()->life + health <= all_infos()->life_size / 15)
        all_infos()->life += health;
    if (stamina == 1) {
        all_infos()->stamina = 10;
        return;
    }
    if (stamina == 2 && all_infos()->stamina < 5) {
        all_infos()->stamina = 5;
    } else if (all_infos()->stamina + 1 <= 10) {
        all_infos()->stamina += 1;
    }
}
