Here's the corrected version of the README file:

# Minitalk - Terminal-based Echo Server

Welcome to Minitalk! This project reimplements an [Echo Server](https://medium.com/@himalee.tailor/what-is-an-echoserver-b2bfd3b8deeb) that allows communication between separate processes using Unix signals.

## Introduction

The project sets up a client and a server. Once the server is up and running, it prints its process ID (PID) that the client can target to send messages to. When a message is received by the server, it prints it to the standard output.

## Features

**Server:**
- Job identification: the server prints the PID of the client from which it receives the message, to allow for identification per sender.

**Client:**
- Extensive error handling and hints.
- Delivery report: once a message is fully delivered and the server has finished printing, it flags the job done, and the client prints a delivery status.

## Getting Started

To get started with this project, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/p-molnar/minitalk.git
   ```

2. Compile the source code via Makefile into `server` and `client` executables:
   ```bash
   make all
   ```

## Usage

3. Run the `server` and wait for the PID:
   ```bash
   ./server
   ```

4. When the `server` is running, pass its PID to the client along with a message to be printed by the server:
   ```bash
   ./client <PID> <message>
   ```

## License

This project is licensed under the [MIT License](LICENSE), allowing you to use, modify, and distribute the code freely.

Feel free to reach out if you have any questions or feedback.
