# Core Systems Lab

> "Do not reinvent the wheel." - They say.  
> "Reinvent the wheel to understand how it rolls." - This repository.

## Introduction

This repository serves as a centralized archive for an intensive 8-week winter training program (2025). The primary objective is to transition from a student to a System Software Engineer by mastering low-level computing, memory management, and security exploits.

The philosophy is simple: **No Magic.** I avoid using high-level abstractions where possible and instead implement core functionalities (like memory allocators, vector containers, and system calls) from scratch to achieve deep understanding.

## Architecture & Directory Structure

This project is organized into seven core modules, each targeting a specific domain of system engineering.
```text
.
├── 00_Daily_Log
│   └── Daily engineering journal, troubleshooting logs, and learnings.
│
├── 01_Wheel_Reinvention
│   ├── Implements standard libraries (malloc, vector, string) from scratch.
│   └── Focus: Memory management, pointers, and data structure internals.
│
├── 02_Algorithm_PS
│   ├── Baekjoon: C++ practice for implementation skills (BFS/DFS, Bitmask).
│   ├── LeetCode: Preparation for global tech interviews.
│   ├── SWEA: Samsung SW Expert Academy problems.
│   └── Focus: Time complexity analysis and code optimization.
│
├── 03_CTF_Practice
│   ├── Wargame write-ups and exploit scripts.
│   └── Focus: Buffer Overflow, ROP, and binary analysis using Python pwntools.
│
├── 04_CUDA_Lab
│   ├── GPU programming and parallel computing (Matrix Multiplication).
│   └── Focus: SIMT architecture and memory hierarchy optimization.
│
├── 05_OpenSource_Contrib
│   ├── Open Source Contribution preparation (Target: QEMU, Linux Kernel).
│   └── Focus: Codebase analysis, patch submission, and communication.
│
└── 06_AI-Agent_Dev
    ├── Agentic AI development using Model Context Protocol (MCP).
    └── Focus: Backend logic for file/security analysis agents.
```

## Technical Stack

- **Languages**: C, C++ (STL, Low-level), Python (Scripting), x86-64 Assembly
- **System**: Linux (Ubuntu), Git, Vim/VS Code
- **Tools**: GDB (Debugging), Pwntools (Exploit), GCC/Make (Build), Docker
- **Hardware**: NVIDIA CUDA (Scheduled)

## Key Implementations (Highlights)

- **Custom Memory Allocator**: A simplified implementation of `malloc` and `free` using explicit list management.
- **My Vector**: Re-implementation of `std::vector` handling dynamic memory resizing and template programming.
- **Binary Analyzer**: A Python-based agentic tool for detecting file anomalies and security threats.

## Status

- **Period**: Dec 2025 - Feb 2026 (8 Weeks)
- **Current Focus**: Phase 1 - C Language Deep Dive & Algorithm Foundation.

---

Copyright (c) 2025 sumin-world. All rights reserved.