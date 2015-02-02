#include <stdio.h>
#include <stdlib.h>

typedef struct State State;
struct State
{
    char c;
    State *out;
};

typedef struct List List;
struct List
{
    State *s;
};

State *State_new(char c, State *out)
{
	State *s;
	s = malloc(sizeof(*s));
	s->c = c;
	s->out = out;
	return s;
}

void *List_new(State **outpp)
{
    List *slist = malloc(sizeof(*slist));
    slist->s = *outpp;
    return slist;
}

int main()
{
    State *a = State_new('a', NULL);
    List *l  = List_new(&(a->out));

    /* This printf() will result in a seg fault, since a->out is NULL. */
    //printf("%c\n", a->out->c);

    /* change what State struct is pointed to by l */
    l->s = State_new('b', NULL);

    /* why is this not b? */
    //printf("%c\n", a->out->c);
    return 0;
}