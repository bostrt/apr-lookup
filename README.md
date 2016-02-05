```
# gcc lookup.c -o lookup $(apr-1-config --cflags --cppflags --includes --link-ld) -ggdb
# ./lookup 
Usage: ./lookup host port

# ./lookup google.com 80
google.com:80 => 173.194.123.96
```
