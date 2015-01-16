#include <stdio.h>
#include "nfa.h"
#include "simul.h"


/*
 * A helpful constructor function for the State struct. See:
 * http://stackoverflow.com/a/3774202/1830334.
 */
State *State_new(int c, State *out1, State *out2)
{
	/* 
	 * This is used to correctly allocate enough memory for the NFA. In RSC's
	 * implementation, it is a global.
	 */
	//state_count++;

	State *s;
	s = malloc(sizeof *s);
	s->list_id = 0;
	s->c = c;
	s->out1 = out1;
	s->out2 = out2;
	return s;
}

/* TODO: Use enum. */
State match_state = { 256 };

/* See State_new for details about this pattern. */
Frag Frag_new(State *start, State **out)
{
	Frag n = { start, out };
	return n;
}

/* Creates a new pointer list containing a single pointer out_ptr. */
State **Unconn_ptrs_new(State *out_ptr)
{
    /* Take the address of out_ptr and set it as the first element. */
    State **nlist = &out_ptr;
    return nlist;
}

/* Concatenates two pointer lists. */
State **concat(State **l1, State **l2)
{
    int st_n = sizeof(State);
    int l1_n = sizeof(l1) / sizeof(State);
    int l2_n = sizeof(l2) / sizeof(State);

    State **l3 = malloc((l1_n + l2_n) * st_n);
    memcpy(l3, l1, l1_n * st_n);
    memcpy(l3 + l1_n * st_n, l2, l2_n * st_n);
    return l3;
}

/* Connects the unconnected pointers to new out state. */
void patch(State **unconn_out_ptrs, State *s)
{
    //out_s->out1 = s;
}
