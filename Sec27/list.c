#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct List
{
  struct Link *first;
  struct Link *last;
};

struct Link
{
  struct Link *pre;
  struct Link *suc;
};

void init(struct List *lst)
{
  assert(lst);
  lst->first = lst->last = 0;
}

struct List *create()
{
  struct List *lst = (struct List *)malloc(sizeof(struct List));
  init(lst);
  return lst;
}

void clear(struct List *lst)
{
  assert(lst);
  struct Link *curr = lst->first;
  while (curr)
  {
    struct Link *next = curr->suc;
    free(curr);
    curr = next;
  }
  lst->first = lst->last = 0;
}

void destroy(struct List *lst)
{
  assert(lst);
  clear(lst);
  free(lst);
}

void push_back(struct List *lst, struct Link *p)
{
  assert(lst);
  assert(p);
  struct Link *last = lst->last;
  if (last)
  {
    last->suc = p;
    p->pre = last;
  }
  else
  {
    lst->first = p;
    p->pre = 0;
  }
  lst->last = p;
  p->suc = 0;
}

struct Link *erase(struct List *lst, struct Link *p)
{
  assert(lst);
  if (p == 0)
  {
    return 0;
  }
  if (p == lst->first)
  {
    if (p->suc)
    {
      lst->first = p->suc;
      p->suc->pre = 0;
      return p->suc;
    }
    else
    {
      lst->first = lst->last = 0;
      return 0;
    }
  }
  else if (p == lst->last)
  {
    if (p->pre)
    {
      lst->last = p->pre;
      p->pre->suc = 0;
    }
    else
    {
      lst->first = lst->last = 0;
    }
    return 0;
  }
  else
  {
    p->suc->pre = p->pre;
    p->pre->suc = p->suc;
    return p->suc;
  }
}

struct Name
{
  struct Link lnk;
  char *p;
};

struct Name *make_name(char *n)
{
  struct Name *p = (struct Name *)malloc(sizeof(struct Name));
  p->p = n;
  return p;
}

void flush(struct List *lst)
{
  int cnt = 0;
  struct Link *curr = lst->first;
  for (; curr; curr = curr->suc)
  {
    printf("No. %d: %s\n", cnt++, ((struct Name *)curr)->p);
  }
}

int main()
{
  struct List names;
  init(&names);
  push_back(&names, (struct Link *)make_name("Nagao Kagetora"));
  push_back(&names, (struct Link *)make_name("Sakamoto Ryoma"));
  push_back(&names, (struct Link *)make_name("Chacha"));
  push_back(&names, (struct Link *)make_name("Oda Nobunaga"));
  flush(&names);
  struct Link *curr = names.first->suc;
  erase(&names, curr);
  flush(&names);
}