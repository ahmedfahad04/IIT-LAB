# IIT-LAB

A personal archive of the lab work, assignments, and side explorations I did during my undergraduate years at IIT. Everything lives here — C homework from the first semester, socket programming, database scripts, design patterns in Java, and Jupyter notebooks on image processing and machine learning.

Feel free to dive into the ocean of code. :)

---

## Table of Contents

- [What's inside](#whats-inside)
- [Repository layout](#repository-layout)
- [Languages and tools](#languages-and-tools)
- [Running the code](#running-the-code)
- [Notes](#notes)

---

## What's inside

The repo is organized by semester, then by course. Not every semester is present, and folder names are a mix of course codes and plain descriptions (the archive was reorganized over time).

### 1st Semester

| Course | Folder | Highlights |
| --- | --- | --- |
| CSE101 — Structured Programming | `1st Semester Lab/CSE101_ Structured Programming` | Home assignments HA1–HA5, string/character utilities, CGPA calculator, search-efficiency comparison |

### 2nd Semester

| Course | Folder | Highlights |
| --- | --- | --- |
| CSE 201 — Data Structures & Algorithms | `2nd Semester Labs/CSE 201: DSA` | Linked lists, stacks/queues, binary trees, heaps, Huffman coding, sorting, infix→postfix; dynamic programming, graph theory, greedy algorithms, network flow |

### 3rd Semester

| Course | Folder | Highlights |
| --- | --- | --- |
| CSE301 — Combinatorial Optimization | `3rd Semester Labs/CSE301_ CO Course` | Dynamic programming, graph theory, greedy algorithms, network flow, lecture slides |
| CSE311 — Computer Networking | `3rd Semester Labs/CSE311_Networking` | Wireshark lab reports and packet traces (DNS, HTTP, TCP, UDP, IP, ICMP, SSL, DHCP, 802.11, NAT) |
| MATH304 — Numerical Analysis | `3rd Semester Labs/MATH304_ Numerical Analysis` | Root finding, linear systems, numerical differentiation/integration, class practice |
| SE312 — Theory of Computing | `3rd Semester Labs/SE312_ Theory of Computing` | CNF conversion, lab tasks in C++ |

### 4th Semester

| Course | Folder | Highlights |
| --- | --- | --- |
| CSE 401 — OS & System Programming | `4th Semester Labs/CSE 401_ OS and System Programming` | Banker's algorithm, dining philosophers, producer–consumer, reader–writer, threads & mutexes, fork/pthread client–server, chat server, lab final practice |
| CSE 402 — Database Management System I | `4th Semester Labs/CSE 402_Database Management System I` | SQL practice and lab tests, stored procedures/functions, B+ tree, bundled SQLite source |
| CSE 411 — Information Security | `4th Semester Labs/CSE 411_ Information Security` | AES (ECB/CBC/CTR) implementations, SHA-512, mono/polyalphabetic ciphers, Nmap scanning lab |

### 5th Semester

| Course | Folder | Highlights |
| --- | --- | --- |
| SE506 — Design Patterns | `5th Semester Labs/SE506_Design Pattern` | GoF creational/structural/behavioral patterns in Java, SOLID assignment, lab final and practice projects |

### 6th Semester

| Course | Folder | Highlights |
| --- | --- | --- |
| CSE601 — Distributed Systems | `6th Semester Labs/CSE601_Distributed Systems` | Notes on database scaling: master–slave and master–master replication |
| CSE604 — Artificial Intelligence | `6th Semester Labs/CSE604_AI` | 8-puzzle solver (Python) plus an interactive React/Tailwind version |
| CSE605 — Software Testing | `6th Semester Labs/CSE605_Software Testing` | JUnit/Maven `BookStore` project, Eclipse `bookstore` variant, reference material |
| CSE606 — Software Design | `6th Semester Labs/CSE606_Software Design` | MVC user app in Node.js/Express/Mongoose (two iterations) |

### 8th Semester

| Course | Folder | Highlights |
| --- | --- | --- |
| CSE803 — Project Management | `8th Semester Labs/CSE803_Project Management` | PMBOK guide, sample assignment, final exam syllabus |
| CSE811 — Software Maintenance | `8th Semester Labs/CSE811_Software Maintenance` | Java refactoring exercises, mock finals, paint application (original and solved) |
| CSE829 — Image Processing | `8th Semester Labs/CSE829_Image Processing` | Notebooks on image I/O, histogram equalization, edge detection (Sobel/Roberts/Laplacian), noise removal, thresholding (incl. Otsu), morphology, sharpening; paper presentation on edge detection (TEED) |
| CSE837 — Machine Learning | `8th Semester Labs/CSE837_Machine Learning` | AUC–ROC notebook, lecture PDFs, final project (*StyleTalker*), reference books in `Books/` |

---

## Repository layout

```
IIT-LAB/
├── 1st Semester Lab/
│   └── CSE101_ Structured Programming/
├── 2nd Semester Labs/
│   └── CSE 201: DSA/
├── 3rd Semester Labs/
│   ├── CSE301_ CO Course/
│   ├── CSE311_Networking/
│   ├── MATH304_ Numerical Analysis/
│   └── SE312_ Theory of Computing/
├── 4th Semester Labs/
│   ├── CSE 401_ OS and System Programming/
│   ├── CSE 402_Database Management System I/
│   └── CSE 411_ Information Security/
├── 5th Semester Labs/
│   └── SE506_Design Pattern/
├── 6th Semester Labs/
│   ├── CSE601_Distributed Systems/
│   ├── CSE604_AI/
│   ├── CSE605_Software Testing/
│   └── CSE606_Software Design/
└── 8th Semester Labs/
    ├── CSE803_Project Management/
    ├── CSE811_Software Maintenance/
    ├── CSE829_Image Processing/
    └── CSE837_Machine Learning/
        └── Books/
```

---

## Languages and tools

| Area | Used in |
| --- | --- |
| **C** | Structured programming, OS & system programming, information security helpers |
| **C++** | Data structures & algorithms, theory of computing, OS tasks |
| **Java** | Design patterns, software maintenance, software testing (JUnit) |
| **Python** | AI (8-puzzle), image processing, security ciphers |
| **JavaScript / Node.js** | 8-puzzle (React + Tailwind), MVC apps (Express + Mongoose) |
| **SQL / SQLite** | DBMS labs, stored procedures, B+ tree work |
| **Jupyter Notebook** | Image processing, machine learning |
| **Wireshark** | Networking packet analysis |
| **Maven / npm** | Java and JavaScript project builds |

---

## Running the code

Most programs are standalone and were written for coursework, so there is no single build system for the whole repo. Typical commands:

**C / C++**

```bash
gcc file.c -o file && ./file
g++ -std=c++17 file.cpp -o file && ./file
```

**Java** (Maven projects use the included `pom.xml`)

```bash
javac File.java && java File
mvn test
```

**Python / notebooks**

```bash
pip install numpy matplotlib jupyter
jupyter notebook
python 8-puzzle.py
```

**SQL**

```bash
sqlite3 mydb.db < script.sql
```

**Node.js projects**

```bash
cd "6th Semester Labs/CSE606_Software Design/MVC Model V1/backend"
npm install
npm start          # or: npm run dev
```

**React 8-puzzle**

```bash
cd "6th Semester Labs/CSE604_AI/8-puzzle"
npm install
npm start
```

---

## Notes

- This is an academic archive, so code quality varies by semester and assignment. Some files are intentionally left as submitted.
- A few folders include third-party material: the SQLite source tree, an external Java project used for maintenance practice, and PDF books/slides. Those belong to their original authors.
- Large files (datasets, archives, IDE metadata) are excluded through `.gitignore`; a few paths may therefore be incomplete if you clone on a fresh machine.
- Folder naming is inconsistent (`CSE 201: DSA` vs `CSE311_Networking`) because the repo was reorganized after the fact — use the table above as the map.
- Experiments, half-finished practice files, and compiled binaries live alongside the polished submissions. Explore freely, but expect rough edges.

---

<p align="center"><i>Written somewhere between deadlines and midnight compiler errors.</i></p>
