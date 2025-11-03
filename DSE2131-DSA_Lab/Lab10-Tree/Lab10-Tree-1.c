/*
TODO: expand
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct n {
  int v;
  struct n *l, *r;
} n;

n *mk(int v)
{
  n *t = malloc(sizeof *t);
  if (!t) return NULL;
  t->v = v;
  t->l = t->r = NULL;
  return t;
}

n *ins(n *r, int v)
{
  if (!r) return mk(v);
  if (v < r->v)
    r->l = ins(r->l, v);
  else if (v > r->v)
    r->r = ins(r->r, v);
  return r;
}

n *mn(n *r)
{
  while (r && r->l)
    r = r->l;
  return r;
}

n *deln(n *r, int v)
{
  if (!r) return NULL;
  if (v < r->v)
    r->l = deln(r->l, v);
  else if (v > r->v)
    r->r = deln(r->r, v);
  else {
    if (!r->l || !r->r) {
      n *t = r->l ? r->l : r->r;
      free(r);
      return t;
    }
    n *s = mn(r->r);
    r->v = s->v;
    r->r = deln(r->r, s->v);
  }
  return r;
}

n *srch(n *r, int v)
{
  if (!r) return NULL;
  return (v == r->v) ? r : (v < r->v ? srch(r->l, v) : srch(r->r, v));
}

void freet(n *r)
{
  if (!r) return;
  freet(r->l);
  freet(r->r);
  free(r);
}

/* test helper */
void chk(const char *s, int ok)
{
  printf("%s: %s\n", s, ok ? "PASSED" : "FAILED");
}

int main(void)
{
  n *r = NULL;

  /* Test 1: insert 10 */
  r = ins(r, 10);
  chk("Test1 - ins 10", r && r->v == 10);

  /* Test 2: insert 20 */
  r = ins(r, 20);
  chk("Test2 - ins 20", r->r && r->r->v == 20);

  /* Test 3: search 20 */
  chk("Test3 - srch 20", srch(r, 20) != NULL);

  /* Test 4: delete 20 */
  r = deln(r, 20);
  chk("Test4 - del 20", srch(r, 20) == NULL && r && r->v == 10);

  /* Test 5: delete root 10 */
  r = deln(r, 10);
  chk("Test5 - del 10", r == NULL);

  freet(r);
  return 0;
}