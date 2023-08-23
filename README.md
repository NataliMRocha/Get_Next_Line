# :clipboard: Get_Next_Line | 42 SP
- Actual Status : finished.
- Result        : Approved with 125 points by moulinette (the 42 tester) ✅

  GNL is the second project at 42.
  The aim of this project is to write a function that reads a file of buffer size specified by the user parameter and returns only one line each time the function is called.
  There are two main challenges: handling varying buffer sizes and eliminating memory leaks.
## 📝 Functions

| Function | Description |
| :------: | :---------: |
| ``get_next_line.c`` | Contains the functions that compose the program logic, make with linked list.|
| ``get_next_line_utils`` | Contains the auxiliary functions. |
| ``get_next_line.h`` | The header with functions libraries and prototypes. |
| ``get_next_line_bonus.c`` | Contains the functions that compose the program logic, make with array.|
| ``get_next_line_utils_bonus`` | Contains the auxiliary functions. |
| ``get_next_line_bonus.h`` | The header with functions libraries and prototypes. |


## :star: Bonus
The same function but the challenge is dealing with multiple file descriptors!

## 🛠️ Usage

In order to use this function in your project, you must download this repository into your pc 

``` shell
$> git clone https://github.com/NataliMRocha/Get_Next_Line.git
```
Modify the path of the .txt file to one file of your preference in the main.

Compile with the command below (remember to replace "n" to the number of your preference):
``` shell
$> cc -Wall -Wextra -Werror -D BUFFER_SIZE=n get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```
