memorymasterscore=0;
echo ""
for bin in $(ls build/); do
	cd build;
	echo "[-] Valgrinding $bin ...";
	valgrind --leak-check=full "./$bin" &> /dev/null;
	if [[ $? -ne 0 ]]; then
		echo "[!] Check your memory stuff in $bin.c";
	else
		echo "[+] Memory master!!";
		memorymasterscore=$(($memorymasterscore + 1));
	fi;
	cd ..;
done;
echo "[!] Memory master with a score of $memorymasterscore";
echo ""
