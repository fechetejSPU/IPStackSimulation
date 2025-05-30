# 💻 Internet Protocol Stack Simulation Assignment

**Project Group 1:** Joshua Fechete, Joyce Tang, and Anthony Scanlon

---

## Program Description

This program is designed to simulate how messages are transferred through the Internet protocol stack, with an emphasis on four core layers: **Application**, **Transport**, **Network**, and **Link**.

The simulation demonstrates **encapsulation** and **decapsulation** as the message moves through the stack. Upon running the program, you’ll be prompted to enter a message. The message is then visibly passed through each layer (sending side), and later received back in reverse order (receiving side), outputting the final message.

When the message crosses the link layer, you will have the option to control whether it successfully crosses, and see how the network recovers from errors.

---

## File Structure / Overview

Our main folder contains:
- `main.cpp`
- Two subfolders: `layers/` and `.vscode/`

### 🔹 `main.cpp`  
Controls our program's actions, including outputting various text, allowing for user input to accept a message, and then calling the application layer to send the message through the stack, simulating the IP stack process. 

### 🔹 `layers/`  
Contains 8 files (`.h` and `.cpp` pairs) for:
- Application Layer
- Transport Layer
- Network Layer
- Link Layer

Each layer has `send` and `receive` functions that modify a global `myMessage` string and pass the data through the stack.

### 🔹 `.vscode/`  
Contains a `tasks.json` file with one task:  
**"Build & Run IP Simulation"**  
This allows the program to be built and executed directly from within the VSCode terminal.

---

## How to Build / Run

Our program can be run in a standard way using a terminal of choice (some of us used WSL to run this), or by running the "Build & Run IP Simulation" task in VSCode. 

---

### With Terminal

1. Navigate to the project directory in your terminal.
2. Compile the program with:

```bash
g++ -o 'mainRun' 'main.cpp' 'layers/application.cpp' 'layers/link.cpp' 'layers/transport.cpp' 'layers/network.cpp'
```

3. Then run it using:

```bash
./mainRun
```

This will launch the program. Enter a message when prompted, and observe how it passes through each layer.

---

### With VSCode Tasks

Using VSCode, you can run the task and save time by running the program conveniently.

1. Open the project in VSCode.
2. From the top bar, go to:
   `Terminal` → `Run Task`
3. Choose **"Build & Run IP Simulation"**.
4. The program will build and run automatically.
5. Enter your message and watch the stack simulation unfold in the terminal.

---