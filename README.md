## WackyTerminal
A terminal that is currently not very powerful. Made it just to mess around with NCurses and such. 

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


## Requirements
A Linux system or Windows with WSL (Windows Subsystem for Linux)

gcc (C compiler)

libncurses development package

## Installation

1.
On Debian/Ubuntu/WSL:

sudo apt update

sudo apt install build-essential libncurses5-dev

2.
git clone https://github.com/W4CKY/WackyTerminal.git

cd WackyTerminal

gcc wackyterminal.c -o wackyterminal -lncurses

3.
./wackyterminal

This should run the terminal. Have fun!
