# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    fuckme.sh                                          :+:    :+:             #
#                                                      +:+                     #
#    By: nsterk <nsterk@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:55:48 by nsterk        #+#    #+#                  #
#    Updated: 2020/11/15 01:58:11 by nsterk        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

source ./config.sh

#for arg in ${@}
#do
#	case "${arg}" in
#		"-gently")		OPT_GENTLY=1 ;;
#		"-hard")		OPT_HARD=1 ;;
#		"-p1")			OPT_PART2=0 ;;
#		"-p2")			OPT_PART1=0 ;;
#	esac
#done


compile_library()
{
	printf "\033[0;36mCompiling library..\033[0m\n"
	if  [ -e ${PATH_LIBFT}/Makefile ]
	then
		make -C $PATH_LIBFT re && make re
		result=$?
	else
		printf "\033[0;31mMissing Makefile\033[0m\n"
		exit 1;
	fi

	if [ $result -gt 0 ]
	then
		printf "\033[0;31mSomething went wrong during compilation. Sorry.\033[0m\n"
		exit 1;
	fi
	printf "\033[0;36mDone compiling\033[0m\n\n"
}

run()
{
	printf "\033[0;36mStarting execution...\033[0m\n"
	./fuckme
	printf "\033[0;36mFinished execution\033[0m\n"
	exit $?
}

compile_library
run 
;;