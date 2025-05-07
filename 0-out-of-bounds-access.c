#include <string.h>
#include <stdlib.h>

void test(char *p)
{
	p[10] = 'x';
}				/* access a pointer out of range */

static char static_var[1];	/* example static variable */

/* example unchecked module mixed with checked module */
/*   No special preparation is required, even for */
/*   structures containing pointers. */

struct s_tag {
	char *a;
	char *b;
};

void unchecked(struct s_tag *s)
{
	memset(s->a, 0, 2);	/* example of catching checked pointers in */
	memcpy(s->b, s->a, 2);	/* library functions even from unchecked code */
}

int main()
{
	char local_var[1];	/* example stack variable */
	char *heap_var;
	struct s_tag s;
	heap_var = malloc(1);	/* example heap variable */
	test(local_var);	/* access a local variable out of range */
	test(static_var);	/* access a static variable out of range */
	test(heap_var);		/* access a heap variable out of range */
	s.a = local_var;
	s.b = static_var;
	unchecked(&s);		/* pass to a routine in unchecked module */
	return 0;
}
