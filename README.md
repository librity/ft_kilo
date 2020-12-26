# ft_kilo

> "Programs do one thing, do it well, and act on files."
> Some bearded nerd in the 70's

CLI text editor written in C, following 42's Norminette. Inspired by:

- https://github.com/antirez/kilo/blob/master/kilo.c
- https://viewsourcecode.org/snaptoken/kilo/

## Resources

- https://www.tutorialspoint.com/cprogramming/c_data_types.htm
- https://stackoverflow.com/questions/31119606/expression-is-not-an-integer-constant-expression-in-ios-objective-c

- https://github.com/Gegel85/norminette/tree/master/tests
- http://check.sourceforge.net/doc/check_html/check_2.html#SEC3
- https://stackoverflow.com/questions/65820/unit-testing-c-code
- https://notes.eatonphil.com/unit-testing-c-code-with-gtest.html

- https://en.wikipedia.org/wiki/Makefile
- https://opensource.com/article/19/7/structure-multi-file-c-part-1

- https://vt100.net/docs/vt100-ug/chapter3.html#ED
- https://en.wikipedia.org/wiki/VT100
- http://ascii-table.com/control-chars.php
- https://en.wikipedia.org/wiki/Ncurses
- https://en.wikipedia.org/wiki/Terminfo

## Compile and Run

Using `make`:

```bash
$ make && ./kilo
$ make clean
```

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
$ norminette *.c **/*.c **/*.h
```

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

## [termios.h](https://man7.org/linux/man-pages/man0/termios.h.0p.html)

Contains the definitions used by the terminal I/O interfaces.

- `IXON`: input bitflag that enables `XOFF` and `XON` signal, `Ctrl-S` and
  `Ctrl-Q` respectively.
- `ICRNL`: input bitflag that enables the terminal to interpret a carriage
  return as a new line.
- `BRKINT`: input bitflag sends a `SIGINT` signal to the program whenever it
  reaches a break condition.
- `INPCK`: input bitflag that enables parity checking.
- `ISTRIP`: input bitflag that "strips" the 8th bit of each input byte, i.e.,
  sets it to 0.

- `OPOST`: output bitflag that enables post-processing of output, like `\n` into
  `\r\n`. When we disable it, the terminal emulator doesn't input a carriage
  return after every new line and the output "stairs down" the terminal.

- `CS8`: bit mask that sets the character size (CS) to 8 bits per byte.

- `ECHO`: local [bitflag](https://en.wikipedia.org/wiki/Bit_field) that causes
  each key you type to be printed to the terminal. Disabling it no longer prints
  everything we type on the terminal.
- `ICANON`: local bitflag that enables canonical mode, i.e., reads input
  line-by-line. Disabling it allows us to read input byte-by-byte.
- `ISIG`: local bitflag that enables `SIGINT` and `SIGTSTP` signal, `Ctrl-C`
  and `Ctrl-Z` respectively.
- `IEXTEN`: local bitflag that enables `Ctrl-V` and `Ctrl-O` signals, that
  interpret the next character as a literal.

- `VMIN`: control character index that represents the minimun number of bytes
  that `read()` reads before returning.
- `VTIME`: control character index that represents the timeout of `read()` in
  tenths of a second.

## [sys/ioctl.h](https://man7.org/linux/man-pages/man2/ioctl.2.html)

- `TIOCGWINSZ`: TerminalInputOutputControlGetWINdowSiZe
