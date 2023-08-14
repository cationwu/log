# C++   Synchronous&Asynchronous Logging System Based on Multiple Design Patterns
## This project mainly implements an individual log system, which mainly supports the following functions:
- Holding multi-level blog messages
- Holding synchronous and asynchronous logs
- Keep reliable writing records in the control console, components, and rolling components
- Concurrent writing of logs for multithreaded programs
- Supporting the expansion of different destination destinations
## development environment
- CentOS 7
- vscode
- g++/gdb
- Makefile
## key technology
- Class hierarchy design (inheritance and polymorphic applications)
- C++11 (multithreading, auto, smart pointer, right value index, etc.)
- Double Buffering
- Production and consumption model
- Design patterns (singletons, abstract factory, proxies, templates, etc.)
## performance testing
Next, perform a performance test on the log system to test how many log messages can be printed per second on average.(These testing are based on Tencent Cloud Server)  

Test environment:
- CPU -2 core memory -2GB
- System disk - SSD cloud hard drive 40GB
- OS：CentOS 7.6 64bit

Synchronous log & single thread input:

Synchronous log & five thread input:

Asynchronous log & single thread input:

Asynchronous log & five thread input:

