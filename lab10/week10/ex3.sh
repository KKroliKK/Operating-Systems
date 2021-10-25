touch _ex3.txt
echo "Some content" >> _ex3.txt
chmod a-x _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod uo+wrx _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod 660 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod 775 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod 777 _ex3.txt
ls -l _ex3.txt >> ex3.txt
