# Text Cross-Reference Generator

This C++ program reads text from a file, generates a cross-reference table of words along with the lines they appear on, and prints the text with line numbers. 

It's a useful tool for quick word and line references in a text document.

## Features

- **Text with Line Numbers**: Displays the original text with line numbers, making it easier to reference specific lines.

- **Cross-Reference Table**: Generates a cross-reference table of words and the lines they appear on.

- **Word Cleaning**: Cleans words by removing non-alphabetic characters and converting them to lowercase for accurate word counts.


## Input File Format
The input file should contain the text you want to process. The program reads and analyzes this text.

### Example Input File:

```
cherry tree tree
Cherry;
mango cherry tree,
apple. %^**(@#
free 324235
```
## Examples
Example command and expected output:

### Text with Line Numbers:

```
1: cherry tree tree
2: Cherry;
3: mango cherry tree,
4: apple. %^**(@#
5: free 324235
```

### Cross-Reference Table:

```
Words:          Lines:
apple           4
cherry          1 2 3
free            5
mango           3
tree            1 3
```
