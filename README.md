
---

# Simple Unix Util

This repository contains simple reimplementations of common Unix command-line utilities written in C:  
- `cp` – copy files  
- `mv` – move/rename files  
- `pwd` – print the current working directory  
- `echo` – print arguments to standard output  

## Compilation

Use `gcc` to compile each utility individually. Example:

```bash
gcc -o cp cp.c
gcc -o mv mv.c
gcc -o pwd pwd.c
gcc -o echo echo.c
```

This will generate the executable files `cp`, `mv`, `pwd`, and `echo`.

## Usage Examples

### `cp`

```bash
./cp source.txt destination.txt
```

Copies `source.txt` to `destination.txt`.

---

### `mv`

```bash
./mv oldname.txt newname.txt
```

Renames or moves `oldname.txt` to `newname.txt`.

---

### `pwd`

```bash
./pwd
```

Prints the absolute path of the current directory.

---

### `echo`

```bash
./echo Hello World!
```

Prints:  
```
Hello World!
```

---
