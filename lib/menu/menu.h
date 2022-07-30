#ifndef _MENU_H_
#define _MENU_H_

typedef void (*opt_ptr)(void);
typedef int (*checker)(void);
typedef void (*opt_visualizer)(int);

struct menu_t {
    int opt_num;
    opt_ptr* options;
    checker scrollup_checker;
    checker scrolldown_checker;
    opt_visualizer visualizer;
    checker selection_checker;
};

enum checker_type{SCROLL_UP, SCROLL_DOWN, SELECTION};

struct menu_t create_menu();
int select_checker(struct menu_t*, checker, enum checker_type);
void select_options(struct menu_t*, opt_ptr[], int);
void select_visualizer(struct menu_t*, opt_visualizer);
int enter_menu(struct menu_t*);

#endif
