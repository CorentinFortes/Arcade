g++ -c -fPIC mylib.cpp
g++ -shared -o libr.so mylib.o
g++ -c -fPIC mylib2.cpp
g++ -shared -o libr2.so mylib2.o
g++ myprograme.cpp -ldl
rm *.o