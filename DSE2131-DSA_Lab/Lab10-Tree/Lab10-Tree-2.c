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

/* traversal output buffer */
int a[128];
int ai;

/* preorder */
void pr(n *r)
{
  if (!r) return;
  a[ai++] = r->v;
  pr(r->l);
  pr(r->r);
}

/* inorder */
void ino(n *r)
{
  if (!r) return;
  ino(r->l);
  a[ai++] = r->v;
  ino(r->r);
}

/* postorder */
void pst(n *r)
{
  if (!r) return;
  pst(r->l);
  pst(r->r);
  a[ai++] = r->v;
}

int cmp_arr(int *b, int bl, int *c, int cl)
{
  if (bl != cl) return 0;
  for (int i = 0; i < bl; i++)
    if (b[i] != c[i]) return 0;
  return 1;
}

void chk(const char *s, int ok)
{
  printf("%s: %s\n", s, ok ? "PASSED" : "FAILED");
}

int main(void)
{
  n *r = NULL;
  int vals[] = {50, 30, 70, 20, 40, 60, 80};
  for (int i = 0; i < 7; i++)
    r = ins(r, vals[i]);

  /* preorder expected: 50 30 20 40 70 60 80 */
  int exp1[] = {50, 30, 20, 40, 70, 60, 80};
  ai = 0;
  pr(r);
  chk("Preorder", cmp_arr(a, ai, exp1, 7));

  /* inorder expected: 20 30 40 50 60 70 80 */
  int exp2[] = {20, 30, 40, 50, 60, 70, 80};
  ai = 0;
  ino(r);
  chk("Inorder", cmp_arr(a, ai, exp2, 7));

  /* postorder expected: 20 40 30 60 80 70 50 */
  int exp3[] = {20, 40, 30, 60, 80, 70, 50};
  ai = 0;
  pst(r);
  chk("Postorder", cmp_arr(a, ai, exp3, 7));

  return 0;
}