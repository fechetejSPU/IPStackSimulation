# Internet Protocol Stack Simulation Assignment

Project Group 1: Joshua Fechete, Joyce Tang, and Anthony Scanlon

## Program Description

This program is designed to simulate how messages are transferred through the Internet protocol stack, with an emphasis on four core layers, being the Application, Transport, Network, and Link layers. In our program, we hope to show a demonstration of the encapsulation and decapsulation process, as our message interacts with each of the layers in order to deliver a final message. Upon running the program, you will be prompted to type in a message. The program will then visibly take the message you input and send it through each layer, and then receive it in reverse order through each layer, outputting the original message.

## File Structure/Overview

In our main folder, we have main.cpp and 2 subfolders, layers and .vscode. Our main.cpp file controls our programs actions, including outputting various text, allowing for user input to accept a message, and then calling upon functions from the 4 .h and .cpp files within the layers subfolder, in order to execute the rest of the program, simulating the IP stack process. In the layers folder, we have in total 8 files, .h and .cpp files for application, transport, network, and link layers. Each layer represented has a function to send and receive a message, modifying a global "myMessage" string and sending it back to main to be processed further. 

In the .vscode folder, we have tasks.json which contains one task labelled "Build & Run IP Simulation", which upon running, will compile, build, and run our program within the VSCode terminal. 

## How to Build/Run

Our program can be run in a standard way using a terminal of choice (some of us used WSL to run this), or by running the "Build & Run IP Simulation" task in VSCode. 

## With Terminal

With a terminal, first access the program filespace. Then, run the following command to compile and build the program into an executable:

g++ -o 'mainRun' 'main.cpp' 'layers/application.cpp' 'layers/link.cpp' 'layers/transport.cpp' 'layers/network.cpp'

Then, simply run the following command to run the newly created .exe file:

./'mainRun'

This will begin running the program, and then you can input a message, and watch the simulation process unfold. 

## With Tasks

Using VSCode, you can run the task and save time by running the program conveniently. While in the project workspace, and while you have the Task Runner extension active on VSCode, click on the top bar on the screen, and navigate to the "Run Task" option in the dropdown menu. You should see "Build & Run IP Simulation" as the one task we have created in our project workspace. Run that task, and the program will compile, build, and run, then just enter the message you want to send, and let the rest of the program run to completion. 