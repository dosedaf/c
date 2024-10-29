# yg gua pelajarin dri projek ini

## integer
int niatnya dibuat portable buat mesin yg punya data size beda, masalahnya, kadang kita perlu range int yang eksak, yang terus sama walau pindah mesin. nah masalah ini bs disolve dengan lu pake typedefs nya stdint. kek uint8_t sampai uint64_t. bahasan lanjutan terkait integer ada di [libc - integer](https://www.gnu.org/software/libc/manual/html_node/Integers.html)

## typedef

## function pointer

## void pointer
pointer yg bisa dipopulate address tipe data apapun, void pointer bisa di typecast ke tipe data apapun.

### aturan void pointer:
  1. **gabisa langsung didereference**
      harus di typecast ke pointer dengan tipe data a baru lalu di dereference
  2. **c standard ga ngebolehin void pointer sm arithmetic**
      tp di gnu c boleh, considering the size of void as 1

### benefit pake void pointer:
  1. **implementasi generic functions**
  2. **commonly used for typecasting (i dont see the benefit tbh)**
  3. **is used in malloc and calloc**
  4. **void pointer + function pointer memungkinkan fungsi yg bs ambil argumen apapun dan return value apapun**

## arithmetic pointer

