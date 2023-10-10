# Our own simple shell

This is our self owned  coded simple shell project in C language.

### About

Shell is a user interface to use the services of a computer. It can be a command-line interface –the one we will build- or graphical user interface, like regular software such as Windows Office.

### Compilation
This simple shell is compiled with:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

### Output
This program have exact same output as ```sh``` as well as the exact same error output. The only difference is when it prints an error, the name of the program is equivalent to ```argv[0]```.

#### Example of error with ```sh```:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

#### Error with our program:

```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
### Testing
#### Our shell work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

#### But also in non-interactive mode:
```
$ echo "/bin/ls" | ./a.out
/bin/ls
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
### Examples
```
$ /bin/pwd
/home/wiseman/simple_shell
```

```
$ ls -la
total 60
drwxr-xr-x 1 wiseman wiseman   512 Sep  9 12:24 .
drwxr-x--- 1 wiseman wiseman   512 Sep  9 12:22 ..
-rw-r--r-- 1 wiseman wiseman  2567 Sep  9 12:25 README.md
-rw-r--r-- 1 wiseman wiseman   382 Sep  9 12:11 _getenv.c
-rwxr-xr-x 1 wiseman wiseman 22080 Sep  9 12:13 a.out
-rw-r--r-- 1 wiseman wiseman   221 Sep  9 12:09 free_all.c
-rw-r--r-- 1 wiseman wiseman  1554 Sep  9 12:08 handle_cd.c
-rw-r--r-- 1 wiseman wiseman   360 Sep  9 12:02 handle_comment.c
-rw-r--r-- 1 wiseman wiseman   443 Sep  9 12:00 handle_exit.c
-rw-r--r-- 1 wiseman wiseman   541 Sep  9 11:58 handle_firstarg.c
-rw-r--r-- 1 wiseman wiseman   313 Sep  9 11:25 handle_msg.c
-rw-r--r-- 1 wiseman wiseman   476 Sep  9 11:55 handle_processes.c
-rw-r--r-- 1 wiseman wiseman   704 Sep  9 11:53 handle_separator.c
-rw-r--r-- 1 wiseman wiseman  1420 Sep  9 11:22 handle_setenv.c
-rw-r--r-- 1 wiseman wiseman   779 Sep  9 11:58 handle_unsetenv.c
-rw-r--r-- 1 wiseman wiseman  1218 Sep  9 12:13 handle_vars.c
-rw-r--r-- 1 wiseman wiseman   501 Sep  9 11:32 main.c
-rw-r--r-- 1 wiseman wiseman  1023 Sep  9 12:12 shell.h
$ 
```

```
$ Ethio
./hsh: No such file or directory
```

### Authors
[Wiseman Umanah](https://github.com/wiseman-umanah)

[Jane mathenge](https://github.com/codingbot995)
