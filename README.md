```
# yum install apr apr-util apr-devel gcc

# gcc lookup.c -o lookup $(apr-1-config --cflags --cppflags --includes --link-ld) -ggdb
# ./lookup 
Usage: ./lookup host

# ./lookup google.com
google.com => 173.194.123.96
```
