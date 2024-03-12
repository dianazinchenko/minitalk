# minitalk
## Overview
The purpose of this project is to code a small data exchange program using UNIX signals.

## Features
- **Signal-based Communication:** Utilizes UNIX signals for inter-process communication (SIGUSR1 and SIGUSR2).
- **Fast Message Transmission:** The server implements optimized signal handling mechanisms to achieve rapid message transmission, ensuring minimal latency in data exchange.
- **Support for Multiple Clients:** Capable of handling concurrent connections from multiple clients without the need for server restarts, enabling seamless communication in a multi-user environment.

## Usage
1. Clone the repository
   ```
   git clone git@github.com:dianazinchenko/minitalk.git
2. Go inside the project folder and compile the library
   ```bash
   cd minitalk
   make
3. Run the server
   ```bash
   ./server
4. Now, in a new terminal, run the client
   ```bash
   ./client [SERVER PID] [message]
