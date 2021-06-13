g++ -std=c++11 -O2 -o PN_Stock.exe PN_Stock.cpp
for ((i=1;i<=10;i++)); do
    echo $i
    ./PN_Stock.exe < $i.in > $i.sol
done
rm *.exe