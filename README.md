# Projects on C
Some of my projects on C that I made during CS50 course.

## Caesar (an assignment on Arrays)
Caesar is a program on C that enables you to encrypt messages using Caesar’s cipher. 
Caesar (yes, that Caesar) used to “encrypt” confidential messages by shifting each letter therein by some number of places. Upon receiving such messages from Caesar, recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places.
Using this program, the user should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime.
For example, if the user inputs a key of **`1`** and a plaintext of **`HELLO`**:
```bash
$ ./caesar 1
plaintext:  HELLO
ciphertext: IFMMP
```

## Speller (an assignment on Data Structures - Hash Tables)
Speller is a program that spell-checks a file using a dictionary of words. The algorithm designed as a hash table. Along with the spell-checking it's also benchmarking (i.e., timing the execution of) the program implementation in order to study time complexity.
The challenge of this assignment was to implement the program as efficiently as possible using a hash table in such a way that TIME IN load, TIME IN check, TIME IN size, and TIME IN unload are all minimized. 
You can test the implementation of the program with a whole bunch of texts, for example, the script from La La Land, the text of the Affordable Care Act, three million bytes from Tolstoy, some excerpts from The Federalist Papers and Shakespeare, and more.
As an output, it reports each misspelling in that file along with a bunch of statistics.

```bash
MISSPELLED WORDS

Chazelle
L
TECHNO
L
Thelonious
Prius
MIA
Mia
AHHHHHHHHHHHHHHHT

WORDS MISSPELLED:     955
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        17756
TIME IN load:         0.02
TIME IN check:        0.01
TIME IN size:         0.00
TIME IN unload:       0.00
TIME IN TOTAL:        0.04
```
#### Usage
Compile the file and run the program by specifying the name of the file as a command-line argument:
```bash
cd recover
make speller
./speller texts/lalaland.txt
```
You can also “redirect” your program’s output to a file, as with the below:
**`./speller texts/lalaland.txt > result.txt`**

#### Testing
You can find my statistics in **`student.txt`** and the CS50 staff's statistics in **`staff.txt`**
Tou can then compare your results with mine in the same window, as with the below:
**`diff -y result.txt student.txt`**


## Inheritance (an assignment on Data Structures - Linked List, and recursion)
Inheritance is a program on C that simulates the inheritance of blood types for each member of a family.
As known, a person’s blood type is determined by two alleles (i.e., different forms of a gene). The child should have two alleles, one from each parent. The parents should each have two alleles, one from each of their parents.
The program creates a family of a specified generation size and assigns blood type alleles to each family member. The oldest generation will have alleles assigned randomly to them.
For example, in the example below, the child in Generation 0 received an O allele from both Generation 1 parents. The first parent received an A from the first grandparent and a O from the second grandparent. Similarly, the second parent received an O and a B from their grandparents.
```bash
./inheritance
Generation 0, blood type OO
    Generation 1, blood type AO
        Generation 2, blood type OA
        Generation 2, blood type BO
    Generation 1, blood type OB
        Generation 2, blood type AO
        Generation 2, blood type BO
```
#### Usage
Compile the file and run the program:
```bash
cd inheritance
make inheritance
./inheritance
```


## Filter (an assignment on Memory and Memory Allocation)
["Find it here "](https://github.com/nikaffa/Projects-on-C/tree/master/filter)

## Recover (an assignment on Memory and Memory Allocation)
Recover is a program on C that recovers JPEGs from a forensic image stored in a file called  **`card.raw`**.
Aftre running the program you should ultimately find that the image contains 50 JPEGs.

#### Usage
Compile the file and run the program by specifying the name of the image as a command-line argument:
```bash
cd recover
make recover
./recover card.raw
```

