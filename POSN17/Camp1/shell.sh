for((i = 1; i <= 100; i++)); do
    echo $i
    ./gen $i > int
    ./Anyway < int > out
done