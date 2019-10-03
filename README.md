# CRAPPY-Compiler
Compiles a CRAPPY script to a binary file that can be run by the CRAPPY interpreter.
-
Command Palette:\
load       - 0x00 loads either the content of a cell, a number or a string in the accumulator\
loadstring - 0x01 loads a string from the storage in the accumulator                         \
store      - 0x02 stores the accumulator in a cell                                           \
mov        - 0x03 moves the value of one to another cell                                     \
add        - 0x04 adds sth. to the accumulator                                               \
sub        - 0x05 substracts                                                                 \
mul        - 0x06 multiplication (repeats strings)                                           \
div        - 0x07 division                                                                   \
not        - 0x08 binary not                                                                 \
or         - 0x09 binary or                                                                  \
nor        - 0x0A binary nor                                                                 \
and        - 0x0B binary and                                                                 \
nand       - 0x0C binary nand                                                                \
xor        - 0x0D xor                                                                        \
nxor       - 0x0E binary nxor                                                                \
shiftl     - 0x0F left shift on the accumulator                                              \
shiftr     - 0x10 right shift on the accumulator                                             \
goto       - 0x11 goes to a certain marker                                                   \
goz        - 0x12 go if zero                                                                 \
gonz       - 0x13 go if not zero                                                             \
gon        - 0x14 go if negative                                                             \
gonn       - 0x15 go if not negative                                                         \
gop        - 0x16 go if positive                                                             \
gonp       - 0x17 go if not positive                                                         \
gog        - 0x18 go if greater than                                                         \
gos        - 0x19 go if smaller than                                                         \
goeq       - 0x1A go if equal to                                                             \
print      - 0x1B prints in the console                                                      \
println    - 0x1C prints and adds a linebreak character                                      \
printf     - 0x1D interpretes cell references while printing                                 \
run        - 0x1E runs a scipts (e.g. shell, bash, another CRAPPY, etc.)                     \
stop       - 0x1F quits the program

number literal 0x00\
cell/$number   0x01\
accu as cell/$ 0x02\
string literal 0x03

01111111\
 |||||||\
 ||+------operator\
 |+-------number literal / cell\
 +--------accu / string literal\

#8-bit\
#define haxx and $13\
load #0100111         0x00 0x00 0x47\
haxx                  0x0B 0x01 0x0D\
store $               0x02 0x02\
load "Hello"  	      0x00 0x03 0x48 0x65 0x6c 0x6c 0x6f 0x00\
println $     	      0x1A 0x02\
stop "cya"            0x1D 0x63 0x79 0x61
