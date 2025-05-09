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

3.
git clone https://github.com/W4CKY/WackyTerminal.git
cd wacky-terminal
gcc -o wackyterminal wackyterminal.c -lncurses

5.
./wackyterminal

This should run the terminal. Have fun!
