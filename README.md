# ft_kilo

> "Programs do one thing, do it well, and act on files."
> Some bearded nerd in the 70's

CLI text editor written in C, following 42's Norminette. Inspired by:

- https://github.com/antirez/kilo/blob/master/kilo.c
- https://viewsourcecode.org/snaptoken/kilo/

## [Norminnette](https://github.com/42Paris/norminette)

1. Install

```bash
$ git clone https://github.com/42Paris/norminette.git ~/.norminette/
$ cd ~/.norminette/
$ bundle

$ echo 'alias norminette="~/.norminette/norminette.rb"' >> ~/.bash_profile
$ source ~/.bash_profile
```

2. Run

```bash
$ norminette *.c *.h
```

## Compile and Run

```bash
$ cc -Wall -Wextra -Werror -pedantic -std=c99 *.c -o kilo && ./kilo
```

Using `make`:

```bash
$ make && ./kilo
$ make clean
```

## Resources

- https://github.com/Gegel85/norminette/tree/master/tests
- http://check.sourceforge.net/doc/check_html/check_2.html#SEC3
- https://stackoverflow.com/questions/65820/unit-testing-c-code
- https://notes.eatonphil.com/unit-testing-c-code-with-gtest.html
- https://opensource.com/article/19/7/structure-multi-file-c-part-1
- https://en.wikipedia.org/wiki/Makefile

## Makefile

- `$(CC)` is a variable that make expands to cc by default.
- `-Wall` stands for “all Warnings”, and gets the compiler to warn you when it
sees code in your program that might not technically be wrong, but is considered
bad or questionable usage of the C language, like using variables before
initializing them.
- `-Wextra`, `-Werror` and `-pedantic` turn on even more warnings. For each step
in this tutorial, if your program compiles, it shouldn’t produce any warnings
except for “unused variable” warnings in some cases. If you get any other
warnings, check to make sure your code exactly matches the code in that step.
- `-std=c99` specifies the exact version of the C language standard we’re using,
which is C99. C99 allows us to declare variables anywhere within a function,
whereas ANSI C requires all variables to be declared at the top of a function or
block.

## Commands

```bash
# Get the return of the last executed command:
$ echo $?
```
