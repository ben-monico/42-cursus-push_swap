let total=0
let num=0
let in=0
let out=0
let max=0
let maxin=0
let j=100



for ((i=0; i<j; i++))
do
	in=$(ruby -e "puts (0..500).to_a.shuffle.join(' ')")
	out=$(./push_swap $in)
	num=$(echo $out | wc -w | xargs)
	if ((num > max))
	then
		maxin=$in
		((max=num))
	fi
	((total+=num))
done
echo $maxin > max.out
echo "Average: " $((total / j))
echo "MAX:     " $max
