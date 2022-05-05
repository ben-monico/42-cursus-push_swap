let total=0
let num=0
let in=0
let out=0
let max=0
let min=9999
let maxin=0
let minin=99999
let j=100


# system("leaks -- push_swap");

for ((i=0; i<j; i++))
do
	in=$(ruby -e "puts (0..4).to_a.shuffle.join(' ')")
	out=$(./push_swap $in)
	num=$(echo $out | wc -w | xargs)
	echo $out | tr ' ' '\n' | ./checker_Mac $in
	if ((num > max))
	then
		maxin=$in
		((max=num))
	fi
	if ((num < min))
	then
		minin=$in
		((min=num))
	fi
	((total+=num))
done
echo $maxin > max.out
echo "Average: " $((total / j))
echo "MAX:     " $max
echo "MIN:     " $min
