# Queue Implementation in C (Imperative ADT Design)

## Overview

This project is a Queue Abstract Data Type (ADT) implemented in the C programming language. The program supports common queue operations such as:

- Insertion (`enqueue`)
- Deletion (`dequeue`)
- Printing the queue
- Getting the queue size
- Reversing the queue

It was developed as a final project for **CS3003: Programming Languages (Summer 2025)** to explore how imperative programming paradigms—particularly in C—affect problem solving and software structure.

---

## Programming Paradigm

This project is built using the **imperative programming paradigm**, where computation is carried out through sequences of explicit commands that change the program’s state.

Key characteristics of imperative programming highlighted in this project include:

- Direct manipulation of memory using pointers
- Procedural code structure
- Lack of built-in data encapsulation or safety
- Manual memory management

---

## Language Features Explored

### **Manual Memory Management**

- Used `malloc()` to allocate memory for queue nodes and strings.
- Paired every allocation with `free()` to prevent memory leaks.

### **Struct-Based ADT Simulation**

- Defined a `Node` and a `Queue` struct to simulate an abstract data type.
- Created a separate header file (`Queue.h`) to define interfaces.

### **Function-Based Encapsulation**

- Each queue operation is implemented as a standalone function.
- Separated concerns between interface (Queue.h), implementation (Queue.c), and usage (QueueRun.c).

### **Pointer Operations**

- Managed linked list behavior through direct pointer manipulation.
- Ensured correct updates to `front`, `rear`, and `next` pointers during insertions, deletions, and reversals.
