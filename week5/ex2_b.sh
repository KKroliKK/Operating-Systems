for i in {1..3000}
#while true
do  
    flock file.txt -c ./ex2_c.sh # this flock call prevents the race, withiut it numbers in the file repeat
done
