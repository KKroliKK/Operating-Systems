touch ../week01/file.txt
echo "I am the content!" >> ../week01/file.txt
link ../week01/file.txt _ex2.txt
ls -i ../week01/file.txt >> ex2.txt
find .. -inum 13244049 >> ex2.txt
find .. -inum 13244049 -exec rm {} \;