//Bash script to auto check output
for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > in
    # ./a < in > out1
    # ./brute < in > out2
    # diff -w out1 out2 || break
    diff -w <(./sol < in) <(./brute < in) || break
done
echo case
cat in
#create and build a bruteforce code named brute.cpp, main solution code sol.cpp and a random test case generator gen.cpp. To make this script runable, run this command chmod +x s.sh (s.sh is this bash script name). Then run the script by ./s.sh or bash s.sh