for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > in
    ./1112 < in > out1
    ./1112_brute < in > out2
    diff -w out1 out2 || break
    #diff -w <(./a < int) <(./brute < int) || break
done
