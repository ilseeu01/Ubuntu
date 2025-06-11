#!/bin/bash

prefix="ece9048_example_"
ext=".txt"

index=0

#현재 디렉터리의 .txt 파일들에 대해 반복
for file in *.txt
do 
	#존재하는 파일인지 확인하는 조건문
	[ -f "$file" ] || continue

	#새로운 파일명 생성(2자리 숫자 형식)
	new_name=$(printf "%s%02d%s" "$prefix" "$index" "$ext")

	#파일 이름 변경
	mv "$file" "$new_name"

	let index+=1

done
