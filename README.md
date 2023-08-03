# Pipex 42

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Description](#description)
- [Commands](#commands)
- [Example](#example)


## Introduction

Pipex is a project at [42 ](https://www.42bangkok.com/) that involves reproducing the functionality of the shell command pipeline (`|`) using two commands and an intermediate file. The goal is to redirect the output of the first command as input to the second command, simulating the behavior of a shell pipe.

This project helps to deepen understanding of file descriptors, processes, and system calls in Unix-like operating systems.

## Usage

1. Clone the repository:

```bash
git clone https://github.com/nuttanon172/pipex.git
```
2. Build the project:
```bash
make
```
3. Run pipex:
```bash
./pipex infile cmd1 cmd2 outfile
```

## Description
Pipex takes two commands cmd1 and cmd2, and two filenames infile and outfile. It executes cmd1 with infile as input, redirects the output to an intermediate file, and then executes cmd2 with the intermediate file as input. The final result is saved in outfile.

## Commands

Pipex supports the following commands:

* infile : Input file to be used with the first command.
* cmd1 : First command to be executed.
* cmd2 : Second command to be executed.
* outfile : Output file to store the final result.

## Example

To extract lines containing "example" from file1 and count the occurrences using grep and wc, the following command can be used:

```bash
./pipex file1 "grep example" "wc -l" file2
```