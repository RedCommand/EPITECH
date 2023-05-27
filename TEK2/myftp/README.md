# myftp project :file_folder:

## Done by Maxime - Epitech 2023 :mortar_board:

### Overview

This project is a part of the **second** year of Epitech.<br>
I had **2 weeks** to complete it. :spiral_calendar:<br>

The goal of this project was to create a ftp server complient with a [RFC959 like](PROTOCOL.txt) protocol in **C**. :open_file_folder:<br>

### Feature

The following command are implemented, you can find their description in the [protocol](PROTOCOL.txt)

* `USER`
* `PASS`
* `CWD`
* `CDUP`
* `QUIT`
* `PWD`
* `PASV`
* `HELP`
* `NOOP`
* `LIST`
* `RETR`
* `STOR`
* `SYST`

> **Warning**
> there is **no authentification system**, the only way to log into the server is by using the `Anonymous` user with a blank password (you must use the `PASS` command with a blank password, not providing any password will not work)

### Running the project locally

* Clone this repository locally
* Run `make` in your bash / command line
* Run `./myftp <port> <path>`

To try this program, you can to use this **command**: <br>

```bash
make && ./myftp 4242 ./
```

> **Warning**
> the only way to quit the server is to kill it, either via CTRL-C in the command line or by sending a SIGINT

### Arguments

* port: on which port the server will launch
* path: indicate the root folder of the server

Here are the different **tools** and **languages** we used to make this project: :hammer_and_wrench:

[![Main tools](https://skillicons.dev/icons?i=c,cmake,idea,github,md&perline=9)](https://github.com/tandpfun/skill-icons)
