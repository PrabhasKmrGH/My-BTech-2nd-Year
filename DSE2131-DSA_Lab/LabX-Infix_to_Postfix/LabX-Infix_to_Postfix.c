/*
TODO: expand
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int prec(char c)
{
  if (c == '+' || c == '-') return 1;
  if (c == '*' || c == '/') return 2;
  if (c == '^') return 3;
  return 0;
}

/* right-assoc for ^ */
int is_right_assoc(char c)
{
  return c == '^';
}

char *inf2post(const char *s)
{
  int n = strlen(s);
  char *out = malloc(n + 2);
  char *st  = malloc(n + 2);
  int oi = 0, si = 0;

  for (int i = 0; i < n; i++) {
    char c = s[i];
    if (isspace((unsigned char)c)) continue;
    if (isalnum((unsigned char)c)) {
      out[oi++] = c;
      continue;
    }
    if (c == '(') {
      st[si++] = c;
      continue;
    }
    if (c == ')') {
      while (si && st[si - 1] != '(')
        out[oi++] = st[--si];
      if (si && st[si - 1] == '(') si--;
      continue;
    }
    /* operator */
    while (si && st[si - 1] != '(') {
      int p1 = prec(st[si - 1]);
      int p2 = prec(c);
      if (p1 > p2 || (p1 == p2 && !is_right_assoc(c))) {
        out[oi++] = st[--si];
      } else break;
    }
    st[si++] = c;
  }

  while (si) out[oi++] = st[--si];
  out[oi] = '\0';
  free(st);
  return out;
}

void chk(const char *s, int ok)
{
  printf("%s: %s\n", s, ok ? "PASSED" : "FAILED");
}

int main(void)
{
  char *s, *r;

  s = "a+b*c";
  r = inf2post(s);
  chk("Test 1 a+b*c", strcmp(r, "abc*+") == 0);
  free(r);

  s = "(a+b)*c";
  r = inf2post(s);
  chk("Test 2 (a+b)*c", strcmp(r, "ab+c*") == 0);
  free(r);

  s = "a+b-c";
  r = inf2post(s);
  chk("Test 3 a+b-c", strcmp(r, "ab+c-") == 0);
  free(r);

  s = "a*b+c";
  r = inf2post(s);
  chk("Test 4 a*b+c", strcmp(r, "ab*c+") == 0);
  free(r);

  s = "(a+(b*c-(d/e^f)*g)*h)";
  r = inf2post(s);
  chk("Test 5 complex (non-empty)", r && strlen(r) > 0);
  free(r);

  return 0;
}