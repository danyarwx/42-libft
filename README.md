# libft — My 42 C Utility Library

![Library of Alexandria](assets/library.png)

A lightweight re-implementation of common C standard library routines plus a few convenience utilities and a singly-linked list API (“bonus”). It compiles into a static library you can link against in any C project.

---

## Contents

- [Why this exists](#why-this-exists)  
- [Build & use](#build--use)  
- [Header](#header)  
- [Function overview](#function-overview)
  - [Character checks & case](#character-checks--case)
  - [Memory](#memory)
  - [Strings](#strings)
  - [Conversion & allocation helpers](#conversion--allocation-helpers)
  - [File descriptor output](#file-descriptor-output)
  - [Linked list (bonus)](#linked-list-bonus)
- [Examples](#examples)
- [Makefile targets](#makefile-targets)
- [Project structure](#project-structure)
- [License](#license)

---

## Why this exists

The 42 *libft* project builds foundational C skills by re-creating a subset of `<ctype.h>`, `<string.h>`, and related utilities, then extending them with safe helpers and a minimal linked-list module.

---

## Build & use

```bash
# Build the base library
make

# Build with bonus (linked list) functions included
make bonus
```

This produces `libft.a`.

Link it in your programs:

```bash
gcc -Wall -Wextra -Werror main.c -L. -lft -I .
# or explicitly
gcc main.c ./libft.a -I .
```

> **Tip:** Always include the header in your sources:
```c
#include "libft.h"
```

---

## Header

All function prototypes and type definitions are in **`libft.h`**.

---

## Function overview

### Character checks & case

| Function | Purpose |
|---|---|
| `ft_isalpha(int c)` | Non-zero if `c` is an alphabetic character. |
| `ft_isdigit(int c)` | Non-zero if `c` is a decimal digit. |
| `ft_isalnum(int c)` | Non-zero if `c` is alphanumeric. |
| `ft_isascii(int c)` | Non-zero if `c` is in the ASCII range `[0,127]`. |
| `ft_isprint(int c)` | Non-zero if `c` is printable (incl. space). |
| `ft_toupper(int c)` | Uppercases ASCII letters; others unchanged. |
| `ft_tolower(int c)` | Lowercases ASCII letters; others unchanged. |

### Memory

| Function | Purpose |
|---|---|
| `ft_memset(void *s, int c, size_t n)` | Fill memory with byte `c`. |
| `ft_bzero(void *s, size_t n)` | Set `n` bytes to zero. |
| `ft_memcpy(void *dst, const void *src, size_t n)` | Copy `n` bytes (no overlap). |
| `ft_memmove(void *dst, const void *src, size_t len)` | Copy `len` bytes (handles overlap). |
| `ft_memchr(const void *s, int c, size_t n)` | Find byte `c` within first `n` bytes. |
| `ft_memcmp(const void *s1, const void *s2, size_t n)` | Lexicographically compare memory. |
| `ft_calloc(size_t count, size_t size)` | Allocate zero-initialized block (`count * size`). |

### Strings

| Function | Purpose |
|---|---|
| `ft_strlen(const char *s)` | Length of a C-string. |
| `ft_strlcpy(char *dst, const char *src, size_t dstsize)` | Size-bounded copy; NUL-terminates. |
| `ft_strlcat(char *dst, const char *src, size_t dstsize)` | Size-bounded concatenation. |
| `ft_strchr(const char *s, int c)` | First occurrence of `c` in `s` (or `NULL`). |
| `ft_strrchr(const char *s, int c)` | Last occurrence of `c` in `s`. |
| `ft_strncmp(const char *s1, const char *s2, size_t n)` | Compare up to `n` chars. |
| `ft_strnstr(const char *hay, const char *need, size_t len)` | Substring search within `len`. |
| `ft_strdup(const char *s)` | Duplicate string to new allocation. |
| `ft_substr(char const *s, unsigned int start, size_t len)` | Extract substring. |
| `ft_strjoin(char const *s1, char const *s2)` | Join two strings into a new one. |
| `ft_strtrim(char const *s1, char const *set)` | Trim characters in `set` from both ends. |
| `ft_split(char const *s, char c)` | Split on delimiter `c` → `char **` (NULL-terminated). |
| `ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Map function over string → new string. |
| `ft_striteri(char *s, void (*f)(unsigned int, char*))` | In-place iterate and apply function. |

### Conversion & allocation helpers

| Function | Purpose |
|---|---|
| `ft_atoi(const char *nptr)` | Convert ASCII string to `int` (like `atoi`). |
| `ft_itoa(int n)` | Convert integer to newly allocated string. |

### File descriptor output

| Function | Purpose |
|---|---|
| `ft_putchar_fd(char c, int fd)` | Write a character to file descriptor `fd`. |
| `ft_putstr_fd(char const *s, int fd)` | Write a string to `fd`. |
| `ft_putendl_fd(char const *s, int fd)` | Write string + newline to `fd`. |
| `ft_putnbr_fd(int n, int fd)` | Write decimal representation of `n` to `fd`. |

### Linked list (bonus)

All bonus routines operate on a simple singly-linked list type:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Purpose |
|---|---|
| `ft_lstnew(void *content)` | Create a new node. |
| `ft_lstadd_front(t_list **lst, t_list *new)` | Push to front. |
| `ft_lstadd_back(t_list **lst, t_list *new)` | Append to end. |
| `ft_lstlast(t_list *lst)` | Return last node. |
| `ft_lstsize(t_list *lst)` | Count nodes. |
| `ft_lstdelone(t_list *lst, void (*del)(void*))` | Delete one node using `del`. |
| `ft_lstclear(t_list **lst, void (*del)(void*))` | Clear and free entire list. |
| `ft_lstiter(t_list *lst, void (*f)(void *))` | Apply `f` to each node’s content. |
| `ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))` | Map to a new list; frees on failure. |

> **Building with bonus:** run `make bonus` (it compiles the list module and adds it to `libft.a`).

---

## Makefile targets

| Target | Description |
|---|---|
| `make` | Build `libft.a` with mandatory functions. |
| `make bonus` | Add bonus list functions and rebuild `libft.a`. |
| `make clean` | Remove object (`.o`) files. |
| `make fclean` | Remove objects and `libft.a`. |
| `make re` | `fclean` then `make`. |

---

## Project structure

```
libft/
├── Makefile
├── libft.h
├── ft_*.c                # Mandatory & additional utilities
└── ft_lst*.c             # Bonus: linked list API
```

---

## License

This repository is for the **42 school libft** educational project. Unless your campus requires otherwise, you may use it for learning and personal projects. If you adapt/publish, credit is appreciated.
