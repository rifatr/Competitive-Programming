for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > inf
    ./a < inf > ouf
    ./b < inf > ans
    ./checker < inf > verdict
    diff -w verdict vrdct || break
    #diff -w <(./a < int) <(./b < int) || break
done
echo case
cat inf
echo output
cat ouf
echo answer
cat ans
