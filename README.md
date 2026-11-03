# English Dictionary

A C++ project that implements an English dictionary using templates and a doubly linked list.

## Features

- Add words and definitions
- Store multiple definitions for the same word
- Find the first definition of a word
- Find all definitions of a word
- Delete the first definition
- Delete all definitions of a word
- Print the dictionary forward and backward
- Count total entries and unique words

## Data Structures and Concepts

This project uses:

- C++ templates
- Doubly linked lists
- Iterators
- Ranges
- Dynamic memory
- Operator overloading
- Recursion
- Header guards

## Project Files

- `Entry.h` — stores one key-value pair
- `DNodeG.h` — represents one node in the doubly linked list
- `IteratorG.h` — moves through the linked list
- `Range.h` — stores the beginning and end of a range of entries
- `NodeDictionaryG.h` — implements the main dictionary data structure and operations
- `EnglishDictionary.h` — provides a simple interface for English words and definitions
- `main.cpp` — demonstrates and tests the dictionary

## How It Works

Each dictionary entry stores a word as the key and its definition as the value.  
The entries are stored in nodes of a doubly linked list. Iterators are used to move through the list, and ranges are used to work with groups of entries such as all definitions of the same word.

## Author

Elena Chagaeva
