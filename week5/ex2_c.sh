File="file.txt"
Var1=0
Var1=$( tail -n 1 file.txt) 
Var1=$(expr $Var1 + 1)
echo "$Var1" >> $File