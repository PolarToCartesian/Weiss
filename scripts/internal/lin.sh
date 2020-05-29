mkdir bin

# $1 is for the output filenam / path
# $2 is for -m32 or -m64
# $3 is for -mavx or nothing

g++ Source.cpp -o $1 -std=c++17 $2 $3 -O3 -I "/mnt/c/VulkanSDK/Include/"

./$1

pause