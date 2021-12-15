# Table of contents
1. [Introduction](#introduction)
2. [Definition of the project](#definition)
3. [Bitwise](#bitwise)
	- [Bitwise operators](#operators)

# Introduction <a name="introduction"></a>
Minitalk is a project developped by myself in ecole 42. The project was developed in C and it was done in about a week. The project introduces sorting unix signals and their usages. The projects also helps teaching basics bitwise operations.

# Definition of The Project <a name="definition"></a>
The goal of the project was to create two different programs, simulating a server and a client.
- The server waits for instruction from the client.
- The client sends instructions in the form of a string and the server must print it.
- We were only able to use SIGURS1 and SIGURS2 to send messages between programs.

# Bitwise <a name="bitwise"></a>
Bitwise is the making of operations on a byte level.
A character in C is usually composed of 1 byte, thus 8 bits.
To perform operations on those bits, we can use the followings operators:

# Bitwise Operators <a name="operators"></a>
- **&** (AND)
```shell
100
101
---
100
```
- **|** (OR)
```shell
100
101
---
101
```

- **^** (XOR)
```shell
100
101
---
001
```

- **~** (NOT)
```shell
101
---
010
```

- **<<** (left shift)
```shell
100<<1
---
010
```

- **<<** (right shift)
```shell
010>>1
---
100
```