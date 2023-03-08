for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > int
    ./1755-palindrome-reorder < int > out1
    ./checker < out1 > out2
    diff -w out3 out2 || break
    # diff -w <(./wa < int) <(./ac < int) || break
done
