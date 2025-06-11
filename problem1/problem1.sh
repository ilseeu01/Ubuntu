#!/bin/bash

declare -a scores=(85 70 100 60 77) # 학생 점수 배열 선언

# 평균 점수를 계산하는 함수
calculate_average() { 
	local arr=("$@") # 모든 인자를 배열로 받음
	local sum=0
	local count=0

	for score in "${arr[@]}"
	do 
		let sum+=score # 점수를 누적하여 합계 계산
		let count+=1 # 학생 수 카운트
	done

	local avg=0
	if [ $count -ne 0 ]; then # 학생 수가 0이 아니면
		let avg=sum/count # 평균 계산
	fi
	
	echo $avg # 평균 반환

}

# 평균 이상인 학생을 세는 함수
count_above_average() { 
	local avg=$1
	shift # 첫 번째 인자(평균)을 제거하고 나머지 점수만 남김
	local arr=("$@")
	local count=0

	for score in "${arr[@]}"
	do
		if [ $score -ge $avg ]; then
			let count+=1 # 평균 이상이면 카운트 증가
		fi
	done

	echo $count # 평균 이상 학생 수 반환
}

# 점수 출력 배열
echo "학생 점수 목록: ${scores[@]}"

# 평균 계산 및 출력
avg_score=$(calculate_average "${scores[@]}")
echo "평균 점수: $avg_score"

# 평균 이상인 학생 수 계산 및 출력
above_avg_count=$(count_above_average $avg_score "${scores[@]}")
echo "평균 이상인 학생의 수: $above_avg_count"

# 90점 이상이면서 짝수인 학생 수 계산
let high_even_count=0
for score in "${scores[@]}"
do
	if [ $score -ge 90 ] && [ $((score % 2)) -eq 0 ]; then
		let high_even_count+=1
	fi
done
echo "90점 이상이면서 짝수인 학생 수: $high_even_count"

# 60 점 미만 또는 100점인 점수 출력
i=0
echo -n "60점 미만이거나 100점인 학생 점수:"
while [ $i -lt ${#scores[@]} ]
do 
	score=${scores[$i]}
	if [ $score -lt 60 ] || [ $score -eq 100 ]; then
		echo -n "$score"
	fi
	let i+=1
done
echo
