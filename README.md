# CS 152 Compiler Design with Flex and Bison

CS 152 Compiler Design with Flex and Bison repository has [Ukrainian :ukraine:](#cs-152-compiler-design-with-flex-and-bison-ukraine) and [English :uk:](#cs-152-compiler-design-with-flex-and-bison-uk) localizations

## CS 152 Compiler Design with Flex and Bison :ukraine:

**_Швидкий перехід по розділам_**

- [CS 152 Compiler Design with Flex and Bison](#cs-152-compiler-design-with-flex-and-bison)
  - [CS 152 Compiler Design with Flex and Bison :ukraine:](#cs-152-compiler-design-with-flex-and-bison-ukraine)
    - [Про проект](#про-проект)
    - [Вимоги](#вимоги)
    - [Інструкції з використання](#інструкції-з-використання)
    - [Посилання на оригінальні джерела](#посилання-на-оригінальні-джерела)
  - [CS 152 Compiler Design with Flex and Bison :uk:](#cs-152-compiler-design-with-flex-and-bison-uk)
    - [About](#about)
    - [Requirements](#requirements)
    - [Usage](#usage)
    - [Links to original sources](#links-to-original-sources)

### Про проект

Цей проєкт є результатом вивчення курсу "CS 152 Compiler Design with Flex and Bison" за матеріалами з [YouTube плейлиста](https://www.youtube.com/playlist?list=PL2fmKE0pL4IyKXQCFvav6up5h5lMBDWfd), у якому [danieltan1517](https://github.com/danieltan1517) подає основи побудови компіляторів, використовуючи інструменти Flex і Bison.

Даний компілятор використовується для простої імперативної мови програмування, створеного з використанням інструментів Flex і Bison. Компілятор перетворює вхідну програму на проміжний код, який потім може бути виконаний інтерпретатором.

### Вимоги

Проект використовує такі залежності:

- flex (2.6.4)
- bison (3.8.2)
- C++ компілятор (g++ 13.2.1)

### Інструкції з використання

Для використання компілятора необхідно виконати такі кроки:

1. Клонуйте репозиторій на свій комп'ютер.

```bash
git clone git clone https://github.com/NikitaBerezhnyj/CS-152.git
```

2. Виконайте команду для збірки проєкту.

```bash
make
```

3. Запустіть скомпільовану програму з введенням вашої мови програмування.

```bash
./a.out < example.txt > a.mil
```

4. Запустіть mil інтерпретатор для запуску отриманого коду

```bash
./mil_run a.mil
```

### Посилання на оригінальні джерела

- **_GitHub автора:_** [https://github.com/danieltan1517](https://github.com/danieltan1517)

- **_Веб-сайт з курсом:_** [https://www.cs.ucr.edu/~dtan004/](https://www.cs.ucr.edu/~dtan004/)

- **_YouTube плейлист:_** [https://www.youtube.com/playlist?list=PL2fmKE0pL4IyKXQCFvav6up5h5lMBDWfd](https://www.youtube.com/playlist?list=PL2fmKE0pL4IyKXQCFvav6up5h5lMBDWfd)

## CS 152 Compiler Design with Flex and Bison :uk:

### About

This project is the result of studying the course "CS 152 Compiler Design with Flex and Bison" based on materials from the [YouTube playlist](https://www.youtube.com/playlist?list=PL2fmKE0pL4IyKXQCFvav6up5h5lMBDWfd), in which [danieltan1517](https://github.com/danieltan1517) presents the basics of building compilers using the Flex and Bison tools.

This compiler is used for a simple imperative programming language created using the Flex and Bison tools. The compiler converts an input program into intermediate code that can then be executed by an interpreter.

### Requirements

The project uses the following dependencies:

- flex (2.6.4)
- bison (3.8.2)
- C++ компілятор (g++ 13.2.1)

### Usage

To use the compiler, you need to perform the following steps:

1. Clone the repository to your computer.

```bash
git clone git clone https://github.com/NikitaBerezhnyj/CS-152.git
```

2. Run the command to build the project.

```bash
make
```

3. Run the compiled program by entering your programming language.

```bash
./a.out < example.txt > a.mil
```

4. Run the mil interpreter to run the resulting code

```bash
./mil_run a.mil
```

### Links to original sources

- **_GitHub of the author:_** [https://github.com/danieltan1517](https://github.com/danieltan1517)

- **_Website with the course:_** [https://www.cs.ucr.edu/~dtan004/](https://www.cs.ucr.edu/~dtan004/)

- **_YouTube playlist:_** [https://www.youtube.com/playlist?list=PL2fmKE0pL4IyKXQCFvav6up5h5lMBDWfd](https://www.youtube.com/playlist?list=PL2fmKE0pL4IyKXQCFvav6up5h5lMBDWfd)
