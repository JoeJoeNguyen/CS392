#!/bin/bash
# junk.sh
# author: Son Nguyen (Joe)
# date: Jan 27, 2023
# I pledge my honor that I have abided by the Stevens Honor System

usage() {
cat << EOF
Usage: $0 [-hlp] [list of files]
   -h: Display help.
   -l: List junked files.
   -p: Purge all files.
   [list of files] with no other arguments to junk those files.
EOF
}

exit_abnormal() {
  usage
  exit 1
}

# Check if the ~/.junk directory exists and create it if it does not
mkdir -p $HOME/.junk

# Initialize a counter for the number of options enabled
option_counter=0

# Check each option
while getopts ":hlp" opt; do
  case ${opt} in
    h )
      option_counter=$((option_counter+1))
      # If more than one option is enabled, print an error message and exit
      if (($# > 1)) ; then
        echo "Error: Too many options enabled."
        usage
        exit 1
      fi
      usage
      ;;
    l )
      option_counter=$((option_counter+1))
      # If more than one option is enabled, print an error message and exit
      if (($# > 1))   ; then
        echo "Error: Too many options enabled."
        usage
        exit 1
      else
        ls -A -l $HOME/.junk/
      fi
      ;;
    p )
      option_counter=$((option_counter+1))
      # Delete all files "*" and hidden files ".*"
      # If more than one option is enabled, print an error message and exit
      if (($# > 1)) ; then
        echo "Error: Too many options enabled."
        usage
        exit 1
      else
        rm -rf $HOME/.junk/{*,.*}
      fi
      ;;
    *)
      echo "Error: Unknown option '-${OPTARG}'." >&2
      exit_abnormal
      ;;
  esac


done

# If no arguments were provided, display usage
if [ $# -eq 0 ]; then
  usage
  exit 0
fi

shift $((OPTIND -1))



# Move the files to the ~/.junk directory if file not found, get warning
for file in "$@"; do
  if [ -e "$file" ]; then
    mv "$file" ~/.junk/
  else
    echo "Warning: '$file' not found."
  fi
done

exit 0
