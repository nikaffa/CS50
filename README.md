# CS50
Some of my projects on C and Python I made during CS50 course:

## Caesar
Caesar is a program on C that enables you to encrypt messages using Caesar’s cipher. 
Caesar (yes, that Caesar) used to “encrypt” confidential messages by shifting each letter therein by some number of places. Upon receiving such messages from Caesar, recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places.
Using this program, the user should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime.
For example, if the user inputs a key of **`1`** and a plaintext of **`HELLO`**:
```bash
$ ./caesar 1
plaintext:  HELLO
ciphertext: IFMMP
```
## Speller

## Filter

## Recover
Recover is a program in C that recovers JPEGs from a forensic image stored in a file called  **`card.raw`**.
Aftre running the program you should ultimately find that the image contains 50 JPEGs.

#### Usage
Compile the file and run the program by specifying the name of the image as a command-line argument:
```bash
cd recover
make recover
./recover card.raw
```


## Inheritance


## Readability
Readability figures out what the reading level of a text is. For example:
```bash
$ ./readability
Text: Congratulations! Today is your day. You\'re off to Great Places! You\'re off and away!
Grade 3
```
```bash
$ ./readability
Text: As the average number of letters and words per sentence increases, the Coleman-Liau index gives the text a higher reading level. If you were to take this paragraph, for instance, which has longer words and sentences than either of the prior two examples, the formula would give the text an eleventh grade reading level. 
Grade 11
```
The allgorithm is based on the Coleman-Liau index which designed to output what grade level is needed to understand the text. The formula is: **`index = 0.0588 * L - 0.296 * S - 15.8`**

## DNA

## Tournament
