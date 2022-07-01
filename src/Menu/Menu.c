#include <Menu.h>
#include <stdlib.h>

struct menu_t create_menu() {
    struct menu_t new_menu;

    new_menu.opt_num = 0;
    new_menu.options = NULL;
    new_menu.scroll_down = NULL;
    new_menu.scroll_up = NULL;
    new_menu.visualizer = NULL;
    new_menu.s_checker = NULL;

    return new_menu;
}

int select_checker(struct menu_t* menu, checker ch, enum checker_type type) {
    switch (type)
    {
        case SCROLL_UP:
            menu -> scrollup_checker = ch;
            return 0;
        
        case SCROLL_DOWN:
            menu -> scrolldown_checker = ch;
            return 0;

        case SELECTION:
            menu -> selection_checker = ch;
            return 0;  

        default:
            return -1;
    }
}

inline void select_options(struct menu_t* menu, opt_ptr options[], int opt_num) {
    menu -> options = options;
    menu -> opt_num = opt_num;
}

inline void select_visualizer(struct menu_t* menu, opt_visualizer visualizer) {
    menu -> visualizer = visualizer;
}

int enter_menu(struct menu_t* menu) {
    if (menu -> visualizer == NULL)
        return -1;

    if (menu -> s_checker == NULL)
        return -2;

    if (menu -> scroll_up == NULL && menu -> scroll_down == NULL)
        return -3;

    if (menu -> options == NULL)
        return -4;

    int curr_opt = 0;

    menu -> visualizer(curr_opt);
    while (1) {
        if (menu -> scroll_up != NULL) {
            if (menu -> scroll_up()) {
                if (curr_opt >= menu -> opt_num - 1)
                    curr_opt = 0;
                else
                    curr_opt ++;

                menu -> visualizer(curr_opt);
            }
        }

        if (menu -> scroll_down != NULL) {
            if (menu -> scroll_down()) {
                if (curr_opt <= 0)
                    curr_opt = menu -> opt_num - 1;
                else
                    curr_opt --;

                menu -> visualizer(curr_opt);
            }
        }
        
        if (menu -> s_checker()){
            menu -> visualizer(curr_opt);
            (menu -> options[curr_opt])();
            break;
        }
    }

    return 0;
}