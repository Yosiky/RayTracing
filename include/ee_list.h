#ifndef EE_LIST_H
# define EE_LIST_H

typedef struct s_eelist
{
    struct s_eelist *next;
    void            *data;
}   t_eelist;



#endif
