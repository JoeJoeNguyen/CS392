#!/bin/bash
# junk.sh
# author: Son Nguyen (Joe)
# date: Jan 27, 2023

usage() {
cat << EOF
Usage: $0 [-hlp] [list of files]
 -h: Display help.
 -l: List junked files
 -p: Purge all files
[list of files] with no other arguments to junk those files.
EOF
  exit 1
}
exit_abnormal() {
  usage
  exit
}
flag_counter=0

# Check if the ~/.junk directory exists and create it if it does not
mkdir -p ~/.junk

while getopts ":hlp" options; do
  case "${options}" in
    h)
      ((flag_counter++))
      usage
      ;;
    l)
      ((flag_counter++))
      ls -a -l ~/.junk/
      ;;
    p)
      ((flag_counter++))
      #delete all file "*" and hidden files ".*"
      rm -rf ~/.junk/{*,.*}
      ;;
    *)
      echo "Error: Unknown option '-${OPTARG}'." >&2
      exit_abnormal
      ;;
  esac
  if ((flag_counter > 1)); then
    echo "Error: Too many options enabled."
    exit_abnormal
  fi
done

shift $((OPTIND -1))

if ((flag_counter > 0)) && (( $# > 0 )); then
  echo "Error: Too many options supplied."
  exit_abnormal
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

