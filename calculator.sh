 

#Shell Program : Write a calculator which takes in only integers and the following operations and prints the result.+, -, *, / , %.


#!/bin/sh
echo "Enter the first no:"
read a
echo "Enter the second no:"
read b
case $1 in
"+") add=`echo $a \+ $b | bc`
echo "The sum is $add";;
"-") sub=`echo $a \- $b | bc`
echo "The difference is $sub";;
'*') pro=`echo $a \* $b | bc`
echo "The product is $pro";;
"/") div=`echo $a \/ $b | bc`
echo "The quotient is $div";;
"%") mod=`echo $a \% $b | bc`
echo "The modulus is $mod";;
esac