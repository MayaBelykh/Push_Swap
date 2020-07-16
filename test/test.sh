CH=""
ARG=""
echo "\033[0m:::::::::::::::::::::::::::::::::::::::\033[1;32m Usage \033[0m:::::::::::::::::::::::::::::::::::::::\033[0m"
echo "\n\033[0;35mFor sort numbers use push-swap:\n\033[0;32m./pushswap \033[0mnumber number .. number\n\033[0m"
echo "\033[0;35mFor check command use checker:\n\033[0;32m./cheker \033[0mnumber number .. number\ncommand\ncommand\n..\ncommand\033[0m"
echo "\n\033[0;35mFor test pushswap with visualisation:\n\033[0;32msh test/test.sh\033[0m"
echo "\n\033[0m::::::::::::::::::::::::::\033[1;33m Starting test with visualisation \033[0m:::::::::::::::::::::::::\033[0m"
echo "\n\033[0;35mDo you wanna use randomiser? \033[0m[y / n]"
read -n 1 CH
case "$CH" in
	[nN]) echo "\033[0;32m\n\nInput arguments:\033[0m"; read ARG;;
	[yY]) echo "\033[0;32m\n\nInput arguments:\033[0m"; ARG=`ruby -e "puts (-10..89).to_a.shuffle.join(' ')"`; echo $ARG;;
	*) echo "\n\n\033[0;31mInvalid input. Abort program 💀\033[0m\n"; exit;;
esac
echo "\n\033[2;37m--> \033[01;30mOpening results push_swap\033[0m" && ./push_swap $ARG > test/command_pushswap && open test/command_pushswap
echo "\n\033[2;32mPush_Swap with checker:\033[0m"
./push_swap $ARG | ./checker $ARG
echo "\n\033[2;32mStart visualisation..\033[0m"
./push_swap $ARG | java -jar visual/out/artifacts/Visual_jar/Visual.jar $ARG
echo "\n\033[0;31m🔥  The End 🔥\033[0m"