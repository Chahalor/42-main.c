#!/bin/bash

# Liste des valeurs pour BUFFER_SIZE
BUFFER_SIZES=(-1 0 1 2 10 32 47 1000000)

if [$# -eq 0]; then
	for size in "${BUFFER_SIZES[@]}"
	do
		# echo "Testing with BUFFER_SIZE=$size"
		cc -Wall -Wextra -Werror -g3 -D BUFFER_SIZE=$size ./get_next_line.c ./get_next_line_utils.c .my_test/main.c -o test_gnl # -fsanitize=address
		# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_gnl
		./test_gnl
		echo "------------------------------------"
	done
fi
for size in "${BUFFER_SIZES[@]}"
do
	# echo "Testing with BUFFER_SIZE=$size"
	cc -Wall -Wextra -Werror -g3 -D BUFFER_SIZE=$size ./get_next_line.c ./get_next_line_utils.c .my_test/main_bonus.c -o test_gnl # -fsanitize=address
	# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_gnl
	./test_gnl
	echo "------------------------------------"
done
# rm ./test_gnl
