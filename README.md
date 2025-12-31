# hft-cpp-roadmap
# HFT C++ Roadmap

A performance-oriented C++ repository documenting the path from standard systems programming to **Low-Latency** and **High-Frequency Trading (HFT)** architectures. 

This project implements core components of a trading engine (Feed Handler, Order Book) enforcing strict memory management constraints typical of financial execution venues.

## 🚀 Key Architectural Concepts

* **Zero-Copy Parsing:** Implementation of a CSV Feed Handler using `std::string_view` and `std::move` semantics to minimize memory bandwidth usage during market data processing.
* **Deterministic Memory Management:** Strict adherence to **RAII** principles. Usage of `std::vector::reserve` and custom pre-allocation patterns to prevent heap allocations (malloc/free) on the critical path (Hot Path).
* **Cache Locality:** Data-Oriented Design (DOD) using contiguous memory layouts (POD Structs) for Order Book entries, maximizing L1/L2 cache hits.
* **Type Safety without Overhead:** Usage of `explicit` constructors and strong typing to prevent implicit conversion bugs at compile-time, with zero runtime cost.

## 🛠️ Components

### 1. Feed Handler (`data_parser.cpp`)
* Parses simulated market data (Tickers, Prices, Sizes).
* **Optimization:** Replaces standard `std::string` copies with move semantics, reducing parsing latency.
* **Input:** High-throughput CSV streams.

### 2. Order Book (`order_book.cpp`)
* Manages the state of Buy/Sell orders in memory.
* **Optimization:** Encapsulated logic with `private` memory management to guarantee capacity constraints (preventing unwanted resizing).

## 📚 Study References
* *C++ Primer (5th Edition)* - Stanley B. Lippman
* *Computer Systems: A Programmer's Perspective (CS:APP)* - Randal E. Bryant
* *Operating Systems: Three Easy Pieces (OSTEP)* - Remzi H. Arpaci-Dusseau

---
