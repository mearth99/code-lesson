target=$1
name=${target:0:-4}

g++ -o $name $target

./$name

if diff /mnt/c/Users/dlwls/Downloads/output.txt /mnt/c/Users/dlwls/Downloads/myoutput.txt 1>/dev/null;then echo "예제정답과 일치합니다.";else echo "예제정답과 일치하지 않습니다.";fi