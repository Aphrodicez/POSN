mkdir InputOutput
cd InputOutput
rm *.in
rm *.out
cd ..
g++ -std=c++11 -O2 -o gen.exe gen.cpp
g++ -std=c++11 -O2 -o PZ_Word.exe PZ_Word.cpp
g++ -std=c++11 -O2 -o sol.exe sol.cpp
for i in $(seq -w 1 100); do
    echo $i
    #./gen.exe $i > $i.in
    #./sol.exe < $i.in > sol$i.out
    #./PZ_Word.exe <$i.in> PZ_Word$i.out
    #diff sol$i.out PZ_Word$i.out || break
    ./gen.exe $i > inp
    ./sol.exe < inp > sol.out
    ./PZ_Word.exe < inp > PZ_Word.out
    diff sol.out PZ_Word.out || break
done
mv *.in InputOutput
mv *.out InputOutput
rm *.exe