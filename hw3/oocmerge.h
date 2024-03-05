//
// Created by Joe Nguyen on 3/1/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void generate_numbers(int, char*);
void create_temp_dir();
void verify_and_print(char*);