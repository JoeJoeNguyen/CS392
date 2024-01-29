#!/bin/bash
# junk.sh
# author: Son Nguyen (Joe)
# date: Jan 27, 2023

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
# Initialize a counter for the number of options enabled
option_counter=0

# Check each option
while getopts ":hlp" opt; do
  case ${opt} in
    h )
      option_counter=$((option_counter+1))
      ;;
    l )
      option_counter=$((option_counter+1))
      ;;
    p )
      option_counter=$((option_counter+1))
      ;;
    *)
      echo "Error: Unknown option '-${OPTARG}'." >&2
      exit_abnormal
      ;;
  esac
done

shift $((OPTIND -1))

# If more than one option is enabled, print an error message and exit
if [ $option_counter -gt 1 ] || ([ $option_counter -gt 0 ] && (( $# > 0 ))); then
  echo "Error: Too many options enabled."
  usage
  exit 1
fi


# Check if the ~/.junk directory exists and create it if it does not
mkdir -p ~/.junk

while getopts ":hlp" options; do
  case "${options}" in
    h)
      usage
      ;;
    l)
      ls -a -l ~/.junk/
      ;;
    p)
      #delete all file "*" and hidden files ".*"
      rm -rf ~/.junk/{*,.*}
      ;;
    *)
      echo "Error: Unknown option '-${OPTARG}'." >&2
      exit_abnormal
      ;;
  esac
done

# Check if no arguments were provided
if [ $# -eq 0 ]; then
  usage
  exit 0
fi


# Move the files to the ~/.junk directory if file not found get warning
for file in "$@"; do
  if [ -e "$file" ]; then
    mv "$file" ~/.junk/
  else
    echo "Warning: '$file' not found."
  fi
done

exit 0

