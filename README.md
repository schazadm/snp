# SNP - Laboratory Planning
<img align="right" title="zhaw.ch" width="176" height="92" src="en-zhaw-ines-rgb.png">

### Description
TODO

### Views
[Github-Pages](https://github.zhaw.ch/pages/SNP/snp/)

[.pdf](https://github.zhaw.ch/SNP/snp-lab-code/blob/master/main.pdf)

## Is-State


| Requirements | Chapter | Lecture Contents | Previous Knowledge | Lab handling | FS21 Lab | Comments | Lab Contents |
| :-- | :-- | :--------: | :--: | :--: | :--: | :--: | :--: |
|| Chapter 1<img width=300/>|<img width=150/>|<img width=100/>|<img width=50/>|<img width= 500/>||<img width=200/>|
|Sie können ein single-file C Programm von Grund auf programmieren. |  | C Programmelemente | no | implicit | --  | | Hello world |
|Sie binden Teile der C Standard Library mit include ein und setzen Macros ein.|  | include, define | no | implicit | --  | | Umwandlungstabelle |
|Sie verwenden Input- und Output-Funktionen für strukturierte Ein- und Ausgabe.|  | Input/Output | no | implicit | -- || word count |
|| ||||Bash Script|||
|| Chapter 2|||||||
|Sie haben die Kompetenz kleinere Programme in C zu verstehen, zu programmieren und zu testen.||comments|yes|implicit|*bit operations*||comments|
|||variables|yes|implicit|QR-Code output|defines|variables|
|||data types|yes|explicit||fputs|data types|
|||literals|yes|implicit| |getchar|literals|
|||operators|yes|implicit| |switch-case|operators|
|||expressions|yes|implicit| Bash script|pipe|expressions|
|||control structures|yes|implicit| |qrencode|control structures|
|||formatted I/O functions|no|explicit| ||printf|
|||complex data types|no|explicit| ||scanf|
||| enums|yes|explicit| ||complex data types|
||| structures|no|explicit| ||enums|
||| ||| ||structures|
|| Chapter 3|||||||
||| functions|no|explicit|Wochentag |enum|functions|
||| by value|yes|explicit| |typedef|by value|
||| variable scope|in principle|explicit| |scanf|variable scope|
||| declarations, definitions|in principle|explicit| |struct|declarations, definitions|
||| ||| |function||
||| ||| |control strcutures||
|| Chapter 4|||||||
||| pre-processor/compiler …|no|explicit|Modularisation |header files|pre-processor/compiler …|
||| modularity in C|no|explicit| |include guards|modularity in C|
||| libraries|no|explicit| |makefiles|libraries|
|Sie verfügen über die Voraussetzungen um grössere Programme zu verstehen, anzupassen und erstellen und testen zu können.  || C standard library|no|explicit| ||C standard library|
||| make|no|explicit| ||make|
|| Chapter 5|||||||
|Sie können die Funktionsweise des sizeof Operators erklären und ihn anwenden.|| sizeof|no|explicit|TicTacToe |sizeof|sizeof|
|Sie wissen wie Arrays in C aufgebaut und im Speicher angelegt werden und wie auf sie zugegriffen werden kann. || arrays|no|explicit| TicTacToe|arrays|
|Sie verstehen die Darstellung von Strings und ihre Ähnlichkeit zu char-Arrays und können die wichtigsten String Funktionen der Standard Library einsetzen. || strings|no|no| |||
|| Chapter 6|||||||
||| pointers|no|explicit|Integer Rechner |pointers to struct|pointers|
||| pointer and arrays|no|explicit||memory management|pointer and arrays|
|Sie verstehen die Speicherverwaltungskonzepte und können den Speichergebrauch optimieren.|| memory management|no|explicit||pointer arithmetic|memory management|
|| Chapter 7|||||||
||| paramaters by reference|no|explicit|__Personen Verwaltung__|pointers|paramaters by reference|
||| multidimensional arrays|no|explicit| |memory management|multidimensional arrays|
||| variable paramaters|no|none| |linked lists|variable paramaters|
||| code issues C|no|none| ||code issues C|
||| test|yes|explicit| ||test|
|| Chapter 8|||||||
||| System Calls|no|explicit|Bash Script|memory management|System Calls|
||| C compiler implementation|no|none| |stdlib|C compiler implementation|
||| File hierarchy|no|none| |file handling|File hierarchy|
|Sie können die Operation eines File-Systems erklären und die entsprechenden System-Aufrufe anwenden. || files and file I/O|no|explicit| |directories|files and file I/O|
|| Chapter 9|||||||
|Sie verstehen die Konzepte von Prozessen und Threads und können diese fachgerecht einsetzen und testen. Sie können mit Synchronisierungs-Methoden und Inter-Prozess-Kommunikation arbeiten. || processes|no|explicit|__Processes and Threads__ |fork|processes|
||| threads|yes|explicit| |pthreads|threads|
|| Chapter 10|||||||
||| pipes|no|explicit| ||pipes|
||| sockets|no|none| ||sockets|
||| shared memory|no|explicit| ||shared memory|
||| message passing|no|explicit| ||message passing|
||| signals|no|explicit| ||signals|
|| Chapter 11|||||||
||| mutex|no|explicit| ||mutex|
||| semaphores|no|explicit| ||semaphores|
|| Chapter 12|||||||
|Sie beherrschen den Umgang mit POSIX-Clocks und hochauflösenden Timern. || ||| |||
|| Chapter 13|||||||
|| Chapter 14|||||||
||| multicore basics||| ||multicore basics|


## Target-State

|Week|Lab|Name|Requirement|Number of files|Preprocessor|Compiler|Build|Function|Boilerplate|Lecturer|
|:--|:--|:--:|:--|:--|:--|:--|:--|:--|:--|:--|
|Week 1<img width=200/>|Lab1<img width=100/>|Erste Schritte mit C|single file, includes, defines, command line compile, output Hello world from scratch<img width=300/>|one<img width=100/>|include define<img width=200/>|command line<img width=300/>|no<img width=100/>|output (input?)<img width=100/>|no<img width=100/>|welo<img width=100/>|
|Week 2|Lab2|Funktionen, Datentyp "enum"| enum functions |||make|||yes|bazz|
|Week 3|Lab3|Bit Operation struct typedef| struct typedef bit operations |||||||fisa|
|Week 4|Lab4|Modularisieren von C Code| C/H files input guard Makefile |||||||huno|
|Week 5|Lab5|TicTacToe| complete an existing multi file program using the sizeof operator, arrays (and manipulating strings?)|multi||make||sizeof arrays (strings?)||grop|
|Week 6|Lab6|Personen Verwaltung Linked List| ability to program a multi file program using data pointers and variable input from scratch|multi|guards|extend make|yes|data pointers variable input|no|donn|
|Week 8|Lab7||Prozesse und Threads|||||||donn|
|Week 10|Lab8|Sync|Synchronisation|||||||donn|
|Week 12|Lab9||File Operations|||||||scia|
|Week 13|Lab10||IPC|||||||scia|
|Week 14|Lab11|Bash|Bash|||||||stsh|
